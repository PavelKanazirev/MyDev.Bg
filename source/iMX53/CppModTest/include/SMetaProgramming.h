/*
 * SMetaProgramming.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_SMETAPROGRAMMING_H_
#define INCLUDE_SMETAPROGRAMMING_H_

#include <iostream>

using namespace std;

// Factorial
template <int n>
struct Factorial {
  Factorial<n-1> prefact;
  const int value;
  Factorial() : value (n * prefact.value) { };
  template <int m>
  friend ostream& operator<<(ostream& outputStream, const Factorial<m> &obj);
};
template <int m>
ostream& operator<<(ostream& outputStream, const Factorial<m> &obj) {
  outputStream << obj.value << ',' << obj.prefact;
  return outputStream;
}
template <>
struct Factorial<0> {
  int value;
  Factorial() : value(1) { };
  friend ostream& operator<<(ostream& outputStream, const Factorial<0> &obj);
};
ostream& operator<<(ostream& outputStream, const Factorial<0> &obj) {
  outputStream << obj.value;
  return outputStream;
}


// Fibonacci numbers
template<int N>
class Fibonacci
{
public:
	enum { value = Fibonacci<N-1>::value + Fibonacci<N-2>::value };
};

template<>
class Fibonacci<1>
{
public:
      enum { value = 1 };
};

template<>
class Fibonacci<0>
{
public:
      enum { value = 0 };
};

// Generic exponent compile-time calculations. Pow<2,3>::result == 2^3
template <unsigned long B, unsigned long E>
struct Pow
{
    static const unsigned long result = B * Pow<B, E-1>::result;
};

template <unsigned long B>
struct Pow<B, 0>
{
    static const unsigned long result = 1;
};



#endif /* INCLUDE_SMETAPROGRAMMING_H_ */
