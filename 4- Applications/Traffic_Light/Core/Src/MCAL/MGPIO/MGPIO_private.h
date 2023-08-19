/*
 *   file : MGPIO_config.h
 *   Date : 13/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/


#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS      0x40020000
#define GPIOB_BASE_ADDRESS      0x40020400
#define GPIOC_BASE_ADDRESS      0x40020800
#define GPIOD_BASE_ADDRESS      0x40020C00
#define GPIOE_BASE_ADDRESS      0x40021000
#define GPIOH_BASE_ADDRESS      0x40021C00


typedef struct myStruct2{
    u32 MODER;
    u32 OTYPER;
    u32 OSPEEDR;
    u32 PUPDR;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 LCKR;
    u32 AFRL;
    u32 AFRH;
}GPIO_memoryMap_t;


#define GPIOA      ((volatile GPIO_memoryMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB      ((volatile GPIO_memoryMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC      ((volatile GPIO_memoryMap_t*)(GPIOC_BASE_ADDRESS))
#define GPIOD      ((volatile GPIO_memoryMap_t*)(GPIOD_BASE_ADDRESS))
#define GPIOE      ((volatile GPIO_memoryMap_t*)(GPIOE_BASE_ADDRESS))
#define GPIOH      ((volatile GPIO_memoryMap_t*)(GPIOH_BASE_ADDRESS))


#define LOCKED_PIN            16

#define CLEAR_ALTERNATIVE_FUNCTION            0b1111

#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
