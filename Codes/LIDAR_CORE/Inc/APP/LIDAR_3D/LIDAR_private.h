/*
 * LIDAR_private.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */

#ifndef APP_LIDAR_3D_LIDAR_PRIVATE_H_
#define APP_LIDAR_3D_LIDAR_PRIVATE_H_

uint32 Global_STEPPER_ANGLES[7];
uint32 Global_STEPPER_CALI_ZERO_POSTION=0;
uint32 Global_STEPPER_REAL_POSITION;



void refine_base_calibration(void);
void set_base_function(void);

#endif /* APP_LIDAR_3D_LIDAR_PRIVATE_H_ */
