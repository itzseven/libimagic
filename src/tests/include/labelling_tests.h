//
//  labelling_tests.h
//  imagic
//
//  Created by Romain Dubreucq on 08/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#ifndef labelling_tests_h
#define labelling_tests_h

#include <stdio.h>

#include "labelling.h"
#include "arithmetic.h"

#define LABELLING_TEST_CASES_COUNT 4

extern int labelling_tests_passed;
extern int labelling_tests_failed;

void test_labels_alloc();

void test_labelling_one_label();
void test_labelling_n_labels();
void test_labelling_complex_labels();


#endif /* labelling_tests_h */
