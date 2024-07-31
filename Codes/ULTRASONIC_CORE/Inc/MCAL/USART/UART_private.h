/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 16 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define     UE_BIT          13
#define     M_BIT           12
#define     TE_BIT          3
#define     RE_BIT          2
#define     TXE_FLAG        7
#define     RXNE_FLAG       5
#define     TC_FLAG          6

typedef struct{
    volatile uint32 SR;
    volatile uint32 DR;
    volatile uint32 BRR;
    volatile uint32 CR1;
    volatile uint32 CR2;
    volatile uint32 CR3;
    volatile uint32 GTPR;
}UART_t;

#define USART1     ((volatile UART_t*)0x40013800)
#define USART2     ((volatile UART_t*)0x40004400)
#define USART3     ((volatile UART_t*)0x40004800)

#endif
