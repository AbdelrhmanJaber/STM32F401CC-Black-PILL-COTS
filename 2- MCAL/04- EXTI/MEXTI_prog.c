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

void MEXTI_voidTriggerSelect(EXTI_Lines_t copy_enumLine , u8 copy_u8SelectedTrigger){
	switch(copy_u8SelectedTrigger){
		case EXTI_RISING_EDGE  : SET_BIT(EXTI->RTSR , copy_enumLine);  break;
		case EXTI_FALLING_EDGE : SET_BIT(EXTI->FTSR , copy_enumLine);  break;
		case EXTI_ANY_CHANGE   :{
			SET_BIT(EXTI->RTSR , copy_enumLine);
			SET_BIT(EXTI->FTSR , copy_enumLine);
			break;
		}
	}
}

void MEXTI_voidSetEXTIConfig (EXTI_Lines_t copy_enumLine , EXTI_Ports_t copy_enumPort){
	switch (copy_enumLine){
		case EXTI_LINE0  : SYSCFG->EXTICR1 &= ~(CONFIG_MASKING)     ; SYSCFG->EXTICR1 |= (copy_enumPort)     ; break;
		case EXTI_LINE1  : SYSCFG->EXTICR1 &= ~(CONFIG_MASKING<<4)  ; SYSCFG->EXTICR1 |= (copy_enumPort<<4)  ; break;
		case EXTI_LINE2  : SYSCFG->EXTICR1 &= ~(CONFIG_MASKING<<8)  ; SYSCFG->EXTICR1 |= (copy_enumPort<<8)  ; break;
		case EXTI_LINE3  : SYSCFG->EXTICR1 &= ~(CONFIG_MASKING<<12) ; SYSCFG->EXTICR1 |= (copy_enumPort<<12) ; break;
		case EXTI_LINE4  : SYSCFG->EXTICR2 &= ~(CONFIG_MASKING)     ; SYSCFG->EXTICR2 |= (copy_enumPort)     ; break;
		case EXTI_LINE5  : SYSCFG->EXTICR2 &= ~(CONFIG_MASKING<<4)  ; SYSCFG->EXTICR2 |= (copy_enumPort<<4)  ; break;
		case EXTI_LINE6  : SYSCFG->EXTICR2 &= ~(CONFIG_MASKING<<8)  ; SYSCFG->EXTICR2 |= (copy_enumPort<<8)  ; break;
		case EXTI_LINE7  : SYSCFG->EXTICR2 &= ~(CONFIG_MASKING<<12) ; SYSCFG->EXTICR2 |= (copy_enumPort<<12) ; break;
		case EXTI_LINE8  : SYSCFG->EXTICR3 &= ~(CONFIG_MASKING)     ; SYSCFG->EXTICR3 |= (copy_enumPort)     ; break;
		case EXTI_LINE9  : SYSCFG->EXTICR3 &= ~(CONFIG_MASKING<<4)  ; SYSCFG->EXTICR3 |= (copy_enumPort<<4)  ; break;
		case EXTI_LINE10 : SYSCFG->EXTICR3 &= ~(CONFIG_MASKING<<8)  ; SYSCFG->EXTICR3 |= (copy_enumPort<<8)  ; break;
		case EXTI_LINE11 : SYSCFG->EXTICR3 &= ~(CONFIG_MASKING<<12) ; SYSCFG->EXTICR3 |= (copy_enumPort<<12) ; break;
		case EXTI_LINE12 : SYSCFG->EXTICR4 &= ~(CONFIG_MASKING)     ; SYSCFG->EXTICR4 |= (copy_enumPort)     ; break;
		case EXTI_LINE13 : SYSCFG->EXTICR4 &= ~(CONFIG_MASKING<<4)  ; SYSCFG->EXTICR4 |= (copy_enumPort<<4)  ; break;
		case EXTI_LINE14 : SYSCFG->EXTICR4 &= ~(CONFIG_MASKING<<8)  ; SYSCFG->EXTICR4 |= (copy_enumPort<<8)  ; break;
		case EXTI_LINE15 : SYSCFG->EXTICR4 &= ~(CONFIG_MASKING<<12) ; SYSCFG->EXTICR4 |= (copy_enumPort<<12) ; break;
		}
}


u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void)){
	u8 local_u8Error = 0;
	if(Copy_Pf != NULL && Copy_u8EXTINum <= 15){
		local_u8Error = 1;
		MEXTI_PF[Copy_u8EXTINum] = Copy_Pf;
	}
	return local_u8Error;
}


EXTI0_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE0] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE0]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE0);
	}
}


EXTI1_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE1] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE1]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE1);
	}
}


EXTI2_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE2] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE2]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE2);
	}
}


EXTI3_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE3] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE3]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE3);
	}
}


EXTI4_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE4] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE4]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE4);
	}
}


EXTI5_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE5] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE5]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE5);
	}
}


EXTI6_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE6] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE6]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE6);
	}
}


EXTI7_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE7] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE7]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE7);
	}
}


EXTI8_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE8] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE8]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE8);
	}
}


EXTI9_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE9] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE9]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE9);
	}
}


EXTI10_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE10] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE10]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE10);
	}
}


EXTI11_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE11] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE11]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE11);
	}
}


EXTI12_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE12] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE12]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE12);
	}
}


EXTI13_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE13] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE13]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE13);
	}
}


EXTI14_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE14] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE14]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE14);
	}
}


EXTI15_IRQHandler(void){
	if(MEXTI_PF[EXTI_LINE15] != NULL){
		/*excute the function*/
		MEXTI_PF[EXTI_LINE15]();
		/*clear the flag*/
		SET_BIT(EXTI->PR , EXTI_LINE15);
	}
}

