/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 16 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/*
BAUD RATE 9600 -->
					DIV=2
					MANTISA=52
BAUD RATE 115200-->
					DIV=6
					MANTISA=4
					*/
#define USART1_BAUDRATE_DIV                 6
#define USART1_BAUDRATE_MANTISA             4

#define USART2_BAUDRATE_DIV                 6
#define USART2_BAUDRATE_MANTISA             4

#define USART3_BAUDRATE_DIV                 2
#define USART3_BAUDRATE_MANTISA             52

#endif
