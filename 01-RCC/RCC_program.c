/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 5/12/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : RCC_program.c    ****************/
/********************		Version  : 03      	        ****************/
/***********************************************************************/
/***********************************************************************/
// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 3- include driver files
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void){
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	 	RCC_CR   = 0x00010000 ; // Enable HSE with no bypass
		RCC_CFGR = 0x00000001 ;
    #elif RCC_CLOCK_TYPE == RCC_HSE
		RCC_CR   = 0x00050000 ; // Enable HSE with  bypass
		RCC_CFGR = 0x00000001 ;
	#elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081 ; // Enable HSI 
		RCC_CFGR = 0x00000000 ;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if    RCC_PLL_INPUT = RCC_PLL_IN_HSI_DIV_2
		
		#elif  RCC_PLL_INPUT = RCC_PLL_IN_HSE_DIV_2
		
		#elif  RCC_PLL_INPUT = RCC_PLL_IN_HSE
		
		#endif
	#else
		#error("You Chosed Wrong Clock Type")
	#endif	
}

void RCC_VoidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusIdId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerId)     break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENRENR,Copy_u8PerId) break;
			case RCC_APB2 :	SET_BIT(RCC_APB2ENRENR,Copy_u8PerId) break;
			default: // Return Error
				break;
		}
		
	}
	else
	{
		/*Return Error*/
	}  
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
	{	
        switch (Copy_u8BusId)
        {
        case RCC_AHB :  CLR_BIT(RCC_AHBENR , Copy_u8PerId);   break;  
        case RCC_APB1:  CLR_BIT(RCC_APB1ENR , Copy_u8PerId);  break;
        case RCC_APB2:  CLR_BIT(RCC_APB2ENR , Copy_u8PerId);  break;
        default:// Return Error
            break;
        }
		
    }
	else 
	{
        /* Return Error */
    }
}




















