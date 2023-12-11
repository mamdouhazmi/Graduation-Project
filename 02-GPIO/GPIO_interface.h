/***********************************************************************/
/***********************************************************************/
/********************		Author   : Mamdouh Azmi		****************/
/********************       Date     : 22/1/2022        ****************/
/********************		SWC      : MCAL_Blue_Pill   ****************/
/********************		SWC_TYPE : GPIO_interface.h ****************/
/********************		Version  : 03      	        ****************/
/***********************************************************************/
/***********************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


/*****************************************************************/
/******                        Functions                    ******/
/*****************************************************************/

/* Choose a specific Pin to Set its Mode */
void MGPIO_vidSetPinDir    (u8 cpy_u8PortX ,u8 cpy_u8PinX  , u8 cpy_u8Mode );

/* Put a Value (HIGH/LOW) on a specific output pin */
void MGPIO_vidSetPinValue  (u8 cpy_u8PortX , u8 cpy_u8PinX  , u8 cpy_u8Value);

/* Put a Value (HIGH/LOW) on a specific output PORT */
void MGPIO_vidSetPortValue  (u8 cpy_u8PortX  , u16 cpy_u8Value);

/* Read a Value (HIGH/LOW) From a specific input pin */
u8   MGPIO_u8GetPinValue   (u8 cpy_u8PortX , u8 cpy_u8PinX );




/*****************************************************************/
/******                Function's parameters                ******/
/*****************************************************************/

/* Choose Port   */
#define MGPIOA             0
#define MGPIOB             1
#define MGPIOC             2

/* Choose Pin Number  */ 
#define MGPIO_PIN00        0
#define MGPIO_PIN01        1
#define MGPIO_PIN02        2
#define MGPIO_PIN03        3
#define MGPIO_PIN04        4
#define MGPIO_PIN05        5
#define MGPIO_PIN06        6
#define MGPIO_PIN07        7
#define MGPIO_PIN08        8
#define MGPIO_PIN09        9
#define MGPIO_PIN10        10
#define MGPIO_PIN11        11
#define MGPIO_PIN12        12
#define MGPIO_PIN13        13
#define MGPIO_PIN14        14
#define MGPIO_PIN15        15

/* Choose Value*/
#define MGPIO_LOW          0
#define MGPIO_HIGH         1
#define MGPIO_TOG          2



/****    choose  Pin Config & Modes      ****/
/* INPUT Config */
#define MGPIO_MODE_IN_ANALOG     0b0000
#define MGPIO_MODE_IN_FLOATING   0b0100
#define MGPIO_MODE_IN_PULL       0b1000


/* OUTPUT 10 MHZ  Mode Configurations */
#define MGPIO_MODE_10MHZ_OUT_PP        0b0001
#define MGPIO_MODE_10MHZ_OUT_OD        0b0101
#define MGPIO_MODE_10MHZ_OUT_AF_PP     0b1001
#define MGPIO_MODE_10MHZ_OUT_AF_OD     0b1101
          
/* OUTPUT 50 MHZ  Mode Configurations */
#define MGPIO_MODE_50MHz_OUT_PP        0b0011
#define MGPIO_MODE_50MHz_OUT_OD        0b0111
#define MGPIO_MODE_50MHz_OUT_AF_PP     0b1011
#define MGPIO_MODE_50MHz_OUT_AF_OD     0b1111

/* OUTPUT 2  MHZ  Mode Configurations */
#define MGPIO_MODE_2MHz_OUT_PP        0b0010
#define MGPIO_MODE_2MHz_OUT_OD        0b0110
#define MGPIO_MODE_2MHz_OUT_AF_PP     0b1010
#define MGPIO_MODE_2MHz_OUT_AF_OD     0b1110








#endif
