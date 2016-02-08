//
//  labelling.h
//  imagic
//
//  Created by Romain Dubreucq on 07/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#ifndef labelling_h
#define labelling_h

#include <stdlib.h>

#include "core.h"

typedef struct _labels {
    uint32_t len, count;
    uint32_t *data;
}labels_t;

labels_t *laballoc(uint16_t width, uint16_t height);

labels_t *label(bini_t *src);

void labfree(labels_t *labels);

#endif /* labelling_h */
