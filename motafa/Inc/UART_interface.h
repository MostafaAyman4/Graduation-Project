/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 16 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define  USART_1            0
#define  USART_2            1
#define  USART_3            2
/*
 * TX1->A9
 * RX1->A10
 *
 * TX2->A2
 * RX2->A3
 *
 * TX3->B10
 * RX3->B11
 *
 */
void MUSART_voidInit(uint8 Copy_uint8USARTNo);
void MUSART_voidSendByte(uint8 Copy_uint8USARTNo,uint8 Copy_uint8Data);
void MUSART_voidSendWord(uint8 Copy_uint8USARTNo, uint8 *Copyuint8String);
uint8 MUSART_uint8ReceiveByte(uint8 Copy_uint8USARTNo);


#endif
