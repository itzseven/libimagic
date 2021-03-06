//
//  geometry.c
//  imagic
//
//  Created by itzseven on 09/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "geometry.h"

pt2darray_t *pt2arralloc(uint32_t count)
{
    pt2darray_t *arr = (pt2darray_t *)malloc(sizeof(pt2darray_t));
    arr->len = count;
    arr->data = (pt2d_t *)calloc(count, sizeof(pt2d_t));
    
    uint32_t i = 0;
    
    for (i = 0; i < count; i++)
    {
        arr->data[i].x = 0;
        arr->data[i].y = 0;
    }
    
    return arr;
}

vect2darray_t *vect2arralloc(uint32_t count) {
    vect2darray_t *arr = (vect2darray_t *)malloc(sizeof(vect2darray_t));
    arr->length = count;
    arr->data = (vect2d_t *)calloc(count, sizeof(vect2d_t));
    
    uint32_t i = 0;
    for (i = 0; i < count; i++) {
        arr->data[i].x = 0;
        arr->data[i].y = 0;
    }
    
    return arr;
}

void vect2darrfree(vect2darray_t* vect2darray) {
    free(vect2darray->data);
    free(vect2darray);
}