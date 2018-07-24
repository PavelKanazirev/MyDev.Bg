#include <limits.h>

#include "TestErrors.h"

#include "SVectorTest.h"

#include <iostream>
using namespace std;

SVectorTest::SVectorTest() :
		fpVector1(NULL), fpVector2(NULL)
{

}

SVectorTest::~SVectorTest()
{
	cleanUp();
}

void SVectorTest::setUp()
{
	fpVector1 = new tIntVector();
	fpVector2 = new tIntVector();
}

void SVectorTest::tearDown()
{
	cleanUp();
}

void SVectorTest::cleanUp()
{
	if (NULL != fpVector1)
	{
		delete fpVector1;
		fpVector1 = NULL;
	}

	if (NULL != fpVector2)
	{
		delete fpVector2;
		fpVector2 = NULL;
	}
}

TestErrors SVectorTest::testDefaultConstructor()
{
	TestErrors result(TestErrors::EOK);

    // test if size and max_size are correctly initialized
    SVector<int>* pVector = new SVector<int>();
    TEST_ALLOC(pVector, result);
    TEST_EXPECT_EQ( (tIntVector::size_type)0, pVector->size(), result );
    TEST_EXPECT_EQ( (tIntVector::size_type)10, pVector->max_size(), result );
    delete pVector;

    return result;
}

TestErrors SVectorTest::testInitConstructor()
{
	TestErrors result(TestErrors::EOK);

    int defaultValue = 7;
    SVector<int>* pVector = new SVector<int>(SVector<int>::MAX_SIZE, defaultValue);
    TEST_ALLOC(pVector, result);
    TEST_EXPECT_EQ( pVector->size(), pVector->max_size(), result );
    //test if values have been initialized correctly
    for (SVector<int>::size_type i; i < pVector->size(); ++i)
    {
    	TEST_EXPECT_EQ( defaultValue, (*pVector)[i], result );
    }
    delete pVector;

    return result;
}

TestErrors SVectorTest::testEmpty()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    //test if vector is empty after contruction
	TEST_EXPECT_EQ( fpVector1->empty(), true, result );

    return result;
}

TestErrors SVectorTest::testPushBack()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    tIntVector::size_type size = fpVector1->size();
    TEST_EXPECT_EQ( (tIntVector::size_type)0, size, result );
    fpVector1->push_back() = 1;
    TEST_EXPECT_EQ( size + 1, fpVector1->size(), result );
    TEST_EXPECT_EQ( 1, fpVector1->back(), result );

    return result;
}

TestErrors SVectorTest::testPopBack()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    fpVector1->push_back() = 123;
    TEST_EXPECT_EQ( (tIntVector::size_type)1, fpVector1->size(), result );
    fpVector1->pop_back();
    TEST_EXPECT_EQ( fpVector1->empty(), true, result );

    return result;
}

TestErrors SVectorTest::testResize()
{
	TestErrors result(TestErrors::EOK);

    tIntVector::size_type size = fpVector1->size();
    TEST_EXPECT_EQ( (tIntVector::size_type)0, size, result );

	TEST_ALLOC(fpVector1, result);
    fpVector1->resize(tIntVector::MAX_SIZE, 17);
    TEST_EXPECT_EQ( fpVector1->size(), fpVector1->max_size(), result );
    TEST_EXPECT_EQ( fpVector1->full(), true, result );
    for (tIntVector::size_type i; i < fpVector1->size(); ++i)
    {
    	TEST_EXPECT_EQ( 17, (*fpVector1)[i], result );
    }
    fpVector1->resize(0);
    TEST_EXPECT_EQ( fpVector1->empty(), true, result );

    return result;
}

TestErrors SVectorTest::testFull()
{
	TestErrors result(TestErrors::EOK);

    SVector<int>* pVector = new SVector<int>(SVector<int>::MAX_SIZE, 0);
	TEST_ALLOC(pVector, result);
    TEST_EXPECT_EQ( pVector->size(), pVector->max_size(), result );
    TEST_EXPECT_EQ( pVector->full(), true, result );
    delete pVector;

    return result;
}

TestErrors SVectorTest::testFront()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    fpVector1->push_back() = 123;
    TEST_EXPECT_EQ( 123, fpVector1->front(), result );
    fpVector1->push_back() = 234;
    TEST_EXPECT_EQ( 123, fpVector1->front(), result );

    return result;
}

TestErrors SVectorTest::testBack()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    fpVector1->push_back() = 123;
    TEST_EXPECT_EQ( 123, fpVector1->back(), result );
    fpVector1->push_back() = 234;
    TEST_EXPECT_EQ( 234, fpVector1->back(), result );

    return result;
}

TestErrors SVectorTest::testClear()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
    fpVector1->push_back() = 123;
    TEST_EXPECT_EQ( !fpVector1->empty(), true, result );
    fpVector1->clear();
    TEST_EXPECT_EQ( (tIntVector::size_type)0, fpVector1->size(), result );
    TEST_EXPECT_EQ( fpVector1->empty(), true, result );

    return result;
}

TestErrors SVectorTest::testIterators()
{
	TestErrors result(TestErrors::EOK);

	TEST_ALLOC(fpVector1, result);
	TEST_EXPECT_EQ( fpVector1->begin(), fpVector1->end(), result );
    fpVector1->push_back() = 1;
    fpVector1->push_back() = 1;
    TEST_EXPECT_NEQ( fpVector1->begin(), fpVector1->end(), result );
    for (tIntVector::iterator itr = fpVector1->begin(); itr != fpVector1->end(); ++itr)
    {
    	TEST_EXPECT_EQ( 1, *itr, result );
    }
    *fpVector1->begin() = 2;
    TEST_EXPECT_EQ( 2, *fpVector1->begin(), result );
    TEST_EXPECT_EQ( fpVector1->front(), *fpVector1->begin(), result );

    return result;
}

TestErrors SVectorTest::testErase()
{
	TestErrors result(TestErrors::EOK);

    tIntVector vector;
    vector.push_back() = 1;
    vector.push_back() = 2;
    vector.push_back() = 1;
    vector.push_back() = 1;
    TEST_EXPECT_EQ( static_cast<tIntVector::size_type>(4), vector.size(), result );
    TEST_EXPECT_EQ( static_cast<tIntVector::size_type>(3), vector.erase(1), result );
    TEST_EXPECT_EQ( static_cast<tIntVector::size_type>(1), vector.size(), result );

    return result;
}

TestErrors SVectorTest::runTest()
{
	TestErrors result(TestErrors::EOK);

	setUp();
	TEST_FXN_CHK(testDefaultConstructor(), result);
	TEST_FXN_CHK(testInitConstructor(), result);
	TEST_FXN_CHK(testEmpty(), result);
	TEST_FXN_CHK(testPushBack(), result);
	TEST_FXN_CHK(testPopBack(), result);
	TEST_FXN_CHK(testResize(), result);
	TEST_FXN_CHK(testFull(), result);
	TEST_FXN_CHK(testFront(), result);
	TEST_FXN_CHK(testBack(), result);
	TEST_FXN_CHK(testClear(), result);
	TEST_FXN_CHK(testIterators(), result);
	TEST_FXN_CHK(testErase(), result);
    tearDown();

    return result;
}
