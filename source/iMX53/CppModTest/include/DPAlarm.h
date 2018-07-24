/*
 * DPAlarm.h
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_DPALARM_H_
#define INCLUDE_DPALARM_H_

#include <iostream>

#include "commonTypes.h"

using namespace std;

class DPAlarm {
public:
	typedef enum alarm_states_e {
		EStateOff,
		EStatePreactivation,
		EStateActivated,
		EStateTriggeredNoisy,
		EStateTriggeredSilent
	} alarm_states_t;

private:
	alarm_states_t currentState;
public:
	DPAlarm(): currentState(EStateOff) {};
	~DPAlarm(){};

	virtual void setAlarmStateImpl(alarm_states_t _new_state) = 0;

	alarm_states_t setAlarmState(alarm_states_t _new_state)
	{
		alarm_states_t oldState = _new_state;
		setAlarmStateImpl(_new_state);
		return oldState;
	}
};

class DPAnalogAlarm: public DPAlarm {
public:
	DPAnalogAlarm(){};
	~DPAnalogAlarm(){};
	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};

class DPHornAlarm : public DPAlarm {
public:
	DPHornAlarm(){};
	~DPHornAlarm(){};

	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};

class DPSounderAlarm : public DPAlarm {
public:
	DPSounderAlarm(){};
	~DPSounderAlarm(){};

	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};

#endif /* INCLUDE_DPALARM_H_ */
