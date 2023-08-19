#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MNVIC_private.h"
#include"MNVIC_config.h"
#include"MNVIC.interface.h"


void MNVIC_EnableIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ISER[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void MNVIC_DisableIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ICER[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void MNVIC_SetPendingIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) {
		SET_BIT(NVIC->ISPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
	}
}

void MNVIC_ClearPendingIRQ(NVIC_IRQN IRQn){
	if((u32)IRQn >= 0) SET_BIT(NVIC->ICPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

u32 MNVIC_GetPendingIRQ(NVIC_IRQN IRQn){
	return GET_BIT(NVIC->ISPR[(u32)IRQn>>5] , ((u32)IRQn & 0x1FUL));
}

void MNVIC_SetDefaultPriority(NVIC_IRQN IRQn, u8 priority){
	if(IRQn >= 0) NVIC->IPR[(u8)IRQn] = (priority << (8 - PRIORITY_RESERVED_BITS));
}

u32 MNVIC_GetPriority(NVIC_IRQN IRQn){
	return	 GET_BIT(NVIC->IABR[(((u32)IRQn)>>5)], (((u32)IRQn)&(0x1FUL)));
}

void MNVIC_voidInterruptGroupingInit(NVIC_Group_Mode_t copyGroupMode ){
	if(copyGroupMode <= NVIC_GroupMode_g0s16)     SCB_AIRCR = (VECTKEY | (copyGroupMode<<8));
}

void MNVIC_voidSetGroupingInterruptPriority(NVIC_IRQN IRQn, NVIC_Group_Mode_t copy_GropMode, u8 copy_u8GroupPriority, u8 copy_u8SubPriority){
	u8 local_u8Priority = 0;
	switch(copy_GropMode){
		case NVIC_GroupMode_g16s0 : local_u8Priority = copy_u8GroupPriority;  break;
		case NVIC_GroupMode_g8s2 :  local_u8Priority = (copy_u8GroupPriority << 1 )  | copy_u8SubPriority ;  break;
		case NVIC_GroupMode_g4s4 :  local_u8Priority = (copy_u8GroupPriority << 2 )  | copy_u8SubPriority ;   break;
		case NVIC_GroupMode_g2s8 :  local_u8Priority = (copy_u8GroupPriority << 3 )  | copy_u8SubPriority ;   break;
		case NVIC_GroupMode_g0s16:  local_u8Priority = copy_u8SubPriority;  break;
	}
	NVIC->IPR[IRQn] = local_u8Priority << (8 - PRIORITY_RESERVED_BITS) ;
}

