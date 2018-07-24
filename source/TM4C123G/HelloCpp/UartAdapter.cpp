#include "UartAdapter.h"

#include "PLL.h"
#include "UART.h"

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

UartAdapter::UartAdapter()
{
};

UartAdapter::~UartAdapter()
{
};

//---------------------OutCRLF---------------------
// Output a CR,LF to UART to go to a new line
// Input: none
// Output: none
void UartAdapter::OutCRLF(void){
		UART_OutChar(CR);
		UART_OutChar(LF);
}

void UartAdapter::init()
{
		PLL_Init();
		UART_Init();              // initialize UART
};

//------------printChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UartAdapter::printChar(unsigned char data){
		UART_OutChar(data);
}

//------------printString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void UartAdapter::printString(char *pt){
		UART_OutString(pt);
}

//-----------------------printUDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void UartAdapter::printUDec(unsigned long n)
{
		UART_OutUDec(n);
}

//--------------------------printUHex----------------------------
// Output a 32-bit number in unsigned hexadecimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1 to 8 digits with no space before or after
void UartAdapter::printUHex(unsigned long number)
{
	  UART_OutUHex(number);
}

//------------readChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
unsigned char UartAdapter::readChar(void)
{
		return UART_InChar();
}

//------------readString------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until <enter> is typed
//    or until max length of the string is reached.
// It echoes each character as it is inputted.
// If a backspace is inputted, the string is modified
//    and the backspace is echoed
// terminates the string with a null character
// uses busy-waiting synchronization on RDRF
// Input: pointer to empty buffer, size of buffer
// Output: Null terminated string
void UartAdapter::readString(char *bufPt, unsigned short max)
{
	UART_InString(bufPt, max);
}

//------------readUDec------------
// InUDec accepts ASCII input in unsigned decimal format
//     and converts to a 32-bit unsigned number
//     valid range is 0 to 4294967295 (2^32-1)
// Input: none
// Output: 32-bit unsigned number
// If you enter a number above 4294967295, it will return an incorrect value
// Backspace will remove last digit typed
unsigned long UartAdapter::readUDec(void)
{
	  return UART_InUDec();
}

//---------------------readUHex----------------------------------------
// Accepts ASCII input in unsigned hexadecimal (base 16) format
// Input: none
// Output: 32-bit unsigned number
// No '$' or '0x' need be entered, just the 1 to 8 hex digits
// It will convert lower case a-f to uppercase A-F
//     and converts to a 16 bit unsigned number
//     value range is 0 to FFFFFFFF
// If you enter a number above FFFFFFFF, it will return an incorrect value
// Backspace will remove last digit typed
unsigned long UartAdapter::readUHex(void)
{
	  return UART_InUHex();
};

