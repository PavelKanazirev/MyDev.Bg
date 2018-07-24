// FileName VirtualBus_ModulA.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#ifndef VIRTUALBUS_MODULA_H
#define VIRTUALBUS_MODULA_H

#include "VirtualBusTypes.h"

extern VBUS_DataPool_t VBUS_dataPool; 

// provides VBus_DeviceInfo through port PDevInfo
#define VBUS_ModulA_PDevInfo_offset (0)
#define VBUS_ModulA_PDevInfo_size 	(sizeof(VBUS_DeviceInfo))
#define VBUS_ModulA_PDevInfo_Write(VBUSdata) \
   memcpy(&VBUS_dataPool._ModuleA._DeviceInfo,VBUSdata, VBUS_ModulA_PDevInfo_size)

#endif // VIRTUALBUS_MODULA_H
