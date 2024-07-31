/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/*                     PORT OPTIONS                       */
#define PORTA_AFIO      0b0000
#define PORTB_AFIO      0b0001
#define PORTC_AFIO      0b0010

/*                     LINE OPTIONS                       */
#define LINE0           0
#define LINE1           1
#define LINE2           2
#define LINE3           3
#define LINE4           4
#define LINE5           5
#define LINE6           6
#define LINE7           7
#define LINE8           8
#define LINE9           9
#define LINE10          10
#define LINE11          11
#define LINE12          12
#define LINE13          13
#define LINE14          14
#define LINE15          15

void MAFIO_voidInitAFIO(void);
void MAFIO_voidSetEXTIConfiguration(uint8 Copy_uint8Port,uint8 Copy_uint8Line);


#endif
