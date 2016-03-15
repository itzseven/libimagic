//
//  opticalflow.h
//  imagic
//
//  Created by Adrien on 23/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#ifndef opticalflow_h
#define opticalflow_h

#include "core.h"
#include "geometry.h"

#define ITERATION 6

/*!
 * Calculates the optical flow between two images.
 * Returns an array of the estimated speed vectors of each pixels.
 *
 * image1 : the first image.
 * image2 : the second image.
 */
vec2d_t* optical_flow(gray8i_t* image1, gray8i_t* image2);

#endif /* opticalflow_h */
