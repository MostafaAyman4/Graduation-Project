/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F103C8T6                              */
/***********************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


#define  SPI_1          0
#define  SPI_2          1

void MSPI_voidInit(uint8 Copy_uint8SPINo);
uint32 MSPI_uint32EnableTranceive(uint8 Copy_uint8SPINo,uint32 Copy_uint32SendData);
#endif
