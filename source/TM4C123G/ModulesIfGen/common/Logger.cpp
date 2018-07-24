// Logger.cpp
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018
#include <cassert>

#include "Logger.h"

UartAdapter* Logger::m_uart = 0;

Logger::Logger() {

};

Logger::~Logger(){};

void Logger::setInstance(UartAdapter * const _uart)
{
		m_uart = _uart;
		assert( 0 != m_uart);
		m_uart->init();
};

void Logger::Log(char * const _string){
		assert( 0 != m_uart);
		m_uart->printString(_string);
};

void Logger::Log(int const _dec){
		assert( 0 != m_uart);
		m_uart->printUDec(_dec);
};

void Log(char * const _string)
{
	  Logger::Log(_string);
}

void Log(int const _dec)
{
		Logger::Log(_dec);
}
