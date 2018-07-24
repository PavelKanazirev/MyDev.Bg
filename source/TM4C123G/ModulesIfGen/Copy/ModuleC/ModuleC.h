// FileName ModuleC.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 05, 2018

#ifndef ModuleC_H
#define ModuleC_H

//#include "../UartAdapter.h"
#include "../Logger.h"
#include "../Interfaces/IRunnable.h"

class ModuleC : public IRunnable {

	public :
		ModuleC();
		~ModuleC();
	
		virtual void run();
};

#endif
