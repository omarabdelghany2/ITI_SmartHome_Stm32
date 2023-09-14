#ifndef HLCD_CONFIG_H
#define HLCD_CONFIG_H

//CONFIG for Control Pins
#define HLCD_u8_RS_PIN       0
#define HLCD_u8_RS_PORT		 MGPIO_PORTA

#define HLCD_u8_RW_PIN       1
#define HLCD_u8_RW_PORT		 MGPIO_PORTA

#define HLCD_u8_EN_PIN       2
#define HLCD_u8_EN_PORT		 MGPIO_PORTA

#define FunctionSet          0X38
#define DisplayControl       0x0f
#define DisplayClear         0x01
#define EntryMode            0x06
#define ReturnCGROM          0x02

/*Data Pins*/
#define HCLD_u8_DATA_PORT    MGPIO_PORTA

#define HLCD_u8DATA_PIN0	8
#define HLCD_u8DATA_PIN1	4
#define HLCD_u8DATA_PIN2	5
#define HLCD_u8DATA_PIN3	11
#define HLCD_u8DATA_PIN4	12
#define HLCD_u8DATA_PIN5	13
#define HLCD_u8DATA_PIN6	14
#define HLCD_u8DATA_PIN7	15

#endif
