/*
 * MUART_config.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_UART_MUART_CONFIG_H_
#define SRC_MCAL_UART_MUART_CONFIG_H_


#define ONE_STOP_BIT       1
#define TWO_STOP_BITS      2

/*
 * STOP BITS
 * ONE_STOP_BIT      1
 * HALF_STOP_BIT     2
 * TWO_STOP_BITS     3
 * */
#define STOP_BIT         ONE_STOP_BIT


#define   PARITY_ENABLE            1
#define   PARITY_DISABLE           2

#define PARITY_ENABLE_OR_DISABLE             PARITY_DISABLE



#define EVEN_PARITY             1
#define ODD_PARITY              0

/*
 * PARITY
 * EVEN_PARITY               2
 * ODD_PARITY                1
 * */

#define PARITY_SELCTION            EVEN_PARITY


#define EIGHT_BITS            1
#define NINE_BITS             2

/*
 * NUMBER OF BITS
 * EIGHT_BITS            1
 * NINE_BITS             2
 * */

#define UART_BITS_NUMBER       EIGHT_BITS


#define  SAMPLING_8                 1
#define  SAMPLING_16                2

#define OVER_SAMPLING               SAMPLING_8

#endif /* SRC_MCAL_UART_MUART_CONFIG_H_ */
