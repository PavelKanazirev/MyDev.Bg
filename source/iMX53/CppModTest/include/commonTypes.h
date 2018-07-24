/**
 * Includes project wide type definitions.
 */

#ifndef _COMMONTYPES_H_
#define _COMMONTYPES_H_

/** unsigned 8-bit integer */
typedef unsigned char   uint8;

/** volatile unsigned 8-bit integer */
typedef volatile unsigned char vuint8;
typedef volatile unsigned char vuint8_t;

/** signed 8-bit integer */
typedef signed char     sint8;

/** unsigned 16-bit integer */
typedef unsigned short  uint16;

/** volatile unsigned 16-bit integer */
typedef volatile unsigned short vuint16;
typedef volatile unsigned short vuint16_t;

/** volatile signed 16-bit integer */
typedef volatile signed short vint16;
typedef volatile signed short vint16_t;

/** signed 16-bit integer */
typedef signed short    sint16;

/** unsigned 32-bit integer */
typedef unsigned long   uint32;

/** volatile unsigned 32-bit integer */
typedef volatile unsigned long vuint32;

/** volatile signed 32-bit integer */
typedef volatile signed long vint32;

/** signed 32-bit integer */
typedef signed long     sint32;

/** unsigned 64-bit integer */
typedef unsigned long long int 	uint64;

/** volatile unsigned 64-bit integer */
typedef volatile unsigned long long int vuint64;

/** signed 64bit integer integer */
typedef signed long long int 			sint64;

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

#endif /* _COMMONTYPES_H_ */
