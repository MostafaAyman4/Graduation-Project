/*
 * LIDAR_interface.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Legasov
 */

#ifndef APP_LIDAR_3D_LIDAR_INTERFACE_H_
#define APP_LIDAR_3D_LIDAR_INTERFACE_H_


void HLIDAR_void_init(void);
void HLIDAR_HOME_voidCALIBRATION(void);
uint8 HLIDAR_uint8READ_DESIRED_ANGLE(void);
void HLIDAR_void_SET_ANGLE(uint32 Copy_uint32ANGLEINDEX);
void HLIDAR_void_ANGLE_READY_FLAG_RISE(void);
void HLIDAR_void_ANGLE_READY_FLAG_DOWN(void);
#endif /* APP_LIDAR_3D_LIDAR_INTERFACE_H_ */
