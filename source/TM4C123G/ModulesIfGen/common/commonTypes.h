// FileName commonTypes.h
// Runs on LM4F120/TM4C123
// application delivered by Pavel Kanazirev
// July 07, 2018

#ifndef _COMMONTYPES_H_
#define _COMMONTYPES_H_

/** unsigned 8-bit integer */
typedef unsigned char   uint8;
#ifndef UNIT_TEST
typedef unsigned char   uint8_t;
#endif

/** volatile unsigned 8-bit integer */
typedef volatile unsigned char vuint8;
typedef volatile unsigned char vuint8_t;

/** signed 8-bit integer */
typedef signed char     sint8;
#ifndef UNIT_TEST
typedef signed char     int8_t;
#endif

/** unsigned 16-bit integer */
typedef unsigned short  uint16;
#ifndef UNIT_TEST
typedef unsigned short  uint16_t;
#endif

/** volatile unsigned 16-bit integer */
typedef volatile unsigned short vuint16;
typedef volatile unsigned short vuint16_t;

/** volatile signed 16-bit integer */
typedef volatile signed short vint16;
typedef volatile signed short vint16_t;

/** signed 16-bit integer */
typedef signed short    sint16;
#ifndef UNIT_TEST
typedef signed short    int16_t;
#endif

/** unsigned 32-bit integer */
typedef unsigned long   uint32;
#ifndef UNIT_TEST
typedef unsigned long   uint32_t;
#endif
/** volatile unsigned 32-bit integer */
typedef volatile unsigned long vuint32;
typedef volatile unsigned long vuint32_t;

/** volatile signed 32-bit integer */
typedef volatile signed long vint32;
typedef volatile signed long vint32_t;

/** signed 32-bit integer */
typedef signed long     sint32;
#ifndef UNIT_TEST
typedef signed long 	int32_t;
#endif

/** unsigned 64-bit integer */
typedef unsigned long long int 	uint64;
typedef unsigned long long int 	uint64_t;

/** volatile unsigned 64-bit integer */
typedef volatile unsigned long long int vuint64;

/** signed 64bit integer integer */
typedef signed long long int 			sint64;
#ifndef UNIT_TEST
typedef signed long long int    int64_t;
#endif

#ifndef NULL
	#define NULL 0
#endif

#ifndef TRUE
	#define TRUE	1
#endif

#ifndef FALSE
	#define FALSE	0
#endif

typedef unsigned char BOOL;

// The value of 'a' won't be computed because 'false && ' is false.
#define UNUSED(a) if (false && (a)) ; else (void) 0 ;

// irevert: Compiling unit test (gtest) with mingw requires intptr_t to be defiend
// This is normally defined in stdint.h provided by the compiler but we have
// redefined it and therefore need to include this definition.
#if defined(UNIT_TEST) && defined(__MINGW32__)
typedef int intptr_t;
#endif

#endif /* _COMMONTYPES_H_ */
