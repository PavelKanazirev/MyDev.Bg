#include <cassert>
#include <limits.h>
#include "gtest/gtest.h"
#include "commonTypes.h"
#include "util/SMap.h"
#include "util/SMapStringUtility.h"
#include <cstdlib>

class SMapTest : public ::testing::Test
{
public:
	struct sillyHash
	{
		unsigned operator()(const uint16 value) const
		{
			return 1;
		}
	};

	/**
	 * special hash functions that returns the same hash value for all keys
	 */
	struct IntHash
	{
		unsigned operator()(const int) const
		{
			return 1;
		}
	};

	typedef SMap<int, int>				tIntMap;
	typedef SMap<char*, int>			tStringMap;
	typedef SMap<int, int, 10, IntHash>	tIntMapSillyHash;


};

TEST_F(SMapTest, defaultConstructor)
{
    tIntMap map;
    EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.size() );
    EXPECT_EQ( static_cast<tIntMap::size_type>(10), map.max_size() );
}

TEST_F(SMapTest, empty)
{
    tIntMap map;
    EXPECT_TRUE( map.empty() );
    map[0] = 5;
    EXPECT_TRUE( !map.empty() );
}

TEST_F(SMapTest, full)
{
    tIntMap map;
    tIntMap::size_type i = 0;
    while (!map.full())
    {
        map[i] = i;
        ++i;
    }
    EXPECT_EQ( static_cast<tIntMap::size_type>(10), map.size() );
    mock::TestAssertException::setExceptionType(mock::TestAssertException::NORMAL_ASSERT_EXCEPTION);
    ASSERT_THROW( map[i] = i, mock::TestAssertException);
}

TEST_F(SMapTest, accessAtIllegalPosition)
{
    tIntMap map;
    for(tIntMap::size_type i = 0; i < tIntMap::MAX_SIZE; i++)
    {
        ASSERT_NO_THROW( map.at(i) );
    }
    mock::TestAssertException::setExceptionType(mock::TestAssertException::NORMAL_ASSERT_EXCEPTION);
    ASSERT_THROW( map.at(tIntMap::MAX_SIZE), mock::TestAssertException);
}

TEST_F(SMapTest, accessOperator)
{
    tIntMap map;
    //assign 5
    map[0] = 5;
    EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.size() );
    EXPECT_EQ( static_cast<tIntMap::data_type>(5), map[0] );
    EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.indexOf(0) );
    //reassign to same key
    map[0] = 7;
    EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.size() );
    EXPECT_EQ( static_cast<tIntMap::data_type>(7), map[0] );
    EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.indexOf(0) );
    //silly hash always returns hash-value 1 -> indexOf has to start with one
    tIntMapSillyHash map2;
    map2[0] = 55;
    map2[5] = 22;
    EXPECT_EQ( static_cast<tIntMapSillyHash::size_type>(2), map2.size() );
    EXPECT_EQ( static_cast<tIntMapSillyHash::data_type>(55), map2[0] );
    EXPECT_EQ( static_cast<tIntMapSillyHash::size_type>(1), map2.indexOf(0) );
    EXPECT_EQ( static_cast<tIntMapSillyHash::data_type>(22), map2[5] );
    EXPECT_EQ( static_cast<tIntMapSillyHash::size_type>(2), map2.indexOf(5) );
}

TEST_F(SMapTest, stringUtilities)
{
    tStringMap map3;
    tStringMap::size_type pos;
    const char* x = "hello";
    char t[strlen(x) + 1];
    strcpy(t, x);
    map3[t] = 555;
    EXPECT_EQ( static_cast<tStringMap::size_type>(1), map3.size() );
    EXPECT_EQ( static_cast<tStringMap::data_type>(555), map3["hello"] );
    pos = map3.indexOf("hello1");
    EXPECT_EQ( static_cast<tStringMap::size_type>(tStringMap::ILLEGAL_INDEX), pos );
    pos = map3.indexOf("hello");
    EXPECT_EQ( static_cast<tStringMap::data_type>(555), map3.at(pos) );
}

