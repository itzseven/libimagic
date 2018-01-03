//
//  pnm.h
//  imagic
//
//  Created by itzseven on 23/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#ifndef pnm_h
#define pnm_h

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    PNM_UNDEFINED = 0x00,
    PBM_PLAIN = 0x02,
    PBM_RAW = 0x03,
    PGM_PLAIN = 0x04,
    PGM_RAW = 0x05,
    PPM_PLAIN = 0x08,
    PPM_RAW = 0x09
}pnm_format_t;

void _pnmopen(const char *filename, void **data, unsigned int *width, unsigned int *height, unsigned int *depth, size_t *dsize, pnm_format_t *format);
void _pnmwrite(const char *filename, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, unsigned int max, pnm_format_t format);

bool is_pnm_format(const char *filextension);
pnm_format_t pnm_format_for_ext(const char *filextension, int opt);

#endif /* pnm_h */
