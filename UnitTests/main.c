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

#include "convert.h"
#include "io.h"

int main(int argc, const char * argv[]) {
    
//    img_t *ppm = pnmopen("/Users/itzseven/Pictures/libimage resources/bus1.ppm");
//
//    img_t *pgm = img(ppm->width, ppm->height, 1, ppm->dsize);
//
//    rgb2gray(ppm, pgm);
//
//    ppm = img(ppm->width, ppm->height, 3, ppm->dsize);
//
//    gray2rgb(pgm, ppm);
//
//    img_t *pbm = img(pgm->width, pgm->height, pgm->depth, pgm->dsize);
//
//    gray2mono(pgm, pbm, 70);
//
//    mono2gray(pbm, pgm);
//
//    pnmwrite("/Users/itzseven/Desktop/bus1.export.pgm", pgm, PNM_NO_OPT);
//    pnmwrite("/Users/itzseven/Desktop/bus1.export.ppm", ppm, PNM_NO_OPT);
    
//    pnmwrite("/Users/itzseven/Desktop/bus1.export.pbm", pbm, PNM_NO_OPT);
    
    ctsrun(matrix_test_suite());
    ctsrun(image_test_suite());
    ctsrun(io_test_suite());
    ctsrun(convert_test_suite());
    
    return 0;
}
