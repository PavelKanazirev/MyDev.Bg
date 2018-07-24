#include <stdio.h>

#include "SampleCppFind.h"
#include "SampleCFind.h"

#include "SampleCSPI.h"
#include "SampleCppSPI.h"

/**
 * main function
 */
int main(int argc, char ** args)
{
	void * cpp_result = 0;
	void * c_result = 0;
	SampleCppFind cpp_tester;

	cpp_result = cpp_tester.run();
	c_result = c_tester_run();

	printf("cpp result = %p -> %d, c result = %p -> %d\n",
			cpp_result, *(int *)cpp_result,
			c_result, *(int *)c_result);

	CColor c1(CColor::red);
	CppColor c2;

	cColorPicker(c1);
	cppColorPicker(c2);

	printf(" size c1 = %d ; size c2 = %d\n", sizeof(c1), sizeof(c2));

    return 0;
}
