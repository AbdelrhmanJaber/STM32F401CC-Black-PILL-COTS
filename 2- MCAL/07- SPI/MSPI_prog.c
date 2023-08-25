/*
 * MSPI_prog.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrahman Ibrahim
 */


#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MSPI_private.h"
#include"MSPI_config.h"
#include"MSPI_interface.h"



static void MSPI1_privateMasterInit(void);
static void MSPI2_privateMasterInit(void);
static void MSPI3_privateMasterInit(void);
static void MSPI4_privateMasterInit(void);

static void MSPI1_privateSlaveInit(void);
static void MSPI2_privateSlaveInit(void);
static void MSPI3_privateSlaveInit(void);
static void MSPI4_privateSlaveInit(void);


void(*MSPI_PF[4])(void) = {NULL , NULL , NULL , NULL};

void MSPI_vMasterInit(u8 copy_u8MasterNumber){
	switch(copy_u8MasterNumber){
	case MASTER_1: MSPI1_privateMasterInit(); break;
	case MASTER_2: MSPI2_privateMasterInit(); break;
	case MASTER_3: MSPI3_privateMasterInit(); break;
	case MASTER_4: MSPI4_privateMasterInit(); break;
	}
}

void MSPI_vSlaveInit(u8 copy_u8SlaveNumber){
	switch(copy_u8SlaveNumber){
	case SLAVE_1: MSPI1_privateSlaveInit(); break;
	case SLAVE_2: MSPI2_privateSlaveInit(); break;
	case SLAVE_3: MSPI3_privateSlaveInit(); break;
	case SLAVE_4: MSPI4_privateSlaveInit(); break;
	}
}

u16 MSPI1_u16Transeive(u16 A_u16Data){
	SPI1->DR = A_u16Data;
	while(!(GET_BIT(SPI1->SR , BSY)));
	return SPI1->DR;
}


u16 MSPI2_u16Transeive(u16 A_u16Data){
	SPI2->DR = A_u16Data;
	while(!(GET_BIT(SPI2->SR , BSY)));
	return SPI2->DR;
}


u16 MSPI3_u16Transeive(u16 A_u16Data){
	SPI3->DR = A_u16Data;
	while(!(GET_BIT(SPI3->SR , BSY)));
	return SPI3->DR;
}


u16 MSPI4_u16Transeive(u16 A_u16Data){
	SPI4->DR = A_u16Data;
	while(!(GET_BIT(SPI4->SR , BSY)));
	return SPI4->DR;
}

void MSPI_voidSetCallBack(u8 copy_u8InterruptIndex , void(*copy_PF)(void)){
	if(copy_PF != NULL){
		MSPI_PF[copy_u8InterruptIndex] = copy_PF;
	}
	switch(copy_u8InterruptIndex){
	case SPI1_INTERRUPT :  SET_BIT(SPI1->CR2 , RXNEIE);  break;
	case SPI2_INTERRUPT :  SET_BIT(SPI2->CR2 , RXNEIE);  break;
	case SPI3_INTERRUPT :  SET_BIT(SPI3->CR2 , RXNEIE);  break;
	case SPI4_INTERRUPT :  SET_BIT(SPI4->CR2 , RXNEIE);  break;
	}
}


void SPI1_IRQHandler(void){
	if(MSPI_PF != NULL){
		MSPI_PF[0]();
		CLR_BIT(SPI1->CR2 , RXNEIE);
	}
}


void SPI2_IRQHandler(void){
	if(MSPI_PF != NULL){
		MSPI_PF[1]();
		CLR_BIT(SPI2->CR2 , RXNEIE);
	}
}


void SPI3_IRQHandler(void){
	if(MSPI_PF != NULL){
		MSPI_PF[2]();
		CLR_BIT(SPI3->CR2 , RXNEIE);
	}
}


void SPI4_IRQHandler(void){
	if(MSPI_PF != NULL){
		MSPI_PF[3]();
		CLR_BIT(SPI3->CR2 , RXNEIE);
	}
}




/***************************************Private Functions*************************************************/


static void MSPI1_privateMasterInit(void){
	/*select master*/
	SET_BIT(SPI1->CR1 , MSTR);

#if(SPI1_CLOCK_PHASE == SPI1_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI1->CR1 , CPHA);
#elif(SPI1_CLOCK_PHASE == SPI1_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI1->CR1 , CPHA);
#endif

#if(SPI1_CLOCK_POLARITY == SPI1_CLK_ZERO_IDLE)
	CLR_BIT(SPI1->CR1 , CPOL);
#elif(SPI1_CLOCK_POLARITY == SPI1_CLK_ONE_IDLE)
	SET_BIT(SPI1->CR1 , CPOL);
#endif

/*set baudrate prescaler*/
	SPI1->CR1 |= SPI1_BAUD_RATE_CONTROL;

#if(SPI1_START_DATA_POSITION == SPI1_MSB)
	CLR_BIT(SPI1->CR1 , LSBFIRST);
#elif(START_DATA_POSITION == LSB)
	SET_BIT(SPI1->CR1 , LSBFIRST);
#endif

#if(SPI1_FRAME_FORMAT == SPI1_BITS_8)
	CLR_BIT(SPI1->CR1 , DFF);
#elif(FRAME_FORMAT == BITS_16)
	SET_BIT(SPI1->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI1->CR1 , SPE);
}

static void MSPI2_privateMasterInit(void){
	/*select master*/
	SET_BIT(SPI2->CR1 , MSTR);

#if(SPI2_CLOCK_PHASE == SPI2_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI2->CR1 , CPHA);
#elif(SPI2_CLOCK_PHASE == SPI2_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI2->CR1 , CPHA);
#endif

#if(SPI2_CLOCK_POLARITY == SPI2_CLK_ZERO_IDLE)
	CLR_BIT(SPI2->CR1 , CPOL);
#elif(SPI2_CLOCK_POLARITY == SPI2_CLK_ONE_IDLE)
	SET_BIT(SPI2->CR1 , CPOL);
#endif

/*set baudrate prescaler*/
	SPI2->CR1 |= SPI2_BAUD_RATE_CONTROL;

#if(SPI2_START_DATA_POSITION == SPI2_MSB)
	CLR_BIT(SPI2->CR1 , LSBFIRST);
#elif(SPI2_START_DATA_POSITION == SPI2_LSB)
	SET_BIT(SPI2->CR1 , LSBFIRST);
#endif

#if(SPI2_FRAME_FORMAT == SPI2_BITS_8)
	CLR_BIT(SPI2->CR1 , DFF);
#elif(SPI2_FRAME_FORMAT == SPI2_BITS_16)
	SET_BIT(SPI2->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI2->CR1 , SPE);
}

static void MSPI3_privateMasterInit(void){
	/*select master*/
	SET_BIT(SPI3->CR1 , MSTR);

#if(SPI3_CLOCK_PHASE == SPI3_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI3->CR1 , CPHA);
#elif(SPI3_CLOCK_PHASE == _SPI3_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI3->CR1 , CPHA);
#endif

#if(SPI3_CLOCK_POLARITY == SPI3_CLK_ZERO_IDLE)
	CLR_BIT(SPI3->CR1 , CPOL);
#elif(SPI3_CLOCK_POLARITY == SPI3_CLK_ONE_IDLE)
	SET_BIT(SPI3->CR1 , CPOL);
#endif

/*set baudrate prescaler*/
	SPI1->CR1 |= SPI3_BAUD_RATE_CONTROL;

#if(SPI3_START_DATA_POSITION == SPI3_MSB)
	CLR_BIT(SPI3->CR1 , LSBFIRST);
#elif(SPI3_START_DATA_POSITION == SPI3_LSB)
	SET_BIT(SPI3->CR1 , LSBFIRST);
#endif

#if(SPI3_FRAME_FORMAT == SPI3_BITS_8)
	CLR_BIT(SPI3->CR1 , DFF);
#elif(SPI3_FRAME_FORMAT == SPI3_BITS_16)
	SET_BIT(SPI3->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI3->CR1 , SPE);
}

static void MSPI4_privateMasterInit(void){
	/*select master*/
	SET_BIT(SPI4->CR1 , MSTR);

#if(SPI4_CLOCK_PHASE == SPI4_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI4->CR1 , CPHA);
#elif(SPI4_CLOCK_PHASE == SPI4_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI4->CR1 , CPHA);
#endif

#if(SPI4_CLOCK_POLARITY == SPI4_CLK_ZERO_IDLE)
	CLR_BIT(SPI4->CR1 , CPOL);
#elif(SPI4_CLOCK_POLARITY == SPI4_CLK_ONE_IDLE)
	SET_BIT(SPI4->CR1 , CPOL);
#endif

/*set baudrate prescaler*/
	SPI4->CR1 |= SPI4_BAUD_RATE_CONTROL;

#if(SPI4_START_DATA_POSITION == SPI4_MSB)
	CLR_BIT(SPI4->CR1 , LSBFIRST);
#elif(START_DATA_POSITION == LSB)
	SET_BIT(SPI4->CR1 , LSBFIRST);
#endif

#if(SPI4_FRAME_FORMAT == SPI4_BITS_8)
	CLR_BIT(SPI4->CR1 , DFF);
#elif(SPI4_FRAME_FORMAT == SPI4_BITS_16)
	SET_BIT(SPI4->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI4->CR1 , SPE);
}


