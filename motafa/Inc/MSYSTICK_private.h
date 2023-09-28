/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 26 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef MSYSTICK_PRIVATE_H
#define MSYSTICK_PRIVATE_H

void (*Callback_function) (void);

#define AHB             0
#define AHB_BY_8        1

#define  ENABLE                 1
#define DISABLE                 0

#define SYSTICK_BASE_ADDRESS    0xE000E010
#define STK_CTRL                *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x00)
#define STK_LOAD                *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x04)
#define STK_VAL                 *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x08)
#define STK_CALIB               *(volatile uint32 *)(SYSTICK_BASE_ADDRESS + 0x0C)


#endif