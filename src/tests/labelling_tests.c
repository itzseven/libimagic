//
//  labelling_tests.c
//  imagic
//
//  Created by itzseven on 08/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "labelling_tests.h"

#include "debug.h"

int labelling_tests_passed;
int labelling_tests_failed;

void test_labels_alloc()
{
    puts("Starts test_labels_alloc\n");
    
    uint16_t width = 20, height = 20;
    
    labels_t *labels = laballoc(width, height);
    
    if (labels->len == (width * height))
    {
        int i = 0;
        
        for (i = 0; i < labels->len; i++)
        {
            if ((labels->data[i] != 0))
            {
                printf("test_labels_alloc failed : expected value %d but got %d on %d\n", 0, labels->data[i], i);
                labelling_tests_failed++;
                labfree(labels);
                return;
            }
        }
    }
    
    else
    {
        printf("test_labels_alloc failed : expected length %d and got %d\n", width * height, labels->len);
        labelling_tests_failed++;
        labfree(labels);
        return;
    }
    
    puts("test_labels_alloc passed\n");
    labelling_tests_passed++;
    labfree(labels);
}

void test_labelling_one_label()
{
    puts("Starts test_labelling_one_label\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    uint32_t ref[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *bin = binarise(img, 50);
    
    labels_t *labels = label(bin);
    
    if (labels->count != 1)
    {
        printf("test_labelling_one_label failed : expected count %d but got %d\n", 1, labels->count);
        labelling_tests_failed++;
        labfree(labels);
        gray8ifree(img);
        binifree(bin);
        return;
    }
    
    int i = 0;
    
    for (i = 0; i < labels->len; i++)
    {
        if ((labels->data[i] != ref[i]))
        {
            printf("test_labelling_one_label failed : expected value %d but got %d on %d\n", ref[i], labels->data[i], i);
            labelling_tests_failed++;
            labfree(labels);
            gray8ifree(img);
            binifree(bin);
            return;
        }
    }
    
    puts("test_labelling_one_label passed\n");
    labelling_tests_passed++;
    labfree(labels);
    gray8ifree(img);
    binifree(bin);
}

void test_labelling_n_labels()
{
    puts("Starts test_labelling_n_labels\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    uint32_t ref[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *bin = binarise(img, 50);
    
    labels_t *labels = label(bin);
    
    if (labels->count != 4)
    {
        printf("test_labelling_n_labels failed : expected count %d but got %d\n", 4, labels->count);
        labelling_tests_failed++;
        labfree(labels);
        gray8ifree(img);
        binifree(bin);
        return;
    }
    
    int i = 0;
    
    for (i = 0; i < labels->len; i++)
    {
        if ((labels->data[i] != ref[i]))
        {
            printf("test_labelling_n_labels failed : expected value %d but got %d on %d\n", ref[i], labels->data[i], i);
            labelling_tests_failed++;
            labfree(labels);
            gray8ifree(img);
            binifree(bin);
            return;
        }
    }
    
    puts("test_labelling_one_label passed\n");
    labelling_tests_passed++;
    labfree(labels);
    gray8ifree(img);
    binifree(bin);
}

void test_labelling_complex_labels()
{
    puts("Starts test_labelling_complex_labels\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    uint32_t ref[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *bin = binarise(img, 50);
    
    labels_t *labels = label(bin);
    
    if (labels->count != 3)
    {
        printf("test_labelling_complex_labels failed : expected count %d but got %d\n", 3, labels->count);
        labelling_tests_failed++;
        labfree(labels);
        gray8ifree(img);
        binifree(bin);
        return;
    }
    
    int i = 0;
    
    for (i = 0; i < labels->len; i++)
    {
        if ((labels->data[i] != ref[i]))
        {
            printf("test_labelling_complex_labels failed : expected value %d but got %d on %d\n", ref[i], labels->data[i], i);
            labelling_tests_failed++;
            labfree(labels);
            gray8ifree(img);
            binifree(bin);
            return;
        }
    }
    
    puts("test_labelling_complex_labels passed\n");
    labelling_tests_passed++;
    labfree(labels);
    gray8ifree(img);
    binifree(bin);
}

void test_labelling_chessboard()
{
    puts("Starts test_labelling_chessboard\n");
    
    uint16_t width = 7, height = 8;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 255, 0, 255, 0, 0, 0, 255, 0, 255, 0, 0, 0, 255, 0, 255, 0, 255, 0, 0, 0, 255, 0, 255, 0, 0, 0, 255, 0, 255, 0, 255, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    uint32_t ref[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 3, 0, 0, 0, 4, 0, 5, 0, 0, 0, 6, 0, 7, 0, 8, 0, 0, 0, 9, 0, 10, 0, 0, 0, 11, 0, 12, 0, 13, 0, 0, 0, 14, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    bini_t *bin = binarise(img, 50);
    
    labels_t *labels = label(bin);
    
    if (labels->count != 15)
    {
        printf("test_labelling_chessboard failed : expected count %d but got %d\n", 15, labels->count);
        labelling_tests_failed++;
        labfree(labels);
        gray8ifree(img);
        binifree(bin);
        return;
    }
    
    int i = 0;
    
    for (i = 0; i < labels->len; i++)
    {
        if ((labels->data[i] != ref[i]))
        {
            printf("test_labelling_chessboard failed : expected value %d but got %d on %d\n", ref[i], labels->data[i], i);
            labelling_tests_failed++;
            labfree(labels);
            gray8ifree(img);
            binifree(bin);
            return;
        }
    }
    
    puts("test_labelling_chessboard passed\n");
    labelling_tests_passed++;
    labfree(labels);
    gray8ifree(img);
    binifree(bin);
}

void labelling_test_suite()
{
    test_labels_alloc();
    test_labelling_one_label();
    test_labelling_n_labels();
    test_labelling_complex_labels();
    test_labelling_chessboard();
}
