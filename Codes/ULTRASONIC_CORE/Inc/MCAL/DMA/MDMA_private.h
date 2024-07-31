/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 28 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef    MDMA_PRIVATE_H
#define    MDMA_PRIVATE_H
typedef struct{
    volatile uint32 CCR;
    volatile uint32 CNDTR;
    volatile uint32 CPAR;
    volatile uint32 CMAR;
    volatile uint32 reserved;
}DMA_Channel;
#define DMA_C      ((volatile DMA_Channel*)0x40030000)
typedef struct{
    volatile uint32 ISR;
    volatile uint32 IFCR;
    DMA_Channel Channel[7];
}DMA_t;

#define DMA      ((volatile DMA_t*)0x40020000)

#endif
