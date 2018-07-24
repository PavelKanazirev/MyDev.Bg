/*
 * DynamicPolimorphTest.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#include "DynamicPolimorphTest.h"

DynamicPolimorphTest::DynamicPolimorphTest() {
	// TODO Auto-generated constructor stub

}

DynamicPolimorphTest::~DynamicPolimorphTest() {
	// TODO Auto-generated destructor stub
}

void DynamicPolimorphTest::run(AlarmType _alarmType)
{
	DPAlarm * activeAlarm = NULL;

	switch (_alarmType)
	{
		case Analog:
		{
			activeAlarm = new DPAnalogAlarm();

			activeAlarm->setAlarmState(DPAlarm::EStatePreactivation);
			break;
		}
		case Horn:
		{
			activeAlarm = new DPHornAlarm();

			activeAlarm->setAlarmState(DPAlarm::EStatePreactivation);
			break;
		}
		case Sounder:
		{
			activeAlarm = new DPSounderAlarm();

			activeAlarm->setAlarmState(DPAlarm::EStatePreactivation);
			break;
		}
	}
}
