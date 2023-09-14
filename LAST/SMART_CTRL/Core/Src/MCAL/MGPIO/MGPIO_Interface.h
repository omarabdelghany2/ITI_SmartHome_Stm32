#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_

#define MGPIO_MODE_INPUT			0
#define MGPIO_MODE_OUTPUT			1
#define MGPIO_MODE_ALTFUN			2
#define MGPIO_MODE_ANALOG			3

#define MGPIO_PORTA					0
#define MGPIO_PORTB					1
#define MGPIO_PORTC					2


#define MGPIO_PUSHPULL				0
#define MGPIO_OPENDRAIN				1

#define MGPIO_LOWSPEED				0
#define MGPIO_MEDSPEED				1
#define MGPIO_HIGHSPEED				2
#define MGPIO_VERYHIGHSPEED			3

#define MGPIO_NOPULL				0
#define MGPIO_PULLUP				1
#define MGPIO_PULLDOWN				2

#define MGPIO_LOW					0
#define MGPIO_HIGH					1


void MGPIO_vSetPinMode(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Mode);

void MGPIO_vSetPinOutPutType(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8OutPutType);

void MGPIO_vSetOutputSpeed(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8OutPutType);

void MGPIO_vSetPinInputPull(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8PullType);

u8 MGPIO_vGetPinVal(u8 A_u8PortId , u8 A_u8PinNo);

void MGPIO_vSetPinVal(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Value);

void MGPIO_vSetPinVal_fast(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8Value); /*Using BSRR */

void MGPIO_vSetAlternativeFunc(u8 A_u8PortId , u8 A_u8PinNo , u8 A_u8AltFun);

#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
