/*
 * StaticPolimorphTest.h
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#ifndef SRC_STATICPOLIMORPHTEST_H_
#define SRC_STATICPOLIMORPHTEST_H_

#include "SPAlarm.h"

class StaticPolimorphTest {
public:
	typedef enum {Analog, Horn, Sounder} AlarmType;
	StaticPolimorphTest();
	virtual ~StaticPolimorphTest();

	void run(AlarmType _alarmType);
};

#endif /* SRC_STATICPOLIMORPHTEST_H_ */
