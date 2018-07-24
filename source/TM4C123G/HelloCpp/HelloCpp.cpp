// HelloCpp.cpp
// Runs on LM4F120/TM4C123

//#include <iostream>

#include "UartAdapter.h"
#include "TestClass.h"

//debug code
int main(void){
	UartAdapter uart;
	TestClass t(uart);
	
	uart.init();

	t.run();
	
//	std::cout << std::endl;
	
	while (1)
	{
		// do nothing - just giving the time to the UART driver to print out
	}
}
