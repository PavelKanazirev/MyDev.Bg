/*
 * FunctorCaller.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef FUNCTORCALLER_H_
#define FUNCTORCALLER_H_

#include "Functor.h"

class FunctorCaller {
private:
	Functor& my_cb;	// will type "beer"

public:
	FunctorCaller(Functor& _cb);
    void drink();	// will type "drink" and call the functor
};

#endif /* FUNCTORCALLER_H_ */
