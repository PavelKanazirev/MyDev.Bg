/*
 * Launcher.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#include <iostream>

#include "../include/PluginBroker/PluginBroker.h"

//!  Class used only for optimization purposes
/*!
  Used in order to define a constant static variable that can be parsed to a template class
*/
class PluginPath
{
public:
    static const char plugin_path[];
};

const char PluginPath::plugin_path[] = "lib";

/**
 * main function
 */
int main()
{
	PluginBroker<PluginPath::plugin_path> pluginBroker;
	pluginBroker.loadPlugins();
	pluginBroker.checkTable();

    return 0;
}


