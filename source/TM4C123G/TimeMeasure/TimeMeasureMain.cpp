// TimeMeasureMain.cpp
// Runs on LM4F120/TM4C123
// Used to test the UART.c driver

//#include <iostream>

#include "UartAdapter.h"
#include "SysTickAdapter.h"

//debug code
int main(void){
	UartAdapter uart;
	SysTickAdapter time;
	unsigned long number_of_ticks1 = 0;
	unsigned long number_of_ticks2 = 0;
	unsigned long number_of_milliseconds = 0;
	unsigned long delay = 50000;
	unsigned int counter = 1;
	
	uart.init();
	time.init();
	
	number_of_ticks1 = time.getCurrentSysTicks();
	
	time.sysTickWait(delay); // 1 ms == 50000
	
	number_of_ticks2 = time.getCurrentSysTicks();
	number_of_milliseconds = time.calculateSysTicksToMilliseconds(
			number_of_ticks1 - number_of_ticks2);
	
		uart.printUDec(delay);
		uart.printString(" : ");
		uart.printUDec(number_of_milliseconds);
		uart.printString("; \n\r");

  while(counter < 11){
		delay += delay; counter++;
		number_of_ticks1 = time.getCurrentSysTicks();
		
		time.sysTickWait(delay);
		
		number_of_ticks2 = time.getCurrentSysTicks();
		number_of_milliseconds = time.calculateSysTicksToMilliseconds(
				number_of_ticks1 - number_of_ticks2);
		
		uart.printUDec(delay);
		uart.printString(" : ");
		uart.printUDec(number_of_milliseconds);
		uart.printString("; \n\r");
  }
}
