// FileName ModuleA.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 05, 2018

#ifndef ModuleA_H
#define ModuleA_H

//#include "../UartAdapter.h"
#include "common/Logger.h"
#include "Interfaces/IRunnable.h"

class ModuleA : public IRunnable {

	public :
		ModuleA();
		~ModuleA();
	
		virtual void run();
};

#endif
