/*
 * Functor.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#include <iostream>

#include "Functor.h"

using namespace std;

namespace common {

void Functor::operator()()
    {
    	cout <<__PRETTY_FUNCTION__<<endl;
    }

} /* namespace common */