TEST_F(SMapTest, count)
{
    tIntMap map;
    EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.count(0) );
    map[0] = 5;
    EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.count(0) );
    map[0] = 5;
    EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.count(0) );
    map[0] = 7;
    EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.count(0) );
}

TEST_F(SMapTest, size)
{
    SMap<int, int, 5> map;
    SMap<int, int, 5>::size_type old_size = map.size();
    int key = 7;
    while (map.size() != SMap<int, int, 5>::MAX_SIZE)
    {
        map[key] = 0;
        EXPECT_EQ( old_size + 1, map.size() );
        map[key] = 0;
        EXPECT_EQ( old_size + 1, map.size() );
        old_size = map.size();
        key++;
    }
    EXPECT_TRUE( map.full() );
}

TEST_F(SMapTest, erase)
{
    tIntMapSillyHash map;
    for(int i = 0; i < 2; i++)
    {
        map[0] = 7;
        map[1] = 8;
        EXPECT_EQ( static_cast<tIntMap::size_type>(2), map.size() );
        EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.erase(0) );
        EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.size() );
        EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.erase(0) );
        EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.erase(1) );
        EXPECT_EQ( static_cast<tIntMap::size_type>(0), map.size() );
    }
}

TEST_F(SMapTest, randomInsertAndErase)
{
    tIntMap map;
    srand(0);
    for(int i = 0; i < 1000; i++)
    {
        while(!map.full())
        {
            map[rand()] = rand();
        }
        for(tIntMap::iterator itr = map.begin(); itr != map.end(); ++itr)
        {
            EXPECT_EQ( static_cast<tIntMap::size_type>(1), map.erase(itr->first) );
        }
        EXPECT_TRUE( map.empty() );
    }
}

TEST_F(SMapTest, clear)
{
    tIntMap map;
    map[0] = 0;
    map[2] = 2;
    map[4] = 4;
    EXPECT_TRUE( !map.empty() );
    map.clear();
    EXPECT_TRUE( map.empty() );
}

TEST_F(SMapTest, initialize)
{
    tIntMap map;
    tIntMap::data_type v = 5;
    map.initialize(v);
    for (tIntMap::size_type i = 0; i < map.max_size(); ++i)
    {
        EXPECT_EQ( v, map[i] );
    }
}

TEST_F(SMapTest, iterators)
{
    tIntMap map;
    EXPECT_TRUE( map.begin() == map.end() );
    map[0] = 5;
    EXPECT_TRUE( map.begin() != map.end() );
    EXPECT_EQ( static_cast<tIntMap::key_type>(0), map.begin()->first );
    EXPECT_EQ( static_cast<tIntMap::data_type>(5), map.begin()->second );
    map.begin()->second = 7;
    EXPECT_EQ( static_cast<tIntMap::key_type>(0), (*map.begin()).first );
    EXPECT_EQ( static_cast<tIntMap::data_type>(7), (*map.begin()).second );
    tIntMap::iterator itr = map.begin();
    EXPECT_TRUE( ++itr == map.end() );
    map.clear();
    map[0] = 1;
    map[3] = 4;
    itr = map.begin();
    EXPECT_EQ( static_cast<tIntMap::key_type>(0), itr->first );
    EXPECT_EQ( static_cast<tIntMap::data_type>(1), itr->second );
    ++itr;
    EXPECT_EQ( static_cast<tIntMap::key_type>(3), itr->first );
    EXPECT_EQ( static_cast<tIntMap::data_type>(4), itr->second );
    EXPECT_TRUE( ++itr == map.end() );
}

// Paar aus FBlock, InstId
typedef SPair<uint8, uint8> tUin8Pair;

struct Uint8PairHash
{
unsigned operator()(const tUin8Pair& pair) const
{
    return pair.first * 256 + pair.second;
}
};

