/*
 * PluginA.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef PLUGINA_INCLUDE_PLUGINA_H_
#define PLUGINA_INCLUDE_PLUGINA_H_

#include <string>

#include "../PluginAPI/plugin_api.h"
#include "../PluginAPI/IPluginSample.h"

/*! \class PluginA
    \brief Representing a plugin service that can bring specific drink on the table

    Declares itself as a plugin
*/
class PluginA: public IPluginSample {
public:
	//! The plugin interface implemenation method
	/*!
	  \return The type of drink to be served
	  \sa onTheTable()
	*/
    virtual std::string onTheTable();
};

DECLARE_PLUGIN(PluginA)

#endif /* PLUGINA_INCLUDE_PLUGINA_H_ */
