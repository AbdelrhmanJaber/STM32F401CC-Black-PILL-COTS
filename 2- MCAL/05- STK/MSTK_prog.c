/*
 *   file : MSTK_prog.c
 *   Date : 19/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */

#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MSTK_private.h"
#include"MSTK_config.h"
#include"MSTK_interface.h"
#include"../MGPIO/MGPIO_interface.h"

static void(*MSTK_PF)(void) = NULL;
static u32 globalLoadValue ;
static u8 global_u8periodicityMode;

void MSTK_voidInit(void){
#if CLK_SOURCE_CONFIG == PROCCESOR_CLK_AHB
	SET_BIT(STK->CTRL , CLKSOURCE);
#elif CLK_SOURCE_CONFIG == AHB_8
	CLR_BIT(STK->CTRL , CLKSOURCE);
#endif
}


u32 MSTK_u32GetCurrentValue(void){
	u32 local_u32CurrentValue;
	local_u32CurrentValue = STK->VAL;
	return local_u32CurrentValue;
}



u32 MSTK_u32GetElapsedTime(void){
	u32 local_u32ElapsedTime;
	local_u32ElapsedTime = STK->LOAD - STK->VAL;
	return local_u32ElapsedTime;
}


void MSTK_voidDelay_ms(u32 copy_u32Delay_ms){
	/*load value*/
#if(CLK_SOURCE_CONFIG == PROCCESOR_CLK_AHB)
#if(CLK_RCC_SOURCE == HSE)
	STK->LOAD = 25000UL * copy_u32Delay_ms;
#elif(CLK_RCC_SOURCE == HSI)
	STK->LOAD = 16000UL * copy_u32Delay_ms;
#endif
#elif(CLK_SOURCE_CONFIG == AHB_8)
#if(CLK_RCC_SOURCE == HSE)
	STK->LOAD = 3125UL * copy_u32Delay_ms;
#elif(CLK_RCC_SOURCE ==HSI)
	STK->LOAD = 2000UL * copy_u32Delay_ms;
#endif
#endif
	/*enable the timer*/
	SET_BIT(STK->CTRL , ENABLE);
	/*wait for the flag*/
	while(!(GET_BIT(STK->CTRL , COUNTFLAG)));
	/*reset the timer*/
	STK->LOAD = 0;
	STK->VAL = 0;
	CLR_BIT(STK->CTRL , ENABLE);
}


void MSTK_voidDelay_us(u32 copy_u32Delay_us){
	/*load value*/
#if(CLK_SOURCE_CONFIG == PROCCESOR_CLK_AHB)
#if(CLK_RCC_SOURCE == HSE)
	STK->LOAD = 25UL * copy_u32Delay_us;
#elif(CLK_RCC_SOURCE == HSI)
	STK->LOAD = 16UL * copy_u32Delay_us;
#endif
#elif(CLK_SOURCE_CONFIG == AHB_8)
#if(CLK_RCC_SOURCE == HSE)
	STK->LOAD = 3UL * copy_u32Delay_us;
#elif(CLK_RCC_SOURCE ==HSI)
	STK->LOAD = 2UL * copy_u32Delay_us;
#endif
#endif
	/*enable the timer*/
	SET_BIT(STK->CTRL , ENABLE);
	/*wait for the flag*/
	while(!(GET_BIT(STK->CTRL , COUNTFLAG)));
	/*reset the timer*/
	STK->LOAD = 0;
	STK->VAL = 0;
	CLR_BIT(STK->CTRL , ENABLE);
}



void MSTK_voidTimeMapping(u16 copy_u8Micro , u16 copy_u8Milli , u8 copy_u8Seconds){
	u32 local_u8MilliTicks;

 local_u8MilliTicks = copy_u8Milli + (copy_u8Seconds*1000) + (copy_u8Micro/1000);

#if(CLK_SOURCE_CONFIG == PROCCESOR_CLK_AHB)
#if(CLK_RCC_SOURCE == HSE)
	globalLoadValue = 25000UL * local_u8MilliTicks;
#elif(CLK_RCC_SOURCE == HSI)
	globalLoadValue = 16000UL * local_u8MilliTicks;
#endif
#elif(CLK_SOURCE_CONFIG == AHB_8)
#if(CLK_RCC_SOURCE == HSE)
	globalLoadValue = 3125UL * local_u8MilliTicks;
#elif(CLK_RCC_SOURCE ==HSI)
	globalLoadValue = 2000UL * local_u8MilliTicks;
#endif
#endif

}

void MSTK_voidSetIntervalAsynch(u8 copy_u8periodicityMode , void(*Copy_Pf)(void)){
	/*load value*/
	STK->LOAD = 1000000UL;
	/*set periodic mode*/
	global_u8periodicityMode = copy_u8periodicityMode;
	/*copy function address*/
	MSTK_PF = Copy_Pf;
	/*enable interrupt*/
	SET_BIT(STK->CTRL , TICKINT);
	/*enable timer*/
	SET_BIT(STK->CTRL , ENABLE);
}



void SysTick_Handler(void){
	/*call the function*/
	MSTK_PF();
	/*check if one interval*/
	if(global_u8periodicityMode == INTERRUPT_FOR_ONCE) {
		/*reset the timer*/
		STK->LOAD = 0;
		STK->VAL = 0;
		CLR_BIT(STK->CTRL , ENABLE);
		CLR_BIT(STK->CTRL , TICKINT);
	}
	volatile u8 local_u8ClearFlag  = GET_BIT(STK->CTRL , COUNTFLAG);
}
