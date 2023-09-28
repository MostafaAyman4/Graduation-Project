/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*                      EXTI_PINS_OPTIONS                   */
#define     PA0              0
#define     PA1              1
#define     PA2              2
#define     PA3              3
#define     PA4              4
#define     PA5              5
#define     PA6              6
#define     PA7              7
#define     PA8              8
#define     PA9              9
#define     PA10             10
#define     PA11             11
#define     PA12             12
#define     PA13             13
#define     PA14             14
#define     PA15             15

#define     PB0              20
#define     PB1              21
#define     PB2              22
#define     PB3              23
#define     PB4              24
#define     PB5              25
#define     PB6              26
#define     PB7              27
#define     PB8              28
#define     PB9              29
#define     PB10             30
#define     PB11             31
#define     PB12             32
#define     PB13             33
#define     PB14             34
#define     PB15             35

#define     PC13             53
#define     PC14             54
#define     PC15             55

/*                        EVENT OPTIONS                         */
#define RISING_ENGE          0
#define FALLING_EDGE         1
#define ON_CHANGE            2

void MEXTI_voidInit(uint8 Copy_uint8EXTINo,uint8 Copy_uint8Event);
void MEXTI_voidEnable(uint8 Copy_uint8EXTINo);
void MEXTI_voiddisable(uint8 Copy_uint8EXTINo);
void MEXTI_voidTriggerSW(uint8 Copy_uint8EXTINo);

#endif
