/****** HEADER GAURD **********/
#ifndef LOGIN_SYSTEM_H_
#define LOGIN_SYSTEM_H_


#define PASS 	"1234"

/******** FUNCTION PROTOTYPES ********/
void System_Reset(void);
u8 Login_System(void);
u8 Check_Pass(u8* pass);


#endif /* LOGIN_SYSTEM_H_ */
