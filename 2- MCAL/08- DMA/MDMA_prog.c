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
			/*set priority*/

			/*set DIR mode*/

			/*SET SIZE Bit source and destination*/

			/*Disable Direct mode to use fifo*/

			/*set fifo threshold*/

			/*SRC & DIST INC*/

			/*Enable to interrupt*/
		}
		break;
	}
	case DMA_2:{

		break;
	}
}
}
