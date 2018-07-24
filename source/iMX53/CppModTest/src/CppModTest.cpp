#include <iostream>

#include "TestErrors.h"
#include "FunctorTest.h"
#include "SPairTest.h"
#include "SVersionTest.h"

using namespace std;
using namespace common;

/*
void interesting()
{
	struct nothing { };
	// A simplified Q7.8 fixed-point representation.
	class fixed_point
	{
	public:
	// Construct from integer with left-shift.
	fixed_point(std::uint16_t u) : value(u << 8) { }
	// Create pi with the special constructor.
	static fixed_point value_pi()
	{
	return fixed_point(nothing(), 0x0324U);
	}
	private:
	std::uint16_t value;
	// Constructor from integer without left-shift.
	fixed_point(const nothing&,
	std::uint16_t u) : value(u) { }
	};


	constexpr unsigned int version = 3U;
	// Print error message if version is less than 2.
	static_assert(version >= 2U, "Version is too low!");

	template<const std::uint32_t N>
	struct factorial
	{
	// Multiply N * (N - 1) with template recursion.
	static constexpr std::uint32_t value
	= N * factorial<N - 1>::value;
	};
	template<>
	struct factorial<0U>
	{
	// Zero’th specialization terminates the recursion.
	static constexpr std::uint32_t value = 1;
	};

	constexpr std::uint32_t fact5 = factorial<5>::value;

	template<const std::size_t N,
	const std::size_t M = 0U>
	struct inner_product
	{
	template<typename iterator_left,
	typename iterator_right,
	typename result_type>
	static result_type sum(iterator_left u,
	iterator_right v,
	const result_type& init)
	{
	// Add (u[M] * v[M]) recursively.
	const result_type uvm
	= *(u + M) * result_type(*(v + M));
	return uvm
	+ inner_product<N, M + 1U>::sum(u, v, init);
	}
	};
	template<const std::size_t N>
	struct inner_product<N, N>
	{
	template<typename iterator_left,
	typename iterator_right,
	typename result_type>
	static result_type sum(iterator_left,
	iterator_right,
	const result_type&)
	{
	// N’th specialization terminates the recursion.
	return result_type(0);
	}
	};


	// check template<typename unsigned_tick> 	class timer
// https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/util/utility/util_time.h
}
*/

int main()
{
	TestErrors lError;
	FunctorTest functorTester;
	SPairTest spairTester;
	SVersionTest testVersion;

	functorTester.run();
	lError = spairTester.run();

	cout <<spairTester.toString()<< " returned "<<lError.toString()<<endl;

    return 0;
}
