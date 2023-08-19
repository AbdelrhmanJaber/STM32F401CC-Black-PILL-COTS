/*
 *   file : MEXTI_private.h
 *   Date : 15/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#define EXTI_BASE_ADRESS                    0x40013C00
#define SYSCFG_BASE_ADDRESS                 0x40013800


typedef struct myStructEXTI{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;


typedef struct{
	u32 MEMRMP ;
	u32 PMC ;
	u32 EXTICR1 ;
	u32 EXTICR2 ;
	u32 EXTICR3 ;
	u32 EXTICR4 ;
	u32 CMPCR ;
}SYSCFG_memoryMap_t;


#define EXTI              ((volatile EXTI_t*)EXTI_BASE_ADRESS)
#define SYSCFG            ((volatile SYSCFG_memoryMap_t*) SYSCFG_BASE_ADDRESS)

#define CONFIG_MASKING       0b1111

#define NULL                  (void*)0

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
