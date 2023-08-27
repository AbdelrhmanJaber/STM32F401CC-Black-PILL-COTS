/*
 * MUSART_interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_
#define SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_

typedef enum{
	USART_1,
	USART_2,
	USART_6
}USART_SELCTION_t;


void MUSART_voidInit(USART_SELCTION_t copy_enumUSART);

void MUSART_voidEnable(void);

void MUSART_voidDisable(void);

void MUSART_voidSendByte(USART_SELCTION_t copy_enumUSART , u8 copy_u8ByteToSend);

u8 MUSART1_u8ReceiveByte(void);

u8 MUSART2_u8ReceiveByte(void);

u8 MUSART6_u8ReceiveByte(void);

void MUSART_voidSendStringSynch(USART_SELCTION_t copy_enumUSART , s8* copy_Pu8StringToSend);

u8 MUSART1_Pu8RecieveStringSynch(s8* word);

u8 MUSART2_Pu8RecieveStringSynch(s8* word);

u8 MUSART6_Pu8RecieveStringSynch(s8* word);

void MUSART_voidSetCallBack(USART_SELCTION_t copy_enumUSART , void(*Copy_Pf)(void));




#endif /* SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_ */
