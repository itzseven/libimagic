//
//  drawing.h
//  imagic
//
//  Created by itzseven on 24/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef drawing_h
#define drawing_h

#include "core.h"
#include "geometry.h"

/*!
 *  Draws a rectangle on a gray8i_t image
 *
 *  src : source image
 *  rect : rectangle coordinates
 *  color : color of the rectangle lines
 *
 */

void drawrctgray8i(gray8i_t *src, rect_t rect, uint8_t color);

/*!
 *  Draws a rectangle on a rgb8i_t image
 *
 *  src : source image
 *  rect : rectangle coordinates
 *  color : color of the rectangle lines
 *
 */

void drawrctrgb8i(rgb8i_t *src, rect_t rect, rgb8 color);

#endif /* drawing_h */
