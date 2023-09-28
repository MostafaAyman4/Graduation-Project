/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 16 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART_voidInit(uint8 Copy_uint8USARTNo){
    switch (Copy_uint8USARTNo)
    {
    case USART_1:
        //enable USART
        SET_BIT(USART1->CR1,UE_BIT);
        //set8 bit data
        CLR_BIT(USART1->CR1,M_BIT);
        //set Baud Rate
        USART1->BRR |= USART1_BAUDRATE_DIV;
        USART1->BRR |= (USART1_BAUDRATE_MANTISA<<4);
        break;
    case USART_2:
        //enable USART
        SET_BIT(USART2->CR1,UE_BIT);
        //set8 bit data
        CLR_BIT(USART2->CR1,M_BIT);
        //set Baud Rate
        USART2->BRR |= USART2_BAUDRATE_DIV;
        USART2->BRR |= (USART2_BAUDRATE_MANTISA<<4);
        break;
    case USART_3:
        //enable USART
        SET_BIT(USART3->CR1,UE_BIT);
        //set8 bit data
        CLR_BIT(USART3->CR1,M_BIT);
        //set Baud Rate
        USART3->BRR |= USART3_BAUDRATE_DIV;
        USART3->BRR |= (USART3_BAUDRATE_MANTISA<<4);
        break;
    }
}
void MUSART_voidSendByte(uint8 Copy_uint8USARTNo,uint8 Copy_uint8Data){
    switch (Copy_uint8USARTNo)
    {
    case USART_1:
        //enable Transmission
        SET_BIT(USART1->CR1,TE_BIT);
        //LOAD DATA
        USART1->DR=Copy_uint8Data;
        while(GET_BIT(USART1->SR,TC_FLAG)==0);
        //Disable Transmission
        SET_BIT(USART1->CR1,TE_BIT);
        break;
    case USART_2:
        //enable Transmission
        SET_BIT(USART2->CR1,TE_BIT);
        //LOAD DATA
        USART2->DR=Copy_uint8Data;
        while(GET_BIT(USART2->SR,TC_FLAG)==0);
        //Disable Transmission
        SET_BIT(USART2->CR1,TE_BIT);
        break;
    case USART_3:
        //enable Transmission
        SET_BIT(USART3->CR1,TE_BIT);
        //LOAD DATA
        USART3->DR=Copy_uint8Data;
        while(GET_BIT(USART3->SR,TC_FLAG)==0);
        //Disable Transmission
        SET_BIT(USART3->CR1,TE_BIT);
        break;
    }
}
uint8 MUSART_uint8ReceiveByte(uint8 Copy_uint8USARTNo){
	uint8 Local_data;
    switch (Copy_uint8USARTNo)
    {
    case USART_1:
    	//enable Transmission
    	        SET_BIT(USART1->CR1,RE_BIT);
    	        while(GET_BIT(USART1->SR,RXNE_FLAG)==0);
    	        Local_data = USART1->DR;
    	        CLR_BIT(USART1->CR1,RE_BIT);
        break;
    case USART_2:
    	//enable Transmission
    	        SET_BIT(USART2->CR1,RE_BIT);
    	        while(GET_BIT(USART2->SR,RXNE_FLAG)==0);
    	        Local_data = USART2->DR;
    	        CLR_BIT(USART2->CR1,RE_BIT);
        break;
    case USART_3:
    	//enable Transmission
    	        SET_BIT(USART3->CR1,RE_BIT);
    	        while(GET_BIT(USART3->SR,RXNE_FLAG)==0);
    	        Local_data = USART3->DR;
    	        CLR_BIT(USART3->CR1,RE_BIT);
        break;
    }
    return Local_data;
}
void MUSART_voidSendWord(uint8 Copy_uint8USARTNo,uint8 *Copyuint8String){
	uint8 i = 0;
	while (Copyuint8String[i] != '\0')
	{
		MUSART_voidSendByte(Copy_uint8USARTNo,Copyuint8String[i]);
		i++;
	}
}
