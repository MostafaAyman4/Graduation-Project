/*
 * @file   		RCC_private.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		20 AUG 2023
 * @MC          STM32F103x
 * @brief       this file is used to store NVIC private data
 */

/*define to prevent recursive inclusion*/
#ifndef    MNVIC_PRIVATE_H
#define    MNVIC_PRIVATE_H

/*                  Register Definitions -assign addresses         */
#define NVIC_BASE_ADDRESS   0xE000E100
#define SCB_BASE_ADDRESS    0xE000ED00

#define NVIC_ISER0          *(uint32 *)(NVIC_BASE_ADDRESS+0x000)
#define NVIC_ISER1          *(uint32 *)(NVIC_BASE_ADDRESS+0x004)

#define NVIC_ICER0          *(uint32 *)(NVIC_BASE_ADDRESS+0x080)
#define NVIC_ICER1          *(uint32 *)(NVIC_BASE_ADDRESS+0x084)

#define NVIC_ISPR0          *(uint32 *)(NVIC_BASE_ADDRESS+0x100)
#define NVIC_ISPR1          *(uint32 *)(NVIC_BASE_ADDRESS+0x104)

#define NVIC_ICPR0          *(uint32 *)(NVIC_BASE_ADDRESS+0x180)
#define NVIC_ICPR1          *(uint32 *)(NVIC_BASE_ADDRESS+0x184)

#define NVIC_IABR0          *(volatile uint32 *)(NVIC_BASE_ADDRESS+0x200)
#define NVIC_IABR1          *(volatile uint32 *)(NVIC_BASE_ADDRESS+0x204)

#define NVIC_IPR             (volatile uint8 *)(NVIC_BASE_ADDRESS+0x300)

#define SCB_AIRCR           *(volatile uint32 *)(SCB_BASE_ADDRESS+0x0C)


#endif
