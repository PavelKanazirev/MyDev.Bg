/*
 * StaticPolimorphTest.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#include "StaticPolimorphTest.h"

StaticPolimorphTest::StaticPolimorphTest()
{
	// TODO Auto-generated constructor stub

}

StaticPolimorphTest::~StaticPolimorphTest()
{
	// TODO Auto-generated destructor stub
}

void StaticPolimorphTest::run(AlarmType _alarmType)
{
//	SPAlarm< AnalogAlarm >::alarm_states_t test_state = SPAlarm< AnalogAlarm >::EStatePreactivation;
	switch (_alarmType)
	{
		case Analog:
		{
			SPAlarm< SPAnalogAlarm > analogAlarm;
			analogAlarm.setAlarmState(SPAlarm< SPAnalogAlarm >::EStatePreactivation);
			break;
		}
		case Horn:
		{
			SPAlarm< SPHornAlarm > hornAlarm;
			hornAlarm.setAlarmState(SPAlarm< SPHornAlarm >::EStatePreactivation);
			break;
		}
		case Sounder:
		{
			SPAlarm< SPSounderAlarm > sounderAlarm;
			sounderAlarm.setAlarmState(SPAlarm< SPSounderAlarm >::EStatePreactivation);
			break;
		}
	}
}
