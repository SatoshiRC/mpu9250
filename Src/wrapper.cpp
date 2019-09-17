/*
 * wrapper.cpp
 *
 *  Created on: 2018/08/31
 *      Author: Sekiguchi Takuya
 */



#include "wrapper.hpp"

#include "tim.h"

#include "i2c_myclass.hpp"

#define memAdd 0x43
#define GYRO_ADD 0x68

I2C_myclass I2C_C(&hi2c2 , MAIN_I2C_ADDRESS);

uint8_t data1[2]={0x75,0};
uint8_t target_address = 0;

void init(){
	I2C_C.init();
	uint8_t a=0;

	while(I2C_C.mem_read(&target_address , 1 , 0x75 , 1 , GYRO_ADD));
	//while(HAL_I2C_Master_Transmit(&hi2c2 , GYRO_ADD ,data1 , 2 , 100) != HAL_OK);
	HAL_GPIO_WritePin(GPIOD , GPIO_PIN_2 , GPIO_PIN_SET);
	while(I2C_C.mem_write(&a , 1 , 0x6b , 1 , GYRO_ADD));
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOD , GPIO_PIN_2 , GPIO_PIN_RESET);
	HAL_TIM_Base_Start_IT(&htim6);
}

int8_t data[6]={};
int16_t angular_velocity[3]={};
double angular[3] = {};

void loop(){

	if(I2C_C.mem_read((uint8_t *)data , sizeof(data) , memAdd , 1 , GYRO_ADD)){
		HAL_GPIO_WritePin(GPIOC , GPIO_PIN_14 , GPIO_PIN_RESET);
	}else{
		HAL_GPIO_WritePin(GPIOC , GPIO_PIN_14 , GPIO_PIN_SET);
	}
	angular_velocity[0] = ((int16_t)data[0]<<8 & data[1]);
	angular_velocity[1] = ((int16_t)data[2]<<8 & data[3]);
	angular_velocity[2] = ((int16_t)data[4]<<8 & data[5]);
}

void tim_internal(){
	for(uint8_t n=0 ; n<3 ; n++)
		angular[n] += ((int16_t)data[n*2]<<8) * 0.001;
	HAL_GPIO_WritePin(GPIOC , GPIO_PIN_13 , GPIO_PIN_SET);
}

