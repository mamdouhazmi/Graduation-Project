/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 20/1/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : GPIO_private.h   ****************/
/********************		Version  : 03      	        ****************/
/***********************************************************************/
/***********************************************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H


/***************        Registers Definition      **************/
/*   Base Address For Each Port */
#define BASE_ADRESS_PORTA    0x40010800
#define BASE_ADRESS_PORTB    0x40010C00
#define BASE_ADRESS_PORTC    0x40011000

/*   PORTA Register Definition */
#define MGPIOA_CRL          *((u32 *)(BASE_ADRESS_PORTA + 0x00))          
#define MGPIOA_CRH          *((u32 *)(BASE_ADRESS_PORTA + 0x04))
#define MGPIOA_IDR          *((u32 *)(BASE_ADRESS_PORTA + 0x08))
#define MGPIOA_ODR          *((u32 *)(BASE_ADRESS_PORTA + 0x0C))
#define MGPIOA_BSRR         *((u32 *)(BASE_ADRESS_PORTA + 0x10))
#define MGPIOA_BRR          *((u32 *)(BASE_ADRESS_PORTA + 0x14))
#define MGPIOA_LCKR         *((u32 *)(BASE_ADRESS_PORTA + 0x18))

/*   PORTC Register Definition */
#define MGPIOB_CRL          *((u32 *)(BASE_ADRESS_PORTB + 0x00))          
#define MGPIOB_CRH          *((u32 *)(BASE_ADRESS_PORTB + 0x04))
#define MGPIOB_IDR          *((u32 *)(BASE_ADRESS_PORTB + 0x08))
#define MGPIOB_ODR          *((u32 *)(BASE_ADRESS_PORTB + 0x0C))
#define MGPIOB_BSRR         *((u32 *)(BASE_ADRESS_PORTB + 0x10))
#define MGPIOB_BRR          *((u32 *)(BASE_ADRESS_PORTB + 0x14))
#define MGPIOB_LCKR         *((u32 *)(BASE_ADRESS_PORTB + 0x18))
 
/*   PORTC Register Definition */
#define MGPIOC_CRL          *((u32 *)(BASE_ADRESS_PORTC + 0x00))          
#define MGPIOC_CRH          *((u32 *)(BASE_ADRESS_PORTC + 0x04))
#define MGPIOC_IDR          *((u32 *)(BASE_ADRESS_PORTC + 0x08))
#define MGPIOC_ODR          *((u32 *)(BASE_ADRESS_PORTC + 0x0C))
#define MGPIOC_BSRR         *((u32 *)(BASE_ADRESS_PORTC + 0x10))
#define MGPIOC_BRR          *((u32 *)(BASE_ADRESS_PORTC + 0x14))
#define MGPIOC_LCKR         *((u32 *)(BASE_ADRESS_PORTC + 0x18))
 






#endif