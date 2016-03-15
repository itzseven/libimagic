//
//  arithmetic.c
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "arithmetic.h"

gray8i_t *grayscale(rgb8i_t *src)
{
    gray8i_t *dst = gray8ialloc(src->width, src->height);
    
    int i = 0;
    
    for (i = 0; i < src->width * src->height; i++)
        dst->data[i] = (uint8_t)((src->data[i].r + src->data[i].g + src->data[i].b) / 3);
    
    return dst;
}

bini_t *binarise(gray8i_t *src, uint8_t threshold)
{
    bini_t *dst = binialloc(src->width, src->height);
    
    int i = 0;
    
    uint32_t pixcount = src->width * src->height;
    
    for (i = 0; i < pixcount; i++)
        dst->data[i] = !(src->data[i] > threshold);
    
    return dst;
}

gray8i_t *unbinarise(bini_t *src)
{
    gray8i_t *dst = gray8ialloc(src->width, src->height);
    
    int i = 0;
    
    uint32_t pixcount = src->width * src->height;
    
    for (i = 0; i < pixcount; i++)
        dst->data[i] = (1 - src->data[i]) * 255;
    
    return dst;
}

gray8i_t *subgray8i(gray8i_t *img1, gray8i_t *img2)
{
    gray8i_t *dst = gray8ialloc(img1->width, img1->height);
    
    int i = 0;
    
    for (i = 0; i < img1->width * img1->height; i++)
        dst->data[i] = abs(img1->data[i] - img2->data[i]);
    
    return dst;
}
