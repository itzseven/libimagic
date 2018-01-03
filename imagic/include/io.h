//
//  io.h
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2017 itzseven. All rights reserved.
//

#ifndef io_h
#define io_h

#include "image.h"

#pragma
#pragma mark - PNM

typedef enum {
    PNM_NO_OPT = 0,
    PNM_PLAIN = 1 << 1, // exports in ASCII format for PNM
    PNM_MAXVALUE = 1 << 2 // calculate max value for PNM format
}pnmw_opt_t;

img_t *pnmopen(const char *filename);
void pnmwrite(const char *filename, const img_t *img, pnmw_opt_t opt);

#endif /* io_h */
