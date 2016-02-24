//
//  morpho.h
//  imagic
//
//  Created by itzseven on 23/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef morpho_h
#define morpho_h

#include <stdio.h>
#include <math.h>
#include "core.h"

bini_t *distension(bini_t *src, uint16_t shift);
bini_t *erosion(bini_t *src, uint16_t shift);
bini_t *opening(bini_t *src, uint16_t shift);
bini_t *closing(bini_t *src, uint16_t shift);


#endif /* morpho_h */
