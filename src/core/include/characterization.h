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

typedef struct _gray8hist {
    uint32_t count;
    uint32_t data[256];
}gray8hist_t;

typedef struct _region_characterization {
    uint32_t id, size;
    float sdx, sdy, sdxy, mdir;
    uint8_t grayav, redav, greenav, blueav;
    gray8hist_t grayhist, redhist, greenhist, bluehist;
    rect_t bounds;
    pt2d_t gravity;
}regchar_t;

typedef struct _charact {
    uint32_t count;
    regchar_t **data;
}charact_t;

charact_t *charactalloc(uint32_t count);

charact_t *characterize(rgb8i_t *rgbi, gray8i_t *grayi, labels_t *labels);

int32_t overlappingreg(regchar_t *ref, labels_t *reflabels, labels_t *labels, uint16_t width);

#endif /* characterization_h */
