// FileName ModuleB.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 05, 2018

#ifndef ModuleB_H
#define ModuleB_H

//#include "../UartAdapter.h"
#include "../Logger.h"
#include "../Interfaces/IRunnable.h"

class ModuleB : public IRunnable {

	public :
		ModuleB();
		~ModuleB();
	
		virtual void run();
};

#endif
