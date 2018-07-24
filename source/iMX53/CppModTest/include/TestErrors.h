/*
 * TestErrors.h
 *
 *  Created on: Jul 18, 2018
 *      Author: pavel
 */

#ifndef INCLUDE_TESTERRORS_H_
#define INCLUDE_TESTERRORS_H_


#include <string>

using namespace std;

class TestErrors {
public:
	typedef enum errors_e {
		EUndefined = 0,
		EOK,
		EFail,
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
			case EMax: result = "EMax"; break;
		}

		return result;
	}
};



#endif /* INCLUDE_TESTERRORS_H_ */
