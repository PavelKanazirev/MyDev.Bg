/*
 * SVersionTest.cpp
 *
 *  Created on: Jul 19, 2018
 *      Author: pavel
 */

#include "SVersionTest.h"


SVersionTest::SVersionTest() {
	// TODO Auto-generated constructor stub

}

SVersionTest::~SVersionTest() {
	// TODO Auto-generated destructor stub
}

int SVersionTest::myStrNCat(char * destination, const char * source, unsigned int n)
{
	// implementation
	UNUSED(destination)
	UNUSED(source)
	UNUSED(n)

	return 0;
}

int SVersionTest::myStrCat(char * destination, const char * source)
{
	static_assert(version == 3U, "Depricated!");

	UNUSED(destination)
	UNUSED(source)

	return 0;
}
