/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 26 AUG 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/
#ifndef MSYSTICK_CONFIG_H
#define MSYSTICK_CONFIG_H


/*              SYSTICK CLOCK SOURCE options
    AHB
    AHB_BY_8
 */
#define SYSTICK_CLOCK_SOURCE        AHB

/*              SYSTICK_INT_EN options
    ENABLE
    DISABLE
*/
#define SYSTICK_INT_EN                ENABLE


#define SYSTICK_CLOCK                   8000000


#endif
