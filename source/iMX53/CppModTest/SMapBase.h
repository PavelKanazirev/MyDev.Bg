/**
 * Contains SMapBase and SMapBaseIterator implementations.
 * @file	SMapBase.h
 * @ingroup	sstl
 *
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SMAPBASE_H_
#define SMAPBASE_H_

#include "SBaseTypes.h"
#include "SPair.h"
#include "SFunction.h"
#include "SIteratorBaseTypes.h"
#include <cassert>

//forward declarations
template<typename Map>
class SMapBaseIterator;

template<typename Map>
bool operator==(
	const SMapBaseIterator<Map>& lhs,
	const SMapBaseIterator<Map>& rhs);

template<typename Map>
bool operator!=(
	const SMapBaseIterator<Map>& lhs,
	const SMapBaseIterator<Map>& rhs);

/**
 * hash function
 * @param	T	type to generate hash of
 *
 * Default implementation for all types castable to unsigned.
 */
template<typename T>
struct SHash :
	 public SUnaryFunction<T, unsigned>
{
	/**
	 * @param	t	value to hash
	 * @return	hash (t casted to unsigned)
	 */
	unsigned operator()(const T& t) const
	{
		return static_cast<unsigned>(t);
	}
};

/**
 * STL like hash map
 * @author	matthias.kessler
 * @param	Key				type of keys in map
 * @param	T				type of values in map
 * @param	HashFunction	unary function to compute hash value
 * @param	Compare			binary function to check equality of two keys
 *
 * This map has no internal memory for its elements. The are passed
 * by its constructor.
 *
 * @section		Implementation
 * The map implements open hashing (i.e. no buckets) and searches
 * linear for free places in the maps underlying data structure.
 * Thus using a bad hash function the map may degenerate to a linear list.
 *
 * @subsection	Structure Internal data
 * Initially all entries in a map a marked FREE. Once occupied by a value
 * their state changes to SET. When being deleted the state changes to
 * DELETED.
 * These states are necessary because of the nature of the open
 * hashing. To find a entry to a given key its hash value is computed
 * and taken modulo the maxSize (size of underlying array) of the map.
 * It is obvious that more than one key may result in the same index to the
 * array. Therefore the keys of entries have to be compared starting at
 * the computed index.
 * If these states were not used the searching would stop in the worst
 * case (if the key is not in the map) after a complete iteration over all
 * elements of the underlying array. Using the states allows the search
 * to stop at the first entry marked FREE.
 * As a consequence erasing elements from the map results in a process
 * of cleaning up the states of the maps entries, which may be worst
 * case O(maxSize).
 */
template<
	typename Key,
	typename T,
	typename HashFunction,
	typename KeyEqual>
class SMapBase
{
private:
	/** the maps type itsself */
	typedef SMapBase<Key, T, HashFunction, KeyEqual>	self_type;
public:
	/**
	 * States a map entry may have.
	 */
	enum SMapEntryState
	{
		/** entry is not set */
		SMAP_FREE = 0,
		/** entry has valid content */
		SMAP_SET,
		/** content of entry has been deleted */
		SMAP_DELETED
	};
	/** type of keys stored in map */
	typedef Key											key_type;
	/** pairs of Key and T are used in map */
	typedef SPair<Key, T>								value_type;
	/** type of helper structure used in map */
	typedef SPair<SMapEntryState, value_type>			data_base_type;
	/** key equal functor */
	typedef KeyEqual									key_equal;
	/** hash functor */
	typedef HashFunction								hasher;
	/** type of values to keys stored in map */
	typedef typename STypeTraits<T>::value_type			data_type;
	/** pointer to value */
	typedef typename STypeTraits<T>::pointer			pointer;
	/** reference to value */
	typedef typename STypeTraits<T>::reference			reference;
	/** const reference to value */
	typedef typename STypeTraits<T>::const_reference	const_reference;
	/** unsigned integral type */
	typedef typename STypeTraits<T>::size_type			size_type;
	/** signed integral type */
	typedef typename STypeTraits<T>::difference_type	difference_type;
	/** maps iterator */
	typedef SMapBaseIterator<self_type>					iterator;
	/** constant representing an illegal index */
	static const size_type ILLEGAL_INDEX = 0xFFFFFFFF;

