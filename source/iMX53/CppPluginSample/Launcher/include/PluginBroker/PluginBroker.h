/*
 * PluginBroker.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef PLUGINBROKER_H_
#define PLUGINBROKER_H_

#include <iostream>
#include <string>
#include <vector>

#include "../../Common/include/ProjectErrors.h"
#include "../../PluginAPI/plugin_api.h"

using namespace std;

/*! \class PluginBroker
    \brief Used for manipulating plugins.

    Accepts the folder name as a template instead of like a constant parameter.
*/
template <const char * PLUGIN_PATH>
class PluginBroker
{
private:
	typedef vector<string> plugin_names_type;
	typedef vector<IPluginSample*> plugins_type;
	plugin_names_type plugin_names;
	plugins_type plugins;

	//! Used to check the available plugins
	/*!
	 * \return Project specific error type
	   \sa readCurrentPluginNames()
	*/
	ProjectErrors readCurrentPluginNames();
	//! Used to check the available plugins
	/*!
	 * \return Project specific error type
	   \sa loadPlugin()
	*/
	ProjectErrors loadPlugin(string plugin_name);
public:
    //! The constructor.
    /*!
      Does nothing specific since the important directory name is already passed as a template parameter
    */
	PluginBroker();

    //! The destructor.
    /*!
      Does nothing specific for this class
    */
	~PluginBroker();

	//! Public method used to check what is the content of the plugin directory and process it further
	/*!
	  \sa loadPlugins()
	*/
	void loadPlugins();
	//! Reports the final result - the drinks served on the table
	/*!
	   \sa checkTable()
	*/
	void checkTable();
};

#include "../../src/PluginBroker/PluginBroker.cpp"

#endif /* PLUGINBROKER_H_ */
