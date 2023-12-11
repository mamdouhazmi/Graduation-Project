/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 20/4/2022        ****************/
/********************		SWC      : HALL_Blue_Pill   ****************/
/********************		SWC_TYPE : ESP_program.c    ****************/
/********************		Version  : 04      	        ****************/
/***********************************************************************/
/***********************************************************************/


//1- include liberary
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//2- include upper layers
#include "USART_interface.h"
#include "ESP_interface.h"

void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	while( Local_u8Result == 0)
	{
		/*	Echo disable */
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = Esp_u8ValidateCmd();
	}
	u8 Local_u8Result = 0;
	while(Local_u8Result == 0)
	{
		/*	Set station mode */
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = Esp_u8ValidateCmd();
	}
	while(Local_u8Result == 0)
	{
		MUSART1_voidTransmit("AT+CWJAP_CUR=\"WE_B3B3D4\",\"M0501047410\"\r\n");
		Local_u8Result = Esp_u8ValidateCmd();
	}
	while(Local_u8Result == 0)
	{
		MUSART1_voidTransmit("AT+CIPSEND=44\r\n");
		MUSART1_voidTransmit("GET http://yoriichi.freevar.com/status.txt");
		Local_u8Result = Esp_u8ValidateCmd();
	}
}
u8 Esp_u8ValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0 ;
	u8 Dumy = 0 ;
	u8 Result = 0 ;
	while(Dumy != 255)
	{
	  Dumy = MUSART1_u8Receive();
	  Local_u8Response[i]= Dumy ;
	  i++;
	}
	
	if(Local_u8Response[0]=='O' && Local_u8Response[0]=='K')
	{
		Result = 1 ;
	}
	return Result ;
}

