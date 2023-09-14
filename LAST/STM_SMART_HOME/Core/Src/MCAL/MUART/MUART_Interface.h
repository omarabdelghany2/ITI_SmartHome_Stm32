/*
 * MUART_Interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Ziad Ragab
 */

#ifndef SRC_MCAL_MUART_MUART_INTERFACE_H_
#define SRC_MCAL_MUART_MUART_INTERFACE_H_

void MUART_UART1_vInit(void);

void MUART_UART1_vSendByte(u8 A_u8Data);

u8 MUART_UART1_u8ReceiveByte(void);

#endif /* SRC_MCAL_MUART_MUART_INTERFACE_H_ */
