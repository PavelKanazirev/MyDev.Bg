/*
 * IPluginSample.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef IPLUGINSAMPLE_H
#define IPLUGINSAMPLE_H

#include <string>

/*! \class IPluginSample
    \brief Interface class for all the plugins

    Provides the virtual function that needs to be implemented by the plugin services
*/
class IPluginSample {
public:
    //! A pure virtual destructor.
    /*!
      \sa IPluginSample()
    */
	virtual ~IPluginSample() = 0;
    //! A pure virtual member.
    /*!
      \sa onTheTable()
      \return The type of the drink served on the table.
    */
    virtual std::string onTheTable() = 0;

};

#endif // IPLUGINSAMPLE_H
