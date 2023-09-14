#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include "MRCC_Interface.h"
#include "MRCC_Config.h"
#include "MRCC_Private.h"


void MRCC_vInit(void){
	/*Select Clock Source (HSI/HSE/PLL)*/
#if RCC_SYS_CLK == RCC_HSE
				/*ENABLE HSE as a clock source*/
					SET_BIT(RCC->CR , HSEON);
				while(!(GET_BIT(RCC->CR, HSERDY)));
				switch(RCC_HSE_BYPASS){
					case ENABLE :   CLR_BIT(RCC->CR , HSEBYP);   break;
					case DISABLE :   SET_BIT(RCC->CR , HSEBYP);   break;
					}
				 /*Input System Clock*/
				 SET_BIT(RCC->CFGR , SW0);
				 CLR_BIT(RCC->CFGR , SW1);
				 while(!((GET_BIT(RCC->CFGR , SWS0) == 1)) && (GET_BIT(RCC->CFGR , SWS1) == 0 ));

#elif RCC_SYS_CLK == RCC_HSI
				 /*ENABLE HSI as a clock source*/
				 SET_BIT(RCC->CR ,HSION);
				 while(!(GET_BIT(RCC->CR , HSIRDY)));
				 /*Input System Clock*/
				 CLR_BIT(RCC->CFGR , SW0);
				 CLR_BIT(RCC->CFGR , SW1);
				 while(!((GET_BIT(RCC->CFGR , SWS0) == 0)) && (GET_BIT(RCC->CFGR , SWS1) == 0 ));

#elif RCC_SYS_CLK == RCC_PLL
				 /*ENABLE PLL as a clock source*/
				 SET_BIT(RCC->CR , PLLON);
				 while(!(GET_BIT(RCC->CR, PLLRDY)));
				 /*Input System Clock*/
				 SET_BIT(RCC->CFGR , SW1);
				 CLR_BIT(RCC->CFGR , SW0);
				 while(!((GET_BIT(RCC->CFGR , SWS0) == 0)) && (GET_BIT(RCC->CFGR , SWS1) == 1 ));
#endif


	/* CSS (ON/OFF) */
	#if RCC_CSS_Enable == ENABLE
		if(RCC_HSE_Enable == ENABLE){
		while(! GET_BIT(RCC->CR,HSE );
		SET_BIT(RCC->CR, CSSON);
		}
	#endif
}

void MRCC_vEnableClock(u8 A_u8BUS , u8 A_u8Peripheral){
	switch(A_u8BUS){
	case MRCC_AHB1 : SET_BIT(RCC->AHB1ENR,A_u8Peripheral); break;
	case MRCC_APB1 : SET_BIT(RCC->APB1ENR,A_u8Peripheral); break;
	case MRCC_APB2 : SET_BIT(RCC->APB2ENR,A_u8Peripheral); break;
	}
}

void MRCC_vDisableClock(u8 A_u8BUS , u8 A_u8Peripheral){
	switch(A_u8BUS){
		case MRCC_AHB1 : CLR_BIT(RCC->AHB1ENR,A_u8Peripheral); break;
		case MRCC_APB1 : CLR_BIT(RCC->APB1ENR,A_u8Peripheral); break;
		case MRCC_APB2 : CLR_BIT(RCC->APB2ENR,A_u8Peripheral); break;
		}
}
