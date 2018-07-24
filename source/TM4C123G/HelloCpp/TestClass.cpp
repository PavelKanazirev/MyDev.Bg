//#include <iostream>
#include <vector>

#include "TestClass.h"

TestClass::TestClass(UartAdapter &_uart): m_uart(_uart) 
{

};

TestClass::~TestClass(){};
	
void TestClass::run()
{
	unsigned long ui_array[] = {2,4,1,3};
	std::vector<unsigned long> my_vector;
	
//	my_vector.push_back(ui_array[2]);
	
	m_uart.printString("Hello");
	m_uart.printUDec(ui_array[2]);
};
