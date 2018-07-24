// FileName TestClass.cpp
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 05, 2018

#include "TestClass.h"

TestClass::TestClass(UartAdapter &_uart): m_uart(_uart) {

};
TestClass::~TestClass(){};
	
void TestClass::run()
{
		m_uart.printString("Hello");
};
