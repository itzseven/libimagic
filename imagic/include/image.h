//
//  image.h
//  imagic
//
//  Created by itzseven on 07/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#ifndef image_h
#define image_h

#include <stdlib.h>

typedef struct {
    uint8_t r, g, b;
}rgb8;

typedef struct {
    unsigned int width, height;
    size_t dsize;
    rgb8 *data;
}rgb8i_t;

typedef struct {
    unsigned int width, height;
    size_t dsize;
    uint8_t *data;
}gray8i_t;

#pragma
#pragma mark - Allocation copy deallocation

rgb8i_t *rgb8i(unsigned int width, unsigned int height);
rgb8i_t *rgb8icpy(const rgb8i_t *src);
void rgb8idcpy(rgb8i_t *dst, const rgb8 *data);
void rgb8ifree(rgb8i_t *img);

gray8i_t *gray8i(unsigned int width, unsigned int height);
gray8i_t *gray8icpy(const gray8i_t *src);
void gray8idcpy(gray8i_t *dst, const uint8_t *data);
void gray8ifree(gray8i_t *img);

#pragma
#pragma mark - Comparison

unsigned int rgb8icmp(const rgb8i_t *img1, const rgb8i_t *img2);
unsigned int gray8icmp(const gray8i_t *img1, const gray8i_t *img2);

#endif /* image_h */
