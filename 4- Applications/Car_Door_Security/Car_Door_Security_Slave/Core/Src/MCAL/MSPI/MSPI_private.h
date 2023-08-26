/*
 * MSPI_private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSPI_MSPI_PRIVATE_H_
#define SRC_MCAL_MSPI_MSPI_PRIVATE_H_



#define SPI1_BASE_ADD			0x40013000
#define SPI2_BASE_ADD			0x40003800
#define SPI3_BASE_ADD			0x40003C00
#define SPI4_BASE_ADD			0x40013400



typedef struct SPI_STRUCT{
	u32  CR1;
	u32  CR2;
	u32  SR;
	u32  DR;
	u32  CRCPR;
	u32  RXCRCR;
	u32  TXCRCR;
	u32  I2SCFGR;
	u32  I2SPR;
}SPI_memoryMap_t;


#define SPI1        ((volatile SPI_memoryMap_t*)SPI1_BASE_ADD)
#define SPI2        ((volatile SPI_memoryMap_t*)SPI2_BASE_ADD)
#define SPI3        ((volatile SPI_memoryMap_t*)SPI3_BASE_ADD)
#define SPI4        ((volatile SPI_memoryMap_t*)SPI4_BASE_ADD)



typedef enum{
	CPHA = 0,
	CPOL,
	MSTR,
	BR_3,
	BR_4,
	BR_5,
	SPE,
	LSBFIRST,
	SSI,
	SSM,
	RXONLY,
	DFF,
	CRCNEXT,
	CRCEN,
	BIDIOE,
	BIDIMODE
}CR1_BITS;


#define BSY				7

#define RXNEIE          6

#define   NULL (void*)0

#define  fPCLK_2            0b0000000000000000
#define  fPCLK_4            0b0000000000001000
#define  fPCLK_8            0b0000000000010000
#define  fPCLK_16           0b0000000000011000
#define  fPCLK_32           0b0000000000100000
#define  fPCLK_64           0b0000000000101000
#define  fPCLK_128          0b0000000000110000
#define  fPCLK_256          0b0000000000111000


#endif /* SRC_MCAL_MSPI_MSPI_PRIVATE_H_ */
