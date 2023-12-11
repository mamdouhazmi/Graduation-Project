/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 20/4/2023        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : USART_interface.h****************/
/********************		Version  : 04      	        ****************/
/***********************************************************************/
/***********************************************************************/
#ifndef   _USART_INTERFACE_H
#define   _USART_INTERFACE_H


void MUSART1_voidInit(void);
//void MUSART1_voidTransmit(u8 arr[]);
void MUSART1_vidSendTextSynch (u8 * pu8TextDataToSend);
void MUSART1_vidSendSynch     (u8 * pu8DataToSend);
//u8 MUSART1_u8Receive(void); 
void MUSART1_vidReceiveSynch(u8 * pu8ReceivedData,u32 Copy_u32timeout);








#endif 