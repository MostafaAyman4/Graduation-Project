/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "MNVIC_interface.h"

#include "AFIO_interface.h"


void MEXTI_voidInit(uint8 Copy_uint8EXTINo,uint8 Copy_uint8Event){
    MAFIO_voidInitAFIO();
    if(Copy_uint8EXTINo < 20){
        /*Port A*/
        /*AFIO initiate*/
        MAFIO_voidSetEXTIConfiguration(PORTA_AFIO,Copy_uint8EXTINo);
        /*NVIC initiate*/
        if(Copy_uint8EXTINo == 0){
            MNVIC_voidEnableInterrupt(EXTI0_INT_NO);
        }
        else if(Copy_uint8EXTINo == 1){
            MNVIC_voidEnableInterrupt(EXTI1_INT_NO);
        }
        else if(Copy_uint8EXTINo == 2){
            MNVIC_voidEnableInterrupt(EXTI2_INT_NO);
        }
        else if(Copy_uint8EXTINo == 3){
            MNVIC_voidEnableInterrupt(EXTI3_INT_NO);
        }
        else if(Copy_uint8EXTINo == 4){
            MNVIC_voidEnableInterrupt(EXTI4_INT_NO);
        }
        else if(Copy_uint8EXTINo < 10){
            MNVIC_voidEnableInterrupt(EXTI9_5_INT_NO);
        }
        else if(Copy_uint8EXTINo < 16){
            MNVIC_voidEnableInterrupt(EXTI15_10_INT_NO);
        }
        else{
            /*waring wrong interrupt input for nvic selection*/
        }
        /*Interrupt set periorty*/
        switch(Copy_uint8Event){
            case RISING_ENGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            break;
            case FALLING_EDGE:
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);
            break;
            case ON_CHANGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);   
            break;
        }
    }
    else if(Copy_uint8EXTINo < 40){
        /*Port B*/
        Copy_uint8EXTINo -= 20;
        /*AFIO initiate*/
        MAFIO_voidSetEXTIConfiguration(PORTB_AFIO ,Copy_uint8EXTINo);
        /*Interrupt set periorty*/
        switch(Copy_uint8Event){
            case RISING_ENGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            break;
            case FALLING_EDGE:
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);
            break;
            case ON_CHANGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);   
            break;
        }
    }
    else if(Copy_uint8EXTINo < 60){
        /*Port_C*/
        Copy_uint8EXTINo -= 40;
        /*AFIO initiate*/
        MAFIO_voidSetEXTIConfiguration(PORTC_AFIO,Copy_uint8EXTINo);
        /*Interrupt set periorty*/
        switch(Copy_uint8Event){
            case RISING_ENGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            break;
            case FALLING_EDGE:
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);
            break;
            case ON_CHANGE:
            SET_BIT(EXTI -> RTSR , Copy_uint8EXTINo);
            SET_BIT(EXTI -> FTSR , Copy_uint8EXTINo);   
            break;
        }
    }
    else{
        /*Waring wrong chose of pins*/
    }
}
void MEXTI_voidEnable(uint8 Copy_uint8EXTINo){
    if(Copy_uint8EXTINo < 20){
        /*Port A*/
        /*Interrupt mask register*/
        SET_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 40){
        /*Port B*/
        Copy_uint8EXTINo -= 20; 
        /*Interrupt mask register*/
        SET_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 60){
        /*Port_C*/
        Copy_uint8EXTINo -= 40;
        /*Interrupt mask register*/
        SET_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else{
        /*Waring wrong chose of pins*/
    }
}
void MEXTI_voiddisable(uint8 Copy_uint8EXTINo){
    if(Copy_uint8EXTINo < 20){
        /*Port A*/
        /*Interrupt mask register*/
        CLR_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 40){
        /*Port B*/
        Copy_uint8EXTINo -= 20; 
        CLR_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 60){
        /*Port_C*/
        Copy_uint8EXTINo -= 40;
        CLR_BIT(EXTI -> IMR , Copy_uint8EXTINo);
    }
    else{
        /*Waring wrong chose of pins*/
    }
}
void MEXTI_voidTriggerSW(uint8 Copy_uint8EXTINo){
    if(Copy_uint8EXTINo < 20){
        /*Port A*/
        SET_BIT(EXTI -> SWIER,Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 40){
        /*Port B*/
        Copy_uint8EXTINo -= 20; 
        SET_BIT(EXTI -> SWIER,Copy_uint8EXTINo);
    }
    else if(Copy_uint8EXTINo < 60){
        /*Port_C*/
        Copy_uint8EXTINo -= 40;
        SET_BIT(EXTI -> SWIER,Copy_uint8EXTINo);
    }
    else{
        /*Waring wrong chose of pins*/
    }
}
