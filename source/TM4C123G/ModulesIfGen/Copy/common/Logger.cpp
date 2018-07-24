// Logger.cpp
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#include "Logger.h"

Logger::Logger(UartAdapter &_uart): m_uart(_uart) {

};

Logger::~Logger(){};

void Logger::init()
{
		m_uart.init();
};	

void Logger::Log(char* string){
		 m_uart.printString(string);
};

void Log(char* string)
{
//	Logger::Log(string);
}
