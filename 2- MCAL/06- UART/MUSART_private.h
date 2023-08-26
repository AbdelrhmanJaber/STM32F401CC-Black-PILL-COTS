/*
 * MUSART_private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSUSART_MSUSART_PRIVATE_H_
#define SRC_MCAL_MSUSART_MSUSART_PRIVATE_H_


#define MUSART1_BASE_ADD		0x40011000

#define MUSART2_BASE_ADD		0x40004400

#define MUSART6_BASE_ADD		0x40011400

#define NEXT_LINE           0x0d

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
}USART_memMap_t;

#define USART1 		((volatile USART_memMap_t *)MUSART1_BASE_ADD)

#define USART2		((volatile USART_memMap_t *)MUSART2_BASE_ADD)

#define USART6		((volatile USART_memMap_t *)MUSART6_BASE_ADD)



#define MAX_SPEED_MODES                     2
#define MAX_BAUDRATES_OPTIONS               7

#endif /* SRC_MCAL_MSUSART_MSUSART_PRIVATE_H_ */
