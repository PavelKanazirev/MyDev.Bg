// FileName VirtualBusTypes.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#ifndef VIRTUALBUSTYPES_H
#define VIRTUALBUSTYPES_H


// current implementation of the VirtualBus pool operations are 
// performed using memset - so the system include will be placed here
#include <string.h>

#include "common/commonTypes.h"

typedef uint8 VBusU8;
typedef uint8 VBusS8;
typedef uint32 VBusU32;
typedef sint32 VBusS32;
typedef uint64 VBusU64;
typedef sint64 VBusS64;
typedef BOOL VBusBool;

#define VBUS_E_OK 								((VBusU8)0)
#define VBUS_E_INVALID 						((VBusU8)1)
#define VBUS_E_TIMEOUT 						((VBusU8)2)
#define VBUS_E_LIMIT 							((VBusU8)3)
#define VBUS_E_NO_DATA 						((VBusU8)4)
#define VBUS_E_TRANSMIT_ACK 			((VBusU8)5)
#define VBUS_E_LOST_DATA 					((VBusU8)6)
#define VBUS_E_MAX_AGE_EXCEEDED 	((VBusU8)7)

typedef VBusU8 VBUS_ReturnType;

typedef struct {
	VBusU8 enStSerialID[8];
	VBusBool bAuthorised;
} VBUS_DeviceInfo;

typedef struct {
	VBusU8 CRIN[8];
	VBusU8 VIN[8];
} VBUS_ManufacturingInfo;

typedef enum {
	ESecurity_PortAttacked,
	ESecurity_RAMIntrusion,
	ESecurity_FlashIntrusion,
	ESecurity_UnauthorizedAccess
} VBUS_SecurityEvents;

typedef struct {
	uint8 numHistory;
	struct{
		VBUS_SecurityEvents event;
		VBusU8 Year;
		VBusU8 Month;
		VBusU8 Day;
		VBusU8 Hour;
	} Value[20] ;
} VBUS_SecurityLog;

typedef struct {
		struct {
				VBUS_DeviceInfo _DeviceInfo;
		} _ModuleA;
} VBUS_DataPool_t;

#endif // VIRTUALBUSTYPES_H
