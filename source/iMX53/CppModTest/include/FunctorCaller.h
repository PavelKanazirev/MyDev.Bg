/*
 * FunctorCaller.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef FUNCTORCALLER_H_
#define FUNCTORCALLER_H_

#include "Functor.h"

namespace common {

class FunctorCaller {
public:
	Functor& my_cb;

public:
	FunctorCaller(Functor& _cb);
    void signal();
};

} /* namespace common */

#endif /* FUNCTORCALLER_H_ */
