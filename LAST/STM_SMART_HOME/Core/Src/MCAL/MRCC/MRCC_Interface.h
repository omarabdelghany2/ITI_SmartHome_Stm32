#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_

/*** BUSES to use in Enable/ Disable Functions ***/
#define		MRCC_AHB1		1
#define		MRCC_APB1		2
#define		MRCC_APB2		3

/**** 	Peripherals List for each bus to use to CLock (EN/DIS)	***/
/**********     	Numbers in Macros map to Bits		    ******/

/********** 		AHB1 Options		******/
#define GPIOAEN_DIS			0
#define GPIOBEN_DIS			1
#define GPIOCEN_DIS			2
#define CRCEN_DIS			12
#define	DMA1EN_DIS			21
#define DMA2EN_DIS			22

/********** 		APB1 Options		******/
#define TIM2EN_DIS			0
#define TIM3EN_DIS			1
#define TIM4EN_DIS			2
#define TIM5EN_DIS			3
#define WWDGEN_DIS			11
#define SPI2EN_DIS			14
#define SPI3EN_DIS			15
#define USART2EN_DIS		17
#define I2C1EN_DIS			21
#define I2C2EN_DIS			22
#define I2C3EN_DIS			23
#define PWREN_DIS			28

/********** 		APB2 Options		******/
#define TIM1EN_DIS			0
#define USART1EN_DIS		4
#define USART6EN_DIS		5
#define ADC1EN_DIS			8
#define SDIOEN_DIS			11
#define SPI1EN_DIS			12
#define SPI4EN_DIS			13
#define SYSCFGEN_DIS		14
#define TIM9EN_DIS			16
#define TIM10EN_DIS			17
#define TIM11EN_DIS			18




/********** 		Functions Prototypes		******/
void MRCC_vInit(void);

void MRCC_vEnableClock(u8 A_u8BUS , u8 A_u8Peripheral);

void MRCC_vDisableClock(u8 A_u8BUS , u8 A_u8Peripheral);


#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
