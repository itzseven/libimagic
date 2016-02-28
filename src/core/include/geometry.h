//
//  geometry.h
//  imagic
//
//  Created by itzseven on 09/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef geometry_h
#define geometry_h

#include <stdint.h>
#include <stdlib.h>

/*!
 *  Data type to represent a point in 2D space with coordinates (x, y)
 */

typedef struct _point2d {
    uint32_t x, y;
}pt2d_t;

/*!
 *  Data type to represent a rectangle defined by two points
 */

typedef struct _rect {
    pt2d_t start, end;
}rect_t;

/*!
 *  Data type to store several 2D space points
 */

typedef struct _point2darray {
    uint32_t len;
    pt2d_t *data;
}pt2darray_t;

/*!
 *  Returns an initialized pt2d_t array with initialized 2D points
 *
 *  count : number of points (array size)
 *
 */

pt2darray_t *pt2arralloc(uint32_t count);

#endif /* geometry_h */
