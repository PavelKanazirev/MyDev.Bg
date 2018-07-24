/*
 * SampleCppFind.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

#include "SampleCppFind.h"

SampleCppFind::SampleCppFind()
{
	init();
};
SampleCppFind::~SampleCppFind(){};

void SampleCppFind::init()
{
	for (int index = 0; index < CPP_ARRAY_SIZE; index++)
	{
		my_array[index] = index * 2;
	}
}

void * SampleCppFind::run()
{
	int n1 = 6;
	int n2 = 4;
	void * pResult = NULL;

	pResult = std::find(my_array, my_array+CPP_ARRAY_SIZE, n1);

	return pResult;
};


