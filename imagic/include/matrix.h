//
//  matrix.h
//  imagic
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <stdlib.h>

#define ELT_IDX(width, x, y) (((y) * width) + (x))
#define ELT(mat, x, y) mat->data[PXL_IDX(mat->width, x, y)]

#pragma
#pragma mark - Matrix datatype

typedef struct mat_t {
    unsigned int width, height;
    size_t dsize;
    void *data;
}mat_t;

#pragma
#pragma mark - Allocation copy deallocation

void *mat(unsigned int width, unsigned int height, size_t dsize);
mat_t *matcpy(mat_t *mat);
void matdcpy(mat_t *mat, const void *data);
void matfree(mat_t *mat);

#endif /* matrix_h */
