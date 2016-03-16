//
//  filter.c
//  imagic
//
//  Created by itzseven on 24/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "filter.h"

gray8i_t *lowpassflt(gray8i_t *src)
{
    gray8i_t *dst = gray8ialloc(src->width, src->height);
    
    int i = 0, j = 0, k = 0;
    float tmp;
    
    for (i = 1; i < src->height - 1; i++)
    {
        for (j = 1; j < src->width - 1; j++)
        {
            tmp = (float)LP_FLT(src, j, i);
            k = PXL_IDX(src->width, j, i);
            dst->data[k] = (uint8_t)(tmp / 9.0);
        }
    }
    
    return dst;
}

gray8i_t *highpassflt(gray8i_t *src)
{
    gray8i_t *dst = gray8ialloc(src->width, src->height);
    
    int i = 0, j = 0, k = 0;
    float tmp;
    
    for (i = 1; i < src->height - 1; i++)
    {
        for (j = 1; j < src->width - 1; j++)
        {
            tmp = (float)HP_FLT(src, j, i);
            k = PXL_IDX(src->width, j, i);
            dst->data[k] = (uint8_t)(tmp);
        }
    }
    
    return dst;
}