// TExaS.h
// Runs on LM4F120/TM4C123
// Periodic timer Timer4A, ADC1, PD3, and UART0 used to create the scope
// Periodic timer Timer5A which will interact with debugger and grade the lab 
// It initializes on reset and runs whenever interrupts are enabled
// March 4, 2014

// ************TExaS_Init*****************
// Initialize grader, triggered by timer 5A
// This needs to be called once 
// Inputs: none oscilloscope to be implemented (uses UART0 and TExaSdisplay)
// Outputs: none
void TExaS_Init(void);

// ************TExaS_Stop*****************
// Stop the transfer 
// Inputs:  none
// Outputs: none
void TExaS_Stop(void);
