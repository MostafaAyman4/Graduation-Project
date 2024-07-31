/*
 * @file   		MSYSTICK_config.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		26 AUG 2023
 * @MC          STM32F103x
 * @brief       this file be used for setting configurations
 */

/*define to prevent recursive inclusion*/
#ifndef MSYSTICK_CONFIG_H
#define MSYSTICK_CONFIG_H


/*        @ref SYSTICK_CLOCK_SOURCE
    AHB
    AHB_BY_8
 */
#define SYSTICK_CLOCK_SOURCE        AHB			/*<! this MICRO can be a value of @ref SYSTICK_CLOCK_SOURCE*/

/*        @ref SYSTICK_INT_EN
    ENABLE
    DISABLE
*/
#define SYSTICK_INT_EN                DISABLE	/*<! this MICRO can be a value of @ref SYSTICK_INT_EN*/




#define SYSTICK_CLOCK                   8000000		/*<! this micro MUST be set to the SYSTICK_CLOCK_SOURCE takes integer values*/


#endif
