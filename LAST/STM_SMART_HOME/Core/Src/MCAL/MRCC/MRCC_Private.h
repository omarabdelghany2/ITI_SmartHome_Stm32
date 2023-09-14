#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_


/***	RCC Bits ***/
#define HSEON			16
#define HSERDY			17
#define HSEBYP			18
#define CSSON			19
#define HSION			0
#define HSIRDY			1
#define PLLON			24
#define PLLRDY			25

#define SW0					0
#define SW1					1
#define SWS0				2
#define SWS1				3



/*** RCC Base Address ****/
#define RCC_Base_Address	0x40023800


typedef struct {
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;

}RCC_memMap_t;

#define RCC ((volatile RCC_memMap_t *)RCC_Base_Address)

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
