/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F103C8T6                              */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
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
void MSPI_voidInit(uint8 Copy_uint8SPINo){
	SPI1->CR1 = 0x037F;

}
/*void MSPI_voidInit(uint8 Copy_uint8SPINo){
    switch (Copy_uint8SPINo)
    {
    case SPI_1:
            #if SPI1_MODE == MASTER
            //set baud rate
            SPI1->CR1 |= (SPI1_BAUDRATE<<3);
            //set clock level
            SET_BIT(SPI1->CR1,1);
            //set clock phase
            SET_BIT(SPI1->CR1,0);
            //set data length
            SPI1->CR1 |= (SPI1_DATA_FRAME_SIZE<<11);
            //set LSB first
            SET_BIT(SPI1->CR1,7);
            //enable spi1
            SET_BIT(SPI1->CR1,6);
            //set master mode
            SET_BIT(SPI1->CR1,2);
             #elif SPI1_MODE == SLAVE
             //set clock level
            CLR_BIT(SPI1->CR1,1);
            //set clock phase
            CLR_BIT(SPI1->CR1,0);
            //set data length
            SPI1->CR1 |= (SPI1_BAUDRATE<<11);
            //set LSB first
            SET_BIT(SPI1->CR1,7);
            //set SLAVE mode
            CLR_BIT(SPI1->CR1,2);

    #endif
        break;
    case SPI_2:
            #if SPI2_MODE == MASTER

            #elif SPI2_MODE == SLAVE

    #endif
        break;
    }

    }*/
uint32 MSPI_uint32EnableTranceive(uint8 Copy_uint8SPINo,uint32 Copy_uint32SendData){
    uint32 Local_uint32RecData=0;
    switch (Copy_uint8SPINo)
    {
    case SPI_1:
      #if  SPI1_MODE == MASTER

        //move data to data register
        SPI1->DR = 'A';
        while(GET_BIT(SPI1->SR,7)==1);
        /*//wait the transmition process
        while(GET_BIT(SPI1->SR,1)==0);
        //wait the receiving to complete
        while(GET_BIT(SPI1->SR,0)==0);*/
        Local_uint32RecData = SPI1->DR;
        //disable spi1
        CLR_BIT(SPI1->CR1,6);
        return Local_uint32RecData;
        #elif SPI1_MODE == SLAVE
        //enable spi1
        SET_BIT(SPI2->CR1,6);
        //wait the spi to be busy
        while(GET_BIT(SPI1->SR,7)==0);
        //move data to data register
        SPI2->DR=Copy_uint32SendData;
        //wait the transmition process
        while(GET_BIT(SPI2->SR,1)==0);
        //wait the receiving to complete
        while(GET_BIT(SPI2->SR,0)==0);
        Local_uint32RecData = SPI2->DR;
        //disable spi1
        CLR_BIT(SPI2->CR1,6);
        return Local_uint32RecData;

    #endif
        break;
    case SPI_2:
      #if  SPI2_MODE == MASTER
        //move data to data register
        SPI2->DR=Copy_uint32SendData;
        //enable spi1
        SET_BIT(SPI2->CR1,6);
        //wait the transmition process
        while(GET_BIT(SPI2->SR,1)==0);
        //wait the receiving to complete
        while(GET_BIT(SPI2->SR,0)==0);
        Local_uint32RecData = SPI2->DR;
        //disable spi1
        CLR_BIT(SPI2->CR1,6);
        return Local_uint32RecData;
        
        #elif SPI2_MODE == SLAVE
        
        #endif
        break;
    }

}
