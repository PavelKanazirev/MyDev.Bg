/*
 * SampleCFind.h
 *
 *  Created on: Jul 22, 2018
 *      Author: pavel
 */

#ifndef SAMPLECFIND_H_
#define SAMPLECFIND_H_

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

void * c_tester_run();
int count_value(char ** input, int length, int value);

#ifdef __cplusplus
}
#endif



#endif /* SAMPLECFIND_H_ */
