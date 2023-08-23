/*
 * MUART_private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_UART_MUART_PRIVATE_H_
#define SRC_MCAL_UART_MUART_PRIVATE_H_


#define MUART1_BASE_ADD		0x40011000

#define MUART2_BASE_ADD		0x40004400

#define MUART6_BASE_ADD		0x40011400

/* Bits */
#define RE 				2
#define TE 				3
#define M				12
#define UE				13
#define OVER8			15
#define PCE             10
#define PS               9

#define STOP_BIT_13      13
#define STOP_BIT_12      12

#define RXNE			5
#define TC				6
#define TXE				7

#define NULL           (void*)0

typedef struct {
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_memMap_t;

#define UART1 		((volatile UART_memMap_t *)MUART1_BASE_ADD)

#define UART2		((volatile UART_memMap_t *)MUART2_BASE_ADD)

#define UART6		((volatile UART_memMap_t *)MUART6_BASE_ADD)



#endif /* SRC_MCAL_UART_MUART_PRIVATE_H_ */
