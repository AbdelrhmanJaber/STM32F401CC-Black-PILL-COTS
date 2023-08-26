#include"LIB/STD_Types.h"

#include"MCAL/MRCC/MRRC_interface.h"
#include"MCAL/MGPIO/MGPIO_interface.h"
#include"MCAL/MSPI/MSPI_interface.h"

#include"HAL/HLED_interface.h"


int main(void){

	/*init RCC and config*/

	MRCC_voidInit(MRCC_HSI);
	MRCC_voidEnablePeripheral(AHB1ENR_BUS, GPIOAEN);
	MRCC_voidEnablePeripheral(APB2ENR_BUS, SPI1EN);

	/*set alternative functions*/

	MGPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 7, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_MODE_ALT_FUNC);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 6,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 7,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 4,5);
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, 5,5);

	MGPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_MODE_INPUT);  //for switch
	MGPIO_voidSetPinInputPull(GPIO_PORTA, 0, GPIO_PULL_UP);

	/*INIT SPI*/
	MSPI_vMasterInit(MASTER_1);

	while(1){
		if(!(MGPIO_u8GetPinValue(GPIO_PORTA, 0))){
			MSPI1_u16Transeive(5);
		}
	}

	return 0;
}
