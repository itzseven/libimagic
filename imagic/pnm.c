//
//  pnm.c
//  imagic
//
//  Created by itzseven on 23/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "pnm.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define BUFFER_SIZE 1024

#define PBM_FILE_EXTENSION "pbm"
#define PGM_FILE_EXTENSION "pgm"
#define PPM_FILE_EXTENSION "ppm"

#define PBM_PLAIN_MAGIC "P1"
#define PGM_PLAIN_MAGIC "P2"
#define PPM_PLAIN_MAGIC "P3"
#define PBM_RAW_MAGIC "P4"
#define PGM_RAW_MAGIC "P5"
#define PPM_RAW_MAGIC "P6"

#define PBM_LIMIT_STEP 3
#define PGM_LIMIT_STEP 4
#define PPM_LIMIT_STEP 4

#pragma mark - Helpers

bool is_pnm_format(const char *filextension) {
    return !strcmp(filextension, PBM_FILE_EXTENSION) || !strcmp(filextension, PGM_FILE_EXTENSION) || !strcmp(filextension, PPM_FILE_EXTENSION);
}

pnm_format_t pnm_format_for_ext(const char *filextension, int opt) {
    if (!strcmp(filextension, PBM_FILE_EXTENSION)) {
        return opt ? PBM_PLAIN : PBM_RAW;
    } else if (!strcmp(filextension, PGM_FILE_EXTENSION)) {
        return opt ? PGM_PLAIN : PGM_RAW;
    } else if (!strcmp(filextension, PPM_FILE_EXTENSION)) {
        return opt ? PPM_PLAIN : PPM_RAW;
    }
    
    return PNM_UNDEFINED;
}

bool is_raw_format(pnm_format_t format) {
    return format & 0x01; // first bit of format defines whether it's raw (1) or plain (0)
}

bool is_valid_line(const char *line) {
    unsigned int i = 0, is_invalid = 0;
    for (i = 0; i < strlen(line); i++) {
        char c = line[i];
        if (isgraph(c) && !is_invalid) {
            if (c == '#') {
                is_invalid = 1;
                break;
            }
        }
    }
    
    return is_invalid == 0;
}

const char *pnm_magic_number(pnm_format_t format) {
    switch (format) {
        case PBM_PLAIN:
            return PBM_PLAIN_MAGIC;
        break;
            
        case PBM_RAW:
            return PBM_RAW_MAGIC;
            break;
            
        case PGM_PLAIN:
            return PGM_PLAIN_MAGIC;
            break;
            
        case PGM_RAW:
            return PGM_RAW_MAGIC;
            break;
            
        case PPM_PLAIN:
            return PPM_PLAIN_MAGIC;
            break;
            
        case PPM_RAW:
            return PPM_RAW_MAGIC;
        break;
            
        default:
            return NULL;
        break;
    }
    
    return NULL;
}

#pragma mark - Read data

#warning Only binary format differs, io should use the same code to load plain format for PBM/PGM and PPM

/*
 * http://netpbm.sourceforge.net/doc/pbm.html
 */

void pbmdread(FILE *file, void **data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    size_t len = width * height * depth;
    unsigned char buffer[len];
    unsigned int i = 0;
    
    if (raw) {
        unsigned int k;
        unsigned char c;
        while(!feof(file)) {
            c = fgetc(file);
            for (k = 0; k <= 7; k++) {
                buffer[i++] = (c >> (7 - k)) & 1;
                
                if ((i % width) == 0) {
                    break;
                }
            }
        }
    } else {
        unsigned int c;
        while(fscanf(file ,"%u", &c) > 0) {
            buffer[i++] = c;
        }
    }
    
    memcpy(*data, buffer, len * dsize);
}

/*
 * http://netpbm.sourceforge.net/doc/pgm.html
 */

void pgmdread(FILE *file, void **data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    size_t len = width * height * depth;
    uint8_t buffer[len];
    unsigned int i = 0;
    
    if (raw) {
        if (fread(buffer, dsize, len, file) != len) {
            puts("Error when trying to read raw data for pgm\n");
            return;
        }
    } else {
        unsigned int c;
        while(fscanf(file ,"%u", &c) > 0) {
            buffer[i++] = c;
        }
    }
    
    memcpy(*data, buffer, len * dsize);
}

/*
 * http://netpbm.sourceforge.net/doc/ppm.html
 */

void ppmdread(FILE *file, void **data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    size_t len = width * height * depth;
    uint8_t buffer[len];
    unsigned int i = 0;
    
    if (raw) {
        if (fread(buffer, dsize, len, file) != len) {
            puts("Error when trying to read raw data for ppm\n");
            return;
        }
    } else {
        unsigned int c;
        while(fscanf(file ,"%u", &c) > 0) {
            buffer[i++] = c;
        }
    }
    
    memcpy(*data, buffer, len * dsize);
}

