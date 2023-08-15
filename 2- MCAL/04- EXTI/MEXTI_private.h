
#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#define EXTI_BASE_ADRESS      0x40013C00

typedef struct myStructEXTI{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;


#define EXTI              ((volatile EXTI_t*)EXTI_BASE_ADRESS)

#define NULL                  (void*)0

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
