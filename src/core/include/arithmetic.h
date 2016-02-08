//
//  arithmetic.h
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef arithmetic_h
#define arithmetic_h

#include "core.h"

gray8i_t *grayscrgb8i(rgb8i_t *src);
rgb8i_t *colorgray8i(gray8i_t *src);
bini_t *binarise(gray8i_t *src, uint8_t threshold);
gray8i_t *substract(gray8i_t *img1, gray8i_t *img2);

#endif /* arithmetic_h */
