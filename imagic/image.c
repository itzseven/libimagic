//
//  image.c
//  imagic
//
//  Created by itzseven on 07/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "image.h"
#include "matrix.h"
#include <limits.h>

#pragma
#pragma mark - Allocation copy deallocation

rgb8i_t *rgb8i(unsigned int width, unsigned int height) {
    return mat(width, height, 1, sizeof(rgb8i_t));
}

rgb8i_t *rgb8icpy(const rgb8i_t *src) {
    return (rgb8i_t *)matcpy((mat_t *)src);
}

void rgb8idcpy(rgb8i_t *dst, const rgb8 *data) {
    return matdcpy((mat_t *)dst, data);
}

void rgb8ifree(rgb8i_t *img) {
    matfree((mat_t *)img);
}

gray8i_t *gray8i(unsigned int width, unsigned int height) {
    return mat(width, height, 1, sizeof(uint8_t));
}

gray8i_t *gray8icpy(const gray8i_t *src) {
    return (gray8i_t *)matcpy((mat_t *)src);
}

void gray8idcpy(gray8i_t *dst, const uint8_t *data) {
    return matdcpy((mat_t *)dst, data);
}

void gray8ifree(gray8i_t *img) {
    matfree((mat_t *)img);
}

#pragma
#pragma mark - Comparison

unsigned int rgb8icmp(const rgb8i_t *img1, const rgb8i_t *img2) {
    if ((img1->width != img2->width) || (img1->height != img2->height)) {
        return UINT_MAX;
    }
    
    unsigned int diff = 0, i = 0, len = img1->width * img1->height;
    
    for (i = len; i-- ; ) {
        register rgb8 img1val = img1->data[i], img2val = img2->data[i];
        diff += (img1val.r != img2val.r) || (img1val.g != img2val.g) || (img1val.b != img2val.b);
    }
    
    return diff;
}

unsigned int gray8icmp(const gray8i_t *img1, const gray8i_t *img2) {
    if ((img1->width != img2->width) || (img1->height != img2->height)) {
        return UINT_MAX;
    }
    
    unsigned int diff = 0, i = 0, len = img1->width * img1->height;
    
    for (i = len; i-- ; ) {
        diff += img1->data[i] != img2->data[i];
    }
    
    return diff;
}
