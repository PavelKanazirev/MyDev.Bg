/*
 * SampleCppSPI.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef SAMPLECPPSPI_H_
#define SAMPLECPPSPI_H_

#include <string.h>

#include "SPI_protocol.h"

#define SET_KEY_CMD  (21U)
#define SET_MODE_CMD (42U)

typedef void * (callback_t)(void *);
typedef struct cpp_mcu_s { void * spi_link; int id; char * payload; } cpp_mcu_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

int cpp_request(void * _spi_link, uint8_t * const _data, unsigned _length, callback_t _cb, void * _ctx);

int setMsgCommandOnSpi(cpp_mcu_t * const _mcu, SPI_protocol::set_direction _msg, callback_t _cb, void * _ctx);

int setMsgModeOnSpi(cpp_mcu_t * const _mcu,  SPI_protocol::set_direction_mode _msg, callback_t _cb, void * _ctx);

enum class CppColor : uint8_t { red, green, blue };

int cppColorPicker(CppColor _color);

#endif /* SAMPLECPPSPI_H_ */





























