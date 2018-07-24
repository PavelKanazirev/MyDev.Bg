// ModuleB.cpp
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#include "ModuleB.h"

#include "Interfaces/VirtualBus_ModuleB.h"

//ModuleB::ModuleB(UartAdapter &_uart): m_uart(_uart) {
ModuleB::ModuleB(){

};
ModuleB::~ModuleB(){};
	
void ModuleB::run()
{
		VBUS_DeviceInfo devInfo;
		Log("ModuleB\n");
		VBUS_ModulB_RDevInfo_Read(&devInfo);
		Log((char *)devInfo.enStSerialID);
		Log("\n\r Authorised : ");
		Log(devInfo.bAuthorised);
};
