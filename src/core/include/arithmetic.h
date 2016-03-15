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
 *  Returns a grayscaled image (stored in gray8i_t object) from source image in 8-bit RGB
 *
 *  src : 8-bit RGB source image
 *
 */

gray8i_t *grayscale(rgb8i_t *src);

/*!
 *  Returns a binarised image (stored in bini_t object) from source image in grayscale
 *
 *  src : source image
 *  threshold : binarization threshold
 */

bini_t *binarise(gray8i_t *src, uint8_t threshold);

/*!
 *  Returns a grayscaled image (stored in gray8i_t object) from source binarised image
 *
 *  src : binarised source image
 *
 */

gray8i_t *unbinarise(bini_t *src);

/*!
 *  Returns the difference (substraction) between two gra8i_t images
 *
 *  img1 : first gray8i_t image
 *  img2 : second gray8i_t image
 *
 */

gray8i_t *subgray8i(gray8i_t *img1, gray8i_t *img2);

#endif /* arithmetic_h */
