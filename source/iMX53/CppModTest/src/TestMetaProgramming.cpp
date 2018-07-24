#include <iostream>

#include "TestMetaProgramming.h"
#include "SMetaProgramming.h"

using namespace std;

const unsigned int FactBase = 5;

const unsigned int FibID = 10;

const unsigned int powerBase = 2;
const unsigned int powerDegree = 3;

void TestMetaProgramming::run()
{
	Factorial<FactBase> fact;

	cout <<"Calculating the factorial of "<<FactBase<<" = "<< fact <<endl;
	cout <<"Calculating the "<<FibID<<"-th Fibonacci number = "<< Fibonacci<FibID>::value << endl;
	cout <<"Calculating power "<<powerDegree<<" of "<<powerBase<<"  = "<< Pow<2,3>::result <<endl;
}
