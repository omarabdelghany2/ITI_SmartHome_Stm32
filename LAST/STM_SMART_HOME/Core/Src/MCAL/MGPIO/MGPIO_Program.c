#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

#include"MGPIO_Config.h"
#include"MGPIO_Interface.h"
#include "MGPIO_Private.h"

void MGPIO_vSetPinMode(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Mode){
	switch(A_u8PortId){
		case MGPIO_PORTA: GPIOA->MODER &= ~(0b11 <<(A_u8PinNo*2));
					GPIOA->MODER |= (A_u8Mode <<(A_u8PinNo*2));
				break;
		case MGPIO_PORTB: GPIOB->MODER &= ~(0b11 <<(A_u8PinNo*2));
					GPIOB->MODER |= (A_u8Mode <<(A_u8PinNo*2));
				break;
		case MGPIO_PORTC: GPIOC->MODER &= ~(0b11 <<(A_u8PinNo*2));
					GPIOC->MODER |= (A_u8Mode <<(A_u8PinNo*2));
				break;
	}

}

void MGPIO_vSetPinOutPutType(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8OutPutType){
	if(A_u8OutPutType==MGPIO_OPENDRAIN){
		switch(A_u8PortId){
		case MGPIO_PORTA: SET_BIT(GPIOA->OTYPER,A_u8PinNo);
				break;
		case MGPIO_PORTB: SET_BIT(GPIOB->OTYPER,A_u8PinNo);
				break;
		case MGPIO_PORTC: SET_BIT(GPIOC->OTYPER,A_u8PinNo);
				break;
		}
	}
	else if(A_u8OutPutType==MGPIO_PUSHPULL){
		switch(A_u8PortId){
		case MGPIO_PORTA: CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
				break;
		case MGPIO_PORTB: CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
				break;
		case MGPIO_PORTC: CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
				break;
		}
	}

}

void MGPIO_vSetOutputSpeed(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8OutPutType){
	switch(A_u8PortId){
		case MGPIO_PORTA: GPIOA->OSPEEDR &= ~(0b11 <<(A_u8PinNo*2));
					GPIOA->OSPEEDR |= (A_u8OutPutType <<(A_u8PinNo*2));
				break;
		case MGPIO_PORTB: GPIOB->OSPEEDR &= ~(0b11 <<(A_u8PinNo*2));
					GPIOB->OSPEEDR |= (A_u8OutPutType <<(A_u8PinNo*2));
				break;
		case MGPIO_PORTC: GPIOC->OSPEEDR &= ~(0b11 <<(A_u8PinNo*2));
					GPIOC->OSPEEDR |= (A_u8OutPutType <<(A_u8PinNo*2));
				break;
	}
}

void MGPIO_vSetPinInputPull(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8PullType){
	switch(A_u8PortId){
			case MGPIO_PORTA: GPIOA->PUPDR &= ~(0b11 <<(A_u8PinNo*2));
						GPIOA->PUPDR |= (A_u8PullType <<(A_u8PinNo*2));
					break;
			case MGPIO_PORTB: GPIOB->PUPDR &= ~(0b11 <<(A_u8PinNo*2));
						GPIOB->PUPDR |= (A_u8PullType <<(A_u8PinNo*2));
					break;
			case MGPIO_PORTC: GPIOC->PUPDR &= ~(0b11 <<(A_u8PinNo*2));
						GPIOC->PUPDR |= (A_u8PullType <<(A_u8PinNo*2));
					break;
		}
}

u8 MGPIO_vGetPinVal(u8 A_u8PortId , u8 A_u8PinNo){
	u8 L_u8PinValue=0;
	switch(A_u8PortId){
			case MGPIO_PORTA: L_u8PinValue= GET_BIT(GPIOA->IDR,A_u8PinNo);
					break;
			case MGPIO_PORTB: L_u8PinValue= GET_BIT(GPIOB->IDR,A_u8PinNo);
					break;
			case MGPIO_PORTC: L_u8PinValue= GET_BIT(GPIOC->IDR,A_u8PinNo);
					break;
		}
		return L_u8PinValue;
}

