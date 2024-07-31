/*
 * @file   		DIO_program.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		18 AUG 2023
 * @MC          STM32F103x
 * @brief       this file has the implementation of interface file
 */

#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"

#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/DIO/DIO_private.h"
#include "../Inc/MCAL/DIO/DIO_config.h"

void MDIO_INIT(uint8 copy_uint8Port){
			MRCC_voidInitClock();
			MRCC_voidEnableClock(RCC_APB2,copy_uint8Port+2);
}
void MDIO_voidSetDirection(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Mode){

	switch (copy_uint8Port){
		case PORTA:
			if(copy_uint8Pin<8){
				GPIOA_CRL &= ~((0b1111)<<(copy_uint8Pin*4));
				GPIOA_CRL |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			else if(copy_uint8Pin<16){
				copy_uint8Pin -=8;
				GPIOA_CRH &= ~((0b1111)<<(copy_uint8Pin*4));
			    GPIOA_CRH |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			if(copy_uint8Mode == INPUT_PULL_DOWN){
			    CLR_BIT(GPIOA_ODR,copy_uint8Pin);
			}
			else if(copy_uint8Mode == INPUT_PULL_UP){
				SET_BIT(GPIOA_ODR,copy_uint8Pin);
			}
			break;
		case PORTB:
			if(copy_uint8Pin<8){
				GPIOB_CRL &= ~((0b1111)<<(copy_uint8Pin*4));
				GPIOB_CRL |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			else if(copy_uint8Pin<16){
				copy_uint8Pin -=8;
				GPIOB_CRH &= ~((0b1111)<<(copy_uint8Pin*4));
			    GPIOB_CRH |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			if(copy_uint8Mode == INPUT_PULL_DOWN){
				CLR_BIT(GPIOB_ODR,copy_uint8Pin);
			}
			else if(copy_uint8Mode == INPUT_PULL_UP){
				SET_BIT(GPIOB_ODR,copy_uint8Pin);
			}
			break;
		case PORTC:
			if(copy_uint8Pin<8){
				GPIOC_CRL &= ~((0b1111)<<(copy_uint8Pin*4));
				GPIOC_CRL |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			else if(copy_uint8Pin<16){
				copy_uint8Pin -=8;
     			GPIOC_CRH &= ~((0b1111)<<(copy_uint8Pin*4));
			    GPIOC_CRH |= ((copy_uint8Mode)<<(copy_uint8Pin*4));
			}
			if(copy_uint8Mode == INPUT_PULL_DOWN){
			   CLR_BIT(GPIOC_ODR,copy_uint8Pin);
			}
			else if(copy_uint8Mode == INPUT_PULL_UP){
				SET_BIT(GPIOC_ODR,copy_uint8Pin);
			}
			break;
	}
}

void MDIO_voidWrite_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin, uint8 copy_uint8Value){
	switch(copy_uint8Port){
		case PORTA:
				if(copy_uint8Value == HIGH){
					SET_BIT(GPIOA_ODR,copy_uint8Pin);
				}
				else if(copy_uint8Value == LOW){
					CLR_BIT(GPIOA_ODR,copy_uint8Pin);
				}
		break;
		case PORTB:
				if(copy_uint8Value == HIGH){
					SET_BIT(GPIOB_ODR,copy_uint8Pin);
				}
				else if(copy_uint8Value == LOW){
					CLR_BIT(GPIOB_ODR,copy_uint8Pin);
				}
		break;
		case PORTC:
			if(copy_uint8Value == HIGH){
					SET_BIT(GPIOC_ODR,copy_uint8Pin);
			}
			else if(copy_uint8Value == LOW){
					CLR_BIT(GPIOC_ODR,copy_uint8Pin);
			}
		break;
	}
}

uint8 MDIO_uint8Read_D_pin(uint8 copy_uint8Port,uint8 copy_uint8Pin){
	switch(copy_uint8Port){
	case PORTA:
		return GET_BIT(GPIOA_IDR,copy_uint8Pin);
		break;
	case PORTB:
		return GET_BIT(GPIOB_IDR,copy_uint8Pin);
		break;
	case PORTC:
		return GET_BIT(GPIOC_IDR,copy_uint8Pin);
		break;
	}
	return 0;
}

void  MDIO_voidSET_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin){
	switch(copy_uint8Port){
	case PORTA:
		GPIOA_BSRR = copy_uint32pin;
		break;
	case PORTB:
		GPIOB_BSRR = copy_uint32pin;
		break;
	case PORTC:
		GPIOC_BSRR = copy_uint32pin;
		break;
	}
}
void  MDIO_voidCLR_NRMR_pin(uint8 copy_uint8Port,uint32 copy_uint32pin){
	switch(copy_uint8Port){
		case PORTA:
			GPIOA_BRR = copy_uint32pin;
			break;
		case PORTB:
			GPIOB_BRR = copy_uint32pin;
			break;
		case PORTC:
			GPIOC_BRR = copy_uint32pin;
			break;
		}
}
