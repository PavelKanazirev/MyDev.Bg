/**
 * Contains SVector implementation.
 * @file	SVector.h
 * @ingroup	sstl
 *
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SVECTOR_H_
#define SVECTOR_H_

#include "SVectorBase.h"

/**
 * STL like vector with static memory allocation
 * @class	SVector
 * @author	matthias.kessler
 *
 * @param	T		Type of elements stored in SVector
 * @param	MaxSize	Capacity of SVector
 *
 * This class is an adapter to SVectorBase providing statically
 * allocated memory to it to operate on.
 *
 * @see		SVectorBase
 */
template<
	typename T,
	unsigned int MaxSize = 10>
class SVector :
	public SVectorBase<T>
{
private:
	typedef SVectorBase<T>								self_base_type;
public:
	/** const reference to element */
	typedef typename STypeTraits<T>::const_reference	const_reference;
	/** unsigned integral type */
	typedef typename STypeTraits<T>::size_type			size_type;
	/** maximum number of elements in SVector */
	static const size_type	MAX_SIZE = MaxSize;

	/**
	 * default constructor
	 * @pre		MaxSize > 0
	 * @post	empty()
	 * @post	size() == 0
	 * @post	max_size() == MaxSize
	 */
	SVector() :
		self_base_type(&fValues[0], MaxSize)
	{}

	/**
	 * constructor setting an initial size of vector
	 * @param	n		initial size of SVector
	 * @pre		MaxSize > 0
	 * @pre		n <= MaxSize
	 * @post	size() == n
	 * @post	max_size == MaxSize
	 */
	explicit SVector(size_type n) :
		self_base_type(&fValues[0], MaxSize)
	{
		resize(n);
	}

	/**
	 * constructor allowing a number of elements being initialized by a default value
	 * @param	n		initial size of SVector
	 * @param	t		value, size elements of SVectorBase are initialized with
	 * @pre		MaxSize > 0
	 * @pre		n <= MaxSize
	 * @post	size() == n
	 * @post	max_size == MaxSize
	 * @post	[0]...[n-1] == t
	 */
	explicit SVector(size_type n, const_reference t) :
		self_base_type(&fValues[0], MaxSize, n, t)
	{}

private:
	//fields
	T		fValues[MaxSize];
};

#endif /*SVECTOR_H_*/
