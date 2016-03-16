//
//  io_integration_tests.h
//  imagic
//
//  Created by itzseven on 16/03/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef io_integration_tests_h
#define io_integration_tests_h

#include "io.h"

#define IO_TEST_INTEGRATION_CASES_COUNT 1

extern int io_integration_tests_passed;
extern int io_integration_tests_failed;

void test_pgm_write_ascii_with_cmp();

void io_integration_test_suite();


#endif /* io_integration_tests_h */
