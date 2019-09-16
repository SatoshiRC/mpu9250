/*
 * i2c_myclass.cpp
 *
 *  Created on: Jul 11, 2019
 *      Author: conat
 */
#include "i2c_myclass.hpp"

I2C_myclass::I2C_myclass(I2C_HandleTypeDef *hi2c , uint8_t Myaddress){
	i2c = hi2c;
	timeout = 100;
	myaddress = Myaddress;

}

uint8_t I2C_myclass::init(){
	if(myaddress >= 0b10000000 )
		return 1;
	HAL_I2C_DeInit(i2c);
	i2c->Init.OwnAddress1 = myaddress << 1;
	HAL_I2C_Init(i2c);

	return 0;
}

uint8_t I2C_myclass::master_transmit(uint8_t *pdata , uint8_t data_size , uint8_t target_address){
	if(target_address >= 0b10000000 )
		return 1;
	if(HAL_OK == HAL_I2C_Master_Transmit(i2c , target_address << 1 , pdata , data_size , timeout))
		return 0;
	return 1;

}

uint8_t I2C_myclass::slave_receive(uint8_t *pdata , uint8_t data_size){
	if(HAL_OK == HAL_I2C_Slave_Receive(i2c , pdata , data_size , timeout))
		return 0;
	return 1;
}

uint8_t I2C_myclass::slave_transmit(uint8_t *pdata , uint8_t data_size){
	if(HAL_OK == HAL_I2C_Slave_Transmit(i2c , pdata , data_size , timeout))
		return 0;
	return 1;
}

uint8_t I2C_myclass::master_receive(uint8_t *pdata , uint8_t data_size , uint8_t target_address){
	if(target_address >= 0b10000000 )
		return 1;
	if(HAL_OK == HAL_I2C_Master_Receive(i2c , target_address << 1 , pdata , data_size , 0xff))
		return 0;
	return 1;
}

uint8_t I2C_myclass::mem_read(uint8_t *pdata , uint8_t data_size , uint16_t memAddress , uint16_t memAddress_size , uint8_t target_address){
	if(target_address >= 0b10000000 )
		return 1;
	if(HAL_OK == HAL_I2C_Mem_Read(i2c , target_address << 1, memAddress , memAddress_size , pdata , data_size , timeout))
		return 0;
	return 1;
}

uint8_t I2C_myclass::mem_write(uint8_t *pdata , uint8_t data_size , uint16_t memAddress , uint16_t memAddress_size , uint8_t target_address){
	if(target_address >= 0b10000000 )
		return 1;
	if(HAL_OK == HAL_I2C_Mem_Write(i2c , target_address << 1, memAddress , memAddress_size , pdata , data_size , timeout))
		return 0;
	return 1;
}
