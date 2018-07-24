/*
 * plugin_api.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include "IPluginSample.h"

#define PLUGIN_API_VERSION 1
#define PLUGIN_API_SYMBOL "exports"

typedef IPluginSample* (*GetPluginFunc)();

//! Structure that will carry the plugin interface
/*! Each plugin will reserve data for this structure */
struct PluginDetails {
    int apiVersion;
    GetPluginFunc initializeFunc;
};

#define DECLARE_PLUGIN(x) extern "C"{ 		\
			IPluginSample * getPlugin() 	\
			{ 								\
				return new x;				\
			} 								\
			PluginDetails exports =  		\
		    {                             	\
				  PLUGIN_API_VERSION,     	\
		          getPlugin,                \
		    };								\
} // extern "C"
#endif // PLUGIN_API_H
