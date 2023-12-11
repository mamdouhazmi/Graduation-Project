/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 24/1/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : GPIO_program.c   ****************/
/********************		Version  : 03      	        ****************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/* Choose a specific Pin to Set its Mode */
void MGPIO_vidSetPinDir    (u8 cpy_u8PortX ,u8 cpy_u8PinX  ,u8  cpy_u8Mode )
{
  switch (cpy_u8PortX)                                                          /* CHECK the Choosed Port  */
  {
     case MGPIOA :                                                               /* if POERTA is choosed    */
                if (cpy_u8PinX <= 7)                                            /* CHECK the Choosed PIN   */
                {
                    MGPIOA_CRL  &= ~((0b1111)      << (cpy_u8PinX * 4));         /* Clear  Control Bits of this pin to be able to write on it */
                    MGPIOA_CRL  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));         /* Write the Choosed Mode & Config to the Control BITS       */
                }
                else if (cpy_u8PinX <= 15)
                {
                    cpy_u8PinX -= 8;                                            /* to Shift Correctly at the new Register(CRH) you have to start counting pin form zero */
                    MGPIOA_CRH  &= ~((0b1111)      << (cpy_u8PinX * 4));
                    MGPIOA_CRH  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));
                }
                break;
     case MGPIOB :                                                               /* if POERTB is choosed    */
                if (cpy_u8PinX <= 7)                                            /* CHECK the Choosed PIN   */
                {
                    MGPIOB_CRL  &= ~((0b1111)      << (cpy_u8PinX * 4));         /* Clear  Control Bits of this pin to be able to write on it */
                    MGPIOB_CRL  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));         /* Write the Choosed Mode & Config to the Control BITS       */
                }
                else if (cpy_u8PinX <= 15)
                {
                    cpy_u8PinX -= 8;                                            /* to Shift Correctly at the new Register(CRH) you have to start counting pin form zero */
                    MGPIOB_CRH  &= ~((0b1111)      << (cpy_u8PinX * 4));
                    MGPIOB_CRH  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));
                }
                break;
     case MGPIOC :
                if (cpy_u8PinX <= 7)
                {
                    MGPIOC_CRL  &= ~((0b1111)      << (cpy_u8PinX * 4));
                    MGPIOC_CRL  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));
                }
                else if (cpy_u8PinX <= 15)
                {
                    cpy_u8PinX -= 8;
                    MGPIOC_CRH  &= ~((0b1111)      << (cpy_u8PinX * 4));
                    MGPIOC_CRH  |=  ((cpy_u8Mode)  << (cpy_u8PinX * 4));
                }
                break;
  }

}



/* Put a Value (HIGH/LOW) on a specific output pin */

void MGBIO_vidSetPinValue  (u8 cpy_u8PortX , u8 cpy_u8PinX  , u8 cpy_u8Value)
{
    switch (cpy_u8PortX)                                                           /* CHECK the Choosed Port*/
    {
        case MGPIOA :                                                               /* if POERTA is choosed*/
                    switch (cpy_u8Value)                                           /*CHECK The Value*/
                    {
                    case MGPIO_HIGH :     SET_BIT(MGPIOA_ODR, cpy_u8PinX); break;    /*If it High set the pin*/
                    case MGPIO_LOW  :     CLR_BIT(MGPIOA_ODR, cpy_u8PinX); break;    /*if it Low Clean The pin*/
                    case MGPIO_TOG  :     TGL_BIT(MGPIOA_ODR, cpy_u8PinX); break;    /*if it Toggle toggle The pin*/
                    }                               
                    break;                          
        case MGPIOB :                                                              
                    switch (cpy_u8Value)            
                    {                               
                    case MGPIO_HIGH :     SET_BIT(MGPIOB_ODR, cpy_u8PinX); break;
                    case MGPIO_LOW  :     CLR_BIT(MGPIOB_ODR, cpy_u8PinX); break;
                    case MGPIO_TOG  :     TGL_BIT(MGPIOB_ODR, cpy_u8PinX); break;
                    }                               
                    break;                          
        case MGPIOC :                                                            
                    switch (cpy_u8Value)            
                    {                               
                    case MGPIO_HIGH :     SET_BIT(MGPIOC_ODR, cpy_u8PinX); break;
                    case MGPIO_LOW  :     CLR_BIT(MGPIOC_ODR, cpy_u8PinX); break;
                    case MGPIO_TOG  :     TGL_BIT(MGPIOB_ODR, cpy_u8PinX); break;
                    }
                    break;

    }
}




/* Put a Value (HIGH/LOW) on a specific output port */

void MGPIO_vidSetPortValue  (u8 cpy_u8PortX  , u16 cpy_u16Value)
{
    switch (cpy_u8PortX)                                                           
    {
        case MGPIOA :                                                              
                    MGPIOA_ODR = cpy_u16Value ;
                    break;
        case MGPIOB :                                                               
                  MGPIOB_ODR = cpy_u16Value ;
                    break;
                    
        case MGPIOC :                                                             
                    MGPIOC_ODR = cpy_u16Value ;
                    break;

    }

}





/* Read a Value (HIGH/LOW) From a specific input pin */

u8   MGPIO_u8GetPinValue   (u8 cpy_u8PortX , u8 cpy_u8PinX )
{
    u8 LOC_u8Result =0 ;
    switch (cpy_u8PortX)                                                   /* CHECK the Choosed Port*/
    {
        case MGPIOA :                                                       /* if POERTA is choosed*/
                    LOC_u8Result = GET_BIT(MGPIOA_IDR, cpy_u8PinX);         /* Get The value from the pin and store it at LOC_u8Result*/
                    break;
        case MGPIOB :                                                               
                    LOC_u8Result = GET_BIT(MGPIOB_IDR, cpy_u8PinX);
                    break;
        case MGPIOC :                                                             
                    LOC_u8Result = GET_BIT(MGPIOC_IDR, cpy_u8PinX);
                    break;

    }
    return LOC_u8Result ;
}

