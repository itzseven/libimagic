//
//  morpho_tests.h
//  imagic
//
//  Created by itzseven on 23/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef morpho_tests_h
#define morpho_tests_h

#include "morpho.h"

#define MORPHO_TEST_CASES_COUNT 4

extern int morpho_tests_passed;
extern int morpho_tests_failed;

void test_morpho_distension();
void test_morpho_erosion();
void test_morpho_opening();
void test_morpho_closing();

void morpho_test_suite();

#endif /* morpho_tests_h */
