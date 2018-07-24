/**
 * Contains functor base classes.
 * @file	SFunction.h
 * @ingroup	sstl
 * 
 * (c) Copyright 2012, Lear Corporation
 */
#ifndef SFUNCTION_H_
#define SFUNCTION_H_

/**
 * unary function base class declaring types
 * @param	Arg		type of argument
 * @param	Result	type of result
 */
template<typename Arg, typename Result>
struct SUnaryFunction
{
	typedef Arg		argument_type;
	typedef Result	result_type;
};

/**
 * binary function base class declaring types
 * @param	Arg1	type of first argument
 * @param	Arg2	type of second argument
 * @param	Result	type of result
 */
template<typename Arg1, typename Arg2, typename Result>
struct SBinaryFunction
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

/**
 * comparison function (less)
 * @param	T	type of arguments to compare
 */
template<typename T>
struct SLess : public SBinaryFunction<T, T, bool>
{
	/**
	 * @return	result of comparison
	 * 			- true if x < y
	 * 			- false otherwise
	 */
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

/**
 * comparison function (less or equal)
 * @param	T	type of arguments to compare
 */
template<typename T>
struct SLessEqual : public SBinaryFunction<T, T, bool>
{
	/**
	 * @return	result of comparison
	 * 			- true if x < y
	 * 			- false otherwise
	 */
	bool operator()(const T& x, const T& y) const
	{
		return x <= y;
	}
};

/**
 * comparison function (greater)
 * @param	T	type of arguments to compare
 */
template<typename T>
struct SGreater : public SBinaryFunction<T, T, bool>
{
	/**
	 * @return	result of comparison
	 * 			- true if x > y
	 * 			- false otherwise
	 */
	bool operator()(const T& x, const T& y) const
	{
		return x > y;
	}
};

/**
 * comparison function (greater or equal)
 * @param	T	type of arguments to compare
 */
template<typename T>
struct SGreaterEqual : public SBinaryFunction<T, T, bool>
{
	/**
	 * @return	result of comparison
	 * 			- true if x > y
	 * 			- false otherwise
	 */
	bool operator()(const T& x, const T& y) const
	{
		return x >= y;
	}
};

/**
 * comparison function (equal to)
 * @param	T	type of arguments to compare
 */
template<typename T>
struct SEqualTo : public SBinaryFunction<T, T, bool>
{
	/**
	 * @return	result of comparison
	 * 			- true if x == y
	 * 			- false otherwise
	 */
	bool operator()(const T& x, const T& y) const
	{
		return x == y;
	}
};

#endif /*SFUNCTION_H_*/
