//
//  arithmetic.c
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "arithmetic.h"

bini_t *binarise(gray8i_t *src, uint8_t threshold)
{
    bini_t *dst = (bini_t *)binialloc(src->width, src->height);
    
    int i = 0;
    
    uint32_t pixcount = src->width * src->height;
    
    for (i = 0; i < pixcount; i++)
        dst->data[i] = !(src->data[i] > threshold);
    
    return dst;
}
