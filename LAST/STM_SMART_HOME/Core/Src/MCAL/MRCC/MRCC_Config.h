#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_

/*** Config Options ****/
#define ENABLE			1
#define DISABLE			0


#define RCC_HSE_BYPASS 		DISABLE

#define RCC_CSS_Enable		DISABLE



/*** Clock Sources ***/
#define RCC_HSE				0
#define RCC_HSI				1
#define RCC_PLL 			2


#define RCC_SYS_CLK			RCC_HSI

#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
