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
uint8 SPI_transmit(uint8 Copy_uint8SPINo , uint8 *copy_uint8SendData, uint16 size);
uint16 MSPI_uint16EnableTranceive (uint8 Copy_uint8SPINo , uint16 Copy_uint16SendData);
#endif
