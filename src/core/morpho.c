//
//  morpho.c
//  imagic
//
//  Created by itzseven on 23/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "morpho.h"

bini_t *distension(bini_t *src, uint16_t shift)
{
    bini_t *dst = binialloc(src->width, src->height);
    
    int i = 0, j = 0, l = 0, m = 0;
    
    uint32_t acc = 0;
    
    uint16_t width = src->width, height = src->height;
    uint32_t pixidx = 0;
    
    uint16_t comparator = (uint16_t)(powf(shift, 2) + shift) * 4;
    
    for (i = shift; i < height - shift; i++)
    {
        for (j = shift; j < width - shift; j++)
        {
            acc = 0;
            
            pixidx = PXL_IDX(width, j, i);
            
            for (m = i - shift; (m <= i + shift); m++)
                for (l = j - shift; (l <= j + shift); l++)
                    acc += src->data[PXL_IDX(width, l, m)];
            
            acc -= src->data[pixidx];
            
            dst->data[pixidx] = !(acc < comparator);
        }
    }
    
    return dst;
}

bini_t *erosion(bini_t *src, uint16_t shift)
{
    bini_t *dst = binialloc(src->width, src->height);
    
    int i = 0, j = 0, l = 0, m = 0;
    
    uint32_t acc = 0;
    
    uint16_t width = src->width, height = src->height;
    uint32_t pixidx = 0;
    
    for (i = shift; i < height - shift; i++)
    {
        for (j = shift; j < width - shift; j++)
        {
            acc = 0;
            
            pixidx = PXL_IDX(width, j, i);
            
            for (m = i - shift; (m <= i + shift); m++)
                for (l = j - shift; (l <= j + shift); l++)
                    acc += src->data[PXL_IDX(width, l, m)];
            
            acc -= src->data[pixidx];
            
            dst->data[pixidx] = (acc > 0);
        }
    }
    
    return dst;
}

bini_t *opening(bini_t *src, uint16_t shift)
{
    bini_t *dst = binialloc(src->width, src->height);
    
    bini_t *eroded = erosion(src, shift);
    dst = distension(eroded, shift);
    
    binifree(eroded);
    
    return dst;
}

bini_t *closing(bini_t *src, uint16_t shift)
{
    bini_t *dst = binialloc(src->width, src->height);
    
    bini_t *distended = distension(src, shift);
    dst = erosion(distended, shift);
    
    binifree(distended);
    
    return dst;
}