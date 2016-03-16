//
//  filter.h
//  imagic
//
//  Created by itzseven on 24/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef filter_h
#define filter_h

#include "core.h"

#define LP_FLT(img, j, i) (PXL(img, j-1, i-1) + PXL(img, j, i-1) + PXL(img, j+1, i-1) + PXL(img, j-1, i) + PXL(img, j, i) + PXL(img, j+1, i) + PXL(img, j-1, i+1) + PXL(img, j, i+1) + PXL(img, j+1, i+1))

#define HP_FLT(img, j, i) (2 * PXL(img, j, i) - (0.25 * (PXL(img, j, i-1) + PXL(img, j-1, i) + PXL(img, j+1, i) + PXL(img, j, i+1))))

gray8i_t *lowpassflt(gray8i_t *src);
gray8i_t *highpassflt(gray8i_t *src);

#endif /* filter_h */
