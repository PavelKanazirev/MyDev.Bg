/*
 * SampleCppFind.h
 *
 *  Created on: Dec 8, 2014
 *      Author: pavel
 */

#ifndef SAMPLECPPFIND_H_
#define SAMPLECPPFIND_H_

#define CPP_ARRAY_SIZE (4U)

class SampleCppFind {
private:
	int my_array[CPP_ARRAY_SIZE];
public:
	SampleCppFind();
	~SampleCppFind();

	void init();
	void * run();
};



#endif /* SAMPLECPPFIND_H_ */
