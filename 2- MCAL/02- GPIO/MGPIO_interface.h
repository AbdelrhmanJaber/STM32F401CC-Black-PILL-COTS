/*
 *   file : MGPIO_interface.h
 *   Date : 13/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */


/******************************Header Guard*******************************************/

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_


/*******************Macros for port names****************************/

#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2
#define GPIO_PORTD     3
#define GPIO_PORTE     4
#define GPIO_PORTH     5


/*****************Macros for modes of pins ****************/

#define GPIO_MODE_INPUT       00
#define GPIO_MODE_OUTPUT      01
#define GPIO_MODE_ALT_FUNC    10
#define GPIO_MODE_ANALOG      11



/************************Macros for output type of pins********************************/

#define  GPIO_OPENDRAIN         1
#define  GPIO_PUSH_PULL         0


/******************************Macros for speed types********************************/

#define  GPIO_LOW_SPEED           00
#define  GPIO_MEDIUM_SPEED        01
#define  GPIO_HIGH_SPEED          10
#define  GPIO_VERY_HIGH_SPEED     11


/************************Macros for input type of pins********************************/

#define    GPIO_NO_PULL         00
#define	   GPIO_PULL_UP         01
#define	   GPIO_PULL_DOWN       10
#define    RESERVED             11


/************************************Macros for pin values***********************************************/

#define     GPIO_HIGH               1
#define		GPIO_LOW	   	        0


/*****prototype for used functions*****/

void MGPIO_voidSetPinMode(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8Mode);

void MGPIO_voidSetPinOutPutType(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8OutPutType);

void MGPIO_voidSetPinOutPutSpeed(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8OutPutSpeed);

void MGPIO_voidSetPinInputPull(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8PullType);

u8 MGPIO_u8GetPinValue(u8 copy_u8PortId , u8 copy_u8PinNumber);

void MGPIO_voidSetPinValue(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8Value);

void MGPIO_voidSetPinValueFast(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8PinValue);  /*BSRR*/

void MGPIO_voidLockPin(u8 copy_u8PortId , u8 copy_u8PinNumber);

void MGPIO_voidSetAlternativeFunction(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8AltFunction);


#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
