//
//  morpho_tests.c
//  imagic
//
//  Created by Romain Dubreucq on 23/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "morpho_tests.h"

int morpho_tests_passed;
int morpho_tests_failed;

void test_morpho_distension()
{
    puts("Starts test_morpho_distension\n");
    
    uint16_t width = 10, height = 10;
    
    uint8_t ref[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    uint8_t data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    bini_t *img = biniallocwd(width, height, data);
    
    bini_t *dist = distension(img, 1);
    
    int i = 0;
    
    for (i = 0; i < dist->width * dist->height; i++)
    {
        if (dist->data[i] != ref[i])
        {
            printf("test_morpho_distension failed : expected value %d but got %d on %d\n", ref[i], dist->data[i], i);
            morpho_tests_failed++;
            binifree(img);
            binifree(dist);
            return;
        }
    }
    
    puts("test_morpho_distension passed\n");
    morpho_tests_passed++;
    
    binifree(img);
    binifree(dist);
}

void test_morpho_erosion()
{
    puts("Starts test_morpho_erosion\n");
    
    uint16_t width = 10, height = 10;
    
    uint8_t ref[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    uint8_t data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    bini_t *img = biniallocwd(width, height, data);
    
    bini_t *eros = erosion(img, 1);
    
    int i = 0;
    
    for (i = 0; i < eros->width * eros->height; i++)
    {
        if (eros->data[i] != ref[i])
        {
            printf("test_morpho_erosion failed : expected value %d but got %d on %d\n", ref[i], eros->data[i], i);
            morpho_tests_failed++;
            binifree(img);
            binifree(eros);
            return;
        }
    }
    
    puts("test_morpho_erosion passed\n");
    morpho_tests_passed++;
    
    binifree(img);
    binifree(eros);
}

void test_morpho_opening()
{
    puts("Starts test_morpho_opening\n");
    
    uint16_t width = 10, height = 10;
    
    uint8_t ref[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    uint8_t data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    bini_t *img = biniallocwd(width, height, data);
    
    bini_t *open = opening(img, 1);
    
    int i = 0;
    
    for (i = 0; i < open->width * open->height; i++)
    {
        if (open->data[i] != ref[i])
        {
            printf("test_morpho_opening failed : expected value %d but got %d on %d\n", ref[i], open->data[i], i);
            morpho_tests_failed++;
            binifree(img);
            binifree(open);
            return;
        }
    }
    
    puts("test_morpho_opening passed\n");
    morpho_tests_passed++;
    
    binifree(img);
    binifree(open);
}

void test_morpho_closing()
{
    puts("Starts test_morpho_closing\n");
    
    uint16_t width = 10, height = 10;
    
    uint8_t ref[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    uint8_t data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    bini_t *img = biniallocwd(width, height, data);
    
    bini_t *clos = closing(img, 1);
    
    int i = 0;
    
    for (i = 0; i < clos->width * clos->height; i++)
    {
        if (clos->data[i] != ref[i])
        {
            printf("test_morpho_closing failed : expected value %d but got %d on %d\n", ref[i], clos->data[i], i);
            morpho_tests_failed++;
            binifree(img);
            binifree(clos);
            return;
        }
    }
    
    puts("test_morpho_closing passed\n");
    morpho_tests_passed++;
    
    binifree(img);
    binifree(clos);
}

void morpho_test_suite()
{
    test_morpho_distension();
    test_morpho_erosion();
    test_morpho_opening();
    test_morpho_closing();
}