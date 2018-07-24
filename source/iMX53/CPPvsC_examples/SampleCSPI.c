/*
 * SampleCSPI.c
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */


#include "SampleCSPI.h"

int request(void * _spi_link, uint8_t * const _data, unsigned _length, callback_t _cb, void * _ctx)
{
	return -1;
}

int setMsgCommandOnSpi(mcu_t * const _mcu, int _msg_direction, uint16_t _msg_value, callback_t _cb, void * _ctx)
{
	unsigned length = 4;
	uint8_t data[length];

	data[0] = SET_KEY_CMD;
	data[1] = _msg_direction;
	memcpy(&data[2], &_msg_value, 2);

	return request(_mcu->spi_link, data, length, _cb, _ctx);
}

int setMsgModeOnSpi(mcu_t * const _mcu, int _msg_direction, int _mode, callback_t _cb, void * _ctx)
{
	unsigned length = 3;
	uint8_t data[length];

	data[0] = SET_MODE_CMD;
	data[1] = _msg_direction;
	data[2] = _mode;

	return request(_mcu->spi_link, data, length, _cb, _ctx);
}

int cColorPicker(CColor _color)
{
	_color = red;

	return _color;
}













