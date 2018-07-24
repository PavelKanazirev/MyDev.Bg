/*
 * SNormalIterator.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef SNORMALITERATOR_H_
#define SNORMALITERATOR_H_

#include "SIteratorBaseTypes.h"

//forward declarations
template<typename Iterator, typename Container>
class SNormalIterator;

template <typename Iterator, typename Container>
bool operator==(
	const SNormalIterator<Iterator, Container>&  lhs, 
	const SNormalIterator<Iterator, Container>& rhs);
	
template <typename Iterator, typename Container>
bool operator!=(
	const SNormalIterator<Iterator, Container>&  lhs, 
	const SNormalIterator<Iterator, Container>& rhs);

template<
	typename Iterator, 
	typename Container>
class SNormalIterator
{
public:
	/** the iterators category */
	typedef SRandomAccessIteratorTag							iterator_category;
	/** value type of iterator */
	typedef typename SIteratorTraits<Iterator>::value_type		value_type;
	/** reference to value */
	typedef typename SIteratorTraits<Iterator>::reference		reference;
	/** pointer to value */
	typedef typename SIteratorTraits<Iterator>::pointer			pointer;
	/** signed integral type */
	typedef typename SIteratorTraits<Iterator>::difference_type	difference_type;
	
	/**
	 * default constructor
	 */
	SNormalIterator()
		: fCurrent()
	{}
	
	explicit SNormalIterator(const Iterator& i)
		: fCurrent(i)
	{}

	SNormalIterator(const SNormalIterator& rhs)
		: fCurrent(rhs.fCurrent)
	{}
	
	SNormalIterator& operator=(const SNormalIterator& rhs)
	{
		fCurrent = rhs.fCurrent;
		return *this;
	}

	SNormalIterator& operator=(const Iterator& i)
	{
		fCurrent = i;
		return*this;
	}
	
	reference operator*() const
	{
		return *fCurrent;
	}
	
	pointer operator->() const
	{
		return fCurrent;
	}
	
	SNormalIterator& operator++()
	{
		++fCurrent;
		return *this;
	}

	SNormalIterator& operator--()
	{
		--fCurrent;
		return *this;
	}
	
	reference operator[](const difference_type& n)
	{
		return fCurrent[n];
	}
	
	SNormalIterator& operator+=(const difference_type& n)
	{
		fCurrent += n;
		return *this;
	}

	SNormalIterator& operator-=(const difference_type& n)
	{
		fCurrent -= n;
		return *this;
	}
private:

	friend bool operator==<Iterator, Container>(
		const SNormalIterator<Iterator, Container>&  lhs, 
		const SNormalIterator<Iterator, Container>& rhs);
	friend bool operator!=<Iterator, Container>(
		const SNormalIterator<Iterator, Container>&  lhs, 
		const SNormalIterator<Iterator, Container>& rhs);

	Iterator	fCurrent;
};

template <typename Iterator, typename Container>
inline bool operator==(
	const SNormalIterator<Iterator, Container>&  lhs, 
	const SNormalIterator<Iterator, Container>& rhs)
{
	return lhs.fCurrent == rhs.fCurrent;
}

template <typename Iterator, typename Container>
inline bool operator!=(
	const SNormalIterator<Iterator, Container>&  lhs, 
	const SNormalIterator<Iterator, Container>& rhs)
{
	return lhs.fCurrent != rhs.fCurrent;
}

#endif /*SNORMALITERATOR_H_*/
