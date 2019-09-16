/*
 * wrapper.hpp
 *
 *  Created on: 2018/08/31
 *      Author: Sekiguchi Takuya
 */

#ifndef APPLICATION_USER_WRAPPER_HPP_
#define APPLICATION_USER_WRAPPER_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#define MAIN_I2C_ADDRESS	1
#define DRIVE_UNITBASE_ADDRESS	2
#define UNIT_UNITBASE_ADDRESS 3
#define SOLENOID_UNITBASE_ADDRESS 4
#define CONTROL_PANEL_ADDRESS 5

enum choose_field{
  Red_Qualifying_League,
  Red_Final_tournament,
  Blue_Qualifying_League,
  Blue_Final_tournament,
};

#define MAIN

void init(void);
void loop(void);
void tim_internal();
#ifdef __cplusplus
};
#endif

#endif /* APPLICATION_USER_WRAPPER_HPP_ */
