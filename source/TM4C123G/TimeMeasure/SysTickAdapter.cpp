#include "SysTickAdapter.h"


SysTickAdapter::SysTickAdapter(){};
SysTickAdapter::~SysTickAdapter(){};
// Initialize SysTick with busy wait running at bus clock.
void SysTickAdapter::init(void)
{
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}

unsigned long SysTickAdapter::getCurrentSysTicks()
{
	unsigned long startTime = NVIC_ST_CURRENT_R;
	
	return startTime;
}

unsigned int SysTickAdapter::calculateSysTicksToMilliseconds(unsigned long sysTicks)
{
	unsigned int result_milliseconds = sysTicks / 50000; // (assumes 16 MHz clock)
	
	return result_milliseconds;
}

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTickAdapter::sysTickWait(unsigned long delay){
  volatile unsigned long elapsedTime;
  unsigned long startTime = NVIC_ST_CURRENT_R;
  do{
    elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
  }
  while(elapsedTime <= delay);
}

