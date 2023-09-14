/*
 * MUART_Config.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Ziad Ragab
 */

#ifndef SRC_MCAL_MUART_MUART_CONFIG_H_
#define SRC_MCAL_MUART_MUART_CONFIG_H_


/*** Choose number of data bits ( 8/ 9 ) ****/
#define WORD_Length 		8


/*** Choose Number of Stop bits ( 1 / 2 ) ****/
#define STOP_BITS 			1

/*** Choose Baud rate ****/
#define BAUD_RATE			9600

/** System Clock frequency in MHZ **/
#define SYS_CLK				16

#endif /* SRC_MCAL_MUART_MUART_CONFIG_H_ */
