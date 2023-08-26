/*
 * MUSART_config.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSUSART_MSUSART_CONFIG_H_
#define SRC_MCAL_MSUSART_MSUSART_CONFIG_H_


#define USART1_ONE_STOP_BIT       1
#define USART1_TWO_STOP_BITS      2

#define  USART1_STOP_BIT          USART1_ONE_STOP_BIT


#define    USART1_PARITY_ENABLE            1
#define    USART1_PARITY_DISABLE           2

#define  USART1_PARITY_ENABLE_OR_DISABLE              USART1_PARITY_DISABLE


#define  USART1_EVEN_PARITY             1
#define  USART1_ODD_PARITY              0

#define  USART1_PARITY_SELCTION             USART1_EVEN_PARITY


#define  USART1_EIGHT_BITS            1
#define  USART1_NINE_BITS             2

#define USART1_BITS_NUMBER        USART1_EIGHT_BITS


#define   USART1_SAMPLING_8                 1
#define   USART1_SAMPLING_16                2

#define  USART1_OVER_SAMPLING                USART1_SAMPLING_16


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


#define  USART1_SPEED_8_SAMPLING          0
#define  USART1_SPEED_16_SAMPLING         1

#define  USART1_CLOCK_SPEED               USART1_SPEED_16_SAMPLING

#define BAUDRATE_1200                    0
#define BAUDRATE_2400                    1
#define BAUDRATE_9600                    2
#define BAUDRATE_19200                   3
#define BAUDRATE_38400                   4
#define BAUDRATE_57600                   5
#define BAUDRATE_115200                  6

#define  USART1_BAUDRATE                 BAUDRATE_9600




#endif /* SRC_MCAL_MSUSART_MSUSART_CONFIG_H_ */
