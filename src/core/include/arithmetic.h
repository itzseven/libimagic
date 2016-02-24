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

/*!
 *  Returns a binarised image (stored in bini_t object) from source image in grayscale
 *
 *  src : source image
 *  threshold : binarization threshold
 */

bini_t *binarise(gray8i_t *src, uint8_t threshold);
gray8i_t *unbinarise(bini_t *src);

#endif /* arithmetic_h */
