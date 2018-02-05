//
//  labelling.h
//  imagic
//
//  Created by itzseven on 31/01/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#ifndef labelling_h
#define labelling_h

#include "image.h"

typedef struct labels_t {
    unsigned int width, height, count;
    uint32_t *data;
}labels_t;

labels_t *labels(unsigned int width, unsigned int height);
labels_t *labelscpy(const labels_t *labels);
labels_t * label(const img_t *img);
void labelsfree(labels_t *labels);

#endif /* labelling_h */
