/*
 * SPairTest.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SPAIRTEST_H_
#define INCLUDE_SPAIRTEST_H_

#include "ITestable.h"
#include "TestErrors.h"

class SPairTest : public ITestable {
private:
	TestErrors testDefaultConstructor();
	TestErrors initConstructor();
	TestErrors assignment();

public:
	SPairTest(){};
	virtual ~SPairTest(){};
	TestErrors runTest();

	inline string toString() { return "SPairTest";};
};



#endif /* INCLUDE_SPAIRTEST_H_ */
