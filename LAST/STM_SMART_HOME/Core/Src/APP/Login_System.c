/*Library Layer*/
#include"../LIB/std_types.h"

/* MCAL */
#include"../MCAL/MSTK/MSTK_interface.h"

/*HAL*/
#include"../HAL/HLCD/HLCD_interface.h"
#include"../HAL/HKPD/HKPD_interface.h"


#include"Login_System.h"

u8 G_u8pass[4]=PASS;

u8 Byte_1 , Byte_2  , Byte_3 , Byte_4;

void System_Reset(void){
	    /*Start the system*/
		HLCD_u8ClearDisplay();
		HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_2);
		HLCD_u8SendString("Welcome to",2);
		HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_2);
		HLCD_u8SendString("Smart Home",2);
		MSTK_voidDelay_ms(2000);
		HLCD_u8ClearDisplay();
}



u8 Login_System(void){
	u8 pass[4];
	u8 counter = 0,returnedValue,loginFlag = 0,passFlag=1;
	HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
	for(u8 i=0 ; i < 3 ; i++){
		while(1){
			HKPD_u8GetKey(&returnedValue);
			if(returnedValue!= HKPD_u8_NO_KEY_PRESSED){
				if(returnedValue == '=') break;
				else{
					HLCD_u8SetCursor(HLCD_u8_LINE_2,counter);
					HLCD_u8SendChar(returnedValue);
					MSTK_voidDelay_ms(50);
					HLCD_u8SetCursor(HLCD_u8_LINE_2,counter);
					HLCD_u8SendChar('*');
					pass[counter++] = returnedValue;
				}
			}
		}
		if(counter != 4){
			/*User entered unavailable password*/
			counter = 0;
			HLCD_u8ClearDisplay();
			HLCD_u8SetCursor(HLCD_u8_LINE_1,HLCD_u8_Position_0);
			HLCD_u8SendString("Wrong,try again",0);
			HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
			MSTK_voidDelay_ms(2000);
		}
		else{
			/*User entered 4 Chars password  */
			/*Check if the password is right or wrong*/
			 passFlag =  Check_Pass(pass);
			if(passFlag){
				/*Pass is right*/
				loginFlag = 1;
				counter = 0;
				passFlag = 0;
				HLCD_u8ClearDisplay();
				HLCD_u8SendString("Pass is correct",0);
				MSTK_voidDelay_ms(1000);
				break;
			}
			else{
				/*pass is wrong*/
				loginFlag = 0;
				counter = 0;
				HLCD_u8ClearDisplay();
				HLCD_u8SendString("wrong,try again",0);
				HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
				MSTK_voidDelay_ms(2000);
			}
		}
	}
	return loginFlag;
}


u8 Check_Pass(u8* pass){
	u8 passFlag = 1;
	if(pass[0] != G_u8pass[0]) passFlag = 0;
	if(pass[1] != G_u8pass[1]) passFlag = 0;
	if(pass[2] != G_u8pass[2]) passFlag = 0;
	if(pass[3] != G_u8pass[3]) passFlag = 0;
	return passFlag;
}
