//
//  main.c
//  UnitTests
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include <stdio.h>
#include "cunit.h"
#include "matrix_unit_tests.h"
#include "image_unit_tests.h"
#include "io_unit_tests.h"
#include "convert_unit_tests.h"
#include "image.h"
#include "io.h"
#include "convert.h"
#include "labelling.h"

int main(int argc, const char * argv[]) {
    
//    ctsrun(matrix_test_suite());
//    ctsrun(image_test_suite());
//    ctsrun(io_test_suite());
//    ctsrun(convert_test_suite());
    
    img_t *src = pnmopen("/Users/itzseven/Desktop/littlebig.pbm");
    
    clock_t begin = clock();
    
    labels_t *newLabels = label(src);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Legacy method took : %lf seconds\n", time_spent);
    
    begin = clock();
    
    newLabels = label2(src);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("New method took : %lf seconds\n", time_spent);
    
    img_t *normalized = img(src->width, src->height, src->depth, src->dsize);
    
    unsigned int i = 0;
    float coeff = (float)255 / newLabels->count;
    
    for (i = 0; i < src->width * src->height * src->depth; i++) {
        ELT_DATA(normalized, uint8_t, i) = (uint8_t)(coeff * ELT_DATA(newLabels, uint32_t, i));
    }
    
    pnmwrite("/Users/itzseven/Desktop/test_toobig_labels2.pgm", normalized, PNM_NO_OPT);
    
    return 0;
}
