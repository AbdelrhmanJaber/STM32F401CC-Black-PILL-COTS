/*
 *   file : MNVIC_private.h
 *   Date : 13/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/


#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_

/**************Structure for NVIC Register*******************/

#define NVIC_BASEADD		0xE000E100

typedef struct myNVIC{
	u32 ISER[8] ;
	u32 RESERVED_1[24];
	u32 ICER[8];
	u32 RESERVED_2[24];
	u32 ISPR[8];
	u32 RESERVED_3[24];
	u32 ICPR[8];
	u32 RESERVED_4[24];
	u32	IABR[8];
	u32	RESERVED_5[56];
	u8	IPR[240];
	u32	RESERVED_6[644];
}NVIC_memoryMap_t;


#define NVIC				((volatile  NVIC_memoryMap_t*)(NVIC_BASEADD))

#define SCB_AIRCR           (*(volatile u32*) 0xE000ED0C)

#define VECTKEY             0x05FA0000


#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
