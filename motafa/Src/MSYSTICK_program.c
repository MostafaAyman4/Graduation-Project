/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 26 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MSYSTICK_interface.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_private.h"

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
    return STK_VAL;
}
uint32 MSYSTICK_uint32GetRemainingTime(void){
    return Global_ORIGINAL_TICKS - STK_VAL;
}
void MSYSTICK_voidDelay_MS(uint8 Copy_uint8MS){
	MYSYSTICK_voidSet_BusyWait((uint32)(Copy_uint8MS*1000));
}
void MSYSTICK_voidDelay_uS(uint32 Copy_uint32uS){
	MYSYSTICK_voidSet_BusyWait(Copy_uint32uS);
}
void SysTick_Handler(void){
    Callback_function();
}
