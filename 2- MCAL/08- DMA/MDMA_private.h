/*
 * MDMA_private.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MDMA_MDMA_PRIVATE_H_
#define SRC_MCAL_MDMA_MDMA_PRIVATE_H_

#define DMA1_BASE_ADDRESS		0x40026000
#define DMA2_BASE_ADDRESS		0x40026400

typedef struct{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_STREAMS;

typedef struct{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile DMA_STREAMS STREAMID[8];
}DMA;


#define DMA1     ((volatile DMA*)DMA1_BASE_ADDRESS)
#define DMA2	  ((volatile DMA*)DMA2_BASE_ADDRESS)

#endif /* SRC_MCAL_MDMA_MDMA_PRIVATE_H_ */
