/*
 * PluginC.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#include "PluginC.h"

#include <string.h>
#include <stdio.h>

//! The plugin interface implemenation method
/*!
  \return The type of drink to be served
  \sa onTheTable()
*/
std::string PluginC::onTheTable()
{
    return " Rakia! ";
}
