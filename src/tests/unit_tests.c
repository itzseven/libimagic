//
//  unit_tests.c
//  imagic
//
//  Created by itzseven on 01/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include <stdio.h>
#include <time.h>

#include "core_tests.h"
#include "io_tests.h"
#include "edge_tests.h"
#include "labelling_tests.h"
#include "characterization_tests.h"
#include "morpho_tests.h"

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
    
    puts("Starting libimagic unit tests\n");
    
    puts("Starting core component tests\n");
    
    core_tests_passed = 0;
    core_tests_failed = 0;
    
    core_test_suite();
    
    printf("Finished core component tests (%d passed, %d failed on %d tests)\n", core_tests_passed, core_tests_failed, CORE_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting io component tests\n");
    
    io_tests_passed = 0;
    io_tests_failed = 0;
    
    io_test_suite();
    
    printf("Finished io component tests (%d passed, %d failed on %d tests)\n", io_tests_passed, io_tests_failed, IO_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting edge component tests\n");
    
    edge_tests_passed = 0;
    edge_tests_failed = 0;
    
    edge_test_suite();
    
    printf("Finished edge component tests (%d passed, %d failed on %d tests)\n", edge_tests_passed, edge_tests_failed, EDGE_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting labelling component tests\n");
    
    labelling_tests_passed = 0;
    labelling_tests_failed = 0;
    
    labelling_test_suite();
    
    printf("Finished labelling component tests (%d passed, %d failed on %d tests)\n", labelling_tests_passed, labelling_tests_failed, LABELLING_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting characterization component tests\n");
    
    characterization_tests_passed = 0;
    characterization_tests_failed = 0;
    
    characterization_test_suite();
    
    printf("Finished characterization component tests (%d passed, %d failed on %d tests)\n", characterization_tests_passed, characterization_tests_failed, CHARACTERIZATION_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    puts("Starting morpho component tests\n");
    
    morpho_tests_passed = 0;
    morpho_tests_failed = 0;
    
    morpho_test_suite();
    
    printf("Finished morpho component tests (%d passed, %d failed on %d tests)\n", morpho_tests_passed, morpho_tests_failed, MORPHO_TEST_CASES_COUNT);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    unsigned int test_passed = core_tests_passed + io_tests_passed + edge_tests_passed + labelling_tests_passed + characterization_tests_passed + morpho_tests_passed, test_failed =
    core_tests_failed + io_tests_failed + edge_tests_failed + labelling_tests_failed + characterization_tests_failed + morpho_tests_failed, total_tests = CORE_TEST_CASES_COUNT + IO_TEST_CASES_COUNT + EDGE_TEST_CASES_COUNT + LABELLING_TEST_CASES_COUNT + CHARACTERIZATION_TEST_CASES_COUNT + MORPHO_TEST_CASES_COUNT;
    
    printf("Finished libimagic unit tests (%d passed, %d failed on %d tests)\n", test_passed,  test_failed, total_tests);
    
    puts("\n-----------------------------------------------------------------------------------------------\n");
    
    return test_failed;
}
