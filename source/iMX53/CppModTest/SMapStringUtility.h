/**
 * Contains some utilities for maps with strings as key.
 * @file	SMapStringUtility.h
 * @ingroup	sstl
 * 
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SMAPSTRINGUTILITY_H_
#define SMAPSTRINGUTILITY_H_

#include "SFunction.h"
#include <cstring>

//forward declaration
template<typename T>
struct SHash;

/**
 * special implementation for strings
 * @see		SHash
 */
template<>
struct SHash<char*>
{
	/**
	 * computes hash value for a string
	 */
	unsigned operator()(const char* str) const
	{
		unsigned long hash = 5381;
        int c = *str++;
        while (c)
        {
            hash = ((hash << 5) + hash) + c; //hash * 33 + c
            c = *str++;
        }
        return hash; 
	}
};

/**
 * special implementation for strings
 * 
 * @see	SEqualTo
 */
template<>
struct SEqualTo<char*> : public SBinaryFunction<char*, char*, bool>
{
	/**
	 * compares two string
	 */
	bool operator()(char* x, char* y) const
	{
		//is one of the string NULL?
		if ((x || y) && !(x && y))
		{
			return false;
		}
		return strcmp(x, y) == 0;
	}
};

#endif /*SMAPSTRINGUTILITY_H_*/
