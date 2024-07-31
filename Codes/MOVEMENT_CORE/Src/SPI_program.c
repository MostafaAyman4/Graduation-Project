/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F103C8T6                              */
/***********************************************************/
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/SPI/SPI_interface.h"
#include "../Inc/MCAL/SPI/SPI_private.h"
#include "../Inc/MCAL/SPI/SPI_config.h"
/******************
 * note initiate has two functions
 * note data sended not from parameter
 */
/******
 * main code
 * MRCC_voidInitClock();
	//MSYSTICK_voidInit();
	MRCC_voidEnableClock(RCC_APB2,SPI1_EN);

	MDIO_INIT(PORTA);
	MDIO_voidSetDirection(PORTA ,2 ,OUTPUT_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTA ,5 ,AF_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTA ,7 ,AF_10MHZ_PUSH_PULL);
	MDIO_voidSetDirection(PORTA ,6 ,INPUT_FLOATING);

	MSPI_voidInit(SPI_1);
	MDIO_voidWrite_D_pin(PORTA,2, LOW);
	MSPI_uint32EnableTranceive(SPI_1,0X5555);
	MDIO_voidWrite_D_pin(PORTA,2, HIGH);
 */
/*void MSPI_voidInit(uint8 Copy_uint8SPINo){
	SPI1->CR1 = 0x037F;

}*/
void MSPI_voidInit(uint8 Copy_uint8SPINo){
	switch(Copy_uint8SPINo){
	case SPI_1:

		//SET PHASE AND IDLE STATE
		CLR_BIT(SPI1->CR1,CPOL);
		CLR_BIT(SPI1->CR1,CPHA);

#if  SPI1_DATA_DIRECTION == LSB
		SET_BIT(SPI1->CR1,LSBFIRST);
#elif	SPI1_DATA_DIRECTION == MSB
		CLR_BIT(SPI1->CR1,LSBFIRST);
#endif


#if  SPI1_DATA_FRAME_SIZE == ONE_BYTES
		CLR_BIT(SPI1->CR1,DFF);
#elif SPI1_DATA_FRAME_SIZE ==TWO_BYTES
		SET_BIT(SPI1->CR1,DFF);
#endif

		SET_BIT(SPI1->CR1,SSM);
		SET_BIT(SPI1->CR1,SS1);

		//FULLDUPLEX
		CLR_BIT(SPI1->CR1,RXONLY);

        //set baud rate
        SPI1->CR1 |= (SPI1_BAUDRATE<<3);

#if  SPI1_MODE ==  MASTER
        SET_BIT(SPI1->CR1,MSTR);
#elif  SPI1_MODE== SLAVE
        CLR_BIT(SPI1->CR1,MSTR);
#endif
        SET_BIT(SPI1->CR1,SPE);
		break;
	case SPI_2:
		break;
	}
}
uint8 SPI_transmit(uint8 Copy_uint8SPINo , uint8 *copy_uint8SendData, uint16 size){
	uint16 initial_TxXferCount= size;
	uint16 TxXferCount = size;
	uint8 *Local_uint8PtrData ;
	Local_uint8PtrData = copy_uint8SendData;
	while (GET_BIT(SPI1->SR , TXE) == 0);

	if(initial_TxXferCount == 1)
	{
		*((uint8 volatile *)0x4001300C) = *Local_uint8PtrData ;
		Local_uint8PtrData+=sizeof(uint8);
		TxXferCount--;
	}

	while(TxXferCount>0)
	{
		if (GET_BIT ( SPI1->SR , TXE) == 1)
		{
			*((uint8 volatile *)0x4001300C) = *Local_uint8PtrData ;
			Local_uint8PtrData+=sizeof(uint8);
			TxXferCount--;
		}
	}
	return *((uint8 volatile *)0x4001300C);
}

uint16 MSPI_uint16EnableTranceive (uint8 Copy_uint8SPINo , uint16 Copy_uint16SendData){
	switch(Copy_uint8SPINo){
	case SPI_1:
			/* Send data */
			SPI1->DR = Copy_uint16SendData ;
			/* Wait till finish transmission */
			while (GET_BIT ( SPI1-> SR  , TXE) == 0);
			while (GET_BIT ( SPI1-> SR, RXNE) == 0);
			/* Return data data */
			return  SPI1->DR ;
		break;
	case SPI_2:
		break;
}
}
