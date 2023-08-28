/*
 * MDMA_config.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdelrahman Ibrahim
 */

#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MDMA_private.h"
#include"MDMA_config.h"
#include"MDMA_interface.h"


void MDMA_voidStreamInit(u8 copy_u8DMAID , u8 copy_u8StreamID){
	switch(copy_u8DMAID){
	case DMA_1:{
			/*Disable CNF EN bit*/
			DMA1->STREAMID[copy_u8StreamID].CR &= (1U<<0);
			while(DMA1->STREAMID[copy_u8StreamID].CR == 1U);

			/*set priority software priority stream*/
			/*set very high priority*/
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<16) | (1U<<17) ;
			/*set DIR mode*/
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<7);
			DMA1->STREAMID[copy_u8StreamID].CR &=  (1U<<6);
			/*SET SIZE Bit source and destination*/
			/*set Half word 16 bit*/
			DMA1->STREAMID[copy_u8StreamID].CR &=  (1U<<12);
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<11);
			/*Disable Direct mode to use fifo*/
			DMA1->STREAMID[copy_u8StreamID].FCR |=  (1U<<2);
			/*set fifo threshold*/
			DMA1->STREAMID[copy_u8StreamID].FCR |=  (1U<<0);
			DMA1->STREAMID[copy_u8StreamID].FCR |=  (1U<<1);
			/*SRC & DIST INC*/
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<9);
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<10);
			/*Enable to interrupt*/
			DMA1->STREAMID[copy_u8StreamID].CR |=  (1U<<4);
		break;
	}
	case DMA_2:{
		/*Disable CNF EN bit*/
		DMA2->STREAMID[copy_u8StreamID].CR &= (1U<<0);
		while(DMA1->STREAMID[copy_u8StreamID].CR == 1U);

		/*set priority software priority stream*/
		/*set very high priority*/
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<16) | (1U<<17) ;
		/*set DIR mode*/
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<7);
		DMA2->STREAMID[copy_u8StreamID].CR &=  (1U<<6);
		/*SET SIZE Bit source and destination*/
		/*set Half word 16 bit*/
		DMA2->STREAMID[copy_u8StreamID].CR &=  (1U<<12);
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<11);
		/*Disable Direct mode to use fifo*/
		DMA2->STREAMID[copy_u8StreamID].FCR |=  (1U<<2);
		/*set fifo threshold*/
		DMA2->STREAMID[copy_u8StreamID].FCR |=  (1U<<0);
		DMA2->STREAMID[copy_u8StreamID].FCR |=  (1U<<1);
		/*SRC & DIST INC*/
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<9);
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<10);
		/*Enable to interrupt*/
		DMA2->STREAMID[copy_u8StreamID].CR |=  (1U<<4);
		break;
	}
	}

}

