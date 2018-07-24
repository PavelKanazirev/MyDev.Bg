/*
 * SPairTest.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SPAIRTEST_H_
#define INCLUDE_SPAIRTEST_H_

#include "TestErrors.h"

class SPairTest {
private:
	TestErrors testDefaultConstructor();
	TestErrors testInitConstructor();
	TestErrors testAssignment();

public:
	TestErrors run();

	inline string toString() { return "SPairTest";};
};



#endif /* INCLUDE_SPAIRTEST_H_ */
