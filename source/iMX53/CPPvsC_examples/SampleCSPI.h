/*
 * SampleCSPI.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef SAMPLECSPI_H_
#define SAMPLECSPI_H_

#define SET_KEY_CMD  (21U)
#define SET_MODE_CMD (42U)

#include <string.h>

typedef void * (callback_t)(void *);
typedef struct mcu_s { void * spi_link; int id; char * payload; } mcu_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

int request(void * _spi_link, uint8_t * const _data, unsigned _length, callback_t _cb, void * _ctx);

int setMsgCommandOnSpi(mcu_t * const _mcu, int _msg_direction, uint16_t _msg_value, callback_t _cb, void * _ctx);

int setMsgModeOnSpi(mcu_t * const _mcu, int _msg_direction, int _mode, callback_t _cb, void * _ctx);

enum CColor {red, green, blue};

int cColorPicker(CColor _color);

#endif /* SAMPLECSPI_H_ */
