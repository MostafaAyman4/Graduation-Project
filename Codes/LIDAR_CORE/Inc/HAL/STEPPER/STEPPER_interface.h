/*
 * STEPPER_interface.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#define CLOCKWISE   1
#define ANTI_CLOCKWISE  0


void HSTEPPER_voidinit(void);
void HSTEPPER_voidmove(uint32 Copy_uint32steps,uint8 Copy_uint8Direction);
void HSTEPPER_void_move_1_step(uint8 Copy_uint8Direction);


#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
