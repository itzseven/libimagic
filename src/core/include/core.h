//
//  core.h
//  imagic
//
//  Created by itzseven on 01/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef core_h
#define core_h

#include <stdint.h>

/*!
 *  Data type that stores a 8-bit RGB pixel
 */

typedef struct _rgb8 {
    uint8_t r, g, b;
}rgb8;

/*!
 *  Data type that stores a 16-bit RGB pixel
 */

typedef struct _rgb16 {
    uint16_t r, g, b;
}rgb16;

/*!
 *  Data type that represents a 8-bit grayscale image
 */

typedef struct _gray8i {
    size_t width, height;
    uint8_t *data;
}gray8i_t;

/*!
 *  Data type that represents a 16-bit grayscale image
 */

typedef struct _gray16i {
    size_t width, height;
    uint16_t *data;
}gray16i_t;

/*!
 *  Data type that represents a 8-bit RGB image
 */

typedef struct _rgb8i {
    size_t width, height;
    rgb8 *data;
}rgb8i_t;

/*!
 *  Data type that represents a 16-bit RGB image
 */

typedef struct _rgb16i {
    size_t width, height;
    rgb16 *data;
}rgb16i_t;


#endif /* core_h */
