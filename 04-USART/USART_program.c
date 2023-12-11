/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 20/4/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : USART_program.c  ****************/
/********************		Version  : 04      	        ****************/
/***********************************************************************/
/***********************************************************************/
//
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	
	MUSART1_BRR = BOUD_RATE_115200 ;
	
	/* 
	   1- enable Rx
	   2- enable Tx
	   3- enable USART 
	*/
	SET_BIT(MUSART1_CR1,2);
	SET_BIT(MUSART1_CR1,3);
	SET_BIT(MUSART1_CR1,13);
	/* 
      Clear Status rejester 
	*/
	MUSART1_SR = 0 ;
	
}
/*
void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0 ;
	while(arr[i] !='\0')
	{
		MUSART1_DR = arr[i] ;
		/* Wait till transmission complete
		
		while(GET_BIT(MUSART_SR,6)==0);
		i++ ;
	}
}
*/
void MUSART1_vidSendTextSynch   (u8 * pu8TextDataToSend)
{
	u8 Loc_u8Counter=0;
	
	while (pu8TextDataToSend[Loc_u8Counter] != '\0')
	{
		MUSART1_vidSendSynch(&pu8TextDataToSend[Loc_u8Counter]);
		Loc_u8Counter++;
	}
}


void MUSART1_vidSendSynch     (u8 * pu8DatatoSend)
{
	/*Write the Data To the Transmit Buffer*/
	MUSART1_DR = * pu8DatatoSend;
	/*wait until the trnsission complete*/
	while ( GET_BIT(MUSART1_SR,6) ==0  );          
}
/*u8 MUSART1_u8Receive(void)
{
	u8 Local_u8ReceiveData = 0;
	u16 Local_Timeout = 0;
	/* Wait till Receive complete
	while(GET_BIT(MUSART_SR,5) == 0 );
	{
		Local_Timeout++;
		if(Local_Timeout == 10000)
		{
			Local_u8ReceiveData= 255 ;
			break ;
		}
	}
	if(Local_u8ReceiveData==0)
	{
    Local_u8ReceiveData = (0xFF&(MUSART1_DR)) ;
	}
	
	return (Local_u8ReceiveData) ; 
}
*/

void MUSART1_vidReceiveSynch(u8 * pu8ReceivedData,u32 Copy_u32timeout)
{
	u32 Loc_u8TimeOut=0;
	
	/* Make Sure that the Content is Received Buffer*/
	while (GET_BIT(MUSART1_SR,5)==0)		 //This flag is set when receive buffer is not empty(valid data is received)
	{
		Loc_u8TimeOut++;
		if (Loc_u8TimeOut == Copy_u32timeout)
		{
			*pu8ReceivedData = 255;         //the max. value at ASCI table is 127, so if it returned with 255, that mean the time is up without an answer
			break;
		}				
	}
	if (Loc_u8TimeOut != Copy_u32timeout)
	{
		*pu8ReceivedData= MUSART1_DR;
	}
}