/*
 * PluginA.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#include <string>
#include <stdio.h>

#include "../PluginAPI/plugin_api.h"
#include "PluginA.h"

//! The plugin interface implemenation method
/*!
  \return The type of drink to be served
  \sa onTheTable()
*/
std::string PluginA::onTheTable()
{
    return " Whiskey ";
}

