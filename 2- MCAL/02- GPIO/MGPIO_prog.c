#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MGPIO_private.h"
#include"MGPIO_config.h"
#include"MGPIO_interface.h"




void MGPIO_voidSetPinMode(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8Mode){
	switch(copy_u8PortId){
		case GPIO_PORTA:{
			GPIOA->MODER &=  ~(0b11 << (copy_u8PinNumber*2));
			GPIOA->MODER |=  (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTB:{
			GPIOB->MODER &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOB->MODER |=  (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTC:{
			GPIOC->MODER &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOC->MODER |= (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTD:{
			GPIOD->MODER &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOD->MODER |= (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTE:{
			GPIOE->MODER &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOE->MODER |=  (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTH:{
			GPIOH->MODER &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOH->MODER |=  (u32)(copy_u8Mode << (copy_u8PinNumber*2));
			break;
		}
	}
}

/***********************************End Function*********************************************/



void MGPIO_voidSetPinOutPutType(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8OutPutType){
	switch(copy_u8PortId){
		case GPIO_PORTA:  GPIOA->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
		case GPIO_PORTB:  GPIOB->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
		case GPIO_PORTC:  GPIOC->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
		case GPIO_PORTD:  GPIOD->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
		case GPIO_PORTE:  GPIOE->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
		case GPIO_PORTH:  GPIOH->OTYPER |=  (u32)(copy_u8OutPutType << (copy_u8PinNumber));  break;
	}
}


/***********************************End Function*********************************************/


void MGPIO_voidSetPinOutPutSpeed(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8OutPutSpeed){
	switch(copy_u8PortId){
		case GPIO_PORTA:{
			GPIOA->OSPEEDR &=  ~(0b11 << (copy_u8PinNumber*2));
			GPIOA->OSPEEDR |=  (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTB:{
			GPIOB->OSPEEDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOB->OSPEEDR |=  (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTC:{
			GPIOC->OSPEEDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOC->OSPEEDR |= (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTD:{
			GPIOD->OSPEEDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOD->OSPEEDR |= (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTE:{
			GPIOE->OSPEEDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOE->OSPEEDR |=  (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTH:{
			GPIOH->OSPEEDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOH->OSPEEDR |=  (u32)(copy_u8OutPutSpeed << (copy_u8PinNumber*2));
			break;
		}
	}
}

/***********************************End Function*********************************************/


void MGPIO_voidSetPinInputPull(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8PullType){
	switch(copy_u8PortId){
		case GPIO_PORTA:{
			GPIOA->PUPDR &=  ~(0b11 << (copy_u8PinNumber*2));
			GPIOA->PUPDR |=  (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTB:{
			GPIOB->PUPDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOB->PUPDR |=  (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTC:{
			GPIOC->PUPDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOC->PUPDR |= (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTD:{
			GPIOD->PUPDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOD->PUPDR |= (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTE:{
			GPIOE->PUPDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOE->PUPDR |=  (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
		case GPIO_PORTH:{
			GPIOH->PUPDR &= ~(0b11 << (copy_u8PinNumber*2));
			GPIOH->PUPDR |=  (u32)(copy_u8PullType << (copy_u8PinNumber*2));
			break;
		}
	}
}

/***********************************End Function*********************************************/


u8 MGPIO_u8GetPinValue(u8 copy_u8PortId , u8 copy_u8PinNumber){
	u8 local_u8PinValue;
	switch(copy_u8PortId){
		case GPIO_PORTA: local_u8PinValue = GET_BIT(GPIOA->IDR , copy_u8PinNumber);   break;
		case GPIO_PORTB: local_u8PinValue = GET_BIT(GPIOB->IDR , copy_u8PinNumber);   break;
		case GPIO_PORTC: local_u8PinValue = GET_BIT(GPIOC->IDR , copy_u8PinNumber);   break;
		case GPIO_PORTD: local_u8PinValue = GET_BIT(GPIOD->IDR , copy_u8PinNumber);   break;
		case GPIO_PORTE: local_u8PinValue = GET_BIT(GPIOE->IDR , copy_u8PinNumber);   break;
		case GPIO_PORTH: local_u8PinValue = GET_BIT(GPIOH->IDR , copy_u8PinNumber);   break;
	}
	return local_u8PinValue;
}

/***********************************End Function*********************************************/



void MGPIO_voidSetPinValue(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8Value){
	switch(copy_u8PortId){
		case GPIO_PORTA:  GPIOA->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		case GPIO_PORTB:  GPIOB->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		case GPIO_PORTC:  GPIOC->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		case GPIO_PORTD:  GPIOD->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		case GPIO_PORTE:  GPIOE->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		case GPIO_PORTH:  GPIOH->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
	}
}

/***********************************End Function*********************************************/



