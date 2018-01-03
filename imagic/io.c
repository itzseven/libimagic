//
//  io.c
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "io.h"
#include "image.h"
#include "_image.h"
#include "pnm.h"
#include "tools.h"
#include <string.h>
#include <stdio.h>

img_t *pnmopen(const char *filename) {
    const char *filextension = fexts(filename);
    
    if (!is_pnm_format(filextension)) {
        puts("pnmopen: unrecognized file extension\n");
        return NULL;
    }
    
    img_t *loadedImage;
    
    void *data = NULL;
    unsigned int width = 0, height = 0, depth = 0;
    size_t dsize = 0;
    pnm_format_t format;
    
    _pnmopen(filename, &data, &width, &height, &depth, &dsize, &format);
    
    if (data == NULL || !width || !height || !depth) {
        return NULL;
    }
    
    loadedImage = img(width, height, depth, dsize);
    memcpy(loadedImage->data, data, width * height * depth * dsize);
    
    return loadedImage;
}

void pnmwrite(const char *filename, const img_t *img, pnmw_opt_t opt) {
    const char *filextension = fexts(filename);
    
    if (!is_pnm_format(filextension)) {
        puts("pnmwrite: unrecognized file extension\n");
        return;
    }
    
    pnm_format_t format = pnm_format_for_ext(filextension, opt);
    
    if (!format) {
        return;
    }
    
    // should create a single function to handle max value
    unsigned int max_sizes[3] = {UINT8_MAX, UINT16_MAX, UINT32_MAX};
    unsigned int max = opt & PNM_MAXVALUE ? imgmax(img) : format & 0x02 ? 1 : max_sizes[img->dsize >> 1];
    
    _pnmwrite(filename, img->data, img->width, img->height, img->depth, img->dsize, max, format);
}
