//
//  integration_tests.c
//  imagic
//
//  Created by itzseven on 27/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include <stdio.h>

#include "core_integration_tests.h"
#include "io_integration_tests.h"

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
    
    puts("Starting libimagic integration tests\n");
    
    puts("Starting core component integration tests\n");
    
    core_integration_test_suite();
    
    printf("Finished core component integration tests (%d passed, %d failed on %d tests)\n", core_integration_tests_passed, core_integration_tests_failed, CORE_TEST_INTEGRATION_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting io component integration tests\n");
    
    io_integration_test_suite();
    
    printf("Finished io component integration tests (%d passed, %d failed on %d tests)\n", io_integration_tests_passed, io_integration_tests_failed, IO_TEST_INTEGRATION_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    unsigned int test_passed = core_integration_tests_passed + io_integration_tests_passed, test_failed =
    core_integration_tests_failed + io_integration_tests_failed, total_tests = CORE_TEST_INTEGRATION_CASES_COUNT + IO_TEST_INTEGRATION_CASES_COUNT;
    
    printf("Finished libimagic integration tests (%d passed, %d failed on %d tests)\n", test_passed,  test_failed, total_tests);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    return core_integration_tests_failed;
}