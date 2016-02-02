//
//  unit_tests.c
//  imagic
//
//  Created by Romain Dubreucq on 01/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include <stdio.h>

#include "core_tests.h"

int main(int argc, const char * argv[])
{
    puts("Starting libimagic unit tests\n");
    
    core_tests_passed = 0;
    core_tests_failed = 0;
    
    puts("Starting core component tests\n");
    
    test_gray8i_alloc();
    test_gray8i_alloc_with_data();
    test_rgb8i_alloc();
    test_rgb8i_alloc_with_data();
    test_rgb8i_alloc_with_bgra_data();
    test_gray8i_cpy();
    test_rgb8i_cpy();
    test_gray8i_cmp();
    test_rgb8i_cmp();
    test_gray8i_cmp_invalid();
    test_rgb8i_cmp_invalid();
    
    printf("Finished core component tests (%d passed, %d failed on %d tests)\n", core_tests_passed, core_tests_failed, CORE_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    return 0;
}
