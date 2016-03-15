//
//  io.c
//  imagic
//
//  Created by itzseven on 02/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#include "io.h"

gray8i_t *pgmopen(const char *filename)
{
    gray8i_t *img = NULL;
    FILE *file;
    
    if ((file = fopen(filename, "r")))
    {
        char headbuf[128];
        pgmfmt ifmt;
        uint16_t width = 0, height = 0;
        uint32_t length = 0;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        if ((strcmp(headbuf, "P2\n") == 0))
            ifmt = PGM_ASCII;
        
        else if ((strcmp(headbuf, "P5\n") == 0))
            ifmt = PGM_BINARY;
        
        else
            return NULL;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        while (headbuf[0] == '#')
            fgets(headbuf, sizeof(headbuf), file);
        
        char *sizetoken;
        
        sizetoken = strtok(headbuf, " ");
        width = (uint16_t)atoi(sizetoken);
        sizetoken = strtok(NULL, " ");
        height = (uint16_t)atoi(sizetoken);
        
        length = width * height;
        
        img = gray8ialloc(width, height);
        
        fgets(headbuf, sizeof(headbuf), file);
        
        uint32_t i = 0;
        
        if (ifmt == PGM_ASCII)
        {
            unsigned int val;
            while((fscanf(file, "%u", &val) > 0))
            {
                img->data[i] = (uint8_t)val;
                i += (i < length);
            }
            
        }
        
        else
        {
            fread(img->data, sizeof(uint8_t), length, file);
        }
        
        fclose(file);
    }
    
    return img;
}

void pgmwrite(gray8i_t *img, const char *filename, pgmfmt fmt)
{
    FILE *file;
    
    if ((file = fopen(filename, "w")))
    {
        fputs((fmt == PGM_ASCII) ? "P2\n" : "P5\n", file);
        fprintf(file, "# Generated with imagic 1.0 alpha\n");
        fprintf(file, "%u %u\n", img->width, img->height);
        fputs("255\n", file);
        
        if (fmt == PGM_ASCII)
        {
            unsigned int i = 0;
            for (i = 0; i < img->width * img->height; i++)
                fprintf(file, "%d\n", img->data[i]);
        }
        
        else
        {
            fwrite(img->data, sizeof(uint8_t), img->width * img->height, file);
        }
        
        fclose(file);
    }
}

rgb8i_t *ppmopen(const char *filename)
{
    rgb8i_t *img = NULL;
    FILE *file;
    
    if ((file = fopen(filename, "r")))
    {
        char headbuf[128];
        ppmfmt ifmt;
        uint16_t width = 0, height = 0;
        uint32_t length = 0;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        if ((strcmp(headbuf, "P3\n") == 0))
            ifmt = PPM_ASCII;
        
        else if ((strcmp(headbuf, "P6\n") == 0))
            ifmt = PPM_BINARY;
        
        else
            return NULL;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        while (headbuf[0] == '#')
            fgets(headbuf, sizeof(headbuf), file);
        
        char *sizetoken;
        
        sizetoken = strtok(headbuf, " ");
        width = (uint16_t)atoi(sizetoken);
        sizetoken = strtok(NULL, " ");
        height = (uint16_t)atoi(sizetoken);
        
        length = width * height;
        
        img = rgb8ialloc(width, height);
        
        fgets(headbuf, sizeof(headbuf), file);
        
        if (ifmt == PPM_ASCII)
        {
            unsigned int r, g, b, i = 0;
            
            while((fscanf(file, "%u\n%u\n%u", &r, &g, &b) > 0))
            {
                img->data[i].r = r;
                img->data[i].g = g;
                img->data[i].b = b;
                i += i < length;
            }
        }
        
        else
        {
            fread(img->data, sizeof(rgb8), length, file);
        }
        
        fclose(file);
    }
    
    return img;
}

void ppmwrite(rgb8i_t *img, const char *filename, ppmfmt fmt)
{
    FILE *file;
    
    if ((file = fopen(filename, "w")))
    {
        fputs((fmt == PPM_ASCII) ? "P3\n" : "P6\n", file);
        fprintf(file, "# Generated with imagic 1.0 alpha\n");
        fprintf(file, "%u %u\n", img->width, img->height);
        fputs("255\n", file);
        
        if (fmt == PPM_ASCII)
        {
            unsigned int i = 0;
            for (i = 0; i < img->width * img->height; i++)
                fprintf(file, "%u\n%u\n%u\n", img->data[i].r, img->data[i].g, img->data[i].b);
        }
        
        else
        {
            fwrite(img->data, sizeof(rgb8), img->width * img->height, file);
        }
        
        fclose(file);
    }
}

bini_t *pbmopen(const char *filename)
{
    bini_t *img = NULL;
    FILE *file;
    
    if ((file = fopen(filename, "r")))
    {
        char headbuf[128];
        pbmfmt ifmt;
        uint16_t width = 0, height = 0, length = 0;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        if ((strcmp(headbuf, "P1\n") == 0))
            ifmt = PBM_ASCII;
        
        else if ((strcmp(headbuf, "P4\n") == 0))
            ifmt = PBM_BINARY;
        
        else
            return NULL;
        
        fgets(headbuf, sizeof(headbuf), file);
        
        if (headbuf[0] == '#')
            fgets(headbuf, sizeof(headbuf), file);
        
        char *sizetoken;
        
        sizetoken = strtok(headbuf, " ");
        width = (uint16_t)atoi(sizetoken);
        sizetoken = strtok(NULL, " ");
        height = (uint16_t)atoi(sizetoken);
        
        length = width * height;
        
        img = binialloc(width, height);
        
        unsigned int i = 0;
        
        if (ifmt == PBM_ASCII)
        {
            char databuf[length];
            
            fgets(databuf, (int)sizeof(databuf) + 1, file);
            
            for (i = 0; i < length; i += i < length)
                img->data[i] = databuf[i] - '0';
        }
        
        else
        {
            int ss = (width * height + 7) / 8;
            
            //uint8_t space = 0;
            
            char databuf[ss];
            
            //fread(&space, 1, 1, file);
            printf("BINARYYYYYYY : %d\n", ss);
            fread(databuf, sizeof(char), ss, file);
            
//            for (i = 0; i < (length / 8) + (length % 8); i += i < length)
//                printf("%d\n", img->data[i] - '0');
            
            int j = 0, k = 0;;
            
            for (i = 0; i < ss; i++)
            {
                printf("%d\n", databuf[i] - '0');
                for (j = 7; j >= 0; j--)
                {
                    k++;
                    printf("%d", !!((databuf[i] - '0') & (1 << (j))));
                }
                
                puts("\n");
            }
            
            printf("\nk = %d\n", k);
        }
        
        fclose(file);
    }
    
    return img;
}

void pbmwrite(bini_t *img, const char *filename, pbmfmt fmt)
{
    FILE *file;
    
    if ((file = fopen(filename, "w")))
    {
        fputs((fmt == PBM_ASCII) ? "P1\n" : "P4\n", file);
        fprintf(file, "# Generated with imagic 1.0 alpha\n");
        fprintf(file, "%u %u\n", img->width, img->height);
        fputs("255\n", file);
        
        if (fmt == PGM_ASCII)
        {
            unsigned int i = 0;
            for (i = 0; i < img->width * img->height; i++)
                fprintf(file, "%d\n", img->data[i]);
        }
        
        else
        {
            fwrite(img->data, sizeof(uint8_t), img->width * img->height, file);
        }
        
        fclose(file);
    }
}