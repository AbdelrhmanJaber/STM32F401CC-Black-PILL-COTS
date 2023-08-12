/*
 *   file : MRRC_interface.h
 *   Date : 11/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/

#ifndef MCAL_MRRC_INTERFACE_H_
#define MCAL_MRRC_INTERFACE_H_


/***** Macros for clock source *******/

#define MRCC_HSI         0
#define MRCC_HSE         1
#define MRCC_PLL         2



/************** HSE modes******************/
#define HSE_CRYSTAL        0
#define HSE_RC             1


/********************** PLL modes **************************/
#define PLL_HSI_MODE        0
#define PLL_HSE_MODE        1

/**************** prototype for used functions *******************/
void MRCC_voidInit(u8 copy_u8ClockSource);
void MRCC_voidSecurityOn(void);
void MRCC_voidSecurityOff(void);
void MRCC_voidEnablePeripheral(u8 copy_u8BusName , u8 copy_u8Peripheral);
void MRCC_voidDisablePeripheral(u8 copy_u8BusName , u8 copy_u8Peripheral);



/*************************** Start Bus Names to enable peripherals **********************************/

#define AHB1ENR_BUS                  1
#define AHB2ENR_BUS                  2
#define APB1ENR_BUS                  3
#define APB2ENR_BUS					 4

/*************************** end Bus Names to enable peripherals **********************************/


/*****************************************  Start Bits of AHB1ENR Register  **************************************************/

#define DMA2EN         22U
#define DMA1EN         21U
#define CRCEN          12U
#define GPIOHEN         7U
#define GPIOEEN         4U
#define GPIODEN         3U
#define GPIOCEN         2U
#define GPIOBEN         1U
#define GPIOAEN         0U

/*****************************************  end Bits of AHB1ENR Register  **************************************************/



/*****************************************  Start Bits of AHB2ENR Register  **************************************************/

#define OTGFSEN   7U

/*****************************************  end Bits of AHB2ENR Register  **************************************************/



/*****************************************  Start Bits of APB1ENR Register  **************************************************/

#define USART2EN         17U
#define SPI3EN           15U
#define SPI2EN           14U
#define WWDGEN           11U
#define TIM5EN            3U
#define TIM4EN            2U
#define TIM3EN            1U
#define TIM2EN            0U

/*****************************************  end Bits of APB1ENR Register  **************************************************/


/*****************************************  Start Bits of APB2ENR Register  **************************************************/

#define TIM11EN        18U
#define TIM10EN        17U
#define TIM9EN         16U
#define SYSCFGEN       14U
#define SPI4EN         13U
#define SPI1EN         12U
#define SDIOEN         11U
#define ADC1EN          8U
#define USART6EN        5U
#define USART1EN        4U
#define TIM1EN          0U

/*****************************************  end Bits of APB2ENR Register  **************************************************/


#endif /* MCAL_MRRC_INTERFACE_H_ */
