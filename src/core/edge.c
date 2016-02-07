//
//  edge.c
//  imagic
//
//  Created by itzseven on 03/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "edge.h"

//debug
#include <stdio.h>

grad_t *gradalloc(uint16_t width, uint16_t height)
{
    grad_t *g = (grad_t *)malloc(sizeof(grad_t));
    
    g->len = width * height;
    g->hor = (int *)calloc(g->len, sizeof(int));
    g->ver = (int *)calloc(g->len, sizeof(int));
    g->mag = (float *)calloc(g->len, sizeof(float));
    
    return g;
}

grad_t *grdsobel(gray8i_t *src)
{
    uint16_t width = src->width, height = src->height;
    
    grad_t *gsob = gradalloc(width, height);
    
    unsigned int i = 0, j = 0;
    
    uint8_t jm1_im1 = 0, j_im1 = 0, jp1_im1 = 0, jm1_i = 0, jp1_i = 0, jm1_ip1 = 0, j_ip1 = 0, jp1_ip1 = 0;
    
    int gradX = 0, gradY = 0;
    
    for (i = 1; i < height - 1; i++)
    {
        for (j = 1; j < width - 1; j++)
        {
            jm1_im1 = src->data[PXL_IDX(width, j-1, i-1)];
            j_im1 = src->data[PXL_IDX(width, j, i-1)];
            jp1_im1 = src->data[PXL_IDX(width, j+1, i-1)];
            jm1_i = src->data[PXL_IDX(width, j-1, i)];
            
            jp1_i = src->data[PXL_IDX(width, j+1, i)];
            jm1_ip1 = src->data[PXL_IDX(width, j-1, i+1)];
            j_ip1 = src->data[PXL_IDX(width, j, i+1)];
            jp1_ip1 = src->data[PXL_IDX(width, j+1, i+1)];
            
            gradX = H_SOBEL(jp1_im1, jp1_ip1, jp1_i, jm1_im1, jm1_ip1, jm1_i);
            gradY = V_SOBEL(jm1_ip1, jp1_ip1, j_ip1, jm1_im1, jp1_im1, j_im1);
            
            gsob->hor[PXL_IDX(width, j, i)] = gradX;
            gsob->ver[PXL_IDX(width, j, i)] = gradY;
            
            gsob->mag[PXL_IDX(width, j, i)] = sqrtf(powf(gradX, 2.0) + powf(gradY, 2.0));
        }
    }
    
    return gsob;
}

grad_t *grdprewitt(gray8i_t *src)
{
    uint16_t width = src->width, height = src->height;
    
    grad_t *gpre = gradalloc(width, height);
    
    unsigned int i = 0, j = 0;
    
    uint8_t jm1_im1 = 0, j_im1 = 0, jp1_im1 = 0, jm1_i = 0, jp1_i = 0, jm1_ip1 = 0, j_ip1 = 0, jp1_ip1 = 0;
    
    int gradX = 0, gradY = 0;
    
    for (i = 1; i < height - 1; i++)
    {
        for (j = 1; j < width - 1; j++)
        {
            jm1_im1 = src->data[PXL_IDX(width, j-1, i-1)];
            j_im1 = src->data[PXL_IDX(width, j, i-1)];
            jp1_im1 = src->data[PXL_IDX(width, j+1, i-1)];
            jm1_i = src->data[PXL_IDX(width, j-1, i)];
            
            jp1_i = src->data[PXL_IDX(width, j+1, i)];
            jm1_ip1 = src->data[PXL_IDX(width, j-1, i+1)];
            j_ip1 = src->data[PXL_IDX(width, j, i+1)];
            jp1_ip1 = src->data[PXL_IDX(width, j+1, i+1)];
            
            gradX = H_PREWITT(jp1_im1, jp1_ip1, jp1_i, jm1_im1, jm1_ip1, jm1_i);
            gradY = V_PREWITT(jm1_ip1, jp1_ip1, j_ip1, jm1_im1, jp1_im1, j_im1);
            
            gpre->hor[PXL_IDX(width, j, i)] = gradX;
            gpre->ver[PXL_IDX(width, j, i)] = gradY;
            
            gpre->mag[PXL_IDX(width, j, i)] = sqrtf(powf(gradX, 2.0) + powf(gradY, 2.0));
        }
    }
    
    return gpre;
}

grad_t *grdderiv(gray8i_t *src)
{
    uint16_t width = src->width, height = src->height;
    
    grad_t *gder = gradalloc(width, height);
    
    unsigned int i = 0, j = 0;
    
    uint8_t p = 0;
    
    int gradX = 0, gradY = 0;
    
    for (i = 1; i < height - 1; i++)
    {
        for (j = 1; j < width - 1; j++)
        {
            p = src->data[PXL_IDX(width, j, i)];
            
            gradX = p - src->data[PXL_IDX(width, j-1, i)];
            gradY = p - src->data[PXL_IDX(width, j, i-1)];
            
            gder->hor[PXL_IDX(width, j, i)] = gradX;
            gder->ver[PXL_IDX(width, j, i)] = gradY;
            
            gder->mag[PXL_IDX(width, j, i)] = sqrtf(powf(gradX, 2.0) + powf(gradY, 2.0));
        }
    }
    
    return gder;
}

void gradfree(grad_t *grad)
{
    free(grad->hor);
    free(grad->ver);
    free(grad->mag);
    free(grad);
}