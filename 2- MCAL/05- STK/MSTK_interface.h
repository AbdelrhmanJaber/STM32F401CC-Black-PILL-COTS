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



#endif /* MCAL_MSTK_MSTK_INTERFACE_H_ */
