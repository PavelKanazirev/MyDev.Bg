/*
 * SIteratorBaseTypes.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef SITERATORBASETYPES_H_
#define SITERATORBASETYPES_H_

struct SInputIteratorTag {};
struct SOutputIteratorTag {};
struct SForwardIteratorTag : public SInputIteratorTag {};
struct SBidirectionalIteratorTag : public SForwardIteratorTag {};
struct SRandomAccessIteratorTag : public SBidirectionalIteratorTag {};

template<
	typename Category, 
	typename T, 
	typename Distance = signed int,
	typename Pointer = T*, 
	typename Reference = T&>
struct SIterator
{
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
}; 

template<typename Iterator>
struct SIteratorTraits
{
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
};

template<typename T>
struct SIteratorTraits<T*>
{
	typedef SRandomAccessIteratorTag 	iterator_category;
	typedef T							value_type;
	typedef signed int					difference_type;
	typedef value_type*					pointer;
	typedef value_type&					reference;
};


template<typename T>
struct SIteratorTraits<const T*>
{
	typedef SRandomAccessIteratorTag 	iterator_category;
	typedef T							value_type;
	typedef signed int					difference_type;
	typedef const value_type*			pointer;
	typedef const value_type&			reference;
};

#endif /*SITERATORBASETYPES_H_*/