	/**
	 * constructor
	 * @param	container	array of data_base_type to operate on
	 * @param	maxSize		size of container
	 * @pre		container != 0L
	 * @pre		maxSize < ILLEGAL_INDEX
	 * @post	size() == 0
	 * @post	max_size() == maxSize
	 * @throws	assertion
	 */
	explicit SMapBase(data_base_type container[], size_type maxSize) :
		fData(container),
		fMaxSize(maxSize),
		fSize(0)
	{
		assert(container != 0L);
		assert(fMaxSize < ILLEGAL_INDEX);
		initialize();
	}

	/**
	 * @return	current number of elements stored in map
	 */
	size_type size() const
	{
		return fSize;
	}

	/**
	 * @return	maximum number of elements map can take
	 */
	size_type max_size() const
	{
		return fMaxSize;
	}

	/**
	 * @return	state of map
	 * 			- true if map is empty
	 * 			- false otherwise
	 */
	bool empty() const
	{
		return fSize == 0;
	}

	/**
	 * @return	state of map
	 * 			- true if map is full
	 * 			- false otherwise
	 */
	bool full() const
	{
		return fSize == fMaxSize;
	}

	/**
	 * clears map
	 * @post	size() == 0
	 */
	void clear()
	{
		fSize = 0;
		initialize();
	}

	/**
	 * seeks an element in the map and returns its index
	 * @param	k	key to seek in map
	 * @return	index of k
	 * 			- ILLEGAL_INDEX if k is not in map
	 *
	 * @see		at()
	 */
	size_type indexOf(const key_type& k) const
	{
		size_type index = indexOfHelper(k);
		if ((index == ILLEGAL_INDEX) || (fData[index].first != SMAP_SET))
		{//k is not in map
			return ILLEGAL_INDEX;
		}
		else
		{//k is at index
			return index;
		}
	}
	/**
	 * read access to element at a given position
	 * @param	position	index of element to get
	 * @return	const reference to value at position
	 * @pre		position < max_size()
	 * @throws	assertion
	 */
	reference at(size_type position) const
	{
		assert(position < fMaxSize);
		return fData[position].second.second;
	}

	/**
	 * random access operator
	 * @param	k	key of element to access
	 * @return	reference to value for k
	 * @pre		if full() k must be in map
	 * @throws	assertion
	 *
	 * @warning
	 * As all memory of this map is statically allocated this
	 * operator will throw an assertion if a new element is
	 * accessed on a full map.
	 */
	reference operator[](const key_type& k)
	{
		size_type index = indexOfHelper(k);
		assert(index != ILLEGAL_INDEX);
		if (fData[index].first != SMAP_SET)
		{//k is not yet in map --> write access
			++fSize;
			//change state of entry
			fData[index].first = SMAP_SET;
			//set key of entry
			fData[index].second.first = k;
		}
		return fData[index].second.second;
	}

	/**
	 * erases all elements with a given key
	 * @param	k	key whose values should be erased from map
	 * @return	number of elements erased
	 *
	 * @note
	 * This method may have a complexity of O(maxSize) because
	 * the internal data structures are cleaned up during this
	 * operation.
	 */
	size_type erase(const key_type& k);

	/**
	 * counts elements with a given key
	 * @param	k	key to count
	 * @return	number of elements with key k
	 */
	size_type count(const key_type& k) const
	{
		size_type index = indexOfHelper(k);
		if ((index == ILLEGAL_INDEX) || (fData[index].first != SMAP_SET))
		{//k is not in map
			return 0;
		}
		else
		{
			return 1;
		}
	}

	/**
	 * initializes all values in the map with a given value
	 * @param	value	initial value for map entries
	 */
	void initialize(const_reference value)
	{
		initialize();
		for (size_type i = 0; i < fMaxSize; ++i)
		{
			fData[i].second.second = value;
		}
	}

	/**
	 * searches for a key in the map
	 * @param	k	key to find
	 * @return	iterator to element with key k
	 * 			- end() if k is not in map
	 */
	iterator find(const key_type& k)
	{
		size_type position = indexOf(k);
		return iterator(position, *this);
	}

	/**
	 * searches for a range of elements with a given key
	 * @param	k	key to find
	 * @return	pair of iterators representing the result range
	 * 			- first is the begin iterator of the range
	 * 			- second is the end iterator of the range
	 */
	SPair<iterator, iterator> equal_range(const key_type& k)
	{
		return SPair<iterator, iterator>(find(k), end());
	}

	/**
	 * @return	iterator to first element in map
	 *
	 * @note
	 * As a hashmap is not specifically ordered the order of the
	 * elements may be unexpected.
	 */
	iterator begin()
	{
		//get first set position
		size_type position = nextOccupiedPosition(0);
		return iterator(position, *this);
	}

