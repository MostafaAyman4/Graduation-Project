/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"


#include "../Inc/MCAL/AFIO/AFIO_interface.h"
#include "../Inc/MCAL/AFIO/AFIO_private.h"
#include "../Inc/MCAL/AFIO/AFIO_config.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"

void MAFIO_voidInitAFIO(){
    MRCC_voidInitClock();
    MRCC_voidEnableClock(RCC_APB2,0);
}

void Mdisable_JTAG(void){
	AFIO->MAPR |= (1<<26);
}
void MAFIO_voidSetEXTIConfiguration(uint8 Copy_uint8Port,uint8 Copy_uint8Line){
    if(Copy_uint8Line < 4){
        AFIO -> EXTICR[0] &= ~((0b1111)<<(Copy_uint8Line * 4));
        AFIO -> EXTICR[0] |= (Copy_uint8Port<<(Copy_uint8Line * 4));
    }
    else if(Copy_uint8Line < 8){
        Copy_uint8Line -=4;
        AFIO -> EXTICR[1] &= ~((0b1111)<<(Copy_uint8Line * 4));
        AFIO -> EXTICR[1] |= (Copy_uint8Port<<(Copy_uint8Line * 4));
    }
    else if(Copy_uint8Line < 12){
        Copy_uint8Line -= 8;
        AFIO -> EXTICR[1] &= ~((0b1111)<<(Copy_uint8Line * 4));
        AFIO -> EXTICR[1] |= (Copy_uint8Port<<(Copy_uint8Line * 4));
    }
    else if(Copy_uint8Line < 16){
        Copy_uint8Line -= 12;
        AFIO -> EXTICR[1] &= ~((0b1111)<<(Copy_uint8Line * 4));
        AFIO -> EXTICR[1] |= (Copy_uint8Port<<(Copy_uint8Line * 4));
    }
    else{
        /* Waring Wrong chose of Line*/
    }
}
