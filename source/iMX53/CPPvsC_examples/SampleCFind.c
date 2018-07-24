#include <cstdlib>

#include "SampleCFind.h"

#define C_ARRAY_SIZE (4U)

static int my_array[] = { 2, 4, 6, 8 };

void * find(int * first, int * last, const int value)
{
	for (; first != last; ++first)
	{
		if (*first == value)
		{
			return first;
		}
	}

	return last;
}

void * c_tester_run()
{
	int n1 = 6;
	int n2 = 4;
	void * pResult = 0;

	pResult = find(my_array, my_array+C_ARRAY_SIZE, n1);

	return pResult;
}