	/**
	 * @return	iterator one past end of map
	 */
	iterator end()
	{
		return iterator(ILLEGAL_INDEX, *this);
	}
private:
	//friends
	friend class SMapBaseIterator<self_type>;
	//no copies
	SMapBase(const SMapBase& rhs);
	SMapBase& operator=(const SMapBase& rhs);

	/**
	 * cleans up internal data structures
	 * @param	index		position to start cleaning up
	 *
	 * All elements beginning with index that are marked deleted will be
	 * removed backwards.
	 */
	void cleanUpBackwards(size_type index);

	void cleanUpCompletely(size_type index);

	/**
	 * initializes the internal data structures
	 */
	void initialize()
	{
		for (size_type i = 0; i < fMaxSize; ++i)
		{
			fData[i].first = SMAP_FREE;
		}
	}

	/**
	 * searches for an element with key k in SMapBase
	 * @param	k	key to search for
	 * @return	index of search result
	 * 			- index of slot for k if k is in map
	 * 			- index of first free slot if k is not in map
	 * 			- ILLEGAL_INDEX if k is not in map and there are no free slots
	 */
	size_type indexOfHelper(const key_type& k) const;

	/**
	 * returns the next occupied slot in the map from a given position
	 * @param	position	index to start from
	 * @return	next used slot
	 * 			- ILLEGAL_INDEX if there is no free position until end of map
	 */
	size_type nextOccupiedPosition(size_type position);

	//fields
	HashFunction		fHash;
	data_base_type*		fData;
	key_equal			fKeyEqual;
	size_type			fMaxSize;
	size_type			fSize;
};

template<typename Key, typename T, typename HashFunction, typename KeyEqual>
typename SMapBase<Key, T, HashFunction, KeyEqual>::size_type 
SMapBase<Key, T, HashFunction, KeyEqual>::erase(const key_type& k)
{
	size_type index = indexOfHelper(k);
	if ((index == ILLEGAL_INDEX)
		|| (fData[index].first != SMAP_SET))
	{//k is not in map --> we erased 0 elements
		return 0;
	}
	else
	{//k is at index
		//mark slot deleted
		fData[index].first = SMAP_DELETED;
		//decrement size
		--fSize;
		if (fData[(index + 1) % fMaxSize].first == SMAP_FREE)
		{//seek if there is a chain of deleted elements to free (backwards)
			cleanUpBackwards(index);
		}
		else
		{
			size_type right = (index + 1) % fMaxSize;
			size_type left	= (index == 0) ? (fMaxSize - 1) : index - 1;
			if (fData[right].first == SMAP_DELETED &&
				fData[left].first == SMAP_DELETED)
			{
				cleanUpCompletely(index);
			}
		}
		return 1;
	}
}

template<typename Key, typename T, typename HashFunction, typename KeyEqual>
void SMapBase<Key, T, HashFunction, KeyEqual>::cleanUpBackwards(size_type index)
{
	while (fData[index].first == SMAP_DELETED)
	{
		fData[index].first = SMAP_FREE;
		index = (index == 0) ? (fMaxSize - 1) : index - 1;
	}
}

template<typename Key, typename T, typename HashFunction, typename KeyEqual>
void SMapBase<Key, T, HashFunction, KeyEqual>::cleanUpCompletely(size_type index)
{
	size_type overflowAt = index;
	bool completelyErased = true;
	do
	{
		index = (index + 1) % fMaxSize;
		if (fData[index].first != SMAP_DELETED)
		{
			completelyErased = false;
		}
	} while (completelyErased && (index != overflowAt));
	if (completelyErased)
	{
		initialize();
	}
}

template<typename Key, typename T, typename HashFunction, typename KeyEqual>
typename SMapBase<Key, T, HashFunction, KeyEqual>::size_type 
SMapBase<Key, T, HashFunction, KeyEqual>::indexOfHelper(const key_type& k) const
{
	size_type first_free	= ILLEGAL_INDEX;
	//get initial index
	size_type index 		= fHash(k) % fMaxSize;
	//store overflow index
	size_type overflowAt 	= index;
	while ((fData[index].first != SMAP_FREE) &&
		(!fKeyEqual(fData[index].second.first, k)))
	{//search for k in fData
		if ((fData[index].first == SMAP_DELETED) &&
			(first_free == ILLEGAL_INDEX))
		{
			first_free = index;
		}
		index = (index + 1) % fMaxSize;
		if (index == overflowAt)
		{//we did not find k and map is full
			return first_free;
		}
	}
	return index;
}

