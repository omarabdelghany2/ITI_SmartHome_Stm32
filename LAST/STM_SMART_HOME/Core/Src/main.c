/*Library Layer*/
#include"LIB/std_types.h"
#include"LIB/Bit_Math.h"

/*MCAL Layer*/
#include"MCAL/MRCC/MRCC_Interface.h"
#include"MCAL/MGPIO/MGPIO_Interface.h"
#include"MCAL/MSTK/MSTK_interface.h"
#include"MCAL/MUART/MUART_Interface.h"

/*HAL Layer*/
#include"HAL/HLCD/HLCD_interface.h"
#include"HAL/HKPD/HKPD_interface.h"

/*Applications Layer*/
#include"APP/Login_System.h"
#include"APP/SMART_HOME.h"


void MGPIO_vINIT(void);

int main(void){
	/* RCC Init Function*/
	MRCC_vInit();

	/* RCC Enable Clk */
	MRCC_vEnableClock(MRCC_AHB1, GPIOAEN_DIS);
	MRCC_vEnableClock(MRCC_AHB1, GPIOBEN_DIS);
	MRCC_vEnableClock(MRCC_APB2, USART1EN_DIS);

	/* PER , HAL INIT */
	MSTK_voidInit();
	MGPIO_vINIT();
	MUART_UART1_vInit();
	HLCD_voidINIT();

	u8 loginTest = 0 ,system_state;
	System_Reset();
     while(1){

	  HLCD_u8ClearDisplay();
	  HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
	  /*Getting the password from the user and check it*/
	  HLCD_u8SendString("Enter your pass",0);
	  loginTest = Login_System();
	  HLCD_u8ClearDisplay();
	  if(!loginTest){ //Falied Login
		  HLCD_u8SendString("no more trials",0);
		  HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		  HLCD_u8SendString("wait 3 seconds",0);
		  /* Turn on buzzer */
		  MGPIO_vSetPinVal(MGPIO_PORTA, 6, MGPIO_HIGH);
		  MSTK_voidDelay_ms(3000);
		  MGPIO_vSetPinVal(MGPIO_PORTA, 6, MGPIO_LOW);

	  }
	  else{
		  system_state=0;
		  HLCD_u8ClearDisplay();
		  HLCD_u8SendString("Logged in",0);
		  MSTK_voidDelay_ms(1500);
		  while(!system_state)
			 system_state=Control_Home();
	  }

    }
	return 0;
 }




void MGPIO_vINIT(void){
	/* KEYPAD Columns */
	MGPIO_vSetPinMode(MGPIO_PORTB, 0 ,MGPIO_MODE_INPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 1 ,MGPIO_MODE_INPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 2 ,MGPIO_MODE_INPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 3 ,MGPIO_MODE_INPUT);

	MGPIO_vSetPinInputPull(MGPIO_PORTB, 0, MGPIO_PULLUP);
	MGPIO_vSetPinInputPull(MGPIO_PORTB, 1, MGPIO_PULLUP);
	MGPIO_vSetPinInputPull(MGPIO_PORTB, 2, MGPIO_PULLUP);
	MGPIO_vSetPinInputPull(MGPIO_PORTB, 3, MGPIO_PULLUP);

	/* KEYPAD ROWS */
	MGPIO_vSetPinMode(MGPIO_PORTB, 12 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 13 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 14 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTB, 15 ,MGPIO_MODE_OUTPUT);

	/* LCD CTRL PINS */
	MGPIO_vSetPinMode(MGPIO_PORTA, 0 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 1 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 2 ,MGPIO_MODE_OUTPUT);

	/* LCD DATA PINS */
	MGPIO_vSetPinMode(MGPIO_PORTA, 8 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 4 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 5 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 11 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 12 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 13 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 14 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 15 ,MGPIO_MODE_OUTPUT);

	/*Buzzer Pin*/
	MGPIO_vSetPinMode(MGPIO_PORTA, 6 ,MGPIO_MODE_OUTPUT);

	/* UART PINS */
	MGPIO_vSetPinMode(MGPIO_PORTA, 9, MGPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(MGPIO_PORTA, 10, MGPIO_MODE_ALTFUN);

	MGPIO_vSetAlternativeFunc(MGPIO_PORTA, 9, 7);
	MGPIO_vSetAlternativeFunc(MGPIO_PORTA, 10, 7);
}
