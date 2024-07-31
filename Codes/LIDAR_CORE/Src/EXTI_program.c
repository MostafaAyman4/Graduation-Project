/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 23 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32F10x                                  */
/***********************************************************/
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/EXTI/EXTI_interface.h"
#include "../Inc/MCAL/EXTI/EXTI_private.h"
#include "../Inc/MCAL/EXTI/EXTI_config.h"

#include "../Inc/MCAL/NVIC/MNVIC_interface.h"

#include "../Inc/MCAL/AFIO/AFIO_interface.h"

static void (*EXTI_LINE0_CALLBACK)(void);
static void (*EXTI_LINE1_CALLBACK)(void);
static void (*EXTI_LINE2_CALLBACK)(void);
static void (*EXTI_LINE3_CALLBACK)(void);
static void (*EXTI_LINE4_CALLBACK)(void);
static void (*EXTI_LINE5_CALLBACK)(void);
static void (*EXTI_LINE6_CALLBACK)(void);
static void (*EXTI_LINE7_CALLBACK)(void);
static void (*EXTI_LINE8_CALLBACK)(void);
static void (*EXTI_LINE9_CALLBACK)(void);

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

void MEXTI_voidSetCallback(uint8 A_uint8LineNo ,void (*A_voidfptr)(void)){

	switch(A_uint8LineNo){
	case 0:
		EXTI_LINE0_CALLBACK = A_voidfptr;
	break;
	case 1:
		EXTI_LINE1_CALLBACK = A_voidfptr;
	break;
	case 2:
		EXTI_LINE2_CALLBACK = A_voidfptr;
	break;
	case 3:
		EXTI_LINE3_CALLBACK = A_voidfptr;
	break;
	case 4:
		EXTI_LINE4_CALLBACK = A_voidfptr;
	break;
	case 5:
		EXTI_LINE5_CALLBACK = A_voidfptr;
	break;
	case 6:
		EXTI_LINE6_CALLBACK = A_voidfptr;
	break;
	case 7:
		EXTI_LINE7_CALLBACK = A_voidfptr;
	break;
	case 8:
		EXTI_LINE8_CALLBACK = A_voidfptr;
	break;
	case 9:
		EXTI_LINE9_CALLBACK = A_voidfptr;
	break;

	}
}

void EXTI0_IRQHandler(void){
	EXTI_LINE0_CALLBACK();
	SET_BIT(EXTI->PR, 0);
}
void EXTI1_IRQHandler(void){
	EXTI_LINE1_CALLBACK();
	SET_BIT(EXTI->PR, 1);
}
void EXTI2_IRQHandler(void){
	EXTI_LINE2_CALLBACK();
	SET_BIT(EXTI->PR, 2);
}
void EXTI3_IRQHandler(void){
	EXTI_LINE3_CALLBACK();
	SET_BIT(EXTI->PR, 3);
}
void EXTI4_IRQHandler(void){
	EXTI_LINE4_CALLBACK();
	SET_BIT(EXTI->PR, 4);
}
void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI->PR,5)==1)
	{
		EXTI_LINE5_CALLBACK();
		SET_BIT(EXTI->PR,5);
	}
	else if(GET_BIT(EXTI->PR,6)==1)
	{
		EXTI_LINE6_CALLBACK();
		SET_BIT(EXTI->PR,6);
	}
	else if(GET_BIT(EXTI->PR,7)==1)
	{
		EXTI_LINE7_CALLBACK();
		SET_BIT(EXTI->PR,7);
	}
	else if(GET_BIT(EXTI->PR,8)==1)
	{
		EXTI_LINE8_CALLBACK();
		SET_BIT(EXTI->PR,8);
	}
	else if(GET_BIT(EXTI->PR,9)==1)
	{
		EXTI_LINE9_CALLBACK();
		SET_BIT(EXTI->PR,9);
	}
	else
		{

		}
}
