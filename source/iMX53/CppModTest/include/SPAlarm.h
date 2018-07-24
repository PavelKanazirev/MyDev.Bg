/*
 * SPAlarm.h
 *
 *  Created on: Jul 24, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SPALARM_H_
#define INCLUDE_SPALARM_H_

#include <iostream>

#include "commonTypes.h"

using namespace std;

template<class DerivedAlarm>
class SPAlarm {
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
	SPAlarm(): currentState(EStateOff) {};
	~SPAlarm(){};

	alarm_states_t setAlarmState(alarm_states_t _new_state)
	{
		alarm_states_t oldState = _new_state;
		static_cast< DerivedAlarm * >( this )->setAlarmStateImpl(_new_state);
		return oldState;
	}
};

class SPAnalogAlarm: public SPAlarm< SPAnalogAlarm > {
public:
	SPAnalogAlarm(){};
	~SPAnalogAlarm(){};
	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};

class SPHornAlarm : public SPAlarm< SPHornAlarm > {
public:
	SPHornAlarm(){};
	~SPHornAlarm(){};
	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};

class SPSounderAlarm : public SPAlarm< SPSounderAlarm > {
public:
	SPSounderAlarm(){};
	~SPSounderAlarm(){};
	void setAlarmStateImpl(alarm_states_t _new_state)
	{
		UNUSED(_new_state)
//		std::cout <<__PRETTY_FUNCTION__<<endl;
	}

};


#endif /* INCLUDE_SPALARM_H_ */
