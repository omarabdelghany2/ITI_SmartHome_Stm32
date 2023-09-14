/*
 * MUART_Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Ziad Ragab
 */

#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "MUART_Interface.h"
#include "MUART_Config.h"
#include "MUART_Private.h"

void MUART_UART1_vInit(void){
	/*  Choose number of data bits */
#if WORD_Length == 8
	CLR_BIT(UART1->CR1,M);
#elif WORD_Length == 9
	SET_BIT(UART1->CR1,M);
#endif


	/* Choose Number of Stop bits */
#if STOP_BITS == 1
	CLR_BIT(UART1->CR2, 12);
	CLR_BIT(UART1->CR2, 13);
#elif STOP_BITS == 2
	CLR_BIT(UART1->CR2, 12);
	SET_BIT(UART1->CR2, 13);
#endif

	/* Set Baud Rate */
	UART1->BRR =  0x683;

	/** Enable UART **/
	SET_BIT(UART1->CR1,UE);

	/** Enable TX **/
	SET_BIT(UART1->CR1,TE);

	/** Enable RX **/
	SET_BIT(UART1->CR1,RE);
}

void MUART_UART1_vSendByte(u8 A_u8Data){
	while( !(GET_BIT(UART1->SR,TXE)) );
	UART1->DR= A_u8Data;
	while( !(GET_BIT(UART1->SR,TC)) );
	CLR_BIT(UART1->SR,TC);
}

u8 MUART_UART1_u8ReceiveByte(void){
	while( !(GET_BIT(UART1->SR,RXNE)) );
	return UART1->DR;
}
