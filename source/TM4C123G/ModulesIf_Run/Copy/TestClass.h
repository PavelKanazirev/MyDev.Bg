// FileName TestClass.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 05, 2018

#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "UartAdapter.h"
#include "Interfaces\IRunnable.h"

class TestClass : public IRunnable {
	UartAdapter& m_uart;
	public :
		TestClass(UartAdapter &_uart);
		~TestClass();
	
	virtual void run();
};

#endif
