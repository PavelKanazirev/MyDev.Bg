/*
 * SBaseTypes.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef SBASETYPES_H_
#define SBASETYPES_H_

template<typename T>
struct STypeTraits
{
	typedef unsigned int	size_type;
	typedef signed int		difference_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef const T&		const_reference;
};

#endif /*SBASETYPES_H_*/
