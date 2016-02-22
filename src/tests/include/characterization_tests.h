//
//  characterization_tests.h
//  imagic
//
//  Created by itzseven on 22/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef characterization_tests_h
#define characterization_tests_h

#include "characterization.h"
#include "arithmetic.h"

#define CHARACTERIZATION_TEST_CASES_COUNT 4

extern int characterization_tests_passed;
extern int characterization_tests_failed;

void test_charact_alloc();

void test_charact_size();
void test_charact_bounds();
void test_charact_gravity();

#endif /* characterization_tests_h */
