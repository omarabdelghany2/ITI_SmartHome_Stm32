#include "LIB/Std_types.h"
#include "LIB/bit_math.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MUART/MUART_Interface.h"
#include "MCAL/MRCC/MRCC_Interface.h"

static u8 fan=0;
int main(void)
{
	/* RCC Init Function*/
	MRCC_vInit();

	/* RCC Enable Clk */
	MRCC_vEnableClock(MRCC_AHB1, GPIOAEN_DIS);
	MRCC_vEnableClock(MRCC_AHB1, GPIOBEN_DIS);
	MRCC_vEnableClock(MRCC_APB2, USART1EN_DIS);

	MUART_UART1_vInit();


	MGPIO_vSetPinMode(MGPIO_PORTA, 0 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 1 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 2 ,MGPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(MGPIO_PORTA, 3 ,MGPIO_MODE_OUTPUT);

	/* UART PINS */
	MGPIO_vSetPinMode(MGPIO_PORTA, 9, MGPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(MGPIO_PORTA, 10, MGPIO_MODE_ALTFUN);

	MGPIO_vSetAlternativeFunc(MGPIO_PORTA, 9, 7);
	MGPIO_vSetAlternativeFunc(MGPIO_PORTA, 10, 7);

	u8 UART_Data =0;
	while(1)
	{
		UART_Data = MUART_UART1_u8ReceiveByte();
		switch(UART_Data)
		{
		case 1 : // Light The first LED
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 0 , MGPIO_HIGH);
			break;
		case 2 : // Light the second LED
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 1 , MGPIO_HIGH);
			break;
		case 3 : // Light the third LED
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 2 , MGPIO_HIGH);
			break;
		case 4 : // turn off led 1
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 0 , MGPIO_LOW);
			break;
		case 5 : // turn off led 2
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 1 , MGPIO_LOW);
			break;
		case 6 : // turn off led 3
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 2 , MGPIO_LOW);
			break;
		case 7 : // Turn off all lights
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 0 , MGPIO_LOW);
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 1 , MGPIO_LOW);
			MGPIO_vSetPinVal_fast(MGPIO_PORTA, 2 , MGPIO_LOW);
			break;
		case 8 : // Turn Fan ON / off
			UART_Data=0;
			fan = !fan;
			if(fan==0)
			{
				MGPIO_vSetPinVal_fast(MGPIO_PORTA, 3 , MGPIO_LOW);
			}else
			{
				MGPIO_vSetPinVal_fast(MGPIO_PORTA, 3 , MGPIO_HIGH);
			}
			break;
		}
	}
	return 0;
}






