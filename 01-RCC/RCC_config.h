/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 5/12/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : RCC_config.h     ****************/
/********************		Version  : 03      	        ****************/
/***********************************************************************/
/***********************************************************************/
#ifndef     RCC_CONFIG_H
#define     RCC_CONFIG_H
/***********************************************************************/
/*Options:
		RCC_HSE_CRYSTAL			
		RCC_HSE
		RCC_HSI
		RCC_PLL			
		*/
#define RCC_CLOCK_TYPE     RCC_HSE_CRYSTAL

/***********************************************************************/
/*  enable Microcontroller output clock for the selected source 
    Values: 
        MCO_NOCLK
        MCO_SYSCLK
        MCO_HSI
        MCO_HSE
        MCO_PLL
*/
#define MICRO_OUTPUT_CLOCK      MCO_NOCLK  
/***********************************************************************/


#if   RCC_CLOCK_TYPE == RCC_PLL
/*Options : 2 ~ 16
Note : Select value only when PLL as input clock system 			
			*/
#define RCC_PLL_MUL_VAL    4         
/*Options:
Note : Select value only when PLL as input clock system 
		RCC_PLL_IN_HSI_DIV_2			
		RCC_PLL_IN_HSE_DIV_2
		RCC_PLL_IN_HSE
		RCC_PLL			
		*/
#define  RCC_PLL_INPUT	   	RCC_PLL_IN_HSE
#endif 
/***********************************************************************/

#endif  // End Of File
