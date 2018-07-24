/**
 * Contains SMap implementation.
 * @file	SMap.h
 * @ingroup	sstl
 * 
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SMAP_H_
#define SMAP_H_

#include "SMapBase.h"
#include "SFunction.h"
#include "SPair.h"

/**
 * hashmap
 * @author	matthias.kessler
 * 
 * @param	Key				type of keys in map
 * @param	T				type of values in map
 * @param	MaxSize			maximum number of elements stored in map
 * @param	HashFunction	unary function to compute hash value
 * @param	Compare			binary function to check equality of two keys
 * 
 * @pre		T has default constructor
 * @pre		Key has default constructor

 * @note
 * The default size of a map is 10.
 * 
 * @section	Description
 * SMap is an adapter to SMapBase providing it with all neccessary
 * memory which is statically allocated at compile time.
 * 
 * @see		SHash
 * @see		SEqualTo
 * @see		SMapBase
 */
template<
	typename Key, 
	typename T, 
	unsigned MaxSize = 10,
	typename HashFunction = SHash<Key>,
	typename KeyEqual = SEqualTo<Key> >
class SMap : 
	public SMapBase<Key, T, HashFunction, KeyEqual>
{
private:
	/** type of map itsself */
	typedef SMap<Key, T, MaxSize, HashFunction, KeyEqual>	self_type;
	/** type of maps base class */
	typedef SMapBase<Key, T, HashFunction, KeyEqual>		self_base_type;
	/** enum representing the internal state of a map entry */
	typedef typename self_base_type::SMapEntryState			SMapEntryState;
public:
	/** const reference to value */
	typedef typename STypeTraits<T>::const_reference		const_reference;
	/** unsigned integral type */
	typedef typename STypeTraits<T>::size_type				size_type;
	/** constant representing the maximum size of the map */
	static const size_type MAX_SIZE = MaxSize;
	
	/**
	 * default constructor
	 * @post	size() == 0
	 * @post	max_size() == MaxSize
	 */
	SMap() : 
		self_base_type(fData, MaxSize)
	{
	}

	/**
	 * constructor initializing values in map with a default value
	 * @param	value	value to initialize maps entries with
	 * @post	size() == 0;
	 * @post	max_size() == MaxSize
	 * 
	 * This constructor is for example used if the value type of the
	 * map is a pointer. It is often useful in initialize pointer
	 * with NULL to have a default value
	 * @code
	 * void* init = 0L;
	 * //init all pointers with NULL
	 * SMap<int, void*> map(init);
	 * @endcode
	 */
	SMap(const_reference value) : 
		self_base_type(fData, MaxSize)
	{
		initialize(value);
	}
	
private:
	/** internal memory needed by SMapBase */
	SPair<SMapEntryState, SPair<Key, T> >	fData[MaxSize];
};

#endif /*SMAP_H_*/
