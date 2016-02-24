//
//  characterization.h
//  imagic
//
//  Created by itzseven on 09/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef characterization_h
#define characterization_h

#include <stdint.h>
#include <stdlib.h>

#include "labelling.h"
#include "geometry.h"

/*!
 *  Data type that represents histogram of values on range 0-255
 *
 *  count : count of datas
 *  data : datas occurrence array
 */

typedef struct _hist8 {
    uint32_t count;
    uint32_t data[256];
}hist8_t;

/*!
 *  Data type that represents the characterization of a specific region
 *
 *  id : unique identifier
 *  size : size (pixel count)
 *  sdx : standard deviation on x
 *  sdy : standard deviation on y
 *  sdxy : standard deviation on x and y
 *  mdir : main direction
 *  grayav : grayscale component average
 *  redav : red component average
 *  greenav : green component average
 *  blueav : blue component average
 *  grayhist : grayscale histogram
 *  redhist : red histogram
 *  greenhist : green histogram
 *  bluehist : blue histogram
 *  bounds : bounds (spatial limits)
 *  gravity : gravity center point
 *
 */

typedef struct _region_characterization {
    uint32_t id, size;
    float sdx, sdy, sdxy, mdir;
    uint8_t grayav, redav, greenav, blueav;
    hist8_t grayhist, redhist, greenhist, bluehist;
    rect_t bounds;
    pt2d_t gravity;
}regchar_t;

/*!
 *  Data type that represents a set of regions for an image
 *
 *  count : count of regions
 *  data : region array
 */

typedef struct _charact {
    uint32_t count;
    regchar_t **data;
}charact_t;

/*!
 *  Returns an initialized charact_t object with initialized regions with datas set to 0
 *
 *  count : region count
 *
 */

charact_t *charactalloc(uint32_t count);

/*!
 *  Returns a charact_t object containing the regions with their characteristics.
 *
 *  The function will extract the characteristics according to the value of the parameters :
 *  -  if rgbi is not NULL, the RGB characteristics will be extracted
 *  -  otherwise, only the grayscale characteristics will
 *
 *  rgbi : RGB 8-bit image
 *  grayi : grayscale image
 *  labels : labelling of the image
 *
 */

charact_t *characterize(rgb8i_t *rgbi, gray8i_t *grayi, labels_t *labels);

/*!
 *  Frees the memory of a charact_t object
 *
 *  charact_t : characterization to free
 */

void charactfree(charact_t *charact);

#endif /* characterization_h */
