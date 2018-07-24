// FileName: ModulesIf_Run.cpp
// Runs on LM4F120/TM4C123
// Using the UART.c driver delivered by Daniel Valvano
// application delivered by Pavel Kanazirev
// July 07, 2018
#include <cassert>
#include "Logger.h"

#include "ModuleA/ModuleA.h"
#include "ModuleB/ModuleB.h"
#include "ModuleC/ModuleC.h"

int main(void){
	UartAdapter uart;
	Logger::setInstance(&uart);
	
	ModuleA mA;
	ModuleB mB;
	ModuleC mC;

	mA.run();
	mB.run();
	mC.run();

	while(1);
}