template<typename Key, typename T, typename HashFunction, typename KeyEqual>
typename SMapBase<Key, T, HashFunction, KeyEqual>::size_type 
SMapBase<Key, T, HashFunction, KeyEqual>::nextOccupiedPosition(size_type position)
{
	if (position == fMaxSize)
	{
		return ILLEGAL_INDEX;
	}
	while (fData[position].first != SMAP_SET)
	{//search for next set element
		position = (position + 1);
		if (position == fMaxSize)
		{
			return ILLEGAL_INDEX;
		}
	}
	return position;
}

/**
 * iterator for map
 * @author	matthias.kessler
 *
 * @param	Map		the type of map this iterator operates on
 */
template<typename Map>
class SMapBaseIterator
{
public:
	/** the iterators category */
	typedef SForwardIteratorTag						iterator_category;
	/** type of value iterator points to (pair of const key and value) */
	typedef typename SIteratorTraits<
		typename Map::value_type*>::value_type 		value_type;
	/** reference to a value */
	typedef typename SIteratorTraits<
		typename Map::value_type*>::reference	 	reference;
	/** pointer to a value */
	typedef typename SIteratorTraits<
		typename Map::value_type*>::pointer 		pointer;
	/** signed integral type */
	typedef typename SIteratorTraits<
		typename Map::value_type*>::difference_type	difference_type;
	/** unsigned integral type */
	typedef typename Map::size_type 				size_type;

	/**
	 * default constructor
	 */
	SMapBaseIterator() :
		fCurrentPosition(Map::ILLEGAL_INDEX),
		fpMap(0L)
	{}

	/**
	 * constructor
	 * @param	p	current position in map
	 * @param	m	Map this iterator is associated with
	 */
	explicit SMapBaseIterator(typename Map::size_type p, Map& m) :
		fCurrentPosition(p),
		fpMap(&m)
	{}

	/**
	 * copy constructor
	 * @param	rhs	iterator to copy from
	 * @post	*this == rhs
	 */
	SMapBaseIterator(const SMapBaseIterator& rhs) :
		fCurrentPosition(rhs.fCurrentPosition),
		fpMap(rhs.fpMap)
	{}

	/**
	 * assignment operator
	 * @param	rhs	iterator to copy from
	 * @return	copied iterator
	 * @post	*this == rhs
	 */
	SMapBaseIterator& operator=(const SMapBaseIterator& rhs)
	{
		fCurrentPosition = rhs.fCurrentPosition;
		fpMap = rhs.fpMap;
		return *this;
	}

	/**
	 * @return	reference to current value
	 */
	reference operator*() const
	{
		return fpMap->fData[fCurrentPosition].second;
	}

	/**
	 * @return	pointer to current value
	 */
	pointer operator->() const
	{
		return &(fpMap->fData[fCurrentPosition].second);
	}

	/**
	 * prefix increment operator
	 * @return	iterator pointing to next element
	 * @post	iterator points to next entry of map
	 */
	SMapBaseIterator& operator++()
	{
		fCurrentPosition = fpMap->nextOccupiedPosition(fCurrentPosition + 1);
		return *this;
	}
private:
	//friends
	friend bool operator==<Map>(
		const SMapBaseIterator<Map>& lhs,
		const SMapBaseIterator<Map>& rhs);
	friend bool operator!=<Map>(
		const SMapBaseIterator<Map>& lhs,
		const SMapBaseIterator<Map>& rhs);
	//fields
	typename Map::size_type		fCurrentPosition;
	Map*						fpMap;
};

/**
 * comparison operator
 * @param	Map	type of iterators map
 * @param	lhs	first iterator to compare
 * @param	rhs	second iterator to compare
 * @return	result of comparison
 * 			- true if lhs and rhs are equal
 * 			- false otherwise
 */
template<typename Map>
inline bool operator==(
	const SMapBaseIterator<Map>& lhs,
	const SMapBaseIterator<Map>& rhs)
{
	return ((lhs.fpMap == rhs.fpMap) && (lhs.fCurrentPosition == rhs.fCurrentPosition));
}

/**
 * comparison operator
 * @param	Map	type of iterators map
 * @param	lhs	first iterator to compare
 * @param	rhs	second iterator to compare
 * @return	result of comparison
 * 			- true if lhs and rhs are not equal
 * 			- false otherwise
 */
template<typename Map>
inline bool operator!=(
	const SMapBaseIterator<Map>& lhs,
	const SMapBaseIterator<Map>& rhs)
{
	return !(lhs == rhs);
}

#endif /*SMAPBASE_H_*/
