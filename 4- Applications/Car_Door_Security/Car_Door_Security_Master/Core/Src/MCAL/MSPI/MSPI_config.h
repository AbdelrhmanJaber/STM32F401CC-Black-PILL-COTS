/*
 * MSPI_config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSPI_MSPI_CONFIG_H_
#define SRC_MCAL_MSPI_MSPI_CONFIG_H_

/**********************Config for SPI 1*****************************/

#define SPI1_FIRST_CLOCK_FIRST_DATA       1
#define SPI1_SECOND_CLOCK_FIRST_DATA      2

#define SPI1_CLOCK_PHASE                  SPI1_FIRST_CLOCK_FIRST_DATA

#define   SPI1_CLK_ZERO_IDLE              0
#define   SPI1_CLK_ONE_IDLE               1

#define SPI1_CLOCK_POLARITY               SPI1_CLK_ZERO_IDLE

#define SPI1_BAUD_RATE_CONTROL            fPCLK_8

#define    SPI1_MSB                       1
#define    SPI1_LSB                       2

#define SPI1_START_DATA_POSITION          SPI1_MSB

#define   SPI1_BITS_8                     1
#define   SPI1_BITS_16                    2

#define  SPI1_FRAME_FORMAT                SPI1_BITS_8



/**********************Config for SPI 2*****************************/

#define SPI2_FIRST_CLOCK_FIRST_DATA       1
#define SPI2_SECOND_CLOCK_FIRST_DATA      2

#define SPI2_CLOCK_PHASE                  SPI2_FIRST_CLOCK_FIRST_DATA

#define   SPI2_CLK_ZERO_IDLE              0
#define   SPI2_CLK_ONE_IDLE               1

#define SPI2_CLOCK_POLARITY               SPI2_CLK_ZERO_IDLE

#define SPI2_BAUD_RATE_CONTROL            fPCLK_8

#define    SPI2_MSB                       1
#define    SPI2_LSB                       2

#define SPI2_START_DATA_POSITION          SPI2_MSB

#define   SPI2_BITS_8                     1
#define   SPI2_BITS_16                    2

#define  SPI2_FRAME_FORMAT                SPI2_BITS_8



/**********************Config for SPI 3*****************************/

#define SPI3_FIRST_CLOCK_FIRST_DATA       1
#define SPI3_SECOND_CLOCK_FIRST_DATA      2

#define SPI3_CLOCK_PHASE                  SPI3_FIRST_CLOCK_FIRST_DATA

#define   SPI3_CLK_ZERO_IDLE              0
#define   SPI3_CLK_ONE_IDLE               1

#define SPI3_CLOCK_POLARITY               SPI3_CLK_ZERO_IDLE

#define SPI3_BAUD_RATE_CONTROL            fPCLK_8

#define    SPI3_MSB                       1
#define    SPI3_LSB                       2

#define SPI3_START_DATA_POSITION          SPI3_MSB

#define   SPI3_BITS_8                     1
#define   SPI3_BITS_16                    2

#define  SPI3_FRAME_FORMAT                SPI3_BITS_8




/**********************Config for SPI 4*****************************/

#define SPI4_FIRST_CLOCK_FIRST_DATA       1
#define SPI4_SECOND_CLOCK_FIRST_DATA      2

#define SPI4_CLOCK_PHASE                  SPI4_FIRST_CLOCK_FIRST_DATA

#define   SPI4_CLK_ZERO_IDLE              0
#define   SPI4_CLK_ONE_IDLE               1

#define SPI4_CLOCK_POLARITY               SPI4_CLK_ZERO_IDLE

#define SPI4_BAUD_RATE_CONTROL            fPCLK_8

#define    SPI4_MSB                       1
#define    SPI4_LSB                       2

#define SPI4_START_DATA_POSITION          SPI4_MSB

#define   SPI4_BITS_8                     1
#define   SPI4_BITS_16                    2

#define  SPI4_FRAME_FORMAT                SPI4_BITS_8

#endif /* SRC_MCAL_MSPI_MSPI_CONFIG_H_ */
