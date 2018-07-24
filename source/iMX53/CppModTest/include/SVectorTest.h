/*
 * SVectorTest.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SVECTORTEST_H_
#define INCLUDE_SVECTORTEST_H_

#include <string>

#include "TestErrors.h"

class SVectorTest
{
private:
	TestErrors testDefaultConstructor();
	TestErrors testInitConstructor();
	TestErrors testEmpty();
	TestErrors testPushBack();
	TestErrors testPopBack();
	TestErrors testResize();
	TestErrors testFull();
	TestErrors testFront();
	TestErrors testBack();
	TestErrors testClear();
	TestErrors testIterators();
	TestErrors testErase();

	void cleanup();

public:
	SVectorTest();
	virtual ~SVectorTest();

	typedef SVector<int>	tIntVector;
	tIntVector*		fpVector1;
	tIntVector*		fpVector2;

    virtual void SetUp();

    virtual void TearDown();

	TestErrors run();

	inline string toString() { return "SVectorTests";};
};

#endif /* INCLUDE_SVECTORTEST_H_ */
