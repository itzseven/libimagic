//
//  core_tests.h
//  imagic
//
//  Created by itzseven on 01/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef core_tests_h
#define core_tests_h

#include <stdio.h>

#include "core.h"

#define CORE_TEST_CASES_COUNT 13

extern int core_tests_passed;
extern int core_tests_failed;

void test_gray8i_alloc();
void test_gray8i_alloc_with_data();

void test_bini_alloc();
void test_bini_alloc_with_data();

void test_rgb8i_alloc();
void test_rgb8i_alloc_with_data();
void test_rgb8i_alloc_with_bgra_data();

void test_gray8i_cpy();
void test_rgb8i_cpy();

void test_gray8i_cmp();
void test_rgb8i_cmp();

void test_gray8i_cmp_invalid();
void test_rgb8i_cmp_invalid();


#endif /* core_tests_h */
