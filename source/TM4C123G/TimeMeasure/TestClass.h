#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "UartAdapter.h"

class TestClass {
	UartAdapter& m_uart;
	public :
		TestClass(UartAdapter &_uart);
		~TestClass();
	
	void run();
};

#endif
