//
//  core.c
//  imagic
//
//  Created by itzseven on 01/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "core.h"

gray8i_t *gray8ialloc(uint16_t width, uint16_t height)
{
    gray8i_t *gray8img = (gray8i_t *)malloc(sizeof(gray8i_t));
    
    gray8img->width = width;
    gray8img->height = height;
    gray8img->data = (uint8_t *)calloc(width * height, sizeof(uint8_t));
    
    return gray8img;
}

gray8i_t *gray8iallocwd(uint16_t width, uint16_t height, uint8_t *data)
{
    gray8i_t *gray8img = (gray8i_t *)malloc(sizeof(gray8i_t));
    
    gray8img->width = width;
    gray8img->height = height;
    gray8img->data = (uint8_t *)calloc(width * height, sizeof(uint8_t));
    memcpy(gray8img->data, data, sizeof(uint8_t) * width * height);
    
    return gray8img;
}

bini_t *binialloc(uint16_t width, uint16_t height)
{
    bini_t *binimg = (bini_t *)malloc(sizeof(bini_t));
    
    binimg->width = width;
    binimg->height = height;
    binimg->data = (uint8_t *)calloc(width * height, sizeof(uint8_t));
    
    unsigned int i = 0;
    
    for (i = 0; i < width * height; i++)
        binimg->data[i] = 1;
    
    return binimg;
}

bini_t *biniallocwd(uint16_t width, uint16_t height, uint8_t *data)
{
    bini_t *binimg = (bini_t *)malloc(sizeof(bini_t));
    
    binimg->width = width;
    binimg->height = height;
    binimg->data = (uint8_t *)calloc(width * height, sizeof(uint8_t));
    memcpy(binimg->data, data, sizeof(uint8_t) * width * height);
    
    return binimg;
}

rgb8i_t *rgb8ialloc(uint16_t width, uint16_t height)
{
    rgb8i_t *rgb8img = (rgb8i_t *)malloc(sizeof(rgb8i_t));
    
    rgb8img->width = width;
    rgb8img->height = height;
    rgb8img->data = (rgb8 *)calloc(width*height, sizeof(rgb8));
    
    return rgb8img;
}

rgb8i_t *rgb8iallocwd(uint16_t width, uint16_t height, rgb8 *data)
{
    rgb8i_t *rgb8img = (rgb8i_t *)malloc(sizeof(rgb8i_t));
    
    rgb8img->width = width;
    rgb8img->height = height;
    rgb8img->data = (rgb8 *)calloc(width*height, sizeof(rgb8));
    memcpy(rgb8img->data, data, sizeof(rgb8) * width * height);
    
    return rgb8img;
}

rgb8i_t *rgb8iallocwd_bgra(uint16_t width, uint16_t height, uint8_t *data)
{
    rgb8i_t *rgb8img = rgb8ialloc(width, height);
    
    unsigned int i = 0, j = 0;
    
    uint32_t length = width * height * 4;
    
    for (i = 0; i < length; i+=4)
    {
        rgb8img->data[j].r = data[i+2];
        rgb8img->data[j].g = data[i+1];
        rgb8img->data[j].b = data[i];
        
        j++;
    }
    
    return rgb8img;
}

gray8i_t *gray8icpy(gray8i_t *src)
{
    gray8i_t *dst = gray8ialloc(src->width, src->height);
    
    dst->width = src->width;
    dst->height = src->height;
    memcpy(dst->data, src->data, sizeof(uint8_t) * src->width * src->height);
    
    return dst;
}

rgb8i_t *rgb8icpy(rgb8i_t *src)
{
    rgb8i_t *dst = rgb8ialloc(src->width, src->height);
    
    dst->width = src->width;
    dst->height = src->height;
    memcpy(dst->data, src->data, sizeof(rgb8) * src->width * src->height);
    
    return dst;
}

int gray8icmp(gray8i_t *img1, gray8i_t *img2)
{
    int res = 0;
    unsigned int i = 0;
    
    uint32_t length = img1->width * img1->height;
    
    if ((img1->width != img2->width) || (img1->height != img2->height))
        return -1;
    
    for (i = 0; i < length; i++)
        res += img1->data[i] != img2->data[i];
    
    return res;
}

int rgb8icmp(rgb8i_t *img1, rgb8i_t *img2)
{
    int res = 0;
    unsigned int i = 0;
    
    uint32_t length = img1->width * img1->height;
    
    if ((img1->width != img2->width) || (img1->height != img2->height))
        return -1;
    
    for (i = 0; i < length; i++)
    {
        rgb8 p1 = img1->data[i], p2 = img2->data[i];
        res += (p1.r != p2.r) || (p1.g != p2.g) || (p1.b != p2.b);
    }
    
    return res;
}

void gray8ifree(gray8i_t *img)
{
    free(img->data);
    free(img);
}

void binifree(bini_t *img)
{
    free(img->data);
    free(img);
}

void rgb8ifree(rgb8i_t *img)
{
    free(img->data);
    free(img);
}
