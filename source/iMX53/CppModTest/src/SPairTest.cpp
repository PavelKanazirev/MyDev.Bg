#include <limits.h>
#include <iostream>

#include "TestErrors.h"
#include "SPair.h"
#include "SPairTest.h"

using namespace std;

TestErrors SPairTest::testDefaultConstructor()
{
	TestErrors result(TestErrors::EOK);
    SPair<int, float> pair(1, 2.34);
    if ( static_cast<int>(1) != pair.first )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ( static_cast<float>(2.34) != pair.second )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    }

    return result;
}

TestErrors SPairTest::initConstructor()
{
	TestErrors result(TestErrors::EOK);
    SPair<int, float> pair(1, 2.34), target;
    if ( pair == target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    }

    target = pair;
    if ( pair != target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    }

    if ( static_cast<int>(1) != target.first )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    }

    if ( static_cast<float>(2.34) != target.second )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    }

    return result;
}

TestErrors SPairTest::assignment()
{
	TestErrors result(TestErrors::EOK);

    SPair<int, float> pair(1, 2.34), target;
    if ( pair == target )
    {

    }

    target = pair;
    if ( pair != target )
    {

    }

    if ( static_cast<int>(1) != target.first )
    {

    }

    if ( static_cast<float>(2.34) != target.second )
    {

    }

    return result;
}

TestErrors SPairTest::runTest()
{
	TestErrors result(TestErrors::EOK);

	result = testDefaultConstructor();
	if (result == TestErrors::EOK)
	{
		result = initConstructor();
	}

	if (result == TestErrors::EOK)
	{
		result = assignment();
	}

    return result;
}
