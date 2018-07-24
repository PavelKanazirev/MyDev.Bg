// FileName VirtualBus_ModulB.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#ifndef VIRTUALBUS_MODULEB_H
#define VIRTUALBUS_MODULEB_H

#include "VirtualBusTypes.h"
#include "VirtualBus.h"

extern VBUS_DataPool_t VBUS_dataPool; 

// provides VBus_DeviceInfo through port PDevInfo
#define VBUS_ModulB_RDevInfo_offset (0)
#define VBUS_ModulB_RDevInfo_size 	(sizeof(VBUS_DeviceInfo))
#define VBUS_ModulB_RDevInfo_Read(RTEdata) \
   memcpy(RTEdata, &VBUS_dataPool._ModuleA._DeviceInfo, VBUS_ModulB_RDevInfo_size);

#endif // VIRTUALBUS_MODULEB_H
