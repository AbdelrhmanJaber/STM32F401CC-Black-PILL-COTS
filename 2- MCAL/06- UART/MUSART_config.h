/*
 * MUSART_config.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSUSART_MSUSART_CONFIG_H_
#define SRC_MCAL_MSUSART_MSUSART_CONFIG_H_


/***************************************Config for USART1*********************************************/

/*
 * STOP_BIT_1
 * STOP_BIT_HALF
 * STOP_BIT_TWO
 * */

#define  USART1_STOP_BIT          STOP_BIT_1


#define    USART1_PARITY_ENABLE            1
#define    USART1_PARITY_DISABLE           2

#define  USART1_PARITY_CONTROL_ENABLE              USART1_PARITY_DISABLE


#define  USART1_EVEN_PARITY             1
#define  USART1_ODD_PARITY              0

#define  USART1_PARITY_SELCTION             USART1_EVEN_PARITY


#define  USART1_EIGHT_BITS            1
#define  USART1_NINE_BITS             2

#define USART1_BITS_NUMBER        USART1_EIGHT_BITS


#define   USART1_SAMPLING_8                 1
#define   USART1_SAMPLING_16                2

#define  USART1_OVER_SAMPLING                USART1_SAMPLING_16



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






/***************************************Config for USART2*********************************************/

/*
 * STOP_BIT_1
 * STOP_BIT_HALF
 * STOP_BIT_TWO
 * */

#define  USART2_STOP_BIT          STOP_BIT_1


#define    USART2_PARITY_ENABLE            1
#define    USART2_PARITY_DISABLE           2

#define  USART2_PARITY_CONTROL_ENABLE              USART2_PARITY_DISABLE


#define  USART2_EVEN_PARITY             1
#define  USART2_ODD_PARITY              0

#define  USART2_PARITY_SELCTION             USART2_EVEN_PARITY


#define  USART2_EIGHT_BITS            1
#define  USART2_NINE_BITS             2

#define USART2_BITS_NUMBER        USART2_EIGHT_BITS


#define   USART2_SAMPLING_8                 1
#define   USART2_SAMPLING_16                2

#define  USART2_OVER_SAMPLING                USART2_SAMPLING_16



#define  USART2_SPEED_8_SAMPLING          0
#define  USART2_SPEED_16_SAMPLING         1

#define  USART2_CLOCK_SPEED               USART2_SPEED_16_SAMPLING

#define BAUDRATE_1200                    0
#define BAUDRATE_2400                    1
#define BAUDRATE_9600                    2
#define BAUDRATE_19200                   3
#define BAUDRATE_38400                   4
#define BAUDRATE_57600                   5
#define BAUDRATE_115200                  6

#define  USART2_BAUDRATE                 BAUDRATE_9600




/***************************************Config for USART6*********************************************/

/*
 * STOP_BIT_1
 * STOP_BIT_HALF
 * STOP_BIT_TWO
 * */

#define  USART6_STOP_BIT          STOP_BIT_1


#define    USART6_PARITY_ENABLE            1
#define    USART6_PARITY_DISABLE           2

#define  USART6_PARITY_CONTROL_ENABLE              USART6_PARITY_DISABLE


#define  USART6_EVEN_PARITY             1
#define  USART6_ODD_PARITY              0

#define  USART6_PARITY_SELCTION             USART6_EVEN_PARITY


#define  USART6_EIGHT_BITS            1
#define  USART6_NINE_BITS             2

#define USART6_BITS_NUMBER        USART6_EIGHT_BITS


#define   USART6_SAMPLING_8                 1
#define   USART6_SAMPLING_16                2

#define  USART6_OVER_SAMPLING                USART6_SAMPLING_16



#define  USART6_SPEED_8_SAMPLING          0
#define  USART6_SPEED_16_SAMPLING         1

#define  USART6_CLOCK_SPEED               USART6_SPEED_16_SAMPLING

#define BAUDRATE_1200                    0
#define BAUDRATE_2400                    1
#define BAUDRATE_9600                    2
#define BAUDRATE_19200                   3
#define BAUDRATE_38400                   4
#define BAUDRATE_57600                   5
#define BAUDRATE_115200                  6

#define  USART6_BAUDRATE                 BAUDRATE_9600



#endif /* SRC_MCAL_MSUSART_MSUSART_CONFIG_H_ */
