/*
 * i2c_myclass.hpp
 *
 *  Created on: Jul 11, 2019
 *      Author: conat
 */

#ifndef I2C_MYCLASS_HPP_
#define I2C_MYCLASS_HPP_

#include <stdint.h>
#include "i2c.h"


class I2C_myclass{
private :
	uint8_t myaddress;
	uint32_t timeout;
	I2C_HandleTypeDef *i2c;
public :
	I2C_myclass(I2C_HandleTypeDef *hi2c , uint8_t Myaddress);
	uint8_t init();
	uint8_t master_transmit(uint8_t *pdata , uint8_t data_size , uint8_t target_address);
	uint8_t	slave_receive(uint8_t *pdata , uint8_t data_size);
	uint8_t slave_transmit(uint8_t *pdata , uint8_t data_size);
	uint8_t master_receive(uint8_t *pdata , uint8_t data_size , uint8_t target_address);
	uint8_t mem_read(uint8_t *pdata , uint8_t data_size , uint16_t memAddress , uint16_t memAddress_size , uint8_t target_address);
	uint8_t mem_write(uint8_t *pdata , uint8_t data_size , uint16_t memAddress , uint16_t memAddress_size , uint8_t target_address);
};



#endif /* I2C_MYCLASS_HPP_ */
