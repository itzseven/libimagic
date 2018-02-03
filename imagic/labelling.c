//
//  labelling.c
//  imagic
//
//  Created by itzseven on 31/01/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#include "labelling.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

labels_t *labels(unsigned int width, unsigned int height) {
    labels_t *newLabels = malloc(sizeof(labels_t));
    
    newLabels->width = width;
    newLabels->height = height;
    newLabels->count = 0;
    newLabels->data = calloc(width * height, sizeof(uint32_t));
    
    return newLabels;
}

labels_t *labelscpy(const labels_t *labels) {
    labels_t *newLabels = malloc(sizeof(labels_t));
    
    newLabels->width = labels->width;
    newLabels->height = labels->height;
    newLabels->count = labels->count;
    newLabels->data = calloc(labels->width * labels->height, sizeof(uint32_t));
    memcpy(newLabels->data, labels->data, labels->width * labels->height * sizeof(uint32_t));
    
    return newLabels;
}

labels_t * label(const img_t *src)
{
    labels_t *newLabels = labels(src->width, src->height);
    
    uint32_t MAX_LABELS = ceilf(((float)(src->width - 2) / 2)) * (src->height - 2);
    
    uint32_t i = 0, j = 0, k = 0, l = 1, m = 1, n = 0, eB = 0, eA = 0, eC = 0, attA = 0, attB = 0, attC = 0;
    unsigned int *T = (unsigned int *)calloc(MAX_LABELS, sizeof(unsigned int));
    
    unsigned int TeB = 0;
    
    uint8_t attA_eq_attC = 0, attB_eq_attC = 0, eA_eq_eB = 0;
    
    uint32_t jm1_i = 0, j_im1 = 0, j_i = 0;
    
    for (k = 0; k < MAX_LABELS; k++)
        T[k] = k;
    
    for (i = 1; i < src->height; i++)
    {
        for (j = 1; j < src->width; j++)
        {
            jm1_i = ELT_IDX(src, j - 1, i, 0);
            j_im1 = ELT_IDX(src, j, i - 1, 0);
            j_i = ELT_IDX(src, j, i, 0);
            
            attA = ELT_DATA(src, uint8_t, jm1_i);
            attB = ELT_DATA(src, uint8_t, j_im1);
            attC = ELT_DATA(src, uint8_t, j_i);
            
            eA = ELT_DATA(newLabels, uint32_t, jm1_i);
            eB = ELT_DATA(newLabels, uint32_t, j_im1);
            
            TeB = T[eB];
            
            attA_eq_attC = attA == attC;
            attB_eq_attC = attB == attC;
            eA_eq_eB = eA == eB;
            
            if (attC == 0)
            {
                if (attA_eq_attC && !attB_eq_attC)
                    ELT_DATA(newLabels, uint32_t, j_i) = eA;
                
                else if (attB_eq_attC && !attA_eq_attC)
                    ELT_DATA(newLabels, uint32_t, j_i) = TeB;
                
                else if (!attB_eq_attC && !attA_eq_attC)
                    ELT_DATA(newLabels, uint32_t, j_i) = ++newLabels->count;
                
                else if (attB_eq_attC && attA_eq_attC && eA_eq_eB)
                    ELT_DATA(newLabels, uint32_t, j_i) = eA;
                
                else if (attB_eq_attC && attA_eq_attC && !eA_eq_eB)
                {
                    uint8_t TeB_leq_eA = TeB < eA;
                    ELT_DATA(newLabels, uint32_t, j_i) = (TeB_leq_eA) ? TeB : eA;
                    eC = ELT_DATA(newLabels, uint32_t, j_i);
                    T[eC] = eC;
                    T[eA] = eC;
                    T[(!TeB_leq_eA) ? TeB : eA] = eC;
                }
            }
        }
    }
    
    uint32_t Tl = 0;
    uint8_t Tl_eq_l = 0;
    
    for (l = 1; l < MAX_LABELS; l++)
    {
        Tl = T[l];
        Tl_eq_l = Tl == l;
        T[l] = Tl_eq_l ? m++ : T[Tl];
    }
    
    unsigned int maxLabel = 0;
    uint32_t lab = 0;
    
    for (i = 1; i < src->height; i++)
    {
        for (j = 1; j < src->width; j++)
        {
            n = ELT_IDX(src, j, i, 0);
            lab = ELT_DATA(newLabels, uint32_t, n);
            ELT_DATA(newLabels, uint32_t, n) = T[lab];
            lab = ELT_DATA(newLabels, uint32_t, n);
            
            if (lab > maxLabel)
                maxLabel = lab;
        }
    }
    
    newLabels->count = maxLabel;
    
    free(T);
    
    return newLabels;
}

