/*
 * SampleCppSPI.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#include "SampleCppSPI.h"

int cpp_request(void * _spi_link, uint8_t * const _data, unsigned _length, callback_t _cb, void * _ctx)
{
	return -1;
}


int setMsgCommandOnSpi(cpp_mcu_t * const _mcu, SPI_protocol::set_direction _msg, callback_t _cb, void * _ctx)
{
	unsigned length = 4;
	uint8_t data[length];

	data[0] = SET_KEY_CMD;
	data[1] = static_cast<uint8_t>(_msg.direction);
	memcpy(&data[2], &_msg.value, 2);

	return cpp_request(_mcu->spi_link, data, length, _cb, _ctx);
}

int setMsgModeOnSpi(cpp_mcu_t * const _mcu, SPI_protocol::set_direction_mode _msg , callback_t _cb, void * _ctx)
{
	unsigned length = 3;
	uint8_t data[length];

	data[0] = SET_MODE_CMD;
	data[1] = static_cast<uint8_t>(_msg.direction);
	data[2] = static_cast<bool>(_msg.mode);

	return cpp_request(_mcu->spi_link, data, length, _cb, _ctx);
}

int cppColorPicker(CppColor _color = CppColor::red)
{
//	return _color;
}