void MGPIO_vSetPinVal(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Value){
	if(A_u8Value== MGPIO_HIGH){
	switch(A_u8PortId){
			case MGPIO_PORTA: SET_BIT(GPIOA->ODR,A_u8PinNo);
					break;
			case MGPIO_PORTB: SET_BIT(GPIOB->ODR,A_u8PinNo);
					break;
			case MGPIO_PORTC: SET_BIT(GPIOC->ODR,A_u8PinNo);
					break;
		}
}
	else if(A_u8Value== MGPIO_LOW){
	switch(A_u8PortId){
			case MGPIO_PORTA: CLR_BIT(GPIOA->ODR,A_u8PinNo);
					break;
			case MGPIO_PORTB: CLR_BIT(GPIOB->ODR,A_u8PinNo);
					break;
			case MGPIO_PORTC: CLR_BIT(GPIOC->ODR,A_u8PinNo);
					break;
		}
}
}

void MGPIO_vSetPinVal_fast(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Value){
	if(A_u8Value== MGPIO_HIGH){
		switch(A_u8PortId){
				case MGPIO_PORTA: GPIOA->BSRR = (1<<A_u8PinNo);
						break;
				case MGPIO_PORTB: GPIOB->BSRR = (1<<A_u8PinNo);
						break;
				case MGPIO_PORTC: GPIOC->BSRR = (1<<A_u8PinNo);
						break;
			}
	}
		else if(A_u8Value== MGPIO_LOW){
		switch(A_u8PortId){
				case MGPIO_PORTA: GPIOA->BSRR = (1<<(16+A_u8PinNo));
						break;
				case MGPIO_PORTB: GPIOB->BSRR = (1<<(16+A_u8PinNo));
						break;
				case MGPIO_PORTC: GPIOC->BSRR = (1<<(16+A_u8PinNo));
						break;
			}
	}
}

void MGPIO_vSetAlternativeFunc(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8AltFun){
	if(A_u8PinNo<=7 ){
		switch(A_u8PortId){
		case MGPIO_PORTA: GPIOA->AFRL &= ~(SET_ALTFUN_CLEANER <<(A_u8PinNo*4));
						 GPIOA->AFRL |= (A_u8AltFun <<(A_u8PinNo*4));
						 break;
		case MGPIO_PORTB: GPIOB->AFRL &= ~(SET_ALTFUN_CLEANER <<(A_u8PinNo*4));
						 GPIOB->AFRL |= (A_u8AltFun <<(A_u8PinNo*4));
		 	 	 	 	 break;
		case MGPIO_PORTC: GPIOC->AFRL &= ~(SET_ALTFUN_CLEANER <<(A_u8PinNo*4));
						 GPIOC->AFRL |= (A_u8AltFun <<(A_u8PinNo*4));
						 break;
		}
	}
	else{
		u8 L_u8RegBit= A_u8PinNo -8;
		switch(A_u8PortId){
			case MGPIO_PORTA: GPIOA->AFRH &= ~(SET_ALTFUN_CLEANER <<(L_u8RegBit*4));
							 GPIOA->AFRH |= (A_u8AltFun <<(L_u8RegBit*4));
							 break;
			case MGPIO_PORTB: GPIOB->AFRH &= ~(SET_ALTFUN_CLEANER <<(L_u8RegBit*4));
							 GPIOB->AFRH |= (A_u8AltFun <<(L_u8RegBit*4));
			 	 	 	 	 break;
			case MGPIO_PORTC: GPIOC->AFRH &= ~(SET_ALTFUN_CLEANER <<(L_u8RegBit*4));
							 GPIOC->AFRH |= (A_u8AltFun <<(L_u8RegBit*4));
							 break;
			}
	}

}
