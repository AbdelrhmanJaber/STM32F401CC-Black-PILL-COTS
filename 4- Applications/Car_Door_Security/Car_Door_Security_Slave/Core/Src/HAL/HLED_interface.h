/*
 * HLED_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_HAL_HLED_INTERFACE_H_
#define SRC_HAL_HLED_INTERFACE_H_


void HLED_voidSingleLedON(u8 copy_u8PortId,u8 copy_u8PinId);

void HLED_voidSingleLedOF(u8 copy_u8PortId,u8 copy_u8PinId);

void HLED_voidSingleLedTOGGLE_ms(u8 copy_u8PortId,u8 copy_u8PinId,u32 copy_u32DelayTime);


/************************************Macros for ports and pins********************************************/

#define LED_PORTA               1
#define LED_PORTB               2
#define LED_PORTC               3


#define LED_PIN_0                0
#define LED_PIN_1                1
#define LED_PIN_2                2
#define LED_PIN_3                3
#define LED_PIN_4                4
#define LED_PIN_5                5
#define LED_PIN_6                6
#define LED_PIN_7                7
#define LED_PIN_8                8
#define LED_PIN_9                9
#define LED_PIN_10                10
#define LED_PIN_11               11
#define LED_PIN_12                12
#define LED_PIN_13                13
#define LED_PIN_14                14
#define LED_PIN_15                15


#endif /* SRC_HAL_HLED_INTERFACE_H_ */
