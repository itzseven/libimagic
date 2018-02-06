//
//  convert.h
//  imagic
//
//  Created by itzseven on 06/01/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#ifndef convert_h
#define convert_h

#include "image.h"

void rgb2gray(img_t *src, img_t *dst);
void gray2rgb(img_t *src, img_t *dst);

void gray2mono(img_t *src, img_t *dst, unsigned int threshold);
void mono2gray(img_t *src, img_t *dst);

void rgb2rgba(img_t *src, img_t *dst, float alpha); // 0 <= alpha <= 1.0
void rgba2rgb(img_t *src, img_t *dst);

void rgb2argb(img_t *src, img_t *dst, float alpha); // 0 <= alpha <= 1.0
void argb2rgb(img_t *src, img_t *dst);

#endif /* convert_h */
