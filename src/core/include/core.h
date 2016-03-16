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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 *  As the pixels of every image handled are stored in a one dimensional array, you can use this macro to get the index of a 
 *  pixel by specifying its 2D coordinates (x, y) and the width of the image
 */

#define PXL_IDX(width, x, y) (((y) * width) + (x))

#define PXL(img, x, y) img->data[PXL_IDX(img->width, x, y)]

/*!
 *  Data type that stores a 8-bit RGB pixel
 *
 *  r : red channel
 *  g : green channel
 *  b : blue channel
 *
 *  Value range : 0 (black) - 255 (white)
 */

typedef struct _rgb8 {
    uint8_t r, g, b;
}rgb8;

/*!
 *  Data type that stores a 16-bit RGB pixel
 *
 *  r : red channel
 *  g : green channel
 *  b : blue channel
 */

typedef struct _rgb16 {
    uint16_t r, g, b;
}rgb16;

/*!
 *  Data type that represents a 8-bit grayscale image
 *
 *  width : horizontal distance of the image
 *  height : vertical distance of the image
 *  data : pixel array (value range : 0 (black) - 255 (white))
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
 *  Data type that represents a 8-bit binary image
 *
 *  width : horizontal distance of the image
 *  height : vertical distance of the image
 *  data : pixel array (value range : 0 (white) - 1 (black))
 */

typedef struct _bini {
    uint16_t width, height;
    uint8_t *data;
}bini_t;

/*!
 *  Data type that represents a 8-bit RGB image
 *
 *  width : horizontal distance of the image
 *  height : vertical distance of the image
 *  data : pixel array
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
 *
 *  width : width of the image
 *  height : height of the image
 */

gray8i_t *gray8ialloc(uint16_t width, uint16_t height);

/*!
 *  Returns an initialized gray8i_t object with a copy of the data passed in parameter
 *
 *  width : width of the image
 *  height : height of the image
 *  data : pointer to pixel data
 */

gray8i_t *gray8iallocwd(uint16_t width, uint16_t height, uint8_t *data);

/*!
 *  Returns an initialized gray8i_t image (with dimension width x height) with allocated data set to 0
 *
 *  width : width of the image
 *  height : height of the image
 */

bini_t *binialloc(uint16_t width, uint16_t height);

/*!
 *  Returns an initialized bini_t object with a copy of the data passed in parameter
 *
 *  width : width of the image
 *  height : height of the image
 *  data : pointer to pixel data
 */

bini_t *biniallocwd(uint16_t width, uint16_t height, uint8_t *data);

/*!
 *  Returns an initialized rgb8i_t object with allocated data set to 0
 *
 *  width : width of the image
 *  height : height of the image
 */

rgb8i_t *rgb8ialloc(uint16_t width, uint16_t height);

/*!
 *  Returns an initialized rgb8i_t object with a copy of the data passed in parameter
 *
 *  width : width of the image
 *  height : height of the image
 *  data : pointer to RGB pixel data
 */

rgb8i_t *rgb8iallocwd(uint16_t width, uint16_t height, rgb8 *data);

/*!
 *  Returns an initialized rgb8i_t object with a copy of the BGRA (Blue Green Red Alpha) data passed in parameter
 *
 *  width : width of the image
 *  height : height of the image
 *  data : pointer to BGRA pixel data
 */

rgb8i_t *rgb8iallocwd_bgra(uint16_t width, uint16_t height, uint8_t *data);

/*!
 *  Returns a copy of the 8-bit grayscale image passed in parameter
 *
 *  src : source image to copy
 */

gray8i_t *gray8icpy(gray8i_t *src);

/*!
 *  Returns a copy of the 8-bit RGB image passed in parameter
 *
 *  src : source image to copy
 */

rgb8i_t *rgb8icpy(rgb8i_t *src);

/*!
 *  Compares two 8-bit grayscale images
 *
 *  img1 : first image
 *  img2 : second image to compare with img1
 *
 *  Returns 0 if the images are equal
 *  Returns -1 if the images don't have the same dimensions
 *  Returns the number of different pixels otherwise
 */

int gray8icmp(gray8i_t *img1, gray8i_t *img2);

/*!
 *  Compares two 8-bit RGB images
 *
 *  img1 : first image
 *  img2 : second image to compare with img1
 *
 *  Returns 0 if the images are equal
 *  Returns -1 if the images don't have the same dimensions
 *  Returns the number of different pixels otherwise
 */

int rgb8icmp(rgb8i_t *img1, rgb8i_t *img2);

/*!
 *  Frees the memory of an 8-bit grayscale image
 *
 *  img : image to free
 */

void gray8ifree(gray8i_t *img);

/*!
 *  Frees the memory of an binary image
 *
 *  img : image to free
 */

void binifree(bini_t *img);

/*!
 *  Frees the memory of an 8-bit RGB image
 *
 *  img : image to free
 */

void rgb8ifree(rgb8i_t *img);

#endif /* core_h */
