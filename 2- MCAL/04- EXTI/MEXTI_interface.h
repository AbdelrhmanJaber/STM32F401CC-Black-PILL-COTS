
#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

void MEXTI_voidEnableInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidDisableExternalInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidSoftwareInterrupt(u8 copy_u8InterruptNumber);

void MEXTI_voidTriggerSelect(u8 copy_u8Line , u8 copy_u8SelectedTrigger);

u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void));


#define EXTI_RISING_EDGE               1
#define EXTI_FALLING_EDGE              2
#define EXTI_ANY_CHANGE                3

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
