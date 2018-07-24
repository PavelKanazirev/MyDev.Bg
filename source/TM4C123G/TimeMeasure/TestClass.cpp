#include "TestClass.h"

TestClass::TestClass(UartAdapter &_uart): m_uart(_uart) {

};
TestClass::~TestClass(){};
	
void TestClass::run(){m_uart.printString("Hello");};
