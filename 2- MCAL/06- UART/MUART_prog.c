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

void(*UART_PF)(void) = NULL;


void MUART_voidInit(void){
	/*WORD LENGHT*/
#if(UART_BITS_NUMBER == EIGHT_BITS)
	CLR_BIT(UART1->CR1 , M);
#elif(UART_BITS_NUMBER == NINE_BITS)
	SET_BIT(UART1->CR1 , M);
#endif
	/*Over sampling mode 16 bit or 8 bits*/
#if(OVER_SAMPLING == SAMPLING_16)
	CLR_BIT(UART1->CR1 , OVER8);
#elif(OVER_SAMPLING == SAMPLING_8)
	SET_BIT(UART1->CR1 , OVER8);
#endif
	/*parity control enable*/
#if(PARITY_ENABLE_OR_DISABLE == PARITY_ENABLE)
	SET_BIT(UART1->CR1 , PCE);
#elif(PARITY_ENABLE_OR_DISABLE == PARITY_DISABLE)
	CLR_BIT(UART1->CR1 , PCE);
#endif
	/*parity even or odd */
#if(PARITY_ENABLE_OR_DISABLE == PARITY_ENABLE)
#if(PARITY_SELCTION == EVEN_PARITY)
	CLR_BIT(UART1->CR1 , PS);
#elif(PARITY_SELCTION == ODD_PARITY)
	SET_BIT(UART1->CR1 , PS);
#endif
#endif
	/*STOP BITS NUMBER*/
#if(STOP_BIT == ONE_STOP_BIT)
	CLR_BIT(UART1->CR2 , STOP_BIT_13);
	CLR_BIT(UART1->CR2 , STOP_BIT_12);
#elif(STOP_BIT == HALF_STOP_BITS)
	CLR_BIT(UART1->CR2 , STOP_BIT_13);
	SET_BIT(UART1->CR2 , STOP_BIT_12);
#elif(STOP_BIT == TWO_STOP_BITS)
	SET_BIT(UART1->CR2 , STOP_BIT_13);
	SET_BIT(UART1->CR2 , STOP_BIT_12);
#endif
	/*SET BAUDRATE*/
/*Baudrate -> 9600 */
	UART1->BRR = 0x683;
    /*Enable Transmitter*/
  SET_BIT(UART1->CR1 , TE);
	/*Enable Reciever*/
   SET_BIT(UART1->CR1 , RE);
}

void MUART_voidEnable(void){
	/*UART ENABLE*/
	SET_BIT(UART1->CR1 , UE);
}

void MUART_voidDisable(void){
	/*UART DISABLE*/
	CLR_BIT(UART1->CR1 , UE);
}

void MUART_voidSendByte(u8 copy_u8ByteToSend){
	 UART1->DR = copy_u8ByteToSend;
	// while(!(GET_BIT(UART1->SR , TXE)));
	 while(!(GET_BIT(UART1->SR , TC)));
}

u8 MUART_u8ReceiveByte(void){
	u8 data;
	 while(!(GET_BIT(UART1->SR , RXNE)));
	 data = UART1->DR;
	 return data;
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
