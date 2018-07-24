/**
 * Contains SVectorBase implementation.
 * @file	SVectorBase.h
 * @ingroup	sstl
 *
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef _SVECTORBASE_H_
#define _SVECTORBASE_H_

#include "SBaseTypes.h"
#include "SNormalIterator.h"
#include "SAlgorithm.h"
#include <cassert>

/**
 * STL like vector
 * @author	matthias.kessler
 *
 * @param	T		Type of elements stored in vector
 */
template<typename T>
class SVectorBase
{
private:
	/** type of vector itsself */
	typedef SVectorBase<T>								self_type;
public:
	/** type of values stored in vector */
	typedef typename STypeTraits<T>::value_type			value_type;
	/** pointer to value */
	typedef typename STypeTraits<T>::pointer			pointer;
	/** reference to value */
	typedef typename STypeTraits<T>::reference			reference;
	/** const reference to value */
	typedef const T&									const_reference;
	/** unsigned integral type */
	typedef typename STypeTraits<T>::size_type			size_type;
	/** signed integral type */
	typedef typename STypeTraits<T>::difference_type	difference_type;
	/** vectors iterator */
	typedef SNormalIterator<pointer, self_type>			iterator;

	/**
	 * constructor
	 * @param	data			array of elements of type T
	 * @param	numberOfValues	number of elements in array
	 * @pre		data != 0L
	 * @pre		numberOfValues > 0
	 * @post	size() == 0
	 * @post	max_size() == numberOfValues
	 * @throws	assertion
	 */
	explicit SVectorBase(value_type data[], size_type numberOfValues) :
		fData(data),
		fMaxSize(numberOfValues),
		fSize(0)
	{
		assert(fData != 0L);
		assert(fMaxSize > 0);
	}

	/**
	 * constructor setting a default size
	 * @param	data			array of elements of type T
	 * @param	numberOfValues	number of elements in array
	 * @param	defaultSize		initial size of SVectorBase
	 * @param	defaultValue	value, size elements of SVectorBase
	 * are initialized with
	 * @pre		data != 0L
	 * @pre		numberOfValues > 0
	 * @pre		numberOfValues >= size
	 * @post	size() == defaultSize
	 * @post	max_size() == numberOfValues
	 * @post	values [0...size-1] == defaultValue
	 * @throws	assertion
	 */
	explicit SVectorBase(
		value_type data[],
		size_type numberOfValues,
		size_type defaultSize,
		const_reference defaultValue) :
			fData(data),
			fMaxSize(numberOfValues),
			fSize(defaultSize)
	{
		assert(fData != 0L);
		assert(fMaxSize > 0);
		assert(fMaxSize >= fSize);
		//init defaultSize elements with value
		initialize(defaultValue, fSize);
	}

	/**
	 * initializes the first n elements with value
	 * @param	value	value to initialize elements with
	 * @param	n		number of elements to initialize
	 * @pre		n <= max_size()
	 * @post	values[0...n-1] == value
	 * @throws	assertion
	 */
	void initialize(const_reference value, size_type n)
	{
		assert(n <= fMaxSize);
		for (size_type i = 0; i < n; ++i)
		{
			fData[i] = value;
		}
	}

	/**
	 * @return	current number of elements stored in vector
	 */
	size_type size() const
	{
		return fSize;
	}

	/**
	 * @return	maximum number of elements that can be stored in vector
	 */
	size_type max_size() const
	{
		return fMaxSize;
	}

	/**
	 * @return	current state of vector
	 * 			- true if empty
	 * 			- false otherwise
	 */
	bool empty() const
	{
		return (fSize == 0);
	}

	/**
	 * @return	current state of vector
	 * 			- true if full
	 * 			- false otherwise
	 */
	bool full() const
	{
		return (fSize == fMaxSize);
	}

	/**
	 * random access operator
	 * @pre	position < size()
	 * @throws	assertion
	 */
	const_reference operator[](size_type position) const
	{
		assert( position < fSize );
		return fData[position];
	}

	/**
	 * random access operator (write)
	 * @see		operator[]()
	 */
	reference operator[](size_type position)
	{
		return const_cast<reference>(
			static_cast<const self_type&>(
				*this)[position]);
	}

	/**
	 * resizes vector and initializes additional elements
	 * @param	n	new size
	 * @param	t	value to initialize new elements with
	 * @pre		n <= MaxSize
	 * @post	size() = n
	 * @throws	assertion
	 */
	void resize(size_type n, const T& t);

	/**
	 * resizes vector using values default constructor
	 * @param	n	new size
	 * @pre		n <= MaxSize
	 * @post	size() = n
	 * @throws	assertion
	 */
	void resize(size_type n)
	{
		T v;
		resize(n, v);
	}

	/**
	 * adds an element to back of vector
	 * @return	reference to element at the end of vector
	 * @pre		!full()
	 * @post	size() == size() + 1
	 * @throws	assertion
	 */
	reference push_back()
	{
		assert(fSize < fMaxSize);
		return fData[fSize++];
	}

	/**
	 * removes the last element
	 * @pre		!empty()
	 * @post	size() == size() - 1
	 * @throws	assertion
	 */
	void pop_back()
	{
		assert(fSize > 0);
		fSize--;
	}

	/**
	 * write access
	 * @see		front()
	 */
	reference front()
	{
		assert( fSize > 0 );
		return fData[0];
	}

	/**
	 * write access
	 * @see		back()
	 */
	reference back()
	{
		assert( fSize > 0 );
		return fData[fSize - 1];
	}

	/**
	 * clears vector
	 * @post	empty()
	 * @post	size() == 0
	 */
	void clear()
	{
		fSize = 0;
		//TODO:call destructors
	}

	/**
	 * erases all elements equal to v
	 * @param	v	value to remove
	 * @return	number of elements removed
	 * @section	Complexity
	 * To keep to order of the elements in the vector the number of copy
	 * operations is (worst case) @p O(n*n).
	 */
	size_type erase(const value_type& v);

	/**
	 * searches the vector for occurence of v
	 * @param	v	value to search
	 * @return
	 * 			- true: vector contains v
	 * 			- false: vector does not contain v
	 */
	bool contains(const value_type& v) //TODO: const
	{
		return (sfind(begin(), end(), v) != end());
	}

	/**
	 * @return	iterator to first element
	 */
	iterator begin()
	{
		return iterator(&fData[0]);
	}

	/**
	 * @return	iterator one past last element
	 */
	iterator end()
	{
		return iterator(&fData[fSize]); //begin() + fSize
	}
private:
	//no default constructor
	SVectorBase();
	//no copies
	SVectorBase(const SVectorBase& rhs);
	SVectorBase& operator=(const SVectorBase& rhs);
	//fields
	value_type*	fData;
	size_type	fMaxSize;
	size_type	fSize;
};

template<typename T>
void SVectorBase<T>::resize(size_type n, const T& t)
{
	assert(n <= fMaxSize);
	if (size() < n)
	{//add elements
		do
		{
			push_back() = t;
		} while (size() < n);
	}
	else
	{//remove elements (or leave size)
		fSize = n;
		//call destructors ...->~T()
	}
}

template<typename T>
typename SVectorBase<T>::size_type SVectorBase<T>::erase(const value_type& v)
{
	size_type eraseCount = 0;
	size_type position = 0;
	while (position < size())
	{
		if (fData[position] == v)
		{
			for (size_type i = position; i < size() - 1; ++i)
			{
				fData[i] = fData[i + 1];
			}
			pop_back();
			++eraseCount;
		}
		else
		{
			++position;
		}
	}
	return eraseCount;
}

#endif //_SVECTORBASE_H_
