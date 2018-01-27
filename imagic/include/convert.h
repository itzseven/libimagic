//
//  convert.h
//  imagic
//
//  Created by Romain on 06/01/2018.
//  Copyright © 2018 Romain Dubreucq. All rights reserved.
//

#ifndef convert_h
#define convert_h

#include "image.h"

void rgb2gray(img_t *src, img_t *dst);
void gray2rgb(img_t *src, img_t *dst);

void gray2mono(img_t *src, img_t *dst, unsigned int threshold);
void mono2gray(img_t *src, img_t *dst);

//void rgb2rgba(img_t *src, img_t *dst, float alpha);
//void rgba2rgb(img_t *src, img_t *dst);

#endif /* convert_h */