static void MSPI1_privateSlaveInit(void){

	/*select slave*/
	CLR_BIT(SPI1->CR1 , MSTR);

#if(SPI1_CLOCK_PHASE == SPI1_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI1->CR1 , CPHA);
#elif(SPI1_CLOCK_PHASE == SPI1_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI1->CR1 , CPHA);
#endif

#if(SPI1_CLOCK_POLARITY == SPI1_CLK_ZERO_IDLE)
	CLR_BIT(SPI1->CR1 , CPOL);
#elif(SPI1_CLOCK_POLARITY == SPI1_CLK_ONE_IDLE)
	SET_BIT(SPI1->CR1 , CPOL);
#endif



#if(SPI1_START_DATA_POSITION == SPI1_MSB)
	CLR_BIT(SPI1->CR1 , LSBFIRST);
#elif(SPI1_START_DATA_POSITION == SPI1_LSB)
	SET_BIT(SPI1->CR1 , LSBFIRST);
#endif


#if(SPI1_FRAME_FORMAT == SPI1_BITS_8)
	CLR_BIT(SPI1->CR1 , DFF);
#elif(SPI1_FRAME_FORMAT == SPI1_BITS_16)
	SET_BIT(SPI1->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI1->CR1 , SPE);
}

static void MSPI2_privateSlaveInit(void){
	/*select slave*/
	CLR_BIT(SPI2->CR1 , MSTR);

#if(SPI2_CLOCK_PHASE == SPI2_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI2->CR1 , CPHA);
#elif(SPI2_CLOCK_PHASE == SPI2_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI2->CR1 , CPHA);
#endif

#if(SPI2_CLOCK_POLARITY == SPI2_CLK_ZERO_IDLE)
	CLR_BIT(SPI2->CR1 , CPOL);
#elif(SPI2_CLOCK_POLARITY == SPI2_CLK_ONE_IDLE)
	SET_BIT(SPI2->CR1 , CPOL);
#endif



#if(SPI2_START_DATA_POSITION == SPI2_MSB)
	CLR_BIT(SPI2->CR1 , LSBFIRST);
#elif(SPI2_START_DATA_POSITION == SPI2_LSB)
	SET_BIT(SPI2->CR1 , LSBFIRST);
#endif


#if(SPI2_FRAME_FORMAT == SPI2_BITS_8)
	CLR_BIT(SPI2->CR1 , DFF);
#elif(SPI2_FRAME_FORMAT == SPI2_BITS_16)
	SET_BIT(SPI2->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI2->CR1 , SPE);
}

static void MSPI3_privateSlaveInit(void){
	/*select slave*/
	CLR_BIT(SPI3->CR1 , MSTR);

#if(SPI3_CLOCK_PHASE == SPI3_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI3->CR1 , CPHA);
#elif(SPI3_CLOCK_PHASE == SPI3_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI3->CR1 , CPHA);
#endif

#if(SPI3_CLOCK_POLARITY == SPI3_CLK_ZERO_IDLE)
	CLR_BIT(SPI3->CR1 , CPOL);
#elif(SPI3_CLOCK_POLARITY == SPI3_CLK_ONE_IDLE)
	SET_BIT(SPI3->CR1 , CPOL);
#endif



#if(SPI3_START_DATA_POSITION == SPI3_MSB)
	CLR_BIT(SPI3->CR1 , LSBFIRST);
#elif(SPI3_START_DATA_POSITION == SPI3_LSB)
	SET_BIT(SPI3->CR1 , LSBFIRST);
#endif


#if(SPI3_FRAME_FORMAT == SPI3_BITS_8)
	CLR_BIT(SPI3->CR1 , DFF);
#elif(SPI3_FRAME_FORMAT == SPI3_BITS_16)
	SET_BIT(SPI3->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI3->CR1 , SPE);
}

static void MSPI4_privateSlaveInit(void){
	/*select slave*/
	CLR_BIT(SPI4->CR1 , MSTR);

#if(SPI4_CLOCK_PHASE == SPI4_FIRST_CLOCK_FIRST_DATA)
	CLR_BIT(SPI4->CR1 , CPHA);
#elif(SPI4_CLOCK_PHASE == SPI4_SECOND_CLOCK_FIRST_DATA)
	SET_BIT(SPI4->CR1 , CPHA);
#endif

#if(SPI4_CLOCK_POLARITY == SPI4_CLK_ZERO_IDLE)
	CLR_BIT(SPI4->CR1 , CPOL);
#elif(SPI4_CLOCK_POLARITY == SPI4_CLK_ONE_IDLE)
	SET_BIT(SPI4->CR1 , CPOL);
#endif



#if(SPI4_START_DATA_POSITION == SPI4_MSB)
	CLR_BIT(SPI4->CR1 , LSBFIRST);
#elif(SPI4_START_DATA_POSITION == SPI4_LSB)
	SET_BIT(SPI4->CR1 , LSBFIRST);
#endif


#if(SPI4_FRAME_FORMAT == SPI4_BITS_8)
	CLR_BIT(SPI4->CR1 , DFF);
#elif(SPI4_FRAME_FORMAT == SPI4_BITS_16)
	SET_BIT(SPI4->CR1 , DFF);
#endif

	/*enable spi*/
	SET_BIT(SPI4->CR1 , SPE);
}
