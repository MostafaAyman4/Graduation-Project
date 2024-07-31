/*
 * @file   		MSYSTICK_interface.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		26 AUG 2023
 * @MC          STM32F103x
 * @brief       this file be used for user interface
 */

/*define to prevent recursive inclusion*/
#ifndef MSYSTICK_INTERFACE_H
#define MSYSTICK_INTERFACE_H

/*####################### HOW TO USE THIS DRIVER ##########################
 * 			-configure the system clock peripheral clock source
 * 			-if u want to use interrupt enable it from config file
 * 			-use the delay u want by setting the interval
 * ########################################################################
 */

/*
 * @FUNC_name	MSYSTICK_voidInit(void)
 * @brief	this function initiate system timer and set configurations
 * @param   -NONE
 * @retval	NONE
 */
 /*
  * @FUNC_name	MYSYSTICK_voidSet_BusyWait(uint32 Copy_uint32Ticks)
  * @brief	this function is used to make a delay with system clock ticks and hold until ended
  * @param   -Copy_uint32Ticks
  * 				this variable take values from 0 to 16 777 216
  * @retval	NONE
  */
/*
 * @FUNC_name	MSYSTICK_voidSetIntervalSingle(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void))
 * @brief	this function initiate system timer to make an interrupt after a period of time- just one time
 * @param   -Copy_uint32Ticks
 * 				this variable is used to set the delay value in system timer ticks
 * 			-(*Copy_ptr)(void)
 * 				pass the function you want to excuted in interrupt
 * @retval	NONE
 */
/*
 * @FUNC_name	MSYSTICK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void))
 * @brief	this function initiate system timer to make an interrupt after a period of time- periodic
 * @param   -Copy_uint32Ticks
 * 				this variable is used to set the delay value in sustem timer ticks
 * 			-(*Copy_ptr)(void)
 * 				pass the function you want to excuted in interrupt
 * @retval	NONE
 */
/*
 * @FUNC_name	MSYSTICK_voidStopInterval(void)
 * @brief	this function is used to disable the sytem timer from running used in periodic interrupt delay
 * @param   -NONE
 * @retval	NONE
 */
/*
 * @FUNC_name	MSYSTICK_uint32GetElapsedTime(void)
 * @brief	this function is used to return the time that has passed in microseconds
 * @param   -NONE
 * @retval	uint32
 * 				return the elapsed time in microseconds
 */
/*
 * @FUNC_name	MSYSTICK_uint32GetRemainingTime(void)
 * @brief	this function is used to return the remaining time in microseconds
 * @param   -NONE
 * @retval	uint32
 * 				return the remaining time in microseconds
 */
 /*
  * @FUNC_name	MSYSTICK_voidDelay_MS(uint8 Copy_uint8MS)
  * @brief	this function is used to make a delay in milliseconds and hold until ended
  * @param   - Copy_uint8MS
  * 				this variable take values from 0 to max 2097 msec delay at 8MHZ
  * @retval	NONE
  */
 /*
  * @FUNC_name	MSYSTICK_voidDelay_uS(uint32 Copy_uint32uS)
  * @brief	this function is used to make a delay in microseconds and hold until ended
  * @param   -Copy_uint32uS
  * 				this variable take values from 0 to max 2 097 152 usec delay
  * @retval	NONE
  */
void MSYSTICK_voidInit(void);
void MYSYSTICK_voidSet_BusyWait(uint32 Copy_uint32Ticks);
void MSYSTICK_voidSetIntervalSingle(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void));
void MSYSTICK_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks,void (*Copy_ptr)(void));
void MSYSTICK_voidStopInterval(void);
uint32 MSYSTICK_uint32GetElapsedTime(void);
uint32 MSYSTICK_uint32GetRemainingTime(void);
void MSYSTICK_voidDelay_MS(uint32 Copy_uint8MS);
void MSYSTICK_voidDelay_uS(uint32 Copy_uint32uS);

#endif
