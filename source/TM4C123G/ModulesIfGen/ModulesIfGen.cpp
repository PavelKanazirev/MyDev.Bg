// FileName: ModulesIfGen.cpp
// Runs on LM4F120/TM4C123
// Using the UART.c driver delivered by Daniel Valvano
// application delivered by Pavel Kanazirev
// July 07, 2018

#include <cassert>
#include <string.h>
#include "common/Logger.h"

#include "Interfaces/IRunnable.h"
#include "Interfaces/VirtualBusTypes.h"

#include "config/module_files.csv"

#define MODULES_SIZE sizeof(modules)/sizeof(IRunnable *)

unsigned char virtual_bus[3] = {1,2,3};

ModuleC *pmZ;

int main(void)
{
		UartAdapter uart;
		Logger::setInstance(&uart);
#ifndef MODULE_VARS_CSV
#define MODULE_VARS_CSV
#include "config/module_vars.csv"
#endif // MODULE_VARS_CSV

		IRunnable * modules[] = {
#ifndef MODULE_ARRAY_MEMBERS
#define MODULE_ARRAY_MEMBERS
#include "config/module_array_members.csv"
#endif // MODULE_ARRAY_MEMBERS
		};
		
		assert(MODULES_SIZE > 0);
	
		while(1) 
		{
				for (int index = 0; index < MODULES_SIZE /* MODULES_SIZE */; index++)
				{
						modules[index]->run();
				}
		};
}
