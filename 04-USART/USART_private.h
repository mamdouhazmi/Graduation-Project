/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 20/4/2023        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : USEART_private.h ****************/
/********************		Version  : 04      	        ****************/
/***********************************************************************/
/***********************************************************************/
#ifndef   _USART_PRIVATE_H
#define   _USART_PRIVATE_H



#define  MUSART1      		*((volatile u32 *)0x40013800)
#define  MUSART1_SR   		*((volatile u32 *)0x40013800)
#define  MUSART1_DR   		*((volatile u32 *)0x40013804)
#define  MUSART1_BRR   		*((volatile u32 *)0x40013808)
#define  MUSART1_CR1   		*((volatile u32 *)0x4001380C)
#define  MUSART1_CR2   		*((volatile u32 *)0x40013810)
#define  MUSART1_CR3   		*((volatile u32 *)0x40013814)
#define  MUSART1_GTPR   	*((volatile u32 *)0x40013818)

#define BOUD_RATE_9600         0x341 

#define BOUD_RATE_115200        0x45 


#define MUSART1_ENABLE     1
#define MUSART1_DISABLE    0

#define MUSART1_EVEN       0
#define MUSART1_ODD        1













#endif 