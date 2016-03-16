//
//  core_integration_tests.h
//  imagic
//
//  Created by itzseven on 27/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef core_integration_tests_h
#define core_integration_tests_h

#include "core.h"

#define CORE_TEST_INTEGRATION_CASES_COUNT 1

extern int core_integration_tests_passed;
extern int core_integration_tests_failed;

void test_gray8i_cpy_by_cmp();

void core_integration_test_suite();

#endif /* core_integration_tests_h */
