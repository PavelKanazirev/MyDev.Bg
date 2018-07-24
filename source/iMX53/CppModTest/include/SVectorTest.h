/*
 * SVectorTest.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SVECTORTEST_H_
#define INCLUDE_SVECTORTEST_H_

#include "ITestable.h"
#include "TestErrors.h"

#include "SVector.h"

using namespace std;

class SVectorTest : public ITestable
{
private:
	typedef SVector<int>	tIntVector;
	tIntVector*		fpVector1;
	tIntVector*		fpVector2;

    virtual void setUp();
    virtual void tearDown();
    virtual void cleanUp();

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

public:
	SVectorTest();
	virtual ~SVectorTest();

	TestErrors runTest();
	inline string toString() { return "SVectorTest";};

};



#endif /* INCLUDE_SVECTORTEST_H_ */
