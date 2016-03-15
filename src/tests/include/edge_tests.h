//
//  edge_tests.h
//  imagic
//
//  Created by itzseven on 06/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef edge_tests_h
#define edge_tests_h

#include <stdio.h>

#include "edge.h"

#define EDGE_TEST_CASES_COUNT 4

extern int edge_tests_passed;
extern int edge_tests_failed;

void test_grad_alloc();

void test_grdsobel();
void test_grdprewitt();
void test_grdderiv();

void edge_test_suite();

#endif /* edge_tests_h */
