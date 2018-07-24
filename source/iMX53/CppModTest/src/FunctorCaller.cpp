/*
 * FunctorCaller.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */
#include <iostream>

#include "FunctorCaller.h"

using namespace std;

FunctorCaller::FunctorCaller(Functor& _cb): my_cb(_cb)
{

}

void FunctorCaller::drink()
{
	cout <<"drink ";
    my_cb.operator ()();
}

