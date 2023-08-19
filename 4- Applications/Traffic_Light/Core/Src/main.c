#include"LIB/STD_Types.h"
#include"LIB/BIT_Math.h"

#include"MCAL/MGPIO/MGPIO_interface.h"
#include"MCAL/MRCC/MRRC_interface.h"
#include"MCAL/MNVIC/MNVIC.interface.h"
#include"MCAL/MEXTI/MEXTI_interface.h"
#include"MCAL/MSTK/MSTK_interface.h"


/******************PROTOTYPES*****************************/

void test_led(void);

void trafficInit(void);


int main(void){
	MRCC_voidInit(MRCC_HSI);
	MRCC_voidEnablePeripheral(AHB1ENR_BUS , GPIOAEN);
	MRCC_voidEnablePeripheral(APB2ENR_BUS , SYSCFGEN);

	trafficInit();

	MSTK_voidInit();

	MNVIC_EnableIRQ(EXTI1_IRQ);
	MEXTI_u8EXTISetCallBack(EXTI_LINE1,test_led);
	MEXTI_voidTriggerSelect(EXTI_LINE1 , EXTI_FALLING_EDGE);
	MEXTI_voidSetEXTIConfig(EXTI_LINE1 , EXTI_PORTA);
	MEXTI_voidEnableExternalInterrupt(EXTI_LINE1);

	while(1);
	return 0;
}


void trafficInit(void){
	MGPIO_voidSetPinMode(GPIO_PORTA , 0 , GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA , 2 , GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA , 3 , GPIO_MODE_OUTPUT);

	MGPIO_voidSetPinMode(GPIO_PORTA , 1 , GPIO_MODE_INPUT);
	MGPIO_voidSetPinInputPull(GPIO_PORTA , 1 , GPIO_PULL_UP);

	MGPIO_voidSetPinOutPutType(GPIO_PORTA , 0 , GPIO_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(GPIO_PORTA , 2 , GPIO_PUSH_PULL);
	MGPIO_voidSetPinOutPutType(GPIO_PORTA , 3 , GPIO_PUSH_PULL);
}

void test_led(void){
	while(1){
	MGPIO_voidSetPinValue(GPIO_PORTA,0,1);
	MSTK_voidDelay_ms(14000);
	for(u8 i = 0 ; i < 3 ; i++){
	  MGPIO_voidSetPinValue(GPIO_PORTA,0,0);
	  MGPIO_voidSetPinValue(GPIO_PORTA,2,0);
	  MSTK_voidDelay_ms(1000);
	  MGPIO_voidSetPinValue(GPIO_PORTA,0,1);
	  MGPIO_voidSetPinValue(GPIO_PORTA,2,1);
	  MSTK_voidDelay_ms(1000);
	}

	 MGPIO_voidSetPinValue(GPIO_PORTA,0,0);

	 MGPIO_voidSetPinValue(GPIO_PORTA,3,1);
	 MSTK_voidDelay_ms(14000);

	 for(u8 i = 0 ; i < 3 ; i++){
	   MGPIO_voidSetPinValue(GPIO_PORTA,3,0);
	   MGPIO_voidSetPinValue(GPIO_PORTA,2,0);
	   MSTK_voidDelay_ms(1000);
	   MGPIO_voidSetPinValue(GPIO_PORTA,3,1);
	   MGPIO_voidSetPinValue(GPIO_PORTA,2,1);
	   MSTK_voidDelay_ms(1000);
	 }

	 MGPIO_voidSetPinValue(GPIO_PORTA,3,0);
	 MGPIO_voidSetPinValue(GPIO_PORTA,2,0);
	}
}
