//
//  opticalflow_tests.h
//  imagic
//
//  Created by Adrien on 15/03/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#ifndef opticalflow_tests_h
#define opticalflow_tests_h

#include <stdio.h>
#include "opticalflow.h"

#define OPTICALFLOW_TEST_CASES_COUNT 4

extern int opticalflow_tests_passed;
extern int opticalflow_tests_failed;

// Test suite
void opticalflow_testsuite();

// Unit tests
void test_to_left();
void test_to_right();
void test_to_up();
void test_to_bottom();

#endif /* opticalflow_tests_h */
