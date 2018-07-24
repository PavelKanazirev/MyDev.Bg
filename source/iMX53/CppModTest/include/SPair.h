/*
 * SPair.h
 *
 *  Created on: Dec 08, 2012
 *      Author: pavel
 */
#ifndef SPAIR_H_
#define SPAIR_H_

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

template<typename T1, typename T2>
inline bool operator==(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return x.first == y.first && x.second == y.second;
}

template<typename T1, typename T2>
inline bool operator!=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(x == y);
}

template<typename T1, typename T2>
inline bool operator<(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template<typename T1, typename T2>
inline bool operator>(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return y < x;
}

template<typename T1, typename T2>
inline bool operator<=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(y < x);
}

template<typename T1, typename T2>
inline bool operator>=(const SPair<T1, T2>& x, const SPair<T1, T2>& y)
{
	return !(x < y);
}

#endif /*SPAIR_H_*/
