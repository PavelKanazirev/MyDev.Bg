// ModuleA.cpp
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#include "ModuleA.h"

#include "Interfaces/VirtualBus_ModuleA.h"

//ModuleA::ModuleA(UartAdapter &_uart): m_uart(_uart) {
ModuleA::ModuleA(){

};
ModuleA::~ModuleA(){};
	
void ModuleA::run()
{
		VBUS_DeviceInfo devInfo;
		memcpy(devInfo.enStSerialID,"serID",6);
		devInfo.bAuthorised = TRUE;
		Log("ModuleA\n");
		VBUS_ModulA_PDevInfo_Write(&devInfo);
};
