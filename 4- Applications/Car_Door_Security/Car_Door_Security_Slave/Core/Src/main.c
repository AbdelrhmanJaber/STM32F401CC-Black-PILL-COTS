#include"LIB/STD_Types.h"

#include"MCAL/MRCC/MRRC_interface.h"
#include"MCAL/MGPIO/MGPIO_interface.h"
#include"MCAL/MSPI/MSPI_interface.h"
#include"MCAL/MNVIC/MNVIC.interface.h"
#include"MCAL/MEXTI/MEXTI_interface.h"

#include"HAL/HLED_interface.h"


#define RED_LED              0
#define GREEN_LED            2
#define SWITCH               1

u8 global_checkDoor = 0;

void interrupt_func(void){
	static u8 flag = 0;
	if(flag == 0){
	flag = 1;
	global_checkDoor = 1;
	}else if(flag == 1){
		flag = 0;
		global_checkDoor = 0;
	}
}

int main(void){

	u8 spiReciever;
	/*init RCC and config*/

	MRCC_voidInit(MRCC_HSI);
	MRCC_voidEnablePeripheral(AHB1ENR_BUS, GPIOAEN);
	MRCC_voidEnablePeripheral(APB2ENR_BUS, SPI1EN);
	MRCC_voidEnablePeripheral(APB2ENR_BUS, SYSCFGEN);
	/*set alternative functions*/

	MGPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 7, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 6,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 7,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 4,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 5,5);


	MGPIO_voidSetPinMode(GPIO_PORTA, RED_LED, GPIO_MODE_OUTPUT);  //for red LED (door is open)
	MGPIO_voidSetPinOutPutType(GPIO_PORTA, RED_LED, GPIO_PUSH_PULL);
	MGPIO_voidSetPinMode(GPIO_PORTA, GREEN_LED, GPIO_MODE_OUTPUT);  //for GREEN LED (door is closed)
	MGPIO_voidSetPinOutPutType(GPIO_PORTA, GREEN_LED, GPIO_PUSH_PULL);

	MGPIO_voidSetPinMode(GPIO_PORTA, SWITCH, GPIO_MODE_INPUT);  //for switch

	/*init invic and interrupt*/
	MNVIC_EnableIRQ(EXTI1_IRQ);
	MEXTI_u8EXTISetCallBack(EXTI_LINE1, interrupt_func);
	MEXTI_voidTriggerSelect(EXTI_LINE1, EXTI_FALLING_EDGE);
	MEXTI_voidSetEXTIConfig(EXTI_LINE1, EXTI_PORTA);


	/*INIT SPI*/
	MSPI_vSlaveInit(SLAVE_1);


	while(1){
		MEXTI_voidEnableExternalInterrupt(EXTI_LINE1);
		while(global_checkDoor == 0){
			spiReciever = MSPI1_u16Transeive(5);
			if(spiReciever == 5){
				MGPIO_voidSetPinValue(0, RED_LED, 1);
			}
			if(global_checkDoor == 1){
				MGPIO_voidSetPinValue(0, RED_LED, 0);
				break;
			}
		}
		while(global_checkDoor == 1){
			spiReciever = MSPI1_u16Transeive(5);
			if(spiReciever == 5){
				MGPIO_voidSetPinValue(0, GREEN_LED, 1);
			}
			if(global_checkDoor == 0){
				MGPIO_voidSetPinValue(0, GREEN_LED, 0);
				break;
			}
		}
}

	return 0;
}
