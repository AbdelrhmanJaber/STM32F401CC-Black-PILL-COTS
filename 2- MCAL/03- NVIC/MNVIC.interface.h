/*
 *   file : MNVIC_interface.h
 *   Date : 13/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_

/*************Prototype for used function in NIVC driver***********************/

void NVIC_EnableIRQ(NVIC_IRQN IRQn);

void NVIC_DisableIRQ(NVIC_IRQN IRQn);

void NVIC_SetPendingIRQ(NVIC_IRQN IRQn);

void NVIC_ClearPendingIRQ(NVIC_IRQN IRQn);

u32 NVIC_GetPendingIRQ(NVIC_IRQN IRQn);

void NVIC_SetPriority(NVIC_IRQN IRQn, u32 priority);

u32 NVIC_GetPriority(NVIC_IRQN IRQn);


#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
