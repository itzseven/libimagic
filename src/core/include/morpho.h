//
//  morpho.h
//  imagic
//
//  Created by itzseven on 23/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef morpho_h
#define morpho_h

#include <stdio.h>
#include <math.h>
#include "core.h"

/*!
 *  Returns a bini_t object with distended pixels
 *
 *  src : source image
 *  shift : shift from the central pixel to process => size of the neighbourhood to inspect
 *
 */

bini_t *distension(bini_t *src, uint16_t shift);

/*!
 *  Returns a bini_t object with distended pixels
 *
 *  src : source image
 *  shift : shift from the central pixel to process => size of the neighbourhood to inspect
 *
 */

bini_t *erosion(bini_t *src, uint16_t shift);

/*!
 *  Returns a bini_t object processed with opening (erosion, distension)
 *
 *  src : source image
 *  shift : shift from the central pixel to process => size of the neighbourhood to inspect
 *
 */

bini_t *opening(bini_t *src, uint16_t shift);

/*!
 *  Returns a bini_t object processed with closing (distension, erosion)
 *
 *  src : source image
 *  shift : shift from the central pixel to process => size of the neighbourhood to inspect
 *
 */

bini_t *closing(bini_t *src, uint16_t shift);


#endif /* morpho_h */