struct Uint8PairCompare
{
bool operator()(const tUin8Pair& pair1, const tUin8Pair& pair2) const
{
    return (pair1.first * 256 + pair1.second) == (pair2.first * 256 + pair2.second);
}
};

/*
* @test
* tries to insert sth into the map that will be put into the same slot,
* i.e. the Uint8PairHash %MAX_SIZE returns the same value
*/
TEST_F(SMapTest, compareFunctorAndHashFunctorAsParameter)
{
    typedef SMap<tUin8Pair, int, 10, Uint8PairHash, Uint8PairCompare> MyMap;
    MyMap map;
    tUin8Pair pair1(100, 2);
    tUin8Pair pair2(100, 12);

    Uint8PairHash hash;
    EXPECT_EQ(hash(pair1) % MyMap::MAX_SIZE, hash(pair2) % MyMap::MAX_SIZE);
    map[pair1] = 1;
    map[pair2] = 2;
    EXPECT_EQ( static_cast<MyMap::size_type>(2), map.size() );
    EXPECT_EQ( static_cast<MyMap::size_type>(1), map.count(pair1) );
    EXPECT_EQ( static_cast<MyMap::size_type>(1), map.count(pair2) );
}

/**
* @test
* [ZGW-1192]
*/
TEST_F(SMapTest, bugInsertDeletedItemAgain)
{
    typedef SMap<uint16, uint16, 10, sillyHash> TheMap;
    TheMap map;

    map[1] = 1;
    map[2] = 2;
    map.erase(1);
    map[1] = 1;
    map[3] = 3;
    EXPECT_TRUE( map.count(1) > 0 );
    EXPECT_EQ( static_cast<TheMap::size_type>(3), map.size() );
}

/**
* @test
* Insert some values into the map and verify that they are found.
*/
TEST_F(SMapTest, find)
{
    const int MAX_VALUE = 97;
    tIntMap map;
    for (int key = 42; key < 42 + 5; ++key)
    {
        int value = key *17 % MAX_VALUE;
        map[key] = value;
    }

    //[0..41] must not be found
    for (int key = 0; key < 42; ++key)
    {
        EXPECT_TRUE( map.end() == map.find(key) );
    }
    for (int key = 42; key < 42 + 5; ++key)
    {
        int value = key *17 % MAX_VALUE;
        tIntMap::iterator itr = map.find(key);
        EXPECT_TRUE( itr != map.end() );
        EXPECT_EQ( key, itr->first );
        EXPECT_EQ( value, itr->second );
    }
    //[48..97] must not be found
    for (int key = 48; key < MAX_VALUE; ++key)
    {
        EXPECT_TRUE( map.end() == map.find(key) );
    }
}

/**
* @test
* @see	testFind
* Same test as find but with the use of equal_range method
*/
TEST_F(SMapTest, equalRange)
{
    const int MAX_VALUE = 97;
    tIntMap map;
    for (int key = 42; key < 42 + 5; ++key)
    {
        int value = key *17 % MAX_VALUE;
        map[key] = value;
    }
    //result of equal rand is a pair of iterators
    SPair<tIntMap::iterator, tIntMap::iterator> result;
    //[0..41] must not be found
    for (int key = 0; key < 42; ++key)
    {
        result = map.equal_range(key);
        EXPECT_TRUE( result.first == map.end() );
        EXPECT_TRUE( result.second == map.end() );
    }
    for (int key = 42; key < 42 + 5; ++key)
    {
        int value = key *17 % MAX_VALUE;
        result = map.equal_range(key);
        EXPECT_TRUE( result.first != result.second );
        EXPECT_TRUE( result.second == map.end() );
        EXPECT_EQ( key, result.first->first );
        EXPECT_EQ( value, result.first->second );
    }
    //[48..97] must not be found
    for (int key = 48; key < MAX_VALUE; ++key)
    {
        result = map.equal_range(key);
        EXPECT_TRUE( result.first == map.end() );
        EXPECT_TRUE( result.second == map.end() );
    }
}

