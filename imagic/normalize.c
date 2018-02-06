//
//  normalize.c
//  imagic
//
//  Created by itzseven on 06/02/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#include "normalize.h"
#include "_image.h"

void imgnorm8(const mat_t *mat, const img_t *img) {
    unsigned int i = 0, len = img->width * img->height * img->depth, max = imgmax(img);
    unsigned int *matdata = (unsigned int *)
    float coeff = (float)UINT8_MAX / (float)max;
    uint8_t *imgdata = (uint8_t *)img->data;
    
    for (i = len; i--; ) {
        imgdata[i] =
        uint64_t p = ELT_DATA(img, uint64_t, i);
    }
}

void imgnorm(const mat_t *mat, const img_t *img) {
    void (*_imgnorm[1]) (const mat_t *mat, const img_t *img) = {imgnorm8};
    _imgnorm[img->dsize >> 1](mat, img);
}
