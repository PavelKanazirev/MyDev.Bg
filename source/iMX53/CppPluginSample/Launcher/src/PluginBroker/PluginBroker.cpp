/*
 * PluginBroker.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */
#include <dirent.h>
#include <string.h>
#include <dlfcn.h>

#include "../../include/PluginBroker/PluginBroker.h"

//! The constructor.
/*!
  Does nothing specific since the important directory name is already passed as a template parameter
*/
template <const char * PLUGIN_PATH>
PluginBroker<PLUGIN_PATH>::PluginBroker(){}

//! The destructor.
/*!
  Does nothing specific for this class
*/
template <const char * PLUGIN_PATH>
PluginBroker<PLUGIN_PATH>::~PluginBroker(){}

//! Public method used to check what is the content of the plugin directory and process it further
/*!
  \sa loadPlugins()
*/
template <const char * PLUGIN_PATH>
void PluginBroker<PLUGIN_PATH>::loadPlugins()
{
	ProjectErrors err;
	string temp;
	std::cout <<PLUGIN_PATH<<std::endl;
	err = readCurrentPluginNames();

	if (err != ProjectErrors::PE_OK)
	{
		cout <<err.toString()<<endl;
	}
}

//! Used to check the available plugins
/*!
 * \return Project specific error type
   \sa readCurrentPluginNames()
*/
template <const char * PLUGIN_PATH>
ProjectErrors PluginBroker<PLUGIN_PATH>::readCurrentPluginNames()
{
//	int detected_size = 0;
//	int last_filename_size = 0;
	DIR * d = NULL;
	struct dirent * dir = NULL;
	d = opendir(PLUGIN_PATH);

	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (0 != strncmp(dir->d_name, ".", sizeof(char)))
			{
				string new_plugin(dir->d_name);
				plugin_names.push_back(new_plugin);

				loadPlugin(new_plugin);
			}
		}

		closedir(d);
	}

	return ProjectErrors::PE_OK;
}

//! Used to check the available plugins
/*!
 * \return Project specific error type
   \sa loadPlugin()
*/
template <const char * PLUGIN_PATH>
ProjectErrors PluginBroker<PLUGIN_PATH>::loadPlugin(string plugin_name)
{
	string plugin_file_name = PLUGIN_PATH;
	plugin_file_name = plugin_file_name + "/";
	plugin_file_name = plugin_file_name + plugin_name;
	void * plib_handle = NULL;
	PluginDetails * export_details = NULL;

	plib_handle = dlopen(plugin_file_name.c_str(), RTLD_LAZY);
	cout <<"plugin_file_name: "<<plugin_file_name<<endl;
	if (!plib_handle)
	{
	      cerr <<dlerror();
	}
	else
	{
		export_details = static_cast<PluginDetails *>(dlsym(plib_handle, PLUGIN_API_SYMBOL));
		if (export_details)
		{
			plugins.push_back(export_details->initializeFunc());
			cout <<"load address: "<<export_details->initializeFunc()<<endl;
		}
		else
		{
			cout <<"plib_handle: "<<plib_handle<<endl;
		}
	}


	return ProjectErrors::PE_OK;
}

//! Reports the final result - the drinks served on the table
/*!
   \sa checkTable()
*/
template <const char * PLUGIN_PATH>
void PluginBroker<PLUGIN_PATH>::checkTable()
{
	for(plugins_type::iterator it = plugins.begin();
			it != plugins.end(); it++)
	{
		IPluginSample * currentSample = static_cast<IPluginSample *>(*it);
		cout <<"On the table : "<<currentSample->onTheTable()<<endl;
	}

}
