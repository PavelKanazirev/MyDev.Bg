#ifndef LOGGER_H
#define LOGGER_H

#include "IO/UartAdapter.h"

void Log(char * const _string);
void Log(int const _dec);

class Logger {
	private:
		static UartAdapter* m_uart;
	
		Logger();
	public :

		~Logger();
	
		static void setInstance(UartAdapter * const _uart);
	
		static void Log(char * const _string);
		static void Log(int const _dec);
};

#endif // LOGGER_H
