/*
 * PluginC.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef PLUGINA_INCLUDE_PLUGINC_H_
#define PLUGINA_INCLUDE_PLUGINC_H_

#include <string>

#include "../PluginAPI/plugin_api.h"
#include "../PluginAPI/IPluginSample.h"

/*! \class PluginC
    \brief Representing a plugin service that can bring specific drink on the table

    Declares itself as a plugin
*/
class PluginC: public IPluginSample {
	//! The plugin interface implemenation method
	/*!
	  \return The type of drink to be served
	  \sa onTheTable()
	*/
    virtual std::string onTheTable();
};

DECLARE_PLUGIN(PluginC)

#endif /* PLUGINA_INCLUDE_PLUGINC_H_ */
