//
//  labelling.h
//  imagic
//
//  Created by itzseven on 07/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef labelling_h
#define labelling_h

#include <stdlib.h>
#include <math.h>

#include "core.h"

/*!
 *  Data type that represents a matrix of labels
 *
 *  len : length of the data array
 *  count : count of labels
 *  data : label array
 */

typedef struct _labels {
    uint16_t width, height;
    uint32_t len, count;
    uint32_t *data;
}labels_t;

/*!
 *  Returns an initialized labels_t object with allocated data set to 0 and len equal to width * height
 *
 *  width : width of the image
 *  height : height of the image
 */

labels_t *laballoc(uint16_t width, uint16_t height);

/*!
 *  Returns a copy of the labels_t object passed in parameter
 *
 *  src : source labels to copy
 *
 */

labels_t *labcpy(labels_t *src);

/*!
 *  Returns a labels_t object, containing all the labels calculated from the source image
 *
 *  src : source image
 */

labels_t *label(bini_t *src);

/*!
 *  Frees the memory of a labels_t object
 *
 *  labels : labels to free
 */

void labfree(labels_t *labels);

#endif /* labelling_h */
