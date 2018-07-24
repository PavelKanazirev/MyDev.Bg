#include <limits.h>
#include <iostream>

#include "TestErrors.h"
#include "SPair.h"
#include "SPairTest.h"

using namespace std;

using namespace common;

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
    	result = TestErrors::EFail;
    }

    return result;
}

TestErrors SPairTest::testInitConstructor()
{
	TestErrors result(TestErrors::EOK);
    SPair<int, float> pair(1, 2.34), target;
    if ( pair == target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    target = pair;
    if ( pair != target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ( static_cast<int>(1) != target.first )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ( static_cast<float>(2.34) != target.second )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    return result;
}

TestErrors SPairTest::testAssignment()
{
	TestErrors result(TestErrors::EOK);

    SPair<int, float> pair(1, 2.34), target;
    if ( pair == target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    target = pair;
    if ( pair != target )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ( static_cast<int>(1) != target.first )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ( static_cast<float>(2.34) != target.second )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    return result;
}

TestErrors SPairTest::run()
{
	TestErrors result(TestErrors::EOK);

	result = testDefaultConstructor();
	if (result == TestErrors::EOK)
	{
		result = testInitConstructor();
	}

	if (result == TestErrors::EOK)
	{
		result = testAssignment();
	}

    return result;
}
