#include <limits.h>
#include "SVector.h"

#include <iostream>

#include "SVectorTest.h"
#include "SVector.h"

#define CALL_TEST(TEST_FXN, EXPECTED_RESULT, RESULT_VAR_NAME) \
	RESULT_VAR_NAME = TEST_NAME;	\
	if ( EXPECTED_RESULT != RESULT_VAR_NAME ) return RESULT_VAR_NAME;

using namespace std;

SVectorTest::SVectorTest() :
		fpVector1(NULL), fpVector2(NULL)
{

}

SVectorTest::~SVectorTest()
{
	cleanup();
}

void SVectorTest::SetUp()
{
    fpVector1 = new tIntVector();
    fpVector2 = new tIntVector();
}

void SVectorTest::TearDown()
{
	cleanup();
}

TestErrors SVectorTest::run()
{
	TestErrors result(TestErrors::EOK);

	SetUp();

	CALL_TEST(testDefaultConstructor(), TestErrors::EOK, result)
	CALL_TEST(testInitConstructor(), TestErrors::EOK, result)
	CALL_TEST(testEmpty(), TestErrors::EOK, result)
	CALL_TEST(testPushBack(), TestErrors::EOK, result)
	CALL_TEST(testPopBack(), TestErrors::EOK, result)
	CALL_TEST(testResize(), TestErrors::EOK, result)
	CALL_TEST(testFull(), TestErrors::EOK, result)
	CALL_TEST(testFront(), TestErrors::EOK, result)
	CALL_TEST(testBack(), TestErrors::EOK, result)
	CALL_TEST(testClear(), TestErrors::EOK, result)
	CALL_TEST(testIterators(), TestErrors::EOK, result)
	CALL_TEST(testErase(), TestErrors::EOK, result)

	TearDown();

    return result;
}

void SVectorTest::cleanup()
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

    if ((SVector<int>::size_type)0 != pVector->size())
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    if ((SVector<int>::size_type)10 != pVector->max_size() )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    delete pVector;

    return result;
}

TestErrors SVectorTest::testInitConstructor()
{
	TestErrors result(TestErrors::EOK);

    int defaultValue = 7;
    SVector<int>* pVector = new SVector<int>(SVector<int>::MAX_SIZE, defaultValue);
    if ( pVector->size() != pVector->max_size() )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    //test if values have been initialized correctly
    for (SVector<int>::size_type i; i < pVector->size(); ++i)
    {
    	if ( defaultValue != (*pVector)[i] )
    	{
        	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
        	result = TestErrors::EFail;
    	}
    }

    delete pVector;

    return result;
}

TestErrors SVectorTest::testEmpty()
{
	TestErrors result(TestErrors::EOK);

    //test if vector is empty after contruction
    if ( ! fpVector1->empty() )
    {
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result"<<endl;
    	result = TestErrors::EFail;
    }

    return result;
}

TestErrors SVectorTest::testPushBack()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testPopBack()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testResize()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testFull()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testFront()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testBack()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testClear()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testIterators()
{
	TestErrors result(TestErrors::EOK);

    return result;
}

TestErrors SVectorTest::testErase()
{
	TestErrors result(TestErrors::EOK);

    return result;
}


TEST_F(SVectorTest, pushBack)
{
    tIntVector::size_type size = fpVector1->size();
    EXPECT_EQ( (tIntVector::size_type)0, size );
    fpVector1->push_back() = 1;
    EXPECT_EQ( size + 1, fpVector1->size() );
    EXPECT_EQ( 1, fpVector1->back() );
}

TEST_F(SVectorTest, popBack)
{
    fpVector1->push_back() = 123;
    EXPECT_EQ( (tIntVector::size_type)1, fpVector1->size() );
    fpVector1->pop_back();
    EXPECT_TRUE( fpVector1->empty() );
}


TEST_F(SVectorTest, resize)
{
    tIntVector::size_type size = fpVector1->size();
    EXPECT_EQ( (tIntVector::size_type)0, size );
    fpVector1->resize(tIntVector::MAX_SIZE, 17);
    EXPECT_EQ( fpVector1->size(), fpVector1->max_size() );
    EXPECT_TRUE( fpVector1->full() );
    for (tIntVector::size_type i; i < fpVector1->size(); ++i)
    {
        EXPECT_EQ( 17, (*fpVector1)[i] );
    }
    fpVector1->resize(0);
    EXPECT_TRUE( fpVector1->empty() );
}

TEST_F(SVectorTest, full)
{
    SVector<int>* pVector = new SVector<int>(SVector<int>::MAX_SIZE, 0);
    EXPECT_EQ( pVector->size(), pVector->max_size() );
    EXPECT_TRUE( pVector->full() );
    delete pVector;
}

TEST_F(SVectorTest, front)
{
    fpVector1->push_back() = 123;
    EXPECT_EQ( 123, fpVector1->front() );
    fpVector1->push_back() = 234;
    EXPECT_EQ( 123, fpVector1->front() );
}

TEST_F(SVectorTest, back)
{
    fpVector1->push_back() = 123;
    EXPECT_EQ( 123, fpVector1->back() );
    fpVector1->push_back() = 234;
    EXPECT_EQ( 234, fpVector1->back() );
}

TEST_F(SVectorTest, clear)
{
    fpVector1->push_back() = 123;
    EXPECT_TRUE( !fpVector1->empty() );
    fpVector1->clear();
    EXPECT_EQ( (tIntVector::size_type)0, fpVector1->size() );
    EXPECT_TRUE( fpVector1->empty() );
}

TEST_F(SVectorTest, iterators)
{
    EXPECT_TRUE( fpVector1->begin() == fpVector1->end() );
    fpVector1->push_back() = 1;
    fpVector1->push_back() = 1;
    EXPECT_TRUE( fpVector1->begin() != fpVector1->end() );
    for (tIntVector::iterator itr = fpVector1->begin(); itr != fpVector1->end(); ++itr)
    {
        EXPECT_EQ( 1, *itr );
    }
    *fpVector1->begin() = 2;
    EXPECT_EQ( 2, *fpVector1->begin() );
    EXPECT_EQ( fpVector1->front(), *fpVector1->begin() );
}

TEST_F(SVectorTest, erase)
{
    tIntVector vector;
    vector.push_back() = 1;
    vector.push_back() = 2;
    vector.push_back() = 1;
    vector.push_back() = 1;
    EXPECT_EQ( static_cast<tIntVector::size_type>(4), vector.size() );
    EXPECT_EQ( static_cast<tIntVector::size_type>(3), vector.erase(1) );
    EXPECT_EQ( static_cast<tIntVector::size_type>(1), vector.size() );
}

