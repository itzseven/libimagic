//
//  io_tests.h
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef io_tests_h
#define io_tests_h

#include <stdio.h>

#include "io.h"

#define IO_TEST_CASES_COUNT 6

extern int io_tests_passed;
extern int io_tests_failed;

void test_pgmopen_ascii();
void test_pgmopen_binary();

void test_ppmopen_ascii();
void test_ppmopen_binary();

void test_pbmopen_ascii();
void test_pbmopen_binary();



#endif /* io_tests_h */
