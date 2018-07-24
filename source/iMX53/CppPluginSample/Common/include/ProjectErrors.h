/*
 * ProjectErrors.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef PROJECTERRORS_H_
#define PROJECTERRORS_H_

#include <string>

using namespace std;

/*! \class ProjectErrors
    \brief Used for identifying the error type and debugging

    Accepts the folder name as a template instead of like a constant parameter.
*/
class ProjectErrors {
public:
    //! An enum type defining the error types specific for this project.
    /*! Since the project is not big one - basic values will do it. */
	typedef enum {
		PE_OK = 0,
		PE_FAULT,
		PE_MAX
	} error_type;
private:
	error_type value;
public:
    //! A constructor.
    /*!
      Sets a false value by default
    */
	ProjectErrors(): value(PE_FAULT){}
    //! A parametered constructor.
    /*!
      Assigns a value to the object
    */
	ProjectErrors(error_type value):value(value){}
    //! A copy constructor.
    /*!
      Assigns a value to the object
    */
	ProjectErrors(const ProjectErrors &p2):value(p2.value){}

	ProjectErrors& operator=(const ProjectErrors& rhs)
			{ this->value = rhs.value; return *this;}
	inline bool operator==(const ProjectErrors& rhs)
			{ return (this->value == rhs.value); }
	inline bool operator!=(const ProjectErrors& rhs)
			{ return !(this->value == rhs.value); }

    //! Method used only for converting the id into a human readable string
    /*!
      \return The error type converted to a string
      \sa toString
    */
	string toString() {
		string result = "";

		switch (value) {
			case PE_OK: result = "PE_OK"; break;
			case PE_FAULT: result = "PE_FAULT"; break;
			case PE_MAX: result = "PE_MAX"; break;
		}

		return result;
	}

};

#endif // PROJECTERRORS_H_
