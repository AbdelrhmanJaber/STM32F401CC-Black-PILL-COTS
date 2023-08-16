#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MNVIC_private.h"
#include"MNVIC_config.h"
#include"MNVIC.interface.h"


void NVIC_EnableIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ISER[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void NVIC_DisableIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ICER[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void NVIC_SetPendingIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ISPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void NVIC_ClearPendingIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ICPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

u32 NVIC_GetPendingIRQ(NVIC_IRQN IRQn){
	return GET_BIT(NVIC->ISPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void NVIC_SetPriority(NVIC_IRQN IRQn, u32 priority){
	if(IRQn >= 0) NVIC->IPR[(u8)IRQn] = (priority << PRIORITY_RESERVED_BITS);
}

u32 NVIC_GetPriority(NVIC_IRQN IRQn){
	return	 GET_BIT(NVIC->IABR[(((u32)IRQn)>>5)], (((u32)IRQn)&(0x1FUL)));
}
