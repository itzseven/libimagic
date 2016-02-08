//
//  labelling.c
//  imagic
//
//  Created by Romain Dubreucq on 07/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "labelling.h"

labels_t *laballoc(uint16_t width, uint16_t height)
{
    labels_t *labels = (labels_t *)malloc(sizeof(labels_t));
    labels->len = width * height;
    labels->count = 0;
    labels->data = (uint32_t *)calloc(width * height, sizeof(uint32_t));
    
    return labels;
}



labels_t *label(bini_t *src)
{
    labels_t *labels = laballoc(src->width, src->height);
    
    uint16_t width = src->width;
    uint32_t i = 0, j = 0, k = 0, eB = 0, eA = 0, eC = 0, pixcount = src->width * src->height, attA, attB, attC;
    unsigned int *T = (unsigned int *)calloc(src->width * src->height, sizeof(unsigned int));
    
    unsigned int TeB = 0;
    
    uint8_t wpix = 0, attA_eq_attB = 0, attA_eq_attC = 0, attB_eq_attC = 0, eA_eq_eB = 0;
    
    uint32_t jm1_i = 0, j_im1 = 0, j_i = 0;
    
    for (k = 0; k < pixcount; k++)
        T[k] = k;
    
    for (i = 1; i < src->height; i++)
    {
        for (j = 1; j < src->width; j++)
        {
            jm1_i = PXL_IDX(width, j - 1, i);
            j_im1 = PXL_IDX(width, j, i - 1);
            j_i = PXL_IDX(width, j, i);
            
            attA = src->data[jm1_i];
            attB = src->data[j_im1];
            attC = src->data[j_i];
            
            eA = labels->data[jm1_i];
            eB = labels->data[j_im1];
            eC = labels->data[j_i];
            
            //TeB = T[eB];
            
            wpix = attC == 0;
            attA_eq_attB = attA == attB;
            attA_eq_attC = attA == attC;
            attB_eq_attC = attB == attC;
            eA_eq_eB = eA == eB;
            
            // should optimize this as well..
            
            // rewrite all the code (take a look to the document on image processing (ghiles cours)))
        }
    }
    
    // not optimized
    
    // rewrite all the code..
    
    free(T);
    
    return labels;
}

void labfree(labels_t *labels)
{
    free(labels->data);
    free(labels);
}