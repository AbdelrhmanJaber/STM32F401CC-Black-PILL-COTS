/*
 * HLED_prog.c
 *
 *  Created on: Aug 21, 2023
 *      Author:Abdelrahman Ibrahim
 */

#include"../LIB/STD_Types.h"
#include"../LIB/BIT_Math.h"

#include"../MCAL/MGPIO/MGPIO_interface.h"
#include"../MCAL/MSTK/MSTK_interface.h"

#include"HLED_interface.h"


void HLED_voidSingleLedON(u8 copy_u8PortId,u8 copy_u8PinId){
	switch(copy_u8PortId){
		case LED_PORTA:{
			MGPIO_voidSetPinMode(GPIO_PORTA, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTA, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTA, copy_u8PinId, GPIO_HIGH);
			break;
		}
		case LED_PORTB:{
			MGPIO_voidSetPinMode(GPIO_PORTB, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTB, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTB, copy_u8PinId, GPIO_HIGH);
			break;
		}

		case LED_PORTC:{
			MGPIO_voidSetPinMode(GPIO_PORTC, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTC, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTC, copy_u8PinId, GPIO_HIGH);
			break;
		}
	}
}

void HLED_voidSingleLedOF(u8 copy_u8PortId,u8 copy_u8PinId){
	switch(copy_u8PortId){
		case LED_PORTA:{
			MGPIO_voidSetPinMode(GPIO_PORTA, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTA, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTA, copy_u8PinId, GPIO_LOW);
			break;
		}
		case LED_PORTB:{
			MGPIO_voidSetPinMode(GPIO_PORTB, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTB, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTB, copy_u8PinId, GPIO_LOW);
			break;
		}

		case LED_PORTC:{
			MGPIO_voidSetPinMode(GPIO_PORTC, copy_u8PinId, GPIO_MODE_OUTPUT);
			MGPIO_voidSetPinOutPutType(GPIO_PORTC, copy_u8PinId, GPIO_PUSH_PULL);
			MGPIO_voidSetPinValue(GPIO_PORTC, copy_u8PinId, GPIO_LOW);
			break;
		}
	}
}

void HLED_voidSingleLedTOGGLE_ms(u8 copy_u8PortId,u8 copy_u8PinId,u32 copy_u32DelayTime){
	switch(copy_u8PortId){
		case LED_PORTA:{
			HLED_voidSingleLedON(GPIO_PORTA, copy_u8PinId);
			MSTK_voidDelay_ms(copy_u32DelayTime);
			HLED_voidSingleLedOF(GPIO_PORTA, copy_u8PinId);
			MSTK_voidDelay_ms(copy_u32DelayTime);
			break;
		}
		case LED_PORTB:{
		    HLED_voidSingleLedON(GPIO_PORTB, copy_u8PinId);
		    MSTK_voidDelay_ms(copy_u32DelayTime);
		    HLED_voidSingleLedOF(GPIO_PORTB, copy_u8PinId);
		    MSTK_voidDelay_ms(copy_u32DelayTime);
		break;
		}

		case LED_PORTC:{
		    HLED_voidSingleLedON(GPIO_PORTC, copy_u8PinId);
			MSTK_voidDelay_ms(copy_u32DelayTime);
			HLED_voidSingleLedOF(GPIO_PORTC, copy_u8PinId);
			MSTK_voidDelay_ms(copy_u32DelayTime);
			break;
		}
	}
}


