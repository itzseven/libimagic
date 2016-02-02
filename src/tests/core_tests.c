//
//  core_tests.c
//  imagic
//
//  Created by Romain Dubreucq on 01/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "core_tests.h"

int core_tests_passed;
int core_tests_failed;

void test_gray8i_alloc()
{
    puts("Starts test_gray8i_alloc\n");
    
    uint16_t width = 20, height = 20;
    
    gray8i_t *img = gray8ialloc(width, height);
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i] != 0)
            {
                printf("test_gray8i_alloc failed : expected value %d but got %d on %d\n", 0, img->data[i], i);
                core_tests_failed++;
                gray8ifree(img);
                return;
            }
        }
    }
    
    else
    {
        printf("test_gray8i_alloc failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        core_tests_failed++;
        gray8ifree(img);
        return;
    }
    
    puts("test_gray8i_alloc passed\n");
    core_tests_passed++;
    gray8ifree(img);
}

void test_gray8i_alloc_with_data()
{
    puts("Starts test_gray8i_alloc_with_data\n");
    
    uint16_t width = 8, height = 4;
    
    uint8_t data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i] != data[i])
            {
                printf("test_gray8i_alloc_with_data failed : expected value %d but got %d on %d\n", data[i], img->data[i], i);
                core_tests_failed++;
                return;
            }
        }
    }
    
    else
    {
        printf("test_gray8i_alloc_with_data failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        core_tests_failed++;
        return;
    }
    
    puts("test_gray8i_alloc_with_data passed\n");
    core_tests_passed++;
}

void test_rgb8i_alloc()
{
    puts("Starts test_rgb8i_alloc\n");
    
    uint16_t width = 20, height = 20;
    
    rgb8i_t *img = rgb8ialloc(width, height);
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i].r != 0 || img->data[i].g != 0 || img->data[i].b != 0)
            {
                printf("test_rgb8i_alloc failed : expected value (%d, %d, %d) but got (%d, %d, %d) on %d\n", 0, 0, 0, img->data[i].r, img->data[i].g, img->data[i].b, i);
                core_tests_failed++;
                rgb8ifree(img);
                return;
            }
        }
    }
    
    else
    {
        printf("test_rgb8i_alloc failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        core_tests_failed++;
        rgb8ifree(img);
        return;
    }
    
    puts("test_rgb8i_alloc passed\n");
    core_tests_passed++;
    rgb8ifree(img);
}

void test_rgb8i_alloc_with_data()
{
    puts("Starts test_rgb8i_alloc_with_data\n");
    
    uint16_t width = 2, height = 4;
    
    rgb8 data[] = {{0, 1, 0}, {1, 3, 0}, {2, 3, 0}, {1, 3, 4}, {1, 255, 0}, {123, 3, 0}, {190, 37, 0}, {190, 37, 98}};
    
    rgb8i_t *img = rgb8iallocwd(width, height, data);
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0;
        
        for (i = 0; i < img->width * img->height; i++)
        {
            if (img->data[i].r != data[i].r || img->data[i].g != data[i].g || img->data[i].b != data[i].b)
            {
                printf("test_rgb8i_alloc_with_data failed : expected value (%d, %d, %d) but got (%d, %d, %d) on %d\n", data[i].r, data[i].g, data[i].b, img->data[i].r, img->data[i].g, img->data[i].b, i);
                core_tests_failed++;
                return;
            }
        }
    }
    
    else
    {
        printf("test_gray8i_alloc_with_data failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        core_tests_failed++;
        return;
    }
    
    puts("test_gray8i_alloc_with_data passed\n");
    core_tests_passed++;
}

void test_rgb8i_alloc_with_bgra_data()
{
    puts("Starts test_rgb8i_alloc_with_bgra_data\n");
    
    uint16_t width = 8, height = 4;
    
    uint8_t data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    rgb8i_t *img = rgb8iallocwd_bgra(width, height, data);
    
    if ((img->width == width) && (img->height == height))
    {
        int i = 0, j = 0;
        
        for (i = 0, j = 0; i < img->width * img->height && j < img->width * img->height; i++, j += 4)
        {
            if (img->data[i].b != data[j] || img->data[i].g != data[j+1] || img->data[i].r != data[j+2])
            {
                printf("test_rgb8i_alloc_with_bgra_data failed : expected value (%d, %d, %d) but got (%d, %d, %d) on %d\n", data[j+2], data[j+1], data[j], img->data[i].r, img->data[i].g, img->data[i].b, i);
                core_tests_failed++;
                return;
            }
        }
    }
    
    else
    {
        printf("test_rgb8i_alloc_with_bgra_data failed : expected width %d and got %d, height %d and got %d\n", width, img->width, height, img->height);
        core_tests_failed++;
        return;
    }
    
    puts("test_rgb8i_alloc_with_bgra_data passed\n");
    core_tests_passed++;
}

