//
//  io.h
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef io_h
#define io_h

#include <stdio.h>

#include "core.h"

/*!
 *  Export file data format for PGM
 */

typedef enum {
    PGM_ASCII,
    PGM_BINARY
} pgmfmt;

/*!
 *  Export file data format for PPM
 */

typedef enum {
    PPM_ASCII,
    PPM_BINARY
} ppmfmt;

/*!
 *  Export file data format for PBM
 */

typedef enum {
    PBM_ASCII,
    PBM_BINARY
} pbmfmt;

/*!
 *  Returns an initialized gray8i_t image loaded from the file path passed in parameter (PGM file) or NULL if the file couldn't be opened.
 */

gray8i_t *pgmopen(const char *filename);

/*!
 *  Write gray8i_t image data to the destination passed in parameter as a PGM file (according to the data format passed in parameter)
 */

void pgmwrite(gray8i_t *img, const char *filename, pgmfmt fmt);

/*!
 *  Returns an initialized rgb8i_t image loaded from the file path passed in parameter (PPM file)
 *  or NULL if the file couldn't be opened.
 */

rgb8i_t *ppmopen(const char *filename);

/*!
 *  Write rgb8i_t image data to the destination passed in parameter as a PPM file (according to the data format passed in parameter)
 */

void ppmwrite(rgb8i_t *img, const char *filename, ppmfmt fmt);

/*!
 *  Returns an initialized bini_t image loaded from the file path passed in parameter (PBM file)
 *  or NULL if the file couldn't be opened.
 */

bini_t *pbmopen(const char *filename);

/*!
 *  Write bini_t image data to the destination passed in parameter as a PBM file (according to the data format passed in parameter)
 */

void pbmwrite(bini_t *img, const char *filename, pbmfmt fmt);

#endif /* io_h */
