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
#include <stdlib.h>
#include <string.h>

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
    uint16_t width, height;
    uint8_t *data;
}gray8i_t;

/*!
 *  Data type that represents a 16-bit grayscale image
 */

typedef struct _gray16i {
    uint16_t width, height;
    uint16_t *data;
}gray16i_t;

/*!
 *  Data type that represents a 8-bit RGB image
 */

typedef struct _rgb8i {
    uint16_t width, height;
    rgb8 *data;
}rgb8i_t;

/*!
 *  Data type that represents a 16-bit RGB image
 */

typedef struct _rgb16i {
    uint16_t width, height;
    rgb16 *data;
}rgb16i_t;

/*!
 *  Returns an initialized gray8i_t image (with dimension width x height) with allocated data set to 0
 */

gray8i_t *gray8ialloc(uint16_t width, uint16_t height);

/*!
 *  Returns an initialized gray8i_t object with a copy of the data passed in parameter
 */

gray8i_t *gray8iallocwd(uint16_t width, uint16_t height, uint8_t *data);

/*!
 *  Returns an initialized rgb8i_t object with allocated data set to 0
 */

rgb8i_t *rgb8ialloc(uint16_t width, uint16_t height);

/*!
 *  Returns an initialized rgb8i_t object with a copy of the data passed in parameter
 */

rgb8i_t *rgb8iallocwd(uint16_t width, uint16_t height, rgb8 *data);

/*!
 *  Returns an initialized rgb8i_t object with a copy of the BGRA (Blue Green Red Alpha) data passed in parameter
 */

rgb8i_t *rgb8iallocwd_bgra(uint16_t width, uint16_t height, uint8_t *data);

/*!
 *  Returns a copy of the 8-bit grayscale image passed in parameter
 */

gray8i_t *gray8icpy(gray8i_t *src);

/*!
 *  Returns a copy of the 8-bit RGB image passed in parameter
 */

rgb8i_t *rgb8icpy(rgb8i_t *src);

/*!
 *  Compares two 8-bit grayscale images
 *
 *  Returns 0 if the images are equal
 *  Returns -1 if the images don't have the same dimensions
 *  Returns the number of different pixels otherwise
 */

int gray8icmp(gray8i_t *img1, gray8i_t *img2);

/*!
 *  Compares two 8-bit RGB images
 *
 *  Returns 0 if the images are equal
 *  Returns -1 if the images don't have the same dimensions
 *  Returns the number of different pixels otherwise
 */

int rgb8icmp(rgb8i_t *img1, rgb8i_t *img2);

/*!
 *  Frees the memory of an 8-bit grayscale image
 */

void gray8ifree(gray8i_t *img);

/*!
 *  Frees the memory of an 8-bit RGB image
 */

void rgb8ifree(rgb8i_t *img);

#endif /* core_h */
