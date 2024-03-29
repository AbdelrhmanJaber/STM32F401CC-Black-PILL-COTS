/*
 * MUSART_prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */


#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"


#include "MUSART_config.h"
#include "MUSART_interface.h"
#include "MUSART_private.h"

/*array of pointers to function*/

void(*USART_PF[3])(void) = {NULL , NULL, NULL};

/*global variables to send data asynchronous*/

static u16 USART1_global_data_to_send;
static u16 USART2_global_data_to_send;
static u16 USART6_global_data_to_send;

/*global pointers to send string*/
static s8* USART1_globalStringTX = NULL;
static s8* USART2_globalStringTX = NULL;
static s8* USART6_globalStringTX = NULL;

/*global pointers to receive data*/
static u8* USART1_globalByteRX = NULL;
static u8* USART2_globalByteRX = NULL;
static u8* USART6_globalByteRX = NULL;

/*global pointers to receive string*/
static s8* USART1_globalReceiveRX = NULL;
static s8* USART2_globalReceiveRX = NULL;
static s8* USART6_globalReceiveRX = NULL;

/*private init function */

static void MUSART1_privateInit(void);
static void MUSART2_privateInit(void);
static void MUSART6_privateInit(void);

/*private function to send byte synch*/

static void MUSART1_privateSendByte(u8 copy_u8PrivateData);
static void MUSART2_privateSendByte(u8 copy_u8PrivateData);
static void MUSART6_privateSendByte(u8 copy_u8PrivateData);

/*private function to send string synch*/

static void MUSART1_PrivateSendStringSynch(s8* copy_Pu8StringToSend);
static void MUSART2_PrivateSendStringSynch(s8* copy_Pu8StringToSend);
static void MUSART6_PrivateSendStringSynch(s8* copy_Pu8StringToSend);


/*function help sending bytes asynchronous*/

void MUSART1_TX_Byte(void);
void MUSART2_TX_Byte(void);
void MUSART6_TX_Byte(void);

/*function help sending Strings asynchronous*/

void MUSART1_TX_String(void);
void MUSART2_TX_String(void);
void MUSART6_TX_String(void);


/*function help receiving bytes asynchronous*/
void MUSART1_RX_Byte(void);
void MUSART2_RX_Byte(void);
void MUSART6_RX_Byte(void);

/*function help Receiving Strings asynchronous*/

void MUSART1_RX_String(void);
void MUSART2_RX_String(void);
void MUSART6_RX_String(void);


/*global 2d array to set baud rate*/

u32 baud_rate[MAX_SPEED_MODES][MAX_BAUDRATES_OPTIONS] = { {B_SAMPLING_8_1200 , B_SAMPLING_8_2400
, B_SAMPLING_8_9600 , B_SAMPLING_8_19200 , B_SAMPLING_8_38400 , B_SAMPLING_8_57600 , B_SAMPLING_8_115200 } ,
		{B_SAMPLING_16_1200 , B_SAMPLING_16_2400 , B_SAMPLING_16_9600 , B_SAMPLING_16_19200
		, B_SAMPLING_16_38400 , B_SAMPLING_16_57600 , B_SAMPLING_16_115200} };


/********General Init function ********/

void MUSART_voidInit(USART_SELCTION_t copy_enumUSART){
	switch(copy_enumUSART){
	case USART_1 : MUSART1_privateInit();  break;
	case USART_2 : MUSART2_privateInit();  break;
	case USART_6 : MUSART6_privateInit();  break;
	}
}


void MUSART_voidSendByte(USART_SELCTION_t copy_enumUSART , u8 copy_u8ByteToSend){
	switch(copy_enumUSART){
	case USART_1 :  MUSART1_privateSendByte(copy_u8ByteToSend);  break;
	case USART_2 :  MUSART2_privateSendByte(copy_u8ByteToSend);  break;
	case USART_6 :  MUSART6_privateSendByte(copy_u8ByteToSend);  break;
	}
}


void MUSART1_TX_Byte(void){
	USART1->DR = USART1_global_data_to_send;
}

void MUSART1_voidSendByteAsynch(u8 copy_u8ByteToSend){
	USART1_global_data_to_send = copy_u8ByteToSend;
	MUSART_voidSetCallBack(USART_1, MUSART1_TX_Byte);
	/*Enable Interrupt*/
	SET_BIT(USART1->CR1 , TXE);
}


