#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MGPIO_private.h"
#include"MGPIO_config.h"
#include"MGPIO_interface.h"



/***********************************Start Function*********************************************/



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


/***********************************Start Function*********************************************/


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



/***********************************Start Function*********************************************/


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




/***********************************Start Function*********************************************/


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
	u8 local_u8PinValue = 0;
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



/***********************************Start Function*********************************************/


void MGPIO_voidSetPinValue(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8Value){
	switch(copy_u8PortId){
	    case GPIO_PORTA: {
		   GPIOA->ODR &= ~(1<<copy_u8PinNumber);
		   GPIOA->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
	    }
	    case GPIO_PORTB: {
	    	GPIOB->ODR &= ~(1<<copy_u8PinNumber);
		    GPIOB->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
	    }
		case GPIO_PORTC: {
			GPIOC->ODR &= ~(1<<copy_u8PinNumber);
			GPIOC->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		}
		case GPIO_PORTD: {
			GPIOD->ODR &= ~(1<<copy_u8PinNumber);
			GPIOD->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		}
		case GPIO_PORTE: {
			GPIOE->ODR &= ~(1<<copy_u8PinNumber);
			GPIOE->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		}
		case GPIO_PORTH: {
			GPIOH->ODR &= ~(1<<copy_u8PinNumber);
			GPIOH->ODR |=  (u32)(copy_u8Value << (copy_u8PinNumber));  break;
		}
	}
}

/***********************************End Function*********************************************/



/***********************************Start Function*********************************************/


void MGPIO_voidSetPinValueFast(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8PinValue){
	if(copy_u8PinValue == GPIO_HIGH){
		switch(copy_u8PortId){
			case GPIO_PORTA: GPIOA->BSRR = (u32)(1<<copy_u8PinNumber);  break;
			case GPIO_PORTB: GPIOB->BSRR = (u32)(1<<copy_u8PinNumber);  break;
			case GPIO_PORTC: GPIOC->BSRR = (u32)(1<<copy_u8PinNumber);  break;
			case GPIO_PORTD: GPIOD->BSRR = (u32)(1<<copy_u8PinNumber);  break;
			case GPIO_PORTE: GPIOE->BSRR = (u32)(1<<copy_u8PinNumber);  break;
			case GPIO_PORTH: GPIOH->BSRR = (u32)(1<<copy_u8PinNumber);  break;
		}
	}else if(copy_u8PinValue == GPIO_LOW){
		switch(copy_u8PortId){
			case GPIO_PORTA: GPIOA->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
			case GPIO_PORTB: GPIOB->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
			case GPIO_PORTC: GPIOC->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
			case GPIO_PORTD: GPIOD->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
			case GPIO_PORTE: GPIOE->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
			case GPIO_PORTH: GPIOH->BSRR = (u32)(1<< (copy_u8PinNumber+16) );  break;
		}
	}
}

/***********************************End Function*********************************************/



/***********************************Start Function*********************************************/

void MGPIO_voidLockPin(u8 copy_u8PortId , u8 copy_u8PinNumber){
	switch(copy_u8PortId){
		case GPIO_PORTA:{
			SET_BIT(GPIOA->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOA->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOA->LCKR , LOCKED_PIN)));
			break;
		}
		case GPIO_PORTB:{
			SET_BIT(GPIOB->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOB->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOB->LCKR , LOCKED_PIN)));
			break;
		}
		case GPIO_PORTC:{
			SET_BIT(GPIOC->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOC->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOC->LCKR , LOCKED_PIN)));
			break;
		}
		case GPIO_PORTD:{
			SET_BIT(GPIOD->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOD->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOD->LCKR , LOCKED_PIN)));
			break;
		}
		case GPIO_PORTE:{
			SET_BIT(GPIOE->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOE->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOE->LCKR , LOCKED_PIN)));
			break;
		}
		case GPIO_PORTH:{
			SET_BIT(GPIOH->LCKR ,copy_u8PinNumber );
			SET_BIT(GPIOH->LCKR , LOCKED_PIN);
			while(!(GET_BIT(GPIOH->LCKR , LOCKED_PIN)));
			break;
		}
	}
}

/***********************************End Function*********************************************/




/***********************************Start Function*********************************************/


void MGPIO_voidSetAlternativeFunction(u8 copy_u8PortId , u8 copy_u8PinNumber , u8 copy_u8AltFunction){
	if(copy_u8AltFunction <= 7){
		switch(copy_u8PortId){
			case GPIO_PORTA:{
				GPIOA->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOA->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
			case GPIO_PORTB:{
				GPIOB->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOB->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
			case GPIO_PORTC:{
				GPIOC->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOC->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
			case GPIO_PORTD:{
				GPIOD->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOD->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
			case GPIO_PORTE:{
				GPIOE->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOE->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
			case GPIO_PORTH:{
				GPIOH->AFRL &= ~(CLEAR_ALTERNATIVE_FUNCTION << (copy_u8PinNumber*4));
				GPIOH->AFRL |= (copy_u8AltFunction << copy_u8PinNumber*4);
				break;
			}
		}
	}else{
		/*local variable to access alternative function in hugh register*/
		u8 local_u8DummyPin = copy_u8PinNumber - 8 ;
		switch(copy_u8PortId){
			case GPIO_PORTA:{
				GPIOA->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOA->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
			case GPIO_PORTB:{
				GPIOB->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOB->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
			case GPIO_PORTC:{
				GPIOC->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOC->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
			case GPIO_PORTD:{
				GPIOD->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOD->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
			case GPIO_PORTE:{
				GPIOE->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOE->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
			case GPIO_PORTH:{
				GPIOH->AFRH &= ~(CLEAR_ALTERNATIVE_FUNCTION << (local_u8DummyPin*4));
				GPIOH->AFRH |= (copy_u8AltFunction << local_u8DummyPin*4);
				break;
			}
	}
}

}
/***********************************End Function*********************************************/




