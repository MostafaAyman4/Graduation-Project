/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
    volatile uint32 EVCR;
    volatile uint32 MAPR;
    volatile uint32 EXTICR[4];
    volatile uint32 MAPR2;

}AFIO_t;

#define AFIO         ((volatile AFIO_t *) 0x40010000)


#endif
