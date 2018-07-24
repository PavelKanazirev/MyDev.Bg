/*
 * DynamicPolimorphTest.h
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#ifndef DYNAMICPOLIMORPHTEST_H_
#define DYNAMICPOLIMORPHTEST_H_

#include "DPAlarm.h"

class DynamicPolimorphTest {
public:
	typedef enum {Analog, Horn, Sounder} AlarmType;
	DynamicPolimorphTest();
	virtual ~DynamicPolimorphTest();

	void run(AlarmType _alarmType);
};

#endif /* DYNAMICPOLIMORPHTEST_H_ */
