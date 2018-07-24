/*
 * SVersionTest.h
 *
 *  Created on: Jul 19, 2018
 *      Author: pavel
 */

#ifndef SVERSIONTEST_H_
#define SVERSIONTEST_H_

#include "commonTypes.h"

constexpr unsigned int version = 3U;
//constexpr unsigned int version = 4U;

class SVersionTest {
public:
	SVersionTest();
	virtual ~SVersionTest();

	int myStrNCat(char * destination, const char * source, unsigned int n);
	int myStrCat(char * destination, const char * source);
};

#endif /* SVERSIONTEST_H_ */
