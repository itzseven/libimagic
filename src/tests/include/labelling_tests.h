//
//  labelling_tests.h
//  imagic
//
//  Created by itzseven on 08/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef labelling_tests_h
#define labelling_tests_h

#include <stdio.h>

#include "labelling.h"
#include "arithmetic.h"

#define LABELLING_TEST_CASES_COUNT 6

extern int labelling_tests_passed;
extern int labelling_tests_failed;

void test_labels_alloc();
void test_labels_cpy();

void test_labelling_one_label();
void test_labelling_n_labels();
void test_labelling_complex_labels();
void test_labelling_chessboard();

void labelling_test_suite();


#endif /* labelling_tests_h */
