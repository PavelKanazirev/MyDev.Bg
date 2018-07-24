/*
 * TestErrors.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_TESTERRORS_H_
#define INCLUDE_TESTERRORS_H_

#include <string>
#include <iostream>

using namespace std;

#define TEST_FXN_CHK(fxn, result) \
	tearDown(); \
	setUp(); \
	result = fxn; \
	if (result != TestErrors::EOK ) \
	{ \
		cerr <<__PRETTY_FUNCTION__<<"returned wrong result :"<<result.toString()<<endl; \
		return result; \
	}

#define TEST_EXPECT_EQ(par1, par2, result) if (par1 != par2) \
	{ \
		result = TestErrors::EFail; \
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result at line : "<<__LINE__<<endl; \
    	return result; \
	}

#define TEST_EXPECT_NEQ(par1, par2, result) if (par1 == par2) \
	{ \
		result = TestErrors::EFail; \
    	cerr <<__PRETTY_FUNCTION__<<"returned wrong result at line : "<<__LINE__<<endl; \
    	return result; \
	}

#define TEST_ALLOC(pointer, result) if (NULL == pointer) \
		{ \
			result = TestErrors::EAllocFail; \
			cerr <<__PRETTY_FUNCTION__<<"unallocated memory usage attempt at line : "<<__LINE__<<endl; \
	    	return result; \
		}

using namespace std;

class TestErrors {
public:
	typedef enum errors_e {
		EUndefined = 0,
		EOK,
		EFail,
		EAllocFail,
		EAssertDetected,
		EMax
	} error_t;

private:
	error_t value;

public:
    //! A constructor.
    /*!
      Sets a false value by default
    */
	TestErrors(): value(EUndefined){}
    //! A parametered constructor.
    /*!
      Assigns a value to the object
    */
	TestErrors(error_t value):value(value){}
    //! A copy constructor.
    /*!
      Assigns a value to the object
    */
	TestErrors(const TestErrors &p2):value(p2.value){}

	TestErrors& operator=(const TestErrors& rhs)
			{ this->value = rhs.value; return *this;}
//	error_t

	inline bool operator==(const TestErrors& rhs)
			{ return (this->value == rhs.value); }
	inline bool operator!=(const TestErrors& rhs)
			{ return !(this->value == rhs.value); }

    //! Method used only for converting the id into a human readable string
    /*!
      \return The error type converted to a string
      \sa toString
    */
	string toString() {
		string result = "";

		switch (value) {
			case EUndefined: result = "EUndefined"; break;
			case EOK: result = "EOK"; break;
			case EFail: result = "EFail"; break;
			case EAllocFail: result = "EAllocFail"; break;
			case EAssertDetected: result = "EAssertDetected"; break;
			case EMax: result = "EMax"; break;
		}

		return result;
	}
};



#endif /* INCLUDE_TESTERRORS_H_ */
