#include "../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MEXTI_private.h"
#include"MEXTI_config.h"
#include"MEXTI_interface.h"


static void(*MEXTI_PF[16])(void)= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};



void MEXTI_voidEnableExternalInterrupt(u8 copy_u8InterruptNumber){
	SET_BIT(EXTI->IMR , copy_u8InterruptNumber);
}

void MEXTI_voidDisableExternalInterrupt(u8 copy_u8InterruptNumber){
	CLR_BIT(EXTI->IMR , copy_u8InterruptNumber);
}

void MEXTI_voidSoftwareInterrupt(u8 copy_u8InterruptNumber){
	SET_BIT(EXTI->SWIER , copy_u8InterruptNumber);
}

void MEXTI_voidTriggerSelect(u8 copy_u8Line , u8 copy_u8SelectedTrigger){
	switch(copy_u8SelectedTrigger){
		case EXTI_RISING_EDGE  : SET_BIT(EXTI->RTSR , copy_u8Line);  break;
		case EXTI_FALLING_EDGE : SET_BIT(EXTI->FTSR , copy_u8Line);  break;
		case EXTI_ANY_CHANGE   :{
			SET_BIT(EXTI->RTSR , copy_u8Line);
			SET_BIT(EXTI->FTSR , copy_u8Line);
			break;
		}
	}
}


u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void)){
	u8 local_u8Error = 0;
	if(Copy_Pf != NULL && Copy_u8EXTINum >= 15){
		local_u8Error = 1;
		MEXTI_PF[Copy_u8EXTINum] = Copy_Pf;
	}
	return local_u8Error;
}
