//
//  matrix.c
//  imagic
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "matrix.h"
#include <stdlib.h>
#include <string.h>

#pragma
#pragma mark - Allocation copy deallocation

void *mat(unsigned int width, unsigned int height, size_t dsize) {
    if (width <= 0 || height <= 0) {
        return NULL;
    }
    
    mat_t *mat = malloc(sizeof(mat_t));
    
    mat->width = width;
    mat->height = height;
    mat->dsize = dsize;
    mat->data = calloc(width * height, dsize);
    
    return mat;
}

mat_t *matcpy(const mat_t *mat) {
    if ((mat == NULL) || (mat->data == NULL)) {
        return NULL;
    }

    mat_t *dst = malloc(sizeof(mat_t));
    
    dst->width = mat->width;
    dst->height = mat->height;
    dst->dsize = mat->dsize;
    dst->data = calloc(mat->width * mat->height, mat->dsize);
    memcpy(dst->data, mat->data, mat->width * mat->height * mat->dsize);
    
    return dst;
}

void matdcpy(mat_t *mat, const void *data) {
    if (mat == NULL || mat->data == NULL) {
        return;
    }
    
    memcpy(mat->data, data, mat->width * mat->height * mat->dsize);
}

void matfree(mat_t *mat) {
    free(mat->data);
    free(mat);
}
