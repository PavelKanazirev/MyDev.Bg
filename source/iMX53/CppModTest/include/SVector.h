/*
 * SVector.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef SVECTOR_H_
#define SVECTOR_H_

#include "SVectorBase.h"

template<
	typename T,
	unsigned int MaxSize = 10>
class SVector :
	public SVectorBase<T>
{
private:
	typedef SVectorBase<T>								self_base_type;
public:
	typedef typename STypeTraits<T>::const_reference	const_reference;
	typedef typename STypeTraits<T>::size_type			size_type;
	static const size_type	MAX_SIZE = MaxSize;

	SVector() :
		self_base_type(&fValues[0], MaxSize)
	{}

	explicit SVector(size_type n) :
		self_base_type(&fValues[0], MaxSize)
	{
		resize(n);
	}

	explicit SVector(size_type n, const_reference t) :
		self_base_type(&fValues[0], MaxSize, n, t)
	{}

private:
	T		fValues[MaxSize];
};

#endif /*SVECTOR_H_*/
