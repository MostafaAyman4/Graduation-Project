/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
    volatile uint32 IMR;
    volatile uint32 EMR;
    volatile uint32 RTSR;
    volatile uint32 FTSR;
    volatile uint32 SWIER;
    volatile uint32 PR;
}EXTI_t;

#define             EXTI         ((volatile EXTI_t*)0x40010400)

#endif
