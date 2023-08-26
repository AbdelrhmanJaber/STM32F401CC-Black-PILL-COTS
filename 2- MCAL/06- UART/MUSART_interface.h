/*
 * MUSART_interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_
#define SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_


void MUSART_voidInit(void);

void MUSART_voidEnable(void);

void MUSART_voidDisable(void);

void MUSART_voidSendByte(u8 copy_u8ByteToSend);

u8 MUSART_u8ReceiveByte(void);

void MUSART_voidSendStringSynch(s8* copy_Pu8StringToSend);

u8 MUSART_Pu8RecieveStringSynch(s8* word);

void MUSART_voidSetCallBack(void(*Copy_Pf)(void));


typedef enum{
	USART_1,
	USART_2,
	USART_6
}USART_SELCTION_t;


#endif /* SRC_MCAL_MSUSART_MSUSART_INTERFACE_H_ */