void MUSART2_TX_Byte(void){
	USART2->DR = USART2_global_data_to_send;
}

void MUSART2_voidSendByteAsynch(u8 copy_u8ByteToSend){
	USART2_global_data_to_send = copy_u8ByteToSend;
	MUSART_voidSetCallBack(USART_2, MUSART2_TX_Byte);
	/*Enable Interrupt*/
	SET_BIT(USART2->CR1 , TXE);
}


void MUSART6_TX_Byte(void){
	USART6->DR = USART6_global_data_to_send;
}

void MUSART6_voidSendByteAsynch(u8 copy_u8ByteToSend){
	USART6_global_data_to_send = copy_u8ByteToSend;
	MUSART_voidSetCallBack(USART_6, MUSART6_TX_Byte);
	/*Enable Interrupt*/
	SET_BIT(USART6->CR1 , TXE);
}


void MUSART_voidSendStringSynch(USART_SELCTION_t copy_enumUSART , s8* copy_Pu8StringToSend){
	switch(copy_enumUSART){
	case USART_1 :  MUSART1_PrivateSendStringSynch(copy_Pu8StringToSend);  break;
	case USART_2 :  MUSART2_PrivateSendStringSynch(copy_Pu8StringToSend);  break;
	case USART_6 :  MUSART6_PrivateSendStringSynch(copy_Pu8StringToSend);  break;
	}
}

void MUSART1_TX_String(void){
	static u8 index = 0;
		if(USART1_globalStringTX != NULL){
			if(USART1_globalStringTX[index] != '\0'){
				USART1->DR = USART1_globalStringTX[index++];
			}else{
				index = 0;
				/*clear interrupt*/
				CLR_BIT(USART1->CR1 , TXE);
			}
		}
}

void MUSART1_voidSendStringAsynch(s8* copy_Pu8StringToSend){
	if(copy_Pu8StringToSend != NULL){
		USART1_globalStringTX = copy_Pu8StringToSend;
		MUSART_voidSetCallBack(USART_1 , MUSART1_TX_String);
		SET_BIT(USART1->CR1 , TXE);
	}
}

void MUSART2_TX_String(void){
	static u8 index = 0;
		if(USART2_globalStringTX != NULL){
			if(USART2_globalStringTX[index] != '\0'){
				USART2->DR = USART2_globalStringTX[index++];
			}else{
				index = 0;
				/*clear interrupt*/
				CLR_BIT(USART2->CR1 , TXE);
			}
		}
}

void MUSART2_voidSendStringAsynch(s8* copy_Pu8StringToSend){
	if(copy_Pu8StringToSend != NULL){
		USART2_globalStringTX = copy_Pu8StringToSend;
		MUSART_voidSetCallBack(USART_2 , MUSART2_TX_String);
		SET_BIT(USART2->CR1 , TXE);
	}
}


void MUSART6_TX_String(void){
	static u8 index = 0;
		if(USART6_globalStringTX != NULL){
			if(USART6_globalStringTX[index] != '\0'){
				USART6->DR = USART6_globalStringTX[index++];
			}else{
				index = 0;
				/*clear interrupt*/
				CLR_BIT(USART6->CR1 , TXE);
			}
		}
}

void MUSART6_voidSendStringAsynch(s8* copy_Pu8StringToSend){
	if(copy_Pu8StringToSend != NULL){
		USART6_globalStringTX = copy_Pu8StringToSend;
		MUSART_voidSetCallBack(USART_6 , MUSART6_TX_String);
		SET_BIT(USART6->CR1 , TXE);
	}
}


/*****Receive Byte Synchronous******/

u8 MUSART1_u8ReceiveByte(void){
	u8 data;
	while(!(GET_BIT(USART1->SR,RXNE)));
	data =  USART1->DR;
	return data;
}

u8 MUSART2_u8ReceiveByte(void){
	u8 data;
	while(!(GET_BIT(USART2->SR,RXNE)));
	data =  USART2->DR;
	return data;
}



u8 MUSART6_u8ReceiveByte(void){
	u8 data;
	while(!(GET_BIT(USART6->SR,RXNE)));
	data =  USART6->DR;
	return data;
}


void MUSART1_RX_Byte(void){
	if(USART1_globalByteRX != NULL){
		*(USART1_globalByteRX) = USART1->DR;
	}
}

void MUSART1_voidRecieveByteAsynch(u8* data){
	if(data != NULL )  USART1_globalByteRX = data;
	MUSART_voidSetCallBack(USART_1, MUSART1_RX_Byte);
	SET_BIT(USART1->CR1 , RXNE);
}


void MUSART2_RX_Byte(void){
	if(USART2_globalByteRX != NULL){
		*(USART2_globalByteRX) = USART2->DR;
	}
}

void MUSART2_voidRecieveByteAsynch(u8* data){
	if(data != NULL )  USART2_globalByteRX = data;
	MUSART_voidSetCallBack(USART_2, MUSART2_RX_Byte);
	SET_BIT(USART2->CR1 , RXNE);
}



void MUSART6_RX_Byte(void){
	if(USART6_globalByteRX != NULL){
		*(USART6_globalByteRX) = USART6->DR;
	}
}

void MUSART6_voidRecieveByteAsynch(u8* data){
	if(data != NULL )  USART6_globalByteRX = data;
	MUSART_voidSetCallBack(USART_6, MUSART6_RX_Byte);
	SET_BIT(USART6->CR1 , RXNE);
}


u8 MUSART1_Pu8RecieveStringSynch(s8* word){
	u8 local_returnError = 0;
	u8 index=0;
	word[index] = MUSART1_u8ReceiveByte();
	while(word[index] != NEXT_LINE){
		word[++index] = MUSART1_u8ReceiveByte();
		local_returnError = 1;
	}
	word[index] = '\0';
	return local_returnError;
}

u8 MUSART2_Pu8RecieveStringSynch(s8* word){
	u8 local_returnError = 0;
	u8 index=0;
	word[index] = MUSART2_u8ReceiveByte();
	while(word[index] != NEXT_LINE){
		word[++index] = MUSART2_u8ReceiveByte();
		local_returnError = 1;
	}
	word[index] = '\0';
	return local_returnError;
}


u8 MUSART6_Pu8RecieveStringSynch(s8* word){
	u8 local_returnError = 0;
	u8 index=0;
	word[index] = MUSART6_u8ReceiveByte();
	while(word[index] != NEXT_LINE){
		word[++index] = MUSART6_u8ReceiveByte();
		local_returnError = 1;
	}
	word[index] = '\0';
	return local_returnError;
}


void MUSART1_RX_String(void){
	static u8 index = 0;
	u8 temp = USART1->DR;
	if(temp != NEXT_LINE){
		USART1_globalReceiveRX[index] = temp;
		index++;
	}else{
		USART1_globalReceiveRX[index] = '\0';
		index = 0;
		CLR_BIT(USART1->CR1 , RXNE);
	}
}

void MUSART1_voidRecieveStringAsynch(s8* copy_Pu8StringToRecieve){
	if(copy_Pu8StringToRecieve != NULL){
		USART1_globalReceiveRX = copy_Pu8StringToRecieve;
		MUSART_voidSetCallBack(USART_1 ,MUSART1_RX_String );
		SET_BIT(USART1->CR1 , RXNE);
	}
}


void MUSART2_RX_String(void){
	static u8 index = 0;
	u8 temp = USART2->DR;
	if(temp != NEXT_LINE){
		USART2_globalReceiveRX[index] = temp;
		index++;
	}else{
		USART2_globalReceiveRX[index] = '\0';
		index = 0;
		CLR_BIT(USART2->CR1 , RXNE);
	}
}

void MUSART2_voidRecieveStringAsynch(s8* copy_Pu8StringToRecieve){
	if(copy_Pu8StringToRecieve != NULL){
		USART2_globalReceiveRX = copy_Pu8StringToRecieve;
		MUSART_voidSetCallBack(USART_2 ,MUSART1_RX_String );
		SET_BIT(USART2->CR1 , RXNE);
	}
}



void MUSART6_RX_String(void){
	static u8 index = 0;
	u8 temp = USART6->DR;
	if(temp != NEXT_LINE){
		USART6_globalReceiveRX[index] = temp;
		index++;
	}else{
		USART6_globalReceiveRX[index] = '\0';
		index = 0;
		CLR_BIT(USART6->CR1 , RXNE);
	}
}

void MUSART6_voidRecieveStringAsynch(s8* copy_Pu8StringToRecieve){
	if(copy_Pu8StringToRecieve != NULL){
		USART6_globalReceiveRX = copy_Pu8StringToRecieve;
		MUSART_voidSetCallBack(USART_6 ,MUSART1_RX_String );
		SET_BIT(USART6->CR1 , RXNE);
	}
}


void MUSART_voidSetCallBack(USART_SELCTION_t copy_enumUSART , void(*Copy_Pf)(void)){
	if(Copy_Pf != NULL){
		USART_PF[copy_enumUSART] = Copy_Pf;
	}
}




static void MUSART1_privateInit(void){
	/*WORD LENGHT*/
#if (USART1_BITS_NUMBER == USART1_EIGHT_BITS)
	CLR_BIT(USART1->CR1 , M);
#elif(USART1_BITS_NUMBER == USART1_NINE_BITS)
	SET_BIT(USART1->CR1 , M);
#endif
	/*ONE STOP BIT*/
	USART1->CR2 |= USART1_STOP_BIT ;

	/*parity control enable*/
#if(USART1_PARITY_CONTROL_ENABLE == USART1_PARITY_ENABLE)
	SET_BIT(USART1->CR1 , PCE);
#elif(USART1_PARITY_CONTROL_ENABLE == USART1_PARITY_DISABLE)
	CLR_BIT(USART1->CR1 , PCE);
#endif
	/*parity Selection even or odd*/
#if(USART1_PARITY_SELCTION == USART1_EVEN_PARITY)
	CLR_BIT(USART1->CR1 , PS);
#elif(USART1_PARITY_SELCTION == USART1_ODD_PARITY)
	SET_BIT(USART1->CR1 , PS);
#endif
	/*sampling 16 or 8*/
#if(USART1_OVER_SAMPLING == USART1_SAMPLING_16)
	CLR_BIT(USART1->CR1 , OVER8);
#elif(USART1_OVER_SAMPLING == USART1_SAMPLING_8)
	SET_BIT(USART1->CR1 , OVER8);
#endif
	/*SET BAUDRATE*/

	 USART1->BRR =  baud_rate[USART1_CLOCK_SPEED][USART1_BAUDRATE];

	 /*ENABLE USART*/
	 SET_BIT(USART1->CR1 , UE);
	 /*Enable Transmitter*/
	 SET_BIT(USART1->CR1 , TE);
	/*Enable Reciever*/
	 SET_BIT(USART1->CR1 , RE);
}



static void MUSART2_privateInit(void){
	/*WORD LENGHT*/
#if (USART2_BITS_NUMBER == USART2_EIGHT_BITS)
	CLR_BIT(USART2->CR1 , M);
#elif(USART2_BITS_NUMBER == USART2_NINE_BITS)
	SET_BIT(USART2->CR1 , M);
#endif
	/*ONE STOP BIT*/
	USART2->CR2 |= USART2_STOP_BIT ;

	/*parity control enable*/
#if(USART2_PARITY_CONTROL_ENABLE == USART2_PARITY_ENABLE)
	SET_BIT(USART2->CR1 , PCE);
#elif(USART2_PARITY_CONTROL_ENABLE == USART2_PARITY_DISABLE)
	CLR_BIT(USART2->CR1 , PCE);
#endif
	/*parity Selection even or odd*/
#if(USART2_PARITY_SELCTION == USART2_EVEN_PARITY)
	CLR_BIT(USART2->CR1 , PS);
#elif(USART2_PARITY_SELCTION == USART2_ODD_PARITY)
	SET_BIT(USART2->CR1 , PS);
#endif
	/*sampling 16 or 8*/
#if(USART2_OVER_SAMPLING == USART2_SAMPLING_16)
	CLR_BIT(USART2->CR1 , OVER8);
#elif(USART2_OVER_SAMPLING == USART2_SAMPLING_8)
	SET_BIT(USART2->CR1 , OVER8);
#endif
	/*SET BAUDRATE*/

	 USART2->BRR =  baud_rate[USART2_CLOCK_SPEED][USART2_BAUDRATE];

	 /*ENABLE USART*/
	 SET_BIT(USART2->CR1 , UE);
	 /*Enable Transmitter*/
	 SET_BIT(USART2->CR1 , TE);
	/*Enable Reciever*/
	 SET_BIT(USART2->CR1 , RE);
}



