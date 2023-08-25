/*
 * MUART_prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */


#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"


#include"MUART_private.h"
#include"MUART_config.h"
#include"MUART_interface.h"

#include"../MGPIO/MGPIO_interface.h"

void(*UART_PF)(void) = NULL;


void MUART_voidInit(void){

	/*WORD LENGHT*/
	CLR_BIT(UART1->CR1 , 12);

	/*ONE STOP BIT*/
	CLR_BIT(UART1->CR2 , 13);
	CLR_BIT(UART1->CR2 , 12);

	/*SET BAUDRATE*/
    /*Baudrate -> 9600 */
	 UART1->BRR = 0x683;

	/*ENABLE UART*/
	SET_BIT(UART1->CR1 , UE);
    /*Enable Transmitter*/
    SET_BIT(UART1->CR1 , TE);
	/*Enable Reciever*/
    SET_BIT(UART1->CR1 , RE);
}


void MUART_voidSendByte(u8 copy_u8ByteToSend){
	   while( !(GET_BIT(UART1->SR,TXE)) );
		UART1->DR= copy_u8ByteToSend;
		while( !(GET_BIT(UART1->SR,TC)) );
		CLR_BIT(UART1->SR,TC);
}

u8 MUART_u8ReceiveByte(void){
	while( !(GET_BIT(UART1->SR,RXNE)) );
		return UART1->DR;
}

void MUART_voidSetCallBack(void(*Copy_Pf)(void)){
	if(Copy_Pf != NULL){
		UART_PF = Copy_Pf;
	}
}

void USART1_IRQHandler(void){
	if(UART_PF != NULL){
		UART_PF();
		UART1->SR = 0x0000;
	}
}
