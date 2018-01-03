//
//  image.c
//  imagic
//
//  Created by itzseven on 07/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "image.h"
#include "_image.h"
#include <limits.h>

#pragma
#pragma mark - Allocation copy deallocation

img_t *img(unsigned int width, unsigned int height, unsigned int depth, size_t dsize) {
    return mat(width, height, depth, dsize);
}

img_t *imgcpy(const img_t *img) {
    return matcpy((const mat_t *)img);
}

void _img8dcpy(const img_t *dst, const void *data) {
    matdcpy(dst, (const uint8_t *)data);
}

void _img16dcpy(const img_t *dst, const void *data) {
    matdcpy(dst, (const uint16_t *)data);
}

void _img32dcpy(const img_t *dst, const void *data) {
    matdcpy(dst, (const uint32_t *)data);
}

void _img64dcpy(const img_t *dst, const void *data) {
    matdcpy(dst, (const uint64_t *)data);
}

void imgdcpy(const img_t *dst, const void *data) {
    void (*_imgdcpy[4]) (const img_t *dst, const void *data) = {_img8dcpy, _img16dcpy, _img32dcpy, _img64dcpy};
    _imgdcpy[dst->dsize >> 1](dst, data);
}

void imgfree(img_t *img) {
    matfree(img);
}

#pragma
#pragma mark - Comparison

unsigned int _img8cmp(const img_t *img1, const img_t *img2) {
    unsigned int diff = 0, i = 0, len = img1->width * img1->height * img1->depth;
    
    for (i = len; i-- ; ) {
        diff += ELT_DATA(img1, uint8_t, i) != ELT_DATA(img2, uint8_t, i);
    }
    
    return diff;
}

unsigned int _img16cmp(const img_t *img1, const img_t *img2) {
    unsigned int diff = 0, i = 0, len = img1->width * img1->height * img1->depth;
    
    for (i = len; i-- ; ) {
        diff += ELT_DATA(img1, uint16_t, i) != ELT_DATA(img2, uint16_t, i);
    }
    
    return diff;
}

unsigned int _img32cmp(const img_t *img1, const img_t *img2) {
    unsigned int diff = 0, i = 0, len = img1->width * img1->height * img1->depth;
    
    for (i = len; i-- ; ) {
        diff += ELT_DATA(img1, uint32_t, i) != ELT_DATA(img2, uint32_t, i);
    }
    
    return diff;
}

unsigned int _img64cmp(const img_t *img1, const img_t *img2) {
    unsigned int diff = 0, i = 0, len = img1->width * img1->height * img1->depth;
    
    for (i = len; i-- ; ) {
        diff += ELT_DATA(img1, uint64_t, i) != ELT_DATA(img2, uint64_t, i);
    }
    
    return diff;
}

unsigned int imgcmp(const img_t *img1, const img_t *img2) {
    if ((img1->width != img2->width) || (img1->height != img2->height) || (img1->depth != img2->depth) || (img1->dsize != img2->dsize)) {
        return UINT_MAX;
    }
    
    unsigned int (*_imgcmp[4]) (const img_t *img1, const img_t *img2) = {_img8cmp, _img16cmp, _img32cmp, _img64cmp};
    return _imgcmp[img1->dsize >> 1](img1, img2);
}

#pragma mark - Private

unsigned int img8max(const img_t *img) {
    unsigned int i = 0, len = img->width * img->height * img->depth;
    uint8_t max = 0;
    
    for (i = len; i--; ) {
        uint8_t p = ELT_DATA(img, uint8_t, i);
        max = ((p > max) * p) + ((p <= max) * max);
    }
    
    return (unsigned int)max;
}

unsigned int img16max(const img_t *img) {
    unsigned int i = 0, len = img->width * img->height * img->depth;
    uint16_t max = 0;
    
    for (i = len; i--; ) {
        uint16_t p = ELT_DATA(img, uint16_t, i);
        max = ((p > max) * p) + ((p <= max) * max);
    }
    
    return (unsigned int)max;
}

unsigned int img32max(const img_t *img) {
    unsigned int i = 0, len = img->width * img->height * img->depth;
    uint32_t max = 0;
    
    for (i = len; i--; ) {
        uint32_t p = ELT_DATA(img, uint32_t, i);
        max = ((p > max) * p) + ((p <= max) * max);
    }
    
    return (unsigned int)max;
}

unsigned int img64max(const img_t *img) {
    unsigned int i = 0, len = img->width * img->height * img->depth;
    uint64_t max = 0;
    
    for (i = len; i--; ) {
        uint64_t p = ELT_DATA(img, uint64_t, i);
        max = ((p > max) * p) + ((p <= max) * max);
    }
    
    return (unsigned int)max;
}

unsigned int imgmax(const img_t *img) {
    unsigned int (*_imgmax[4]) (const img_t *img) = {img8max, img16max, img32max, img64max};
    return _imgmax[img->dsize >> 1](img);
}

