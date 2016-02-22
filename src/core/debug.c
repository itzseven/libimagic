//
//  debug.c
//  imagic
//
//  Created by itzseven on 06/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "debug.h"

gray8i_t *debug_gray8iFromSignedIntegerData(uint16_t width, uint16_t height, int *data)
{
    gray8i_t *gray8img  = gray8ialloc(width, height);
    
    unsigned int maxValue = 0, tmp = 0, i = 0, j = 0;
    unsigned int *tmpData = (unsigned int *)calloc(width * height, sizeof(unsigned int));
    
    for (i = 0; i < width * height; i++)
    {
        tmp = abs(data[i]);
        tmpData[i] = tmp;
        
        if (tmp > maxValue)
            maxValue = tmp;
    }
    
    float coeff = (float)255 / maxValue;
    
    for (j = 0; j < width * height; j++)
        gray8img->data[j] = (uint8_t)(coeff * tmpData[j]);
    
    free(tmpData);
    
    return gray8img;
}

gray8i_t *debug_gray8iFromUnsignedIntegerData(uint16_t width, uint16_t height, int *data)
{
    gray8i_t *gray8img  = gray8ialloc(width, height);
    
    unsigned int maxValue = 0, i = 0, j = 0;
    
    for (i = 0; i < width * height; i++)
        if (data[i] > maxValue)
            maxValue = data[i];
    
    float coeff = (float)255 / maxValue;
    
    for (j = 0; j < width * height; j++)
        gray8img->data[j] = (uint8_t)(coeff * data[j]);
    
    return gray8img;
}

gray8i_t *debug_gray8iFromFloatData(uint16_t width, uint16_t height, float *data)
{
    gray8i_t *gray8img  = gray8ialloc(width, height);
    
    float maxValue = 0;
    int i = 0, j = 0;
    
    for (i = 0; i < width * height; i++)
        if (data[i] > maxValue)
            maxValue = data[i];
    
    float coeff = (float)255 / (float)maxValue;
    
    for (j = 0; j < width * height; j++)
        gray8img->data[j] = (uint8_t)(coeff * data[j]);
    
    return gray8img;
}

gray8i_t *debug_labellingToGray8i(labels_t *labels, uint16_t width, uint16_t height)
{
    gray8i_t *built_image = gray8ialloc(width, height);

    float coef = (float) 255/ (float)labels->count;

    int i, j, k;

    for (i = 0; i < built_image->height; i++)
    {
        for (j = 0; j <= built_image->width; j++)
        {
            k = PXL_IDX(built_image->width, j, i);
            built_image->data[k] = (uint8_t) (labels->data[k] * coef);
        }
    }

    return built_image;
}

void debug_saveLabels(labels_t *labels, char *filename, uint16_t width, uint16_t height)
{
    FILE* outputFile;

    outputFile = fopen(filename, "w");

    if (outputFile != NULL)
    {
        int i, j;

        for (i = 0; i <= height - 1; i++)
        {
            for (j = 0; j <= width - 1; j++)
            {
                fprintf(outputFile, "%d\t", labels->data[PXL_IDX(width, j, i)]);
            }

            fprintf(outputFile, "\n");
        }
    }

    else
    {
        printf("ERROR : %s is NULL\n\n", filename);
        return;
    }
}