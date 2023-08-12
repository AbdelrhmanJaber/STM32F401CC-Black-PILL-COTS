/*
 *   file : MRRC_private.h
 *   Date : 11/8/2023
 *   Author : Abdelrahman Ibrahim
 *
 * */



/******************************Header Guard*******************************************/

#ifndef MCAL_MRRC_PRIVATE_H_
#define MCAL_MRRC_PRIVATE_H_

/******* RCC registers  ***********/

#define RCC_BASE_ADRESS         0x40023800


typedef struct myStruct{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR ;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved7;
	u32 Reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved9;
	u32 Reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved11;
	u32 Reserved12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved13;
	u32 Reserved14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
}RCC_memoryMap_t;

  /***define a macro of pointer to struct to access the register of RCC***/

#define RCC       ((volatile RCC_memoryMap_t*)(RCC_BASE_ADRESS))




/*****************************************  Start Bits of CR Register  **************************************************/

#define PLLI2SRDY  			27U
#define PLLI2SON 			26U
#define PLLRDY				25U
#define PLLON				24U
#define CSSON				19U
#define HSEBYP				18U
#define HSERDY				17U
#define HSEON 				16U
#define HSIRDY				1U
#define HSION				0U


/*****************************************  end Bits of CR Register  **************************************************/



/*****************************************  Start Bits of PLLCFGR Register  **************************************************/

#define PLLQ				24U
#define PLLSRC				22U
#define PLLP				16U
#define PLLN 				6U
#define PLLM				0U

/*****************************************  end Bits of PLLCFGR Register  **************************************************/



/*****************************************  Start Bits of CFGR Register  **************************************************/

#define SW0					 0U
#define SW1				     01U
#define SW_HSI				(0b00<<SW)
#define SW_HSE				(0b01<<SW)
#define SW_PLL				(0b10<<SW)
#define SWS2                 2U
#define SWS3                 3U

/*****************************************  end Bits of CFGR Register  **************************************************/


#endif /* MCAL_MRRC_PRIVATE_H_ */
