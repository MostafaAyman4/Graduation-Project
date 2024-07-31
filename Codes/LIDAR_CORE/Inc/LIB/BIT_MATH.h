/*
 * @file   		BIT_MATH.h
 * @author 		Mostafa Ayman
 * @version		V2.0
 * @date		13 AUG 2023
 * @MC          STM32F103x
 * @brief       this file is used to manipulate bits
 */

/*define to prevent recursive inclusion*/
#ifndef   BIT_MATH_H
#define   BIT_MATH_H

#define SET_BIT(REG,BIT)       REG |=  (1<<(BIT))
#define CLR_BIT(REG,BIT)       REG &= ~(1<<(BIT))
#define GET_BIT(REG,BIT)       ((REG >> BIT) & 1)
#define TOG_BIT(REG,BIT)       REG ^= (1<<(BIT))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#endif
