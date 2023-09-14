#ifndef HKPD_CONFIG_H
#define HKPD_CONFIG_H
/* Rows */
#define HKPD_u8_R0_PIN       12
#define HKPD_u8_R0_PORT      MGPIO_PORTB

#define HKPD_u8_R1_PIN       13
#define HKPD_u8_R1_PORT      MGPIO_PORTB

#define HKPD_u8_R2_PIN       14
#define HKPD_u8_R2_PORT      MGPIO_PORTB

#define HKPD_u8_R3_PIN       15
#define HKPD_u8_R3_PORT      MGPIO_PORTB

/* Columns */
#define HKPD_u8_C0_PIN       0
#define HKPD_u8_C0_PORT      MGPIO_PORTB

#define HKPD_u8_C1_PIN       1
#define HKPD_u8_C1_PORT      MGPIO_PORTB

#define HKPD_u8_C2_PIN       2
#define HKPD_u8_C2_PORT      MGPIO_PORTB

#define HKPD_u8_C3_PIN       3
#define HKPD_u8_C3_PORT      MGPIO_PORTB

#define HKPD_KEYS            {{'7','8','9','/'}, \
		                     {'4','5','6','*'},  \
		                     {'1','2','3','-'},  \
		                     {'C','0','=','+'} }

#endif
