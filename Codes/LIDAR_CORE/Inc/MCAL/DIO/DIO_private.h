/*
 * @file   		DIO_private.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		18 AUG 2023
 * @MC          STM32F103x
 * @brief       this file is used to store DIO private data
 */

/*define to prevent recursive inclusion*/
#ifndef   DIO_PRIVATE_H
#define   DIO_PRIVATE_H

/*                  Register Definitions -assign addresses         */
#define GPIOA_BASE_ADDRESS     0x40010800
#define GPIOB_BASE_ADDRESS     0x40010C00
#define GPIOC_BASE_ADDRESS     0x40011000

#define GPIOA_CRL 			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x00)
#define GPIOA_CRH 			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x04)
#define GPIOA_IDR 			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x08)
#define GPIOA_ODR 			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x0C)
#define GPIOA_BSRR             *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x10)
#define GPIOA_BRR			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x14)
#define GPIOA_LCKR			   *(uint32 *)(GPIOA_BASE_ADDRESS+ 0x18)

#define GPIOB_CRL 			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x00)
#define GPIOB_CRH 			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x04)
#define GPIOB_IDR 			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x08)
#define GPIOB_ODR 			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x0C)
#define GPIOB_BSRR             *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x10)
#define GPIOB_BRR			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x14)
#define GPIOB_LCKR			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x18)

#define GPIOC_CRL 			   *(uint32 *)(GPIOC_BASE_ADDRESS+ 0x00)
#define GPIOC_CRH 			   *(uint32 *)(GPIOC_BASE_ADDRESS+ 0x04)
#define GPIOC_IDR 			   *(uint32 *)(GPIOC_BASE_ADDRESS+ 0x08)
#define GPIOC_ODR 			   *(uint32 *)(GPIOC_BASE_ADDRESS+ 0x0C)
#define GPIOC_BSRR             *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x10)
#define GPIOC_BRR			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x14)
#define GPIOC_LCKR			   *(uint32 *)(GPIOB_BASE_ADDRESS+ 0x18)



#endif
