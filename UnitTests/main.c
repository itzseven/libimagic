//
//  main.c
//  UnitTests
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include <stdio.h>
#include "cunit.h"
#include "matrix_unit_tests.h"

int main(int argc, const char * argv[]) {
    
    ctsrun(matrix_test_suite());
    
    return 0;
}
