/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 26 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef MSYSTICK_INTERFACE_H
#define MSYSTICK_INTERFACE_H


void MSYSTICK_voidInit(void);
void MYSYSTICK_voidSet_BusyWait(uint32 Copy_uint32Ticks);
void MSYSTICK_voidSetIntervalSingle(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void));
void MSYSTICK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void));
void MSYSTICK_voidStopInterval(void);
uint32 MSYSTICK_uint32GetElapsedTime(void);
uint32 MSYSTICK_uint32GetRemainingTime(void);
void MSYSTICK_voidDelay_MS(uint8 Copy_uint8MS);
void MSYSTICK_voidDelay_uS(uint32 Copy_uint32uS);

#endif