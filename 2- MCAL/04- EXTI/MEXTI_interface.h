/*
 *   file : MEXTI_interface.h
 *   Date : 15/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_


typedef enum{
	EXTI_LINE0 = 0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
}EXTI_Lines_t;



typedef enum{
	EXTI_PORTA = 0,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTE,
	RESERVED1,
	RESERVED2,
	EXTI_PORTH,
}EXTI_Ports_t;

void MEXTI_voidEnableInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidDisableExternalInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidSoftwareInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidTriggerSelect(EXTI_Lines_t copy_enumLine , u8 copy_u8SelectedTrigger);

u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void));

void MEXTI_voidSetEXTIConfig (EXTI_Lines_t copy_enumLine , EXTI_Ports_t copy_enumPort);

#define EXTI_RISING_EDGE               1
#define EXTI_FALLING_EDGE              2
#define EXTI_ANY_CHANGE                3






#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
