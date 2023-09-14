/*Library Layer*/
#include"../LIB/std_types.h"

/* MCAL */
#include"../MCAL/MSTK/MSTK_interface.h"
#include"../MCAL/MUART/MUART_Interface.h"

/*HAL*/
#include"../HAL/HLCD/HLCD_interface.h"
#include"../HAL/HKPD/HKPD_interface.h"

#include"SMART_HOME.h"


static void Page_Option(u8 Copy_u8PageNum);


/***** Function to control home *****/
u8 Control_Home(void){
	u8 returnedValue=HKPD_u8_NO_KEY_PRESSED ,system_state=0;
	static u8 page=0;

	Page_Option(page);

	while(returnedValue == HKPD_u8_NO_KEY_PRESSED){
		/*Getting command from keypad */
		HKPD_u8GetKey(&returnedValue);
		/* Using given command to take action */
		if(returnedValue == '1'){
			// Light The first LED
			MUART_UART1_vSendByte(1);
		}
		else if(returnedValue == '2'){
			// Light The second LED
			MUART_UART1_vSendByte(2);
		}
		else if(returnedValue == '3'){
			// Light The third LED
			MUART_UART1_vSendByte(3);
		}
		else if(returnedValue == '4'){
			// turn off led 1
			MUART_UART1_vSendByte(4);
		}
		else if(returnedValue == '5'){
			// turn off led 2
			MUART_UART1_vSendByte(5);
		}
		else if(returnedValue == '6'){
			// turn off led 3
			MUART_UART1_vSendByte(6);
		}
		else if(returnedValue == '7'){
			// turn off all lights
			MUART_UART1_vSendByte(7);
		}

		else if(returnedValue == '8'){
			// Control Fan
			MUART_UART1_vSendByte(8);
		}
		else if(returnedValue == '9'){
			/* LOG OUT */
			system_state=1;
			break;
		}
		else if(returnedValue == '0'){
			/* Change Page */
			if(page==4) page=-1;
			Page_Option(++page);

		}
		returnedValue=HKPD_u8_NO_KEY_PRESSED;
	}

	return system_state;
}



static void Page_Option(u8 Copy_u8PageNum){
	switch(Copy_u8PageNum){
	case 0:
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
		HLCD_u8SendString("1-ON LED1",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		HLCD_u8SendString("2-ON LED2",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_11);
		HLCD_u8SendString("0-NXT",11);
			break;
	case 1:
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
		HLCD_u8SendString("3-ON LED3",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		HLCD_u8SendString("4-OFFLED1",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_11);
		HLCD_u8SendString("0-NXT",11);
			break;
	case 2:
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
		HLCD_u8SendString("5-OFFLED2",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		HLCD_u8SendString("6-OFFLED3",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_11);
		HLCD_u8SendString("0-NXT",11);
			break;
	case 3:
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
		HLCD_u8SendString("7-LIGHTSOFF",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		HLCD_u8SendString("8-FAN",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_11);
		HLCD_u8SendString("0-NXT",11);
			break;
	case 4:
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
		HLCD_u8SendString("9-LOG OUT",0);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		HLCD_u8SendString("0-FIRST PAGE",0);
			break;
	}

}







