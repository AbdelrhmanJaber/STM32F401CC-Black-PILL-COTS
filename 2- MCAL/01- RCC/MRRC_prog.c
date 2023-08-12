/*
 *   file : MRRC_prog.c
 *   Date : 11/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */

/**** Library Layer ****/
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"


/***** RCC libraries *******/
#include"MRRC_private.h"
#include"MRRC_config.h"
#include"MRRC_interface.h"


void MRCC_voidInit(u8 copy_u8ClockSource){
	switch(copy_u8ClockSource){
		case MRCC_HSE:{
			/*ENABLE HSE as a clock source*/
			SET_BIT(RCC->CR , HSEON);
			while(!(GET_BIT(RCC->CR, HSERDY)));
			switch(HSE_MODE){
				case HSE_CRYSTAL :   CLR_BIT(RCC->CR , HSEBYP);   break;
				case HSE_RC :   SET_BIT(RCC->CR , HSEBYP);   break;
				}
			 /*Input System Clock*/
			 SET_BIT(RCC->CFGR , SW0);
			 CLR_BIT(RCC->CFGR , SW1);
			 while(!((GET_BIT(RCC->CFGR , SWS2) == 1)) && (GET_BIT(RCC->CFGR , SWS3) == 0 ));
			}
			break;

		case MRCC_HSI:{
			/*ENABLE HSI as a clock source*/
			SET_BIT(RCC->CR , HSION);
			while(!(GET_BIT(RCC->CR , HSIRDY)));
			/*Input System Clock*/
			CLR_BIT(RCC->CFGR , SW0);
			CLR_BIT(RCC->CFGR , SW1);
			while(!((GET_BIT(RCC->CFGR , SWS2) == 0)) && (GET_BIT(RCC->CFGR , SWS3) == 0 ));
			break;
		  }
		case MRCC_PLL:{
			switch(PLL_MODE){
				case PLL_HSI_MODE:{
					/*Enable HSI*/
					SET_BIT(RCC->CR , HSION);
					while(!(GET_BIT(RCC->CR , HSIRDY)));
					/*Enable PLL*/
					SET_BIT(RCC->CR , PLLON);
					while(!(GET_BIT(RCC->CR , PLLRDY)));
					/*CHOOSE HSI IN PLL*/
					CLR_BIT(RCC->PLLCFGR , PLLSRC);
					/*Input System Clock*/
					CLR_BIT(RCC->CFGR , SW0);
					SET_BIT(RCC->CFGR , SW1);
					while(!((GET_BIT(RCC->CFGR , SWS2) == 0)) && (GET_BIT(RCC->CFGR , SWS3) == 1 ));
					break;
				}
				case PLL_HSE_MODE:{
					/*ENABLE HSE as a clock source*/
					SET_BIT(RCC->CR , HSEON);
					while(!(GET_BIT(RCC->CR, HSERDY)));
					/*Enable PLL*/
					SET_BIT(RCC->CR , PLLON);
					while(!(GET_BIT(RCC->CR , PLLRDY)));
					/*CHOOSE HSE IN PLL*/
					SET_BIT(RCC->PLLCFGR , PLLSRC);
					/*Input System Clock*/
					CLR_BIT(RCC->CFGR , SW0);
					SET_BIT(RCC->CFGR , SW1);
					while(!((GET_BIT(RCC->CFGR , SWS2) == 0)) && (GET_BIT(RCC->CFGR , SWS3) == 1 ));
					break;
				}
			}
			break;
		 }
		}
}


void MRCC_voidSecurityOn(void){
	SET_BIT(RCC->CR , CSSON);
}

void MRCC_voidSecurityOff(void){
	CLR_BIT(RCC->CR , CSSON);
}

void MRCC_voidEnablePeripheral(u8 copy_u8BusName , u8 copy_u8Peripheral){
	switch(copy_u8BusName){
		case AHB1ENR_BUS:   SET_BIT(RCC->AHB1ENR , copy_u8Peripheral);   break;
		case AHB2ENR_BUS:   SET_BIT(RCC->AHB2ENR , copy_u8Peripheral);   break;
		case APB1ENR_BUS:   SET_BIT(RCC->APB1ENR , copy_u8Peripheral);   break;
		case APB2ENR_BUS:   SET_BIT(RCC->APB2ENR , copy_u8Peripheral);   break;
	}
}

void MRCC_voidDisablePeripheral(u8 copy_u8BusName , u8 copy_u8Peripheral){
	switch(copy_u8BusName){
		case AHB1ENR_BUS:   CLR_BIT(RCC->AHB1ENR , copy_u8Peripheral);   break;
		case AHB2ENR_BUS:   CLR_BIT(RCC->AHB2ENR , copy_u8Peripheral);   break;
		case APB1ENR_BUS:   CLR_BIT(RCC->APB1ENR , copy_u8Peripheral);   break;
		case APB2ENR_BUS:   CLR_BIT(RCC->APB2ENR , copy_u8Peripheral);   break;
	}
}


