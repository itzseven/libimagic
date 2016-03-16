//
//  characterization_tests.c
//  imagic
//
//  Created by itzseven on 22/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include <stdio.h>

#include "characterization_tests.h"

int characterization_tests_passed;
int characterization_tests_failed;

void test_charact_alloc()
{
    puts("Starts test_charact_alloc\n");
    
    uint32_t count = 5;
    
    charact_t *charact = charactalloc(count);
    
    if (charact->count == count)
    {
        int i = 0;
        
        for (i = 0; i < count; i++)
        {
            regchar_t *reg = charact->data[i];
            pt2d_t gravity = reg->gravity;
            rect_t bounds = reg->bounds;
            
            if (reg->size != 0)
            {
                printf("test_charact_alloc failed : expected size %d but got %d on %d\n", 0, charact->data[i]->size, i);
                characterization_tests_failed++;
                charactfree(charact);
                return;
            }
            
            if ((bounds.start.x != UINT32_MAX) || (bounds.start.y != UINT32_MAX) || (bounds.end.x != 0) || (bounds.end.y != 0))
            {
                printf("test_charact_alloc failed : expected start (%d, %d) but got (%d, %d), end (%d, %d) but got (%d, %d) on %d\n", UINT16_MAX, UINT16_MAX, bounds.start.x, bounds.start.y, 0, 0, bounds.end.x, bounds.end.y, i);
                characterization_tests_failed++;
                charactfree(charact);
                return;
            }
            
            if ((gravity.x != 0) || (gravity.y != 0))
            {
                printf("test_charact_alloc failed : expected gravity (%d, %d) but got (%d, %d) on %d\n", 0, 0, gravity.x, gravity.y, i);
                characterization_tests_failed++;
                charactfree(charact);
                return;
            }
        }
    }
    
    else
    {
        printf("test_charact_alloc failed : expected count %d and got %d\n", count, charact->count);
        characterization_tests_failed++;
        charactfree(charact);
        return;
    }
    
    puts("test_charact_alloc passed\n");
    characterization_tests_passed++;
    charactfree(charact);
}

void test_charact_size()
{
    puts("Starts test_charact_size\n");
    
    uint16_t width = 20, height = 20;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *binary = binarise(img, 50);
    
    labels_t *labels = label(binary);
    
    charact_t *charact = characterize(NULL, img, labels);
    
    if ((charact->data[0]->size != 27) || (charact->data[1]->size != 45) || (charact->data[2]->size != 81))
    {
        printf("test_charact_size failed : expected region 1 size %d but got %d, region 2 size %d but got %d, region 3 size %d but got %d\n", charact->data[0]->size, 27, charact->data[1]->size, 45, charact->data[2]->size, 81);
        characterization_tests_failed++;
        gray8ifree(img);
        binifree(binary);
        labfree(labels);
        charactfree(charact);
        return;
    }
    
    puts("test_charact_size passed\n");
    characterization_tests_passed++;
    gray8ifree(img);
    binifree(binary);
    labfree(labels);
    charactfree(charact);
}

void test_charact_bounds()
{
    puts("Starts test_charact_bounds\n");
    
    uint16_t width = 20, height = 20;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *binary = binarise(img, 50);
    
    labels_t *labels = label(binary);
    
    charact_t *charact = characterize(NULL, img, labels);
    
    rect_t breg1 = charact->data[0]->bounds, breg2 = charact->data[1]->bounds, breg3 = charact->data[2]->bounds;
    
    int breg1_nok = (breg1.start.x != 9) || (breg1.end.x != 17) || (breg1.start.y != 3) || (breg1.end.y != 5);
    int breg2_nok = (breg2.start.x != 2) || (breg2.end.x != 6) || (breg2.start.y != 5) || (breg2.end.y != 13);
    int breg3_nok = (breg3.start.x != 9) || (breg3.end.x != 17) || (breg3.start.y != 10) || (breg3.end.y != 18);
    
    if (breg1_nok || breg2_nok || breg3_nok)
    {
        printf("test_charact_bounds failed : expected (%d, %d, %d) but got (%d, %d, %d)\n", 0, 0, 0, breg1_nok, breg2_nok, breg3_nok);
        characterization_tests_failed++;
        gray8ifree(img);
        binifree(binary);
        labfree(labels);
        charactfree(charact);
        return;
    }
    
    puts("test_charact_bounds passed\n");
    characterization_tests_passed++;
    gray8ifree(img);
    binifree(binary);
    labfree(labels);
    charactfree(charact);
}

void test_charact_gravity()
{
    puts("Starts test_charact_gravity\n");
    
    uint16_t width = 20, height = 20;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *binary = binarise(img, 50);
    
    labels_t *labels = label(binary);
    
    charact_t *charact = characterize(NULL, img, labels);
    
    if ((charact->data[0]->gravity.x != 13) || (charact->data[0]->gravity.y != 4) || (charact->data[1]->gravity.x != 4) || (charact->data[1]->gravity.y != 9) || (charact->data[2]->gravity.x != 13) || (charact->data[2]->gravity.y != 14))
    {
        printf("test_charact_gravity failed : expected ((%d, %d), (%d, %d), (%d, %d)) but got ((%d, %d), (%d, %d), (%d, %d))\n", 13, 4, 4, 9, 13, 14, charact->data[0]->gravity.x, charact->data[0]->gravity.y, charact->data[1]->gravity.x, charact->data[1]->gravity.y, charact->data[2]->gravity.x, charact->data[2]->gravity.y);
        characterization_tests_failed++;
        gray8ifree(img);
        binifree(binary);
        labfree(labels);
        charactfree(charact);
        return;
    }
    
    puts("test_charact_gravity passed\n");
    characterization_tests_passed++;
    gray8ifree(img);
    binifree(binary);
    labfree(labels);
    charactfree(charact);
}

void characterization_test_suite()
{
    test_charact_alloc();
    test_charact_size();
    test_charact_bounds();
    test_charact_gravity();
}