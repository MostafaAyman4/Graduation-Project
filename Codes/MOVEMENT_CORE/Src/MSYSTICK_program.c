/*
 * @file   		MSYSTICK_program.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		26 AUG 2023
 * @MC          STM32F103x
 * @brief        this file has the implementation of interface file
 */

#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/SYSTIC/MSYSTICK_interface.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_private.h"
#include "../Inc/MCAL/SYSTIC/MSYSTICK_config.h"

uint32 Global_ORIGINAL_TICKS =0;
uint8 Global_uint8PeriodicCheckBit = 0;
void MSYSTICK_voidInit(void){
    #if  SYSTICK_CLOCK_SOURCE == AHB
    SET_BIT(STK_CTRL,2);
    #elif SYSTICK_CLOCK_SOURCE == AHB_BY_8
    CLR_BIT(STK_CTRL,2);
    #else
        #error("You chosed wrong SYSTICK_CLOCK_SOURCE ")
    #endif
    #if SYSTICK_INT_EN == ENABLE
            SET_BIT(STK_CTRL,1);
    #elif SYSTICK_INT_EN ==DISABLE
            CLR_BIT(STK_CTRL,1);
    #else
        #error("You chosed wrong SYSTICK_INT_ENALBE ")
    #endif
}
void MYSYSTICK_voidSet_BusyWait(uint32 Copy_uint32Ticks){
    STK_LOAD = Copy_uint32Ticks;
    SET_BIT(STK_CTRL,0);
    while(GET_BIT(STK_CTRL,16) == 0);
}
void MSYSTICK_voidSetIntervalSingle(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void)){
    Global_ORIGINAL_TICKS = Copy_uint32Ticks ;
    SET_BIT(STK_CTRL,0);
    /*RUN THE FUNCTION WHICH YOU WILL GET FROM PARAMTER*/
    Callback_function = Copy_ptr;
}
void MSYSTICK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void)){
    Global_uint8PeriodicCheckBit = 1;
    //make sureof the while condition because it run at least once before return to check
    while(Global_uint8PeriodicCheckBit == 1){
    Global_ORIGINAL_TICKS = Copy_uint32Ticks ;
    SET_BIT(STK_CTRL,0);
    /*RUN THE FUNCTION WHICH YOU WILL GET FROM PARAMTER*/
    Callback_function = Copy_ptr;
    SET_BIT(STK_CTRL,0);
    }
}
void MSYSTICK_voidStopInterval(void){
    Global_uint8PeriodicCheckBit = 0;
}
uint32 MSYSTICK_uint32GetElapsedTime(void){
	uint32 Local_uint32us=(STK_VAL)*((float)(1000000.0/SYSTICK_CLOCK));
    return Local_uint32us;
}
uint32 MSYSTICK_uint32GetRemainingTime(void){
	uint32 Local_uint32us=(Global_ORIGINAL_TICKS - STK_VAL)*((float)(1000000.0/SYSTICK_CLOCK));
    return Local_uint32us;
}
void MSYSTICK_voidDelay_MS(uint32 Copy_uint8MS){
	Copy_uint8MS = (Copy_uint8MS*(SYSTICK_CLOCK/1000));
		MYSYSTICK_voidSet_BusyWait(Copy_uint8MS);
}
void MSYSTICK_voidDelay_uS(uint32 Copy_uint32uS){
	Copy_uint32uS = (Copy_uint32uS*(SYSTICK_CLOCK/1000000));
	MYSYSTICK_voidSet_BusyWait(Copy_uint32uS);
}
/*void SysTick_Handler(void){
    Callback_function();
}
*/