static void MUSART6_privateInit(void){
	/*WORD LENGHT*/
#if (USART6_BITS_NUMBER == USART6_EIGHT_BITS)
	CLR_BIT(USART6->CR1 , M);
#elif(USART6_BITS_NUMBER == USART6_NINE_BITS)
	SET_BIT(USART6->CR1 , M);
#endif
	/*ONE STOP BIT*/
	USART6->CR2 |= USART6_STOP_BIT ;

	/*parity control enable*/
#if(USART6_PARITY_CONTROL_ENABLE == USART6_PARITY_ENABLE)
	SET_BIT(USART6->CR1 , PCE);
#elif(USART6_PARITY_CONTROL_ENABLE == USART6_PARITY_DISABLE)
	CLR_BIT(USART6->CR1 , PCE);
#endif
	/*parity Selection even or odd*/
#if(USART6_PARITY_SELCTION == USART6_EVEN_PARITY)
	CLR_BIT(USART6->CR1 , PS);
#elif(USART6_PARITY_SELCTION == USART6_ODD_PARITY)
	SET_BIT(USART6->CR1 , PS);
#endif
	/*sampling 16 or 8*/
#if(USART6_OVER_SAMPLING == USART6_SAMPLING_16)
	CLR_BIT(USART6->CR1 , OVER8);
#elif(USART6_OVER_SAMPLING == USART6_SAMPLING_8)
	SET_BIT(USART6->CR1 , OVER8);
#endif
	/*SET BAUDRATE*/

	 USART6->BRR =  baud_rate[USART6_CLOCK_SPEED][USART6_BAUDRATE];

	 /*ENABLE USART*/
	 SET_BIT(USART6->CR1 , UE);
	 /*Enable Transmitter*/
	 SET_BIT(USART6->CR1 , TE);
	/*Enable Reciever*/
	 SET_BIT(USART6->CR1 , RE);
}




static void MUSART1_privateSendByte(u8 copy_u8PrivateData){
	while( !(GET_BIT(USART1->SR,TXE)) );
	USART1->DR= copy_u8PrivateData;
	while( !(GET_BIT(USART1->SR,TC)) );
	CLR_BIT(USART1->SR,TC);
}

static void MUSART2_privateSendByte(u8 copy_u8PrivateData){
	while( !(GET_BIT(USART2->SR,TXE)) );
	USART2->DR= copy_u8PrivateData;
	while( !(GET_BIT(USART2->SR,TC)) );
	CLR_BIT(USART2->SR,TC);
}

static void MUSART6_privateSendByte(u8 copy_u8PrivateData){
	while( !(GET_BIT(USART6->SR,TXE)) );
	USART6->DR= copy_u8PrivateData;
	while( !(GET_BIT(USART6->SR,TC)) );
	CLR_BIT(USART6->SR,TC);
}



static void MUSART1_PrivateSendStringSynch(s8* copy_Pu8StringToSend){
	u8 index = 0;
	while(copy_Pu8StringToSend[index] != '\0'){
		MUSART_voidSendByte(USART_1 , copy_Pu8StringToSend[index++]);
	}
}

static void MUSART2_PrivateSendStringSynch(s8* copy_Pu8StringToSend){
	u8 index = 0;
	while(copy_Pu8StringToSend[index] != '\0'){
		MUSART_voidSendByte(USART_2 , copy_Pu8StringToSend[index++]);
	}
}

static void MUSART6_PrivateSendStringSynch(s8* copy_Pu8StringToSend){
	u8 index = 0;
	while(copy_Pu8StringToSend[index] != '\0'){
		MUSART_voidSendByte(USART_6 , copy_Pu8StringToSend[index++]);
	}
}



void USART1_IRQHandler(void){
	if(USART_PF[USART_1] != NULL){
		USART_PF[USART_1]();
		/*clear status register*/
		USART1->SR = 0x0000;
	}
}



void USART2_IRQHandler(void){
	if(USART_PF[USART_2] != NULL){
		USART_PF[USART_2]();
		/*clear status register*/
		USART2->SR = 0x0000;
	}
}


void USART6_IRQHandler(void){
	if(USART_PF[USART_6] != NULL){
		USART_PF[USART_6]();
		/*clear status register*/
		USART6->SR = 0x0000;
	}
}
