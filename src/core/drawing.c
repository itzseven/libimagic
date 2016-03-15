//
//  drawing.c
//  imagic
//
//  Created by itzseven on 24/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "drawing.h"

void drawrctgray8i(gray8i_t *src, rect_t rect, uint8_t color)
{
    uint32_t i = 0, j = 0;
    uint16_t width = src->width;
    
    for (i = rect.start.y; i <= rect.end.y; i++)
    {
        src->data[PXL_IDX(width, rect.start.x, i)] = color;
        src->data[PXL_IDX(width, rect.end.x, i)] = color;
    }
    
    for (j = rect.start.x; j <= rect.end.x; j++)
    {
        src->data[PXL_IDX(width, j, rect.start.y)] = color;
        src->data[PXL_IDX(width, j, rect.end.y)] = color;
    }
}

void drawrctrgb8i(rgb8i_t *src, rect_t rect, rgb8 color)
{
    uint32_t i = 0, j = 0;
    uint16_t width = src->width;
    
    for (i = rect.start.y; i <= rect.end.y; i++)
    {
        src->data[PXL_IDX(width, rect.start.x, i)] = color;
        src->data[PXL_IDX(width, rect.end.x, i)] = color;
    }
    
    for (j = rect.start.x; j <= rect.end.x; j++)
    {
        src->data[PXL_IDX(width, j, rect.start.y)] = color;
        src->data[PXL_IDX(width, j, rect.end.y)] = color;
    }
}