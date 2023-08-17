/*
 *   file : MNVIC_interface.h
 *   Date : 13/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_

typedef enum {
	    NVIC_GroupMode_g16s0 = 3,
	    NVIC_GroupMode_g8s2,
	    NVIC_GroupMode_g4s4,
	    NVIC_GroupMode_g2s8,
	    NVIC_GroupMode_g0s16
}NVIC_Group_Mode_t;

/*************Prototype for used function in NIVC driver***********************/

void MNVIC_EnableIRQ(NVIC_IRQN IRQn);

void MNVIC_DisableIRQ(NVIC_IRQN IRQn);

void MNVIC_SetPendingIRQ(NVIC_IRQN IRQn);

void MNVIC_ClearPendingIRQ(NVIC_IRQN IRQn);

u32 MNVIC_GetPendingIRQ(NVIC_IRQN IRQn);

void MNVIC_SetDefaultPriority(NVIC_IRQN IRQn, u8 priority);

u32 MNVIC_GetPriority(NVIC_IRQN IRQn);

void MNVIC_voidInterruptGroupingInit(NVIC_Group_Mode_t copyGroupMode );

void MNVIC_voidSetGroupingInterruptPriority(u8 copy_u8InterruptNum, NVIC_Group_Mode_t copy_GropMode, u8 copy_u8Group, u8 copy_u8IntPriority);

#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
