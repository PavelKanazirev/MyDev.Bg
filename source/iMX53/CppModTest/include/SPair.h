/**
 * Contains SPair implementation.
 * @file	SPair.h
 * @ingroup	sstl
 * 
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SPAIR_H_
#define SPAIR_H_

namespace common {

/**
 * STL like pair class
 * @author		matthias.kessler
 * @version		$Revision: 1.1 $
 * @date		$Date: 2008/08/25 13:21:42 $
 * @param		T1	type of first member
 * @param		T2	type of second member
 * 
 * @pre			T1 has default constructor
 * @pre			T2 has default constructor
 */
template<typename T1, typename T2>
struct SPair
{
	/** type of first element */
	typedef T1 first_type;
	/** type of second element */
	typedef T2 second_type;
	/** first element */
	first_type first;
	/** second element */
	second_type second;

	/**
	 * default constructor
	 */
	SPair() : 
		first(), 
		second()
	{}
	
	/**
	 * constructs an initialzed pair
	 * @param	v1		first value of pair
	 * @param	v2		second value of pair
	 * 
	 * @pre		T1 has copy constructor
	 * @pre		T2 has copy constructor
	 * @post	first == v1
	 * @post	second == v2
	 */
	SPair(const first_type& v1, const second_type& v2) : 
		first(v1), 
		second(v2)
	{}
	
	SPair& operator=(const SPair& rhs)
	{
		first 	= rhs.first;
		second 	= rhs.second;
		return *this;
	}
};

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x and y are equal
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator==(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return x.first == y.first && x.second == y.second;
}

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x and y are not equal
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator!=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(x == y);
}

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x is less than y
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator<(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x is greater than y
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator>(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return y < x;
}

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x is less or equal than y
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator<=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(y < x);
}

/**
 * comparison operator for SPair
 * @param	T1	first type
 * @param	T2	second type
 * @param	x	first pair to compare
 * @param	y	second pair to compare
 * @return	comparison result
 * 			- true if x is greater or equal than y
 * 			- false otherwise
 */
template<typename T1, typename T2>
inline bool operator>=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(x < y);
}

} /* namespace common */

#endif /*SPAIR_H_*/
