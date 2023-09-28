/*********************************************************/
/*Author        : Mostafa Ayman                          */
/*Date          : 13 AUG 2023                            */
/*Vesion        : V1.0                                   */
/*MC            : STM32Fxxxx                             */
/*********************************************************/
#ifndef   BIT_MATH_H
#define   BIT_MATH_H

#define SET_BIT(REG,BIT)       REG |=  (1<<(BIT))
#define CLR_BIT(REG,BIT)       REG &= ~(1<<(BIT))
#define GET_BIT(REG,BIT)       ((REG >> BIT) & 1)
#define TOG_BIT(REG,BIT)       REG ^= (1<<(BIT))
#endif
