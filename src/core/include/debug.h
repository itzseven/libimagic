//
//  debug.h
//  imagic
//
//  Created by Romain Dubreucq on 06/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#ifndef debug_h
#define debug_h

#include <stdio.h>

#include "core.h"
#include "labelling.h"

gray8i_t *debug_gray8iFromSignedIntegerData(uint16_t width, uint16_t height, int *data);
gray8i_t *debug_gray8iFromUnsignedIntegerData(uint16_t width, uint16_t height, int *data);
gray8i_t *debug_gray8iFromFloatData(uint16_t width, uint16_t height, float *data);

gray8i_t *debug_labellingToGray8i(labels_t *labels, uint16_t width, uint16_t height);

void debug_saveLabels(labels_t *labels, char *filename, uint16_t width, uint16_t height);


#endif /* debug_h */
