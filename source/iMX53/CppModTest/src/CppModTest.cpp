#include <iostream>
#include <ctime>

#include "TestErrors.h"
#include "FunctorTest.h"
#include "SVersionTest.h"
#include "TestMetaProgramming.h"
#include "StaticPolimorphTest.h"
#include "DynamicPolimorphTest.h"
#include "SPairTest.h"
#include "SVectorTest.h"

const unsigned int polymorph_test_cycles = 3000000;

using namespace std;

int main()
{
	TestErrors lError;
	SVersionTest testVersion;
	TestMetaProgramming testMetaProgramming;
	FunctorTest functorTester;
	StaticPolimorphTest sPolymorphTester;
	DynamicPolimorphTest dPolymorphTester;
	SPairTest sPairTester;
	SVectorTest sVectorTester;

	functorTester.run();
	testMetaProgramming.run();

	{ // compare static vs dynamic polymorphism
		clock_t static_begin = clock();
		for (unsigned int index = 0; index < polymorph_test_cycles; index++)
		{
			sPolymorphTester.run(StaticPolimorphTest::Analog);
		}
		clock_t static_end = clock();
		double static_elapsed_secs = double(static_end - static_begin) / CLOCKS_PER_SEC;
		cout <<"static_elapsed_secs = "<<static_elapsed_secs<<endl;

		clock_t dynamic_begin = clock();
		for (unsigned int index = 0; index < polymorph_test_cycles; index++)
		{
			dPolymorphTester.run(DynamicPolimorphTest::Analog);
		}
		clock_t dynamic_end = clock();
		double dynamic_elapsed_secs = double(dynamic_end - dynamic_begin) / CLOCKS_PER_SEC;
		cout <<"dynamic_elapsed_secs = "<<dynamic_elapsed_secs<<endl;
	}

	lError = sPairTester.runTest();
	cout <<sPairTester.toString()<< " returned "<<lError.toString()<<endl;

	lError = sVectorTester.runTest();
	cout <<sVectorTester.toString()<< " returned "<<lError.toString()<<endl;

    return 0;
}
