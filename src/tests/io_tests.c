//
//  io_tests.c
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "io_tests.h"

int io_tests_passed;
int io_tests_failed;

void test_pgmopen_ascii()
{
    puts("Starts test_pgmopen_ascii\n");
    
    uint16_t width = 5, height = 5;
    
    gray8i_t *img = pgmopen("resources/stairs-ascii.pgm");
    
    if ((img->width != width) || (img->height != height))
    {
        printf("test_pgmopen_ascii failed : expected width %d and height %d but got %d and %d\n", width, height, img->width, img->height);
    }
    
    uint8_t ref[] = {0, 0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 84, 126, 0, 0, 0, 168, 210, 252, 0, 0, 0, 0, 0, 0};
    
    int i = 0;
    
    for (i = 0; i < img->width * img->height; i++)
    {
        if (img->data[i] != ref[i])
        {
            printf("test_pgmopen_ascii failed : expected value %d but got %d on %d\n", ref[i], img->data[i], i);
            io_tests_failed++;
            gray8ifree(img);
            return;
        }
    }
    
    puts("test_pgmopen_ascii passed\n");
    io_tests_passed++;
    gray8ifree(img);
}

void test_pgmopen_binary()
{
    puts("Starts test_pgmopen_binary\n");
    
    uint16_t width = 5, height = 5;
    
    gray8i_t *img = pgmopen("resources/stairs-bin.pgm");
    
    if ((img->width != width) || (img->height != height))
    {
        printf("test_pgmopen_binary failed : expected width %d and height %d but got %d and %d\n", width, height, img->width, img->height);
    }
    
    uint8_t ref[] = {0, 0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 84, 126, 0, 0, 0, 168, 210, 252, 0, 0, 0, 0, 0, 0};
    
    int i = 0;
    
    for (i = 0; i < img->width * img->height; i++)
    {
        if (img->data[i] != ref[i])
        {
            printf("test_pgmopen_binary failed : expected value %d but got %d on %d\n", ref[i], img->data[i], i);
            io_tests_failed++;
            gray8ifree(img);
            return;
        }
    }
    
    puts("test_pgmopen_ascii passed\n");
    io_tests_passed++;
    gray8ifree(img);
}

void test_ppmopen_ascii()
{
    puts("Starts test_ppmopen_ascii\n");
    
    uint16_t width = 5, height = 5;
    
    rgb8 data[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    rgb8i_t *img = ppmopen("resources/stairs-ascii.ppm");
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i].r != data[i].r || img->data[i].g != data[i].g || img->data[i].b != data[i].b)
            {
                printf("test_ppmopen_ascii failed : expected value (%d, %d, %d) but got (%d, %d, %d) on %d\n", data[i].r, data[i].g, data[i].b, img->data[i].r, img->data[i].g, img->data[i].b, i);
                io_tests_failed++;
                rgb8ifree(img);
                return;
            }
        }
    }
    
    else
    {
        printf("test_ppmopen_ascii failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        io_tests_failed++;
        rgb8ifree(img);
        return;
    }
    
    puts("test_ppmopen_ascii passed\n");
    io_tests_passed++;
    rgb8ifree(img);
}

void test_ppmopen_binary()
{
    puts("Starts test_ppmopen_binary\n");
    
    uint16_t width = 5, height = 5;
    
    rgb8 data[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    rgb8i_t *img = ppmopen("resources/stairs-bin.ppm");
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i].r != data[i].r || img->data[i].g != data[i].g || img->data[i].b != data[i].b)
            {
                printf("test_ppmopen_binary failed : expected value (%d, %d, %d) but got (%d, %d, %d) on %d\n", data[i].r, data[i].g, data[i].b, img->data[i].r, img->data[i].g, img->data[i].b, i);
                io_tests_failed++;
                rgb8ifree(img);
                return;
            }
        }
    }
    
    else
    {
        printf("test_ppmopen_binary failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        io_tests_failed++;
        rgb8ifree(img);
        return;
    }
    
    puts("test_ppmopen_binary passed\n");
    io_tests_passed++;
    rgb8ifree(img);
}

void test_pbmopen_ascii()
{
    puts("Starts test_pbmopen_ascii\n");
    
    uint16_t width = 5, height = 5;
    
    bini_t *img = pbmopen("resources/stairs-ascii.pbm");
    
    if ((img->width != width) || (img->height != height))
    {
        printf("test_pbmopen_ascii failed : expected width %d and height %d but got %d and %d\n", width, height, img->width, img->height);
    }
    
    uint8_t ref[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    
    int i = 0;
    
    for (i = 0; i < img->width * img->height; i++)
    {
        if (img->data[i] != ref[i])
        {
            printf("test_pbmopen_ascii failed : expected value %d but got %d on %d\n", ref[i], img->data[i], i);
            io_tests_failed++;
            binifree(img);
            return;
        }
    }
    
    puts("test_pbmopen_ascii passed\n");
    io_tests_passed++;
    binifree(img);
}

void test_pbmopen_binary()
{
    
}
