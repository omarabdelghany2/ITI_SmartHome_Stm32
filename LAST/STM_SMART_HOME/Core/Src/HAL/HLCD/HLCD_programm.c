/*Library Layer*/
#include"../../LIB/std_types.h"
#include"../../LIB/bit_math.h"

/* MCAL */
#include"../../MCAL/MGPIO/MGPIO_Interface.h"
#include"../../MCAL/MSTK/MSTK_interface.h"

/*HAL*/
#include"HLCD_interface.h"
#include"HLCD_private.h"
#include"HLCD_config.h"


void HLCD_voidINIT(void)
{
	MSTK_voidDelay_us(31);
	/*Function set command*/
	HLCD_u8SendCmnd(FunctionSet);
	MSTK_voidDelay_us(40);
	/*Display on/off Control*/
	HLCD_u8SendCmnd(DisplayControl);
	MSTK_voidDelay_us(40);
	/*Display Clear*/
	HLCD_u8SendCmnd(DisplayClear);
	MSTK_voidDelay_ms(2);
	/*Entry Mode Set*/
	HLCD_u8SendCmnd(EntryMode);
}

u8 HLCD_u8SendCmnd(u8 Copy_u8Cmnd)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/*1- set Rs pin=> Low (command)*/
	MGPIO_vSetPinVal_fast(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN,MGPIO_LOW);
	/*2- set Rw pin=>low (write)*/
	MGPIO_vSetPinVal_fast(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN,MGPIO_LOW);
	/*3- send command to LCD on data Pins*/
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN0, GET_BIT(Copy_u8Cmnd,0));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN1, GET_BIT(Copy_u8Cmnd,1));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN2, GET_BIT(Copy_u8Cmnd,2));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN3, GET_BIT(Copy_u8Cmnd,3));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN4, GET_BIT(Copy_u8Cmnd,4));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN5, GET_BIT(Copy_u8Cmnd,5));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN6, GET_BIT(Copy_u8Cmnd,6));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN7, GET_BIT(Copy_u8Cmnd,7));
	/*4- set Enable pulse*/
	MGPIO_vSetPinVal_fast(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN, MGPIO_HIGH);
	MSTK_voidDelay_us(1);
	MGPIO_vSetPinVal_fast(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN, MGPIO_LOW);
	return Local_u8ErrorState;
}

u8 HLCD_u8SendChar (u8 Copy_u8Char)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/*1- set Rs pin=> high (char)*/
	MGPIO_vSetPinVal_fast(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN, MGPIO_HIGH);
	/*2- set Rw pin=>low (write)*/
	MGPIO_vSetPinVal_fast(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN, MGPIO_LOW);
	/*3- send command to LCD on data Pins*/
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN0, GET_BIT(Copy_u8Char,0));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN1, GET_BIT(Copy_u8Char,1));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN2, GET_BIT(Copy_u8Char,2));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN3, GET_BIT(Copy_u8Char,3));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN4, GET_BIT(Copy_u8Char,4));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN5, GET_BIT(Copy_u8Char,5));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN6, GET_BIT(Copy_u8Char,6));
	MGPIO_vSetPinVal(HCLD_u8_DATA_PORT, HLCD_u8DATA_PIN7, GET_BIT(Copy_u8Char,7));
	/*4- set Enable pulse*/
	MGPIO_vSetPinVal_fast(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN, MGPIO_HIGH);
	MSTK_voidDelay_us(1);
	MGPIO_vSetPinVal_fast(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN, MGPIO_LOW);
	return Local_u8ErrorState;
}


u8 HLCD_u8SetCursor(u8 Copy_u8LineNum,u8 Copy_u8CharNum)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	switch(Copy_u8LineNum)
	{
		case HLCD_u8_LINE_1:HLCD_u8SendCmnd(0x80+Copy_u8CharNum); break;
		case HLCD_u8_LINE_2:HLCD_u8SendCmnd(0xC0+Copy_u8CharNum); break;
		default:Local_u8ErrorState=STD_TYPES_NOK;break;
	}
	return Local_u8ErrorState;
}

u8 HLCD_u8SendString(u8 Copy_u8String[16],u8 Copy_u8Cursor)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	for(u8 i=0;Copy_u8String[i] !='\0'; i++)
	{
		if(i==16-Copy_u8Cursor)
			HLCD_u8SetCursor(2,0);
		HLCD_u8SendChar(Copy_u8String[i]);
	}

	return Local_u8ErrorState;
}

u8 HLCD_u8SendNumber(u16 Copy_u8Number)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 temp1;
	u16 temp2=Copy_u8Number;
	u16 temp3=1;
	u8 counter=0;
	if(Copy_u8Number==0)
		HLCD_u8SendChar('0');
	else{
	while(temp2!=0)
	{
		temp2=temp2/10;
		counter++;
	}
	for(u8 i=0;i<(counter-1);i++)
			temp3=temp3*10;
	for(u8 i=0;i<counter; i++)
	{
		temp1=(Copy_u8Number)/temp3;
		Copy_u8Number=(Copy_u8Number)%temp3;
		temp3=temp3/10;
		HLCD_u8SendChar(48+temp1);
	}
	}
	return Local_u8ErrorState;
}
/*
u8 HLCD_u8GenerateSpecialCharacter(u8* Copy_Pu8_pattern,u8 Copy_u8_CGROM_Index)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	HLCD_u8SendCmnd((0x40+Copy_u8_CGROM_Index));
	for(u8 i=0;i<8;i++)
		HLCD_u8SendChar(Copy_Pu8_pattern[i]);

	return Local_u8ErrorState;
}

u8 HLCD_u8DisplaySpecialCharacter(u8 Copy_u8_PatternId,u8 Copy_u8LineNum,u8 Copy_u8CharNum)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	HLCD_u8SetCursor(Copy_u8LineNum,Copy_u8CharNum);
	HLCD_u8SendChar(Copy_u8_PatternId);
	return Local_u8ErrorState;
}
*/
u8 HLCD_u8ClearDisplay(void)
{
	HLCD_u8SendCmnd(0x01);
	MSTK_voidDelay_ms(50);
	return 1;
}
