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

#define ELT_DATA(mat, dtype, index) ((dtype *)mat->data)[index]
#define ELT_IDX(mat, x, y, d) (((y) * mat->width) + (x) + d)
#define ELT(mat, dtype, x, y, d) ELT_DATA(mat, dtype, ELT_IDX(mat, x, y, d))

#pragma
#pragma mark - Matrix datatype

typedef struct mat_t {
    unsigned int width, height, depth;
    size_t dsize;
    void *data;
}mat_t;

#pragma
#pragma mark - Allocation copy deallocation

void *mat(unsigned int width, unsigned int height, unsigned int depth, size_t dsize);
mat_t *matcpy(const mat_t *mat);
void matdcpy(const mat_t *mat, const void *data);
void matfree(mat_t *mat);

#endif /* matrix_h */
