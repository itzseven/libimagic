//
//  io_integration_tests.c
//  imagic
//
//  Created by itzseven on 16/03/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include <stdio.h>

#include "io_integration_tests.h"

int io_integration_tests_passed;
int io_integration_tests_failed;

void test_pgm_write_ascii_with_cmp()
{
    puts("Starts test_pgm_write_ascii_with_cmp\n");
    
    uint16_t width = 5, height = 5;
    
    uint8_t ref[] = {0, 0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 84, 126, 0, 0, 0, 168, 210, 252, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *export = gray8iallocwd(width, height, ref);
    gray8i_t *refimg = gray8iallocwd(width, height, ref);
    
    pgmwrite(export, "resources/test_pgm_write_ascii_with_cmp.pgm", PGM_ASCII);
    
    gray8i_t *exportLoad = pgmopen("resources/test_pgm_write_ascii_with_cmp.pgm");
    
    int comparison = gray8icmp(refimg, exportLoad);
    
    if (comparison == 0)
    {
        puts("test_pgm_write_ascii_with_cmp passed\n");
        io_integration_tests_passed++;
    }
    
    else
    {
        puts("test_pgm_write_ascii_with_cmp failed\n");
        io_integration_tests_failed++;
    }
    
    puts("test_pgm_write_ascii_with_cmp passed\n");
    gray8ifree(export);
    gray8ifree(refimg);
    gray8ifree(exportLoad);
}

void io_integration_test_suite()
{
    test_pgm_write_ascii_with_cmp();
}
