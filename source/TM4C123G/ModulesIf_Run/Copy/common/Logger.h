#ifndef LOGGER_H
#define LOGGER_H

#include "UartAdapter.h"

void Log(char* string);

class Logger {
	private:
		UartAdapter& m_uart;
	
		Logger();
	public :

		~Logger();

		void get();	
		void get(UartAdapter &_uart);
	
		void Log(char* string);
};

#endif // LOGGER_H