void test_gray8i_cpy()
{
    puts("Starts test_gray8i_cpy\n");
    
    uint16_t width = 8, height = 4;
    
    uint8_t data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    gray8i_t *firstImage = gray8iallocwd(width, height, data);
    gray8i_t *secondImage = gray8icpy(firstImage);
    
    int comparison = gray8icmp(firstImage, secondImage);
    
    if (comparison == 0)
    {
        puts("test_gray8i_cpy passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_gray8i_cpy failed\n");
        core_tests_failed++;
    }
    
    gray8ifree(firstImage);
    gray8ifree(secondImage);
}

void test_rgb8i_cpy()
{
    puts("Starts test_rgb8i_cpy\n");
    
    uint16_t width = 2, height = 4;
    
    rgb8 data[] = {{0, 1, 0}, {1, 3, 0}, {2, 3, 0}, {1, 3, 4}, {1, 255, 0}, {123, 3, 0}, {190, 37, 0}, {190, 37, 98}};
    
    rgb8i_t *firstImage = rgb8iallocwd(width, height, data);
    rgb8i_t *secondImage = rgb8icpy(firstImage);
    
    int comparison = rgb8icmp(firstImage, secondImage);
    
    if (comparison == 0)
    {
        puts("test_rgb8i_cpy passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_rgb8i_cpy failed\n");
        core_tests_failed++;
    }
    
    rgb8ifree(firstImage);
    rgb8ifree(secondImage);
}

void test_gray8i_cmp()
{
    puts("Starts test_gray8i_cmp\n");
    
    uint16_t width = 8, height = 4;
    
    uint8_t data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    gray8i_t *firstImage = gray8iallocwd(width, height, data);
    gray8i_t *secondImage = gray8iallocwd(width, height, data);
    
    int comparison = gray8icmp(firstImage, secondImage);
    
    if (comparison == 0)
    {
        puts("test_gray8i_cmp passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_gray8i_cmp failed\n");
        core_tests_failed++;
    }
    
    gray8ifree(firstImage);
    gray8ifree(secondImage);
}

void test_rgb8i_cmp()
{
    puts("Starts test_rgb8i_cmp\n");
    
    uint16_t width = 2, height = 4;
    
    rgb8 data[] = {{0, 1, 0}, {1, 3, 0}, {2, 3, 0}, {1, 3, 4}, {1, 255, 0}, {123, 3, 0}, {190, 37, 0}, {190, 37, 98}};
    
    rgb8i_t *firstImage = rgb8iallocwd(width, height, data);
    rgb8i_t *secondImage = rgb8iallocwd(width, height, data);
    
    int comparison = rgb8icmp(firstImage, secondImage);
    
    if (comparison == 0)
    {
        puts("test_rgb8i_cmp passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_rgb8i_cmp failed\n");
        core_tests_failed++;
    }
    
    rgb8ifree(firstImage);
    rgb8ifree(secondImage);
}

void test_gray8i_cmp_invalid()
{
    puts("Starts test_gray8i_cmp_invalid\n");
    
    uint16_t width = 8, height = 4;
    
    uint8_t data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    uint8_t data2[] = {0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0E, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x13, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    
    gray8i_t *firstImage = gray8iallocwd(width, height, data);
    gray8i_t *secondImage = gray8iallocwd(width, height, data2);
    
    int comparison = gray8icmp(firstImage, secondImage);
    
    if (comparison == 3)
    {
        puts("test_gray8i_cmp_invalid passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_gray8i_cmp_invalid failed\n");
        core_tests_failed++;
    }
    
    gray8ifree(firstImage);
    gray8ifree(secondImage);
}

void test_rgb8i_cmp_invalid()
{
    puts("Starts test_rgb8i_cmp\n");
    
    uint16_t width = 2, height = 4;
    
    rgb8 data[] = {{0, 1, 0}, {1, 3, 0}, {2, 3, 0}, {1, 3, 4}, {1, 255, 0}, {123, 3, 0}, {190, 37, 0}, {190, 37, 98}};
    
    rgb8 data2[] = {{1, 1, 0}, {1, 3, 0}, {2, 4, 0}, {1, 3, 4}, {1, 255, 0}, {123, 3, 1}, {190, 37, 0}, {190, 37, 98}};
    
    rgb8i_t *firstImage = rgb8iallocwd(width, height, data);
    rgb8i_t *secondImage = rgb8iallocwd(width, height, data2);
    
    int comparison = rgb8icmp(firstImage, secondImage);
    
    if (comparison == 3)
    {
        puts("test_rgb8i_cmp passed\n");
        core_tests_passed++;
    }
    
    else
    {
        puts("test_rgb8i_cmp failed\n");
        core_tests_failed++;
    }
    
    rgb8ifree(firstImage);
    rgb8ifree(secondImage);
}