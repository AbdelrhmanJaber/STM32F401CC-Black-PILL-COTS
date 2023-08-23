/*
 * MUART_interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_UART_MUART_INTERFACE_H_
#define SRC_MCAL_UART_MUART_INTERFACE_H_


void MUART_voidInit(void);

void MUART_voidEnable(void);

void MUART_voidDisable(void);

void MUART_voidSendByte(u8 copy_u8ByteToSend);

u8 MUART_u8ReceiveByte(void);

void MUART_voidSetCallBack(void(*Copy_Pf)(void));



#endif /* SRC_MCAL_UART_MUART_INTERFACE_H_ */
