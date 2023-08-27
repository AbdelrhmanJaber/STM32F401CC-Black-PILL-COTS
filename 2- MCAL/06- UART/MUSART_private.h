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



/*defined baudrate for 16M clk*/

typedef enum{
    B_SAMPLING_16_1200   = 0x44505400,
    B_SAMPLING_16_2400   = 0x43d05800,
    B_SAMPLING_16_9600   = 0x683,
    B_SAMPLING_16_19200  = 0x42504000,
    B_SAMPLING_16_38400  = 0x41d08000,
    B_SAMPLING_16_57600  = 0x418b0000,
    B_SAMPLING_16_115200 = 0x410b0000
}BaudRate_SAMPLING_16_t;


/*defined baudrate for 8M clk*/


typedef enum{
    B_SAMPLING_8_1200   = 0x6825,
    B_SAMPLING_8_2400   = 0x3413,
    B_SAMPLING_8_9600   = 0xD03,
    B_SAMPLING_8_19200  = 0x683,
    B_SAMPLING_8_38400  = 0x341,
    B_SAMPLING_8_57600  = 0x226,
    B_SAMPLING_8_115200 = 0x113
}BaudRate_SAMPLING_8_t;


#define MAX_SPEED_MODES                     2
#define MAX_BAUDRATES_OPTIONS               7


#define STOP_BIT_1             0b00000000000000000000000000000000
#define STOP_BIT_HALF		   0b00000000000000000001000000000000
#define STOP_BIT_TWO		   0b00000000000000000010000000000000

#endif /* SRC_MCAL_MSUSART_MSUSART_PRIVATE_H_ */
