/*
 *   file : MSTK_interface.h
 *   Date : 19/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/


#ifndef MCAL_MSTK_MSTK_INTERFACE_H_
#define MCAL_MSTK_MSTK_INTERFACE_H_


void MSTK_voidInit(void);

u32 MSTK_u32GetCurrentValue(void);

u32 MSTK_u32GetElapsedTime(void);

/*without interrupt*/

void MSTK_voidDelay_ms(u32 copy_u32Delay_ms);

void MSTK_voidDelay_us(u32 copy_u32Delay_us);

/*with interrupt*/

void MSTK_voidTimeMapping(u16 copy_u8Micro , u16 copy_u8Milli , u8 copy_u8Seconds);

void MSTK_voidSetIntervalAsynch(u8 copy_u8periodicityMode , void(*Copy_Pf)(void));


#define INTERRUPT_PERIODIC        1
#define INTERRUPT_FOR_ONCE        2

#endif /* MCAL_MSTK_MSTK_INTERFACE_H_ */