labels_t * label2(const img_t *src)
{
    labels_t *newLabels = labels(src->width, src->height);
    
    unsigned int width = src->width, height = src->height;
    
    uint32_t MAX_LABELS = ceilf(((float)(src->width - 2) / 2)) * (src->height - 2);
    uint32_t i = 0, k = 0, l = 1, m = 1, eB = 0, eA = 0, eC = 0, attA = 0, attB = 0, attC = 0, jm1_i = 0, j_im1 = 0, j_i = 0;
    
    unsigned int *T = (unsigned int *)calloc(MAX_LABELS, sizeof(unsigned int));
    
    unsigned int TeB = 0;
    
    bool attA_eq_attC = 0, attB_eq_attC = 0, eA_eq_eB = 0;
    
    for (k = MAX_LABELS; k--; ) {
        T[k] = k;
    }
    
    uint32_t start = width + 1, end = ((width - 1) * height) - 1;
    uint8_t *imgdata = (uint8_t *)src->data;
    uint32_t *labels = (uint32_t *)newLabels->data;
    
    for (i = start; i < end; i++) {
        jm1_i = i - 1;
        j_im1 = i - width;
        j_i = i;
        
        attA = imgdata[jm1_i];
        attB = imgdata[j_im1];
        attC = imgdata[j_i];
        
        eA = labels[jm1_i];
        eB = labels[j_im1];
        
        TeB = T[eB];
        
        attA_eq_attC = attA == attC;
        attB_eq_attC = attB == attC;
        eA_eq_eB = eA == eB;
        
        if (attC == 0) {
            if (attA_eq_attC && !attB_eq_attC)
                labels[j_i] = eA;
            
            else if (attB_eq_attC && !attA_eq_attC)
                labels[j_i] = TeB;
            
            else if (!attB_eq_attC && !attA_eq_attC)
                labels[j_i] = ++newLabels->count;
            
            else if (attB_eq_attC && attA_eq_attC && eA_eq_eB)
                labels[j_i] = eA;
            
            else if (attB_eq_attC && attA_eq_attC && !eA_eq_eB)
            {
                uint8_t TeB_leq_eA = TeB < eA;
                labels[j_i] = (TeB_leq_eA) ? TeB : eA;
                eC = labels[j_i];
                T[eC] = eC;
                T[eA] = eC;
                T[(!TeB_leq_eA) ? TeB : eA] = eC;
            }
        }
    }
    
    uint32_t Tl = 0;
    bool Tl_eq_l = false;
    
    for (l = 1; l < MAX_LABELS; l++) {
        Tl = T[l];
        Tl_eq_l = Tl == l;
        T[l] = (Tl_eq_l * m++) + (!Tl_eq_l * T[Tl]);
    }
    
    unsigned int maxLabel = 0;
    uint32_t lab = 0;
    
    for (i = start; i < end; i++) {
        lab = labels[i];
        lab = labels[i] = T[lab];
        
        bool newMaxLabel = lab > maxLabel;
        maxLabel = (newMaxLabel * lab) + (!newMaxLabel * maxLabel);
    }
    
    newLabels->count = maxLabel;
    
    free(T);
    
    return newLabels;
}