#pragma mark - Read PNM header

int read_pnm_all(const char *line, pnm_format_t *format, unsigned int *width, unsigned int *height, unsigned int *max) {
    char magicNumber[3];
    int read = sscanf(line, "%s %d %d %d", magicNumber, width, height, max);
    
    if (isnumber(magicNumber[1])) {
        pnm_format_t formats[7] = {PNM_UNDEFINED, PBM_PLAIN, PGM_PLAIN, PPM_PLAIN, PBM_RAW, PGM_RAW, PPM_RAW};
        char pnmFormat[2] = {magicNumber[1], '\0'};
        *format = formats[strtol(pnmFormat, NULL, 10)];
    } else {
        *format = PNM_UNDEFINED;
    }
    
    return read;
}

int read_pnm_size_max(const char *line, pnm_format_t *format, unsigned int *width, unsigned int *height, unsigned int *max) {
    return sscanf(line, "%d %d %d", width, height, max);
}

int read_pnm_height_max(const char *line, pnm_format_t *format, unsigned int *width, unsigned int *height, unsigned int *max) {
    return sscanf(line, "%d %d", height, max);
}

int read_pnm_max(const char *line, pnm_format_t *format, unsigned int *width, unsigned int *height, unsigned int *max) {
    return sscanf(line, "%d", max);
}

void pnmhread(FILE *file, unsigned int *width, unsigned int *height, unsigned int *max, pnm_format_t *format) {
    unsigned int _width = 0, _height = 0, _max = 0, step = 0;
    pnm_format_t _format = PNM_UNDEFINED;
    
    char line[BUFFER_SIZE];
    
    while (fgets(line, BUFFER_SIZE, file) != NULL) {
        if (!is_valid_line(line)) {
            continue;
        }
        
        //unsigned int * adresses[4] = {&_format, &_width, &_height, &_max};
        int (*_pnmreadheadervalue[4]) (const char *line, pnm_format_t *format, unsigned int *width, unsigned int *height, unsigned int *max) = {read_pnm_all, read_pnm_size_max, read_pnm_height_max, read_pnm_max};
        step += _pnmreadheadervalue[step](line, &_format, &_width, &_height, &_max);
        
        unsigned int maxsteps[3] = {PBM_LIMIT_STEP, PGM_LIMIT_STEP, PPM_LIMIT_STEP};
        
        if (step == maxsteps[_format >> 2]) {
            break;
        }
    }
    
    *width = _width;
    *height = _height;
    *max = _max;
    *format = _format;
}

#pragma mark - Write data

void pbmdwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    if (raw) {
        unsigned int i = 0, j = 0, k = 0, l = 0;
        int byteVal = 0;
        
        uint8_t byteArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                byteArray[k++] = ((uint8_t *)data)[(i * width) + j];
                
                if (((k % 8) == 0) || (j == (width - 1))) {
                    for (l = 8; l-- ; ) {
                        int index = 7 - l;
                        byteVal |= byteArray[index] << l;
                        byteArray[index] = 0;
                    }
                    
                    fprintf(file, "%c", byteVal);
                    byteVal = 0;
                    k = 0;
                }
            }
        }
    } else {
        unsigned int i = 0;
        size_t len = width * height * depth;
        
        for (i = 0; i < len; i++) {
            if (((i + 1) % width) == 0) {
                fprintf(file, "%u\n", ((uint8_t *)data)[i]);
                continue;
            }
            
            fprintf(file, "%u ", ((uint8_t *)data)[i]);
        }
    }
}

void _pgm8dwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) {
    size_t len = width * height * depth;
    unsigned int i = 0;
    
    for (i = 0; i < len; i++) {
        if (((i + 1) % width) == 0) {
            fprintf(file, "%u\n", ((uint8_t *)data)[i]);
            continue;
        }
        
        fprintf(file, "%u ", ((uint8_t *)data)[i]);
    }
}

void _pgm16dwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) {
    size_t len = width * height * depth;
    unsigned int i = 0;
    
    for (i = 0; i < len; i++) {
        if (((i + 1) % width) == 0) {
            fprintf(file, "%u\n", ((uint16_t *)data)[i]);
            continue;
        }
        
        fprintf(file, "%u ", ((uint16_t *)data)[i]);
    }
}

void pgmdwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    size_t len = width * height * depth;
    
    if (raw) {
        if (fwrite(data, dsize, len, file) != len) {
            puts("Error when trying to write raw data to pgm\n");
            return;
        }
    } else {
        void (*_pgmdwrite[2]) (FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) = {_pgm8dwrite, _pgm16dwrite};
        _pgmdwrite[dsize >> 1](file, &(*data), width, height, depth, dsize);
    }
}

void _ppm8dwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) {
    size_t len = width * height * depth;
    unsigned int i = 0, j = 0;
    
    for (i = 0; i < len; i += 3) {
        j++;
        if ((j % width) == 0) {
            fprintf(file, "%u %u %u\n", ((uint8_t *)data)[i], ((uint8_t *)data)[i + 1], ((uint8_t *)data)[i + 2]);
            continue;
        }
        
        fprintf(file, "%u %u %u ", ((uint8_t *)data)[i], ((uint8_t *)data)[i + 1], ((uint8_t *)data)[i + 2]);
    }
}

void _ppm16dwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) {
    size_t len = width * height * depth;
    unsigned int i = 0, j = 0;
    
    for (i = 0; i < len; i += 3) {
        j++;
        if ((j % width) == 0) {
            fprintf(file, "%u %u %u\n", ((uint16_t *)data)[i], ((uint16_t *)data)[i + 1], ((uint16_t *)data)[i + 2]);
            continue;
        }
        
        fprintf(file, "%u %u %u ", ((uint16_t *)data)[i], ((uint16_t *)data)[i + 1], ((uint16_t *)data)[i + 2]);
    }
}

void ppmdwrite(FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) {
    size_t len = width * height * depth;
    
    if (raw) {
        if (fwrite(data, dsize, len, file) != len) {
            puts("Error when trying to write raw data to ppm\n");
            return;
        }
    } else {
        void (*_ppmdwrite[2]) (FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize) = {_ppm8dwrite, _ppm16dwrite};
        _ppmdwrite[dsize >> 1](file, &(*data), width, height, depth, dsize);
    }
}

#pragma mark - Write PNM header

void pnmhwrite(FILE *file, unsigned int width, unsigned int height, unsigned int max, pnm_format_t format) {
    const char *magic = pnm_magic_number(format);
    
    if (!magic) {
        return;
    }
    
    char magicNumber[5];
    strcpy(magicNumber, magic);
    strcat(magicNumber, "\n");
    
    fputs(magicNumber, file);
    fprintf(file, "# Generated with imagic 2.0 alpha\n");
    
    if (max > 1) {
        fprintf(file, "%u %u %u\n", width, height, max);
    } else {
        fprintf(file, "%u %u\n", width, height);
    }
}

#pragma mark - Internal methods for io

void _pnmopen(const char *filename, void **data, unsigned int *width, unsigned int *height, unsigned int *depth, size_t *dsize, pnm_format_t *format) {
    FILE *file = NULL;
    
    if (!(file = fopen(filename, "r"))) {
        return;
    }
    
    unsigned int _width = 0, _height = 0, _max = 0;
    pnm_format_t _format;
    
    pnmhread(file, &_width, &_height, &_max, &_format);
    
    if ((_width < 1) || (_height < 1) || (_format == PNM_UNDEFINED)) {
        return;
    }
    
    unsigned int _depth = _format & 0x8 ? 3 : 1;
    size_t _dsize, dlength = _width * _height * _depth;
    
    if (_max <= UINT8_MAX) {
        _dsize = sizeof(uint8_t);
    } else if (_max <= UINT16_MAX) {
        _dsize = sizeof(uint16_t);
    } else if (_max <= UINT32_MAX) {
        _dsize = sizeof(uint32_t);
    } else {
        _dsize = sizeof(unsigned int);
    }
    
    *data = malloc(dlength * _dsize);
    
    void (*_pnmreaddata[3]) (FILE *file, void **data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) = {pbmdread, pgmdread, ppmdread};
    _pnmreaddata[_format >> 2](file, &(*data), _width, _height, _depth, _dsize, is_raw_format(_format));
    
    *width = _width;
    *height = _height;
    *depth = _depth;
    *dsize = _dsize;
    *format = _format;
    
    fclose(file);
}

void _pnmwrite(const char *filename, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, unsigned int max, pnm_format_t format) {
    FILE *file = NULL;
    
    if (!(file = fopen(filename, "w"))) {
        return;
    }
    
    pnmhwrite(file, width, height, max, format);
    
    void (*_pnmwritedata[3]) (FILE *file, void *data, unsigned int width, unsigned int height, unsigned int depth, size_t dsize, bool raw) = {pbmdwrite, pgmdwrite, ppmdwrite};
    _pnmwritedata[format >> 2](file, data, width, height, depth, dsize, is_raw_format(format));
    
    fclose(file);
}
