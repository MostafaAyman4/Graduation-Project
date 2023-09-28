/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 20 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MNVIC_interface.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"

void MNVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber){
    if(Copy_uint8IntNumber>= 0 && Copy_uint8IntNumber <32){
        NVIC_ISER0 = (1<<Copy_uint8IntNumber);
    }
    else if(Copy_uint8IntNumber>=32 && Copy_uint8IntNumber<=59){
        Copy_uint8IntNumber -= 32;
        NVIC_ISER1 = (1<<Copy_uint8IntNumber);
    }
}
void MNVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber){
    if(Copy_uint8IntNumber>= 0 && Copy_uint8IntNumber <32){
        NVIC_ICER0 = (1<<Copy_uint8IntNumber);
    }
    else if(Copy_uint8IntNumber>=32 && Copy_uint8IntNumber<=59){
        Copy_uint8IntNumber -= 32;
        NVIC_ICER1 = (1<<Copy_uint8IntNumber);
    }
}
void MNVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber){
    if(Copy_uint8IntNumber>= 0 && Copy_uint8IntNumber <32){
        NVIC_ISPR0 = (1<<Copy_uint8IntNumber);
    }
    else if(Copy_uint8IntNumber>=32 && Copy_uint8IntNumber<=59){
        Copy_uint8IntNumber -= 32;
        NVIC_ISPR1 = (1<<Copy_uint8IntNumber);
    }
}
void MNVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber){
    if(Copy_uint8IntNumber>= 0 && Copy_uint8IntNumber <32){
        NVIC_ICPR0 = (1<<Copy_uint8IntNumber);
    }
    else if(Copy_uint8IntNumber>=32 && Copy_uint8IntNumber<=59){
        Copy_uint8IntNumber -= 32;
        NVIC_ICPR1 = (1<<Copy_uint8IntNumber);
    }
}
uint8 MNVIC_uint8GetActiveFlag(uint8 Copy_uint8IntNumber){
    if(Copy_uint8IntNumber>= 0 && Copy_uint8IntNumber <32){
        return GET_BIT(NVIC_IABR0,Copy_uint8IntNumber);
    }
    else if(Copy_uint8IntNumber>=32 && Copy_uint8IntNumber<=59){
        Copy_uint8IntNumber -= 32;
        return GET_BIT(NVIC_IABR1,Copy_uint8IntNumber);
    }
}
void MNVIC_voidSetPeriorty(uint8 Copy_uint8IdInt,uint8 Copy_uint8group_periorty, uint8 Copy__uint8sub_perioty){
    SCB_AIRCR = PERIORY_BITS_DIV;
    if(Copy_uint8IdInt>=0){
    //NVIC_IPR[Copy_uint8IdInt]=((Copy__uint8sub_perioty|(Copy_uint8group_periorty<<((PERIORY_BITS_DIV-0X05FA0300)/256)))<<4);
    *(NVIC_IPR+Copy_uint8IdInt)=((Copy__uint8sub_perioty|(Copy_uint8group_periorty<<((PERIORY_BITS_DIV-0X05FA0300)/256)))<<4);
    }
}
