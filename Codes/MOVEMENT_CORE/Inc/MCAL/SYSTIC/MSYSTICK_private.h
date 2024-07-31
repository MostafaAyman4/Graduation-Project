/*
 * @file   		MSYSTICK_interface.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		26 AUG 2023
 * @MC          STM32F103x
 * @brief       this file be used for user interface
 */

/*define to prevent recursive inclusion*/
#ifndef MSYSTICK_PRIVATE_H
#define MSYSTICK_PRIVATE_H

void (*Callback_function) (void);

/*						MICROS						*/
#define AHB             0
#define AHB_BY_8        1

#define  ENABLE                 1
#define DISABLE                 0

/*                  Register Definitions -assign addresses         */
#define SYSTICK_BASE_ADDRESS    0xE000E010
#define STK_CTRL                *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x00)
#define STK_LOAD                *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x04)
#define STK_VAL                 *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x08)
#define STK_CALIB               *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x0C)


#endif
