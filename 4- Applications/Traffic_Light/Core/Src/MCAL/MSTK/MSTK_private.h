/*
 *   file : MSTK_private.h
 *   Date : 19/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/


#ifndef MCAL_MSTK_MSTK_PRIVATE_H_
#define MCAL_MSTK_MSTK_PRIVATE_H_


#define SYSTICK_BASE_ADDRESS	0xE000E010

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSTICK_memoryMap_t;


#define   STK             ((volatile SYSTICK_memoryMap_t*)SYSTICK_BASE_ADDRESS)

#define ENABLE                     0
#define TICKINT                    1
#define CLKSOURCE                  2
#define COUNTFLAG                 16

#define NULL                  (void*)0

#endif /* MCAL_MSTK_MSTK_PRIVATE_H_ */
