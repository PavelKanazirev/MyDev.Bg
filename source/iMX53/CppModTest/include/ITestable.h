/*
 * ITestable.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_ITESTABLE_H_
#define INCLUDE_ITESTABLE_H_

#include <string>

#include "TestErrors.h"

class ITestable {
public:
	virtual TestErrors runTest() = 0;
	virtual string toString() = 0;

};


#endif /* INCLUDE_ITESTABLE_H_ */
