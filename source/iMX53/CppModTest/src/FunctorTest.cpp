/*
 * FunctorTest.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#include "FunctorTest.h"
#include "Functor.h"
#include "FunctorCaller.h"

FunctorTest::FunctorTest() {
	// TODO Auto-generated constructor stub

}

FunctorTest::~FunctorTest() {
	// TODO Auto-generated destructor stub
}

void FunctorTest::run() {
	Functor a;
	FunctorCaller at(a);

	at.drink();
}

