/*
 * SVectorBase.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef _SVECTORBASE_H_
#define _SVECTORBASE_H_

#include "SBaseTypes.h"
#include "SNormalIterator.h"
#include "SAlgorithm.h"
#include <cassert>


template<typename T>
class SVectorBase
{
private:
	typedef SVectorBase<T>								self_type;
public:
	typedef typename STypeTraits<T>::value_type			value_type;
	typedef typename STypeTraits<T>::pointer			pointer;
	typedef typename STypeTraits<T>::reference			reference;
	typedef const T&									const_reference;
	typedef typename STypeTraits<T>::size_type			size_type;
	typedef typename STypeTraits<T>::difference_type	difference_type;
	typedef SNormalIterator<pointer, self_type>			iterator;

	explicit SVectorBase(value_type data[], size_type numberOfValues) :
		fData(data),
		fMaxSize(numberOfValues),
		fSize(0)
	{
		assert(fData != 0L);
		assert(fMaxSize > 0);
	}

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

		initialize(defaultValue, fSize);
	}

	void initialize(const_reference value, size_type n)
	{
		assert(n <= fMaxSize);
		for (size_type i = 0; i < n; ++i)
		{
			fData[i] = value;
		}
	}

	size_type size() const
	{
		return fSize;
	}

	size_type max_size() const
	{
		return fMaxSize;
	}

	bool empty() const
	{
		return (fSize == 0);
	}

	bool full() const
	{
		return (fSize == fMaxSize);
	}

	const_reference operator[](size_type position) const
	{
		assert( position < fSize );
		return fData[position];
	}

	reference operator[](size_type position)
	{
		return const_cast<reference>(
			static_cast<const self_type&>(
				*this)[position]);
	}

	void resize(size_type n, const T& t);

	void resize(size_type n)
	{
		T v;
		resize(n, v);
	}

	reference push_back()
	{
		assert(fSize < fMaxSize);
		return fData[fSize++];
	}

	void pop_back()
	{
		assert(fSize > 0);
		fSize--;
	}

	reference front()
	{
		assert( fSize > 0 );
		return fData[0];
	}

	reference back()
	{
		assert( fSize > 0 );
		return fData[fSize - 1];
	}

	void clear()
	{
		fSize = 0;
	}

	size_type erase(const value_type& v);

	bool contains(const value_type& v)
	{
		return (sfind(begin(), end(), v) != end());
	}

	iterator begin()
	{
		return iterator(&fData[0]);
	}

	iterator end()
	{
		return iterator(&fData[fSize]);
	}
private:
	SVectorBase();
	SVectorBase(const SVectorBase& rhs);
	SVectorBase& operator=(const SVectorBase& rhs);

	value_type*	fData;
	size_type	fMaxSize;
	size_type	fSize;
};

template<typename T>
void SVectorBase<T>::resize(size_type n, const T& t)
{
	assert(n <= fMaxSize);
	if (size() < n)
	{
		do
		{
			push_back() = t;
		} while (size() < n);
	}
	else
	{
		fSize = n;
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
