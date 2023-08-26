/*
 * MUSART_prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */


#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"


#include"../MGPIO/MGPIO_interface.h"
#include "MUSART_config.h"
#include "MUSART_interface.h"
#include "MUSART_private.h"

void(*USART_PF[3])(void) = {NULL , NULL, NULL};


static void MUSART1_privateInit(void);
static void MUSART2_privateInit(void);
static void MUSART6_privateInit(void);


u32 bauad_rate[MAX_SPEED_MODES][MAX_BAUDRATES_OPTIONS] = { {B_SAMPLING_8_1200 , B_SAMPLING_8_2400
, B_SAMPLING_8_9600 , B_SAMPLING_8_19200 , B_SAMPLING_8_38400 , B_SAMPLING_8_57600 , B_SAMPLING_8_115200 } ,
		{B_SAMPLING_16_1200 , B_SAMPLING_16_2400 , B_SAMPLING_16_9600 , B_SAMPLING_16_19200
		, B_SAMPLING_16_38400 , B_SAMPLING_16_57600 , B_SAMPLING_16_115200} };



void MUSART_voidInit(USART_SELCTION_t copy_enumUSART){
	switch(copy_enumUSART){
	case USART_1 : MUSART1_privateInit();  break;
	case USART_2 : MUSART2_privateInit();  break;
	case USART_6 : MUSART6_privateInit();  break;
	}
}


void MUSART_voidSendByte(u8 copy_u8ByteToSend){
	   while( !(GET_BIT(USART1->SR,TXE)) );
		USART1->DR= copy_u8ByteToSend;
		while( !(GET_BIT(USART1->SR,TC)) );
		CLR_BIT(USART1->SR,TC);
}

u8 MUSART_u8ReceiveByte(void){
	u8 data;
	while(!(GET_BIT(USART1->SR,RXNE)));
	data =  USART1->DR;
	return data;
}

void MUSART_voidSendStringSynch(s8* copy_Pu8StringToSend){
	u8 index = 0;
	while(copy_Pu8StringToSend[index] != '\0'){
		MUSART_voidSendByte(copy_Pu8StringToSend[index++]);
	}
}


u8 MUSART_Pu8RecieveStringSynch(s8* word){
	u8 local_returnError = 0;
	u8 index=0;
	word[index] = MUSART_u8ReceiveByte();
	while(word[index] != NEXT_LINE){
		word[++index] = MUSART_u8ReceiveByte();
		local_returnError = 1;
	}
	word[index] = '\0';
	return local_returnError;
}


void MUSART_voidSetCallBack(void(*Copy_Pf)(void)){
	if(Copy_Pf != NULL){
		USART_PF = Copy_Pf;
	}
}

void USART1_IRQHandler(void){
	if(USART_PF != NULL){
		USART_PF();
		USART1->SR = 0x0000;
	}
}



static void MUSART1_privateInit(void){
	/*WORD LENGHT*/
	CLR_BIT(USART1->CR1 , 12);

	/*ONE STOP BIT*/
	CLR_BIT(USART1->CR2 , 13);
	CLR_BIT(USART1->CR2 , 12);

	/*parity selection*/


	/*parity type*/

	/*sampling*/


	/*SET BAUDRATE*/
	 /*Baudrate -> 9600 */
	 USART1->BRR = 0x683;

	/*ENABLE USART*/
	SET_BIT(USART1->CR1 , UE);
	 /*Enable Transmitter*/
	 SET_BIT(USART1->CR1 , TE);
	/*Enable Reciever*/
	 SET_BIT(USART1->CR1 , RE);
}



static void MUSART2_privateInit(void){

}



static void MUSART6_privateInit(void){

}
