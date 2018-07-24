/*
 * SPI_protocol.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef SPI_PROTOCOL_H_
#define SPI_PROTOCOL_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;



namespace SPI_protocol {
	enum class msg_direction_id : uint8_t
	{
		left, right, up, down, none, other
	};

	struct set_direction
	{
		msg_direction_id direction;
		uint16_t value;
	};

	struct set_direction_mode
	{
		msg_direction_id direction;
		bool mode;
	};

}

#endif /* SPI_PROTOCOL_H_ */



