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
#include "matrix.h"

#define BIN(img, x, y) ELT(img, uint8_t, x, y, 0)

#define GRAY(img, dtype, x, y) ELT(img, dtype, x, y, 0)

#define GRAY8(img, x, y) GRAY(img, uint8_t, x, y, 0)
#define GRAY16(img, x, y) GRAY(img, uint16_t, x, y, 0)

#define RGB_R(img, dtype, x, y) ELT(img, dtype, x, y, 0)
#define RGB_G(img, dtype, x, y) ELT(img, dtype, x, y, 1)
#define RGB_B(img, dtype, x, y) ELT(img, dtype, x, y, 2)

#define RGBA_A(img, dtype, x, y) ELT(img, dtype, x, y, 3)

#define RGB8_R(img, x, y) RGB_R(img, uint8_t, x, y)
#define RGB8_G(img, x, y) RGB_G(img, uint8_t, x, y)
#define RGB8_B(img, x, y) RGB_B(img, uint8_t, x, y)

#define RGB16_R(img, x, y) RGB_R(img, uint16_t, x, y)
#define RGB16_G(img, x, y) RGB_G(img, uint16_t, x, y)
#define RGB16_B(img, x, y) RGB_B(img, uint16_t, x, y)

#define RGB32_R(img, x, y) RGB_R(img, uint32_t, x, y)
#define RGB32_G(img, x, y) RGB_G(img, uint32_t, x, y)
#define RGB32_B(img, x, y) RGB_B(img, uint32_t, x, y)

typedef mat_t img_t;

#pragma
#pragma mark - Allocation copy deallocation

img_t *img(unsigned int width, unsigned int height, unsigned int depth, size_t dsize);
img_t *imgcpy(const img_t *img);
void imgdcpy(const img_t *dst, const void *data);
void imgfree(img_t *img);

#pragma
#pragma mark - Comparison

unsigned int imgcmp(const img_t *img1, const img_t *img2);

#endif /* image_h */

