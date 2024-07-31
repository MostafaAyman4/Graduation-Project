/*
 * @file   		MNVIC_config.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		20 AUG 2023
 * @MC          STM32F103x
 * @brief       this file is used to set NVIC configuration
 */

/*define to prevent recursive inclusion*/
#ifndef    MNVIC_CONFIG_H
#define    MNVIC_CONFIG_H

/*
 * 		@ref PERIORY_BITS_DIV
 */
#define PERIOTY_4B_GROUP_0B_SUB       0X05FA0300
#define PERIOTY_3B_GROUP_2B_SUB       0X05FA0400
#define PERIOTY_2B_GROUP_2B_SUB       0X05FA0500
#define PERIOTY_1B_GROUP_3B_SUB       0X05FA0600
#define PERIOTY_0B_GROUP_4B_SUB       0X05FA0700


#define PERIORY_BITS_DIV              PERIOTY_3B_GROUP_2B_SUB  /*<! this MICRO can be a value of @ref PERIORY_BITS_DIV */




#endif
