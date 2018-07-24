/*
 * FunctorCaller.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#include "FunctorCaller.h"

namespace common {

common::FunctorCaller::FunctorCaller(Functor& _cb): my_cb(_cb)
{

}

void FunctorCaller::signal()
{
    my_cb.operator ()();
}

} /* namespace common */
