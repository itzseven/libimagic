//
//  main.c
//  UnitTests
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include <stdio.h>
#include <cunit.h>
#include "matrix_unit_tests.h"
#include "image_unit_tests.h"
#include "io_unit_tests.h"
#include "convert_unit_tests.h"
#include "labelling_unit_tests.h"

int main(int argc, const char * argv[]) {
    
    ctsuite_t *matrixSuite = matrix_test_suite();
    ctsuite_t *imageSuite = image_test_suite();
    ctsuite_t *ioSuite = io_test_suite();
    ctsuite_t *convertSuite = convert_test_suite();
    ctsuite_t *labellingSuite = labelling_test_suite();
    
    ctsrun(matrixSuite);
    ctsrun(imageSuite);
    ctsrun(ioSuite);
    ctsrun(convertSuite);
    ctsrun(labellingSuite);
    
    ctsfree(matrixSuite);
    ctsfree(imageSuite);
    ctsfree(ioSuite);
    ctsfree(convertSuite);
    ctsfree(labellingSuite);
    
    return 0;
}
