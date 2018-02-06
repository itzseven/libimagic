//
//  io_unit_tests.c
//  UnitTests
//
//  Created by itzseven on 23/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "io_unit_tests.h"
#include <string.h>
#include "io.h"
#include "cunit.h"

#define RESOURCES_PATH "Resources/UnitTests/io/"

#define TEST_PBM_RAW_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.binary.pbm"
#define TEST_PBM_PLAIN_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.pbm"

#define TEST_PGM_RAW_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.binary.pgm"
#define TEST_PGM_PLAIN_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.pgm"

#define TEST_PPM_RAW_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.binary.ppm"
#define TEST_PPM_PLAIN_OPEN_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.ppm"

#define TEST_PBM_RAW_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.binary.export.pbm"
#define TEST_PBM_PLAIN_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.export.pbm"

#define TEST_PGM_RAW_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.binary.export.pgm"
#define TEST_PGM_PLAIN_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.export.pgm"

#define TEST_PPM_RAW_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.binary.export.ppm"
#define TEST_PPM_PLAIN_WRITE_RESOURCE_PATH "Resources/UnitTests/io/small.ascii.export.ppm"

ctest_return_t test_pbm_raw_open(ctest_t *test, void *arg) {
    uint8_t expected[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    
    img_t *img = pnmopen(TEST_PBM_RAW_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 1);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_pbm_plain_open(ctest_t *test, void *arg) {
    uint8_t expected[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    
    img_t *img = pnmopen(TEST_PBM_PLAIN_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 1);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_pgm_raw_open(ctest_t *test, void *arg) {
    uint8_t expected[9] = {54, 70, 235, 182, 42, 0, 18, 152, 40};
    
    img_t *img = pnmopen(TEST_PGM_RAW_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 1);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_pgm_plain_open(ctest_t *test, void *arg) {
    uint8_t expected[9] = {54, 70, 235, 182, 42, 0, 18, 152, 40};
    
    img_t *img = pnmopen(TEST_PGM_PLAIN_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 1);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_ppm_raw_open(ctest_t *test, void *arg) {
    uint8_t expected[27] = {255, 0, 0, 255, 0, 216, 246, 255, 0, 0, 255, 0, 92, 14, 172, 0, 0, 0, 0, 0, 255, 191, 150, 61, 61, 25, 121};
    
    img_t *img = pnmopen(TEST_PPM_RAW_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 3);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_ppm_plain_open(ctest_t *test, void *arg) {
    uint8_t expected[27] = {255, 0, 0, 255, 0, 216, 246, 255, 0, 0, 255, 0, 92, 14, 172, 0, 0, 0, 0, 0, 255, 191, 150, 61, 61, 25, 121};
    
    img_t *img = pnmopen(TEST_PPM_PLAIN_OPEN_RESOURCE_PATH);
    
    CTAssertNotNull(test, img);
    CTAssertEqual(test, img->width, 3);
    CTAssertEqual(test, img->height, 3);
    CTAssertEqual(test, img->depth, 3);
    CTAssertEqual(test, img->dsize, sizeof(uint8_t));
    
    unsigned int i = 0;
    for (i = 0; i < img->width * img->height * img->depth; i++) {
        CTAssertEqual(test, ELT_DATA(img, uint8_t, i), expected[i]);
    }
    
    imgfree(img);
}

ctest_return_t test_pbm_raw_write(ctest_t *test, void *arg) {
    uint8_t data[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    
    img_t *img8 = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PBM_RAW_WRITE_RESOURCE_PATH, img8, PNM_NO_OPT);
    
    FILE *export = fopen(TEST_PBM_RAW_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P4\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#'); // Checks if second line is a comment
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3\n"), 0);
    CTAssertEqual(test, fgetc(export), 160); // 1010 0000 => 1 0 1
    CTAssertEqual(test, fgetc(export), 64);  // 0100 0000 => 0 1 0
    CTAssertEqual(test, fgetc(export), 160); // 1010 0000 => 1 0 1
    CTAssertEqual(test, feof(export), 0);
    
    fclose(export);
}

ctest_return_t test_pbm_plain_write(ctest_t *test, void *arg) {
    uint8_t data[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    
    img_t *img8 = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PBM_PLAIN_WRITE_RESOURCE_PATH, img8, PNM_PLAIN);
    
    FILE *export = fopen(TEST_PBM_PLAIN_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P1\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#');
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "1 0 1\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "0 1 0\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "1 0 1\n"), 0);
    CTAssertEqual(test, feof(export), 0);
    
    fclose(export);
}

ctest_return_t test_pgm_raw_write(ctest_t *test, void *arg) {
    uint8_t data[9] = {54, 70, 235, 182, 42, 0, 18, 152, 40};
    
    img_t *img8 = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PGM_RAW_WRITE_RESOURCE_PATH, img8, PNM_NO_OPT);
    
    FILE *export = fopen(TEST_PGM_RAW_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P5\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#');
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3 255\n"), 0);
    
    unsigned int i = 0;
    for (i = 0; i < 9; i++) {
        CTAssertEqual(test, fgetc(export), data[i]);
    }
    
    CTAssertEqual(test, feof(export), 0);
    
    fclose(export);
}

ctest_return_t test_pgm_plain_write(ctest_t *test, void *arg) {
    uint8_t data[9] = {54, 70, 235, 182, 42, 0, 18, 152, 40};
    
    img_t *img8 = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PGM_PLAIN_WRITE_RESOURCE_PATH, img8, PNM_PLAIN);
    
    FILE *export = fopen(TEST_PGM_PLAIN_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P2\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#');
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3 255\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "54 70 235\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "182 42 0\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "18 152 40\n"), 0);
    CTAssertEqual(test, feof(export), 0);
}

ctest_return_t test_ppm_raw_write(ctest_t *test, void *arg) {
    uint8_t data[27] = {255, 0, 0, 255, 0, 216, 246, 255, 0, 0, 255, 0, 92, 14, 172, 0, 0, 0, 0, 0, 255, 191, 150, 61, 61, 25, 121};
    
    img_t *img8 = img(3, 3, 3, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PPM_RAW_WRITE_RESOURCE_PATH, img8, PNM_NO_OPT);
    
    FILE *export = fopen(TEST_PPM_RAW_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P6\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#'); // Checks if second line is a comment
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3 255\n"), 0);
    
    unsigned int i = 0;
    for (i = 0; i < 27; i++) {
        CTAssertEqual(test, fgetc(export), data[i]);
    }
    
    CTAssertEqual(test, feof(export), 0);
    
    fclose(export);
}

ctest_return_t test_ppm_plain_write(ctest_t *test, void *arg) {
    uint8_t data[27] = {255, 0, 0, 255, 0, 216, 246, 255, 0, 0, 255, 0, 92, 14, 172, 0, 0, 0, 0, 0, 255, 191, 150, 61, 61, 25, 121};
    
    img_t *img8 = img(3, 3, 3, sizeof(uint8_t));
    imgdcpy(img8, data);
    
    pnmwrite(TEST_PPM_RAW_WRITE_RESOURCE_PATH, img8, PNM_PLAIN);
    
    FILE *export = fopen(TEST_PPM_RAW_WRITE_RESOURCE_PATH, "r");
    
    CTAssertNotNull(test, export);
    
    char line[512];
    
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "P3\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, line[0], '#'); // Checks if second line is a comment
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "3 3 255\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "255 0 0 255 0 216 246 255 0\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "0 255 0 92 14 172 0 0 0\n"), 0);
    CTAssertNotNull(test, fgets(line, 512, export));
    CTAssertEqual(test, strcmp(line, "0 0 255 191 150 61 61 25 121\n"), 0);
    CTAssertEqual(test, feof(export), 0);
}

ctsuite_t *io_test_suite(void) {
    ctsuite_t *suite = ctsuite("io component");
    
    ctcase_t *pnmOpenTestCase = ctcase("pnm opening");
    
    ctctestadd(pnmOpenTestCase, ctest("test_pbm_raw_open", test_pbm_raw_open, NULL));
    ctctestadd(pnmOpenTestCase, ctest("test_pbm_plain_open", test_pbm_plain_open, NULL));
    ctctestadd(pnmOpenTestCase, ctest("test_pgm_raw_open", test_pgm_raw_open, NULL));
    ctctestadd(pnmOpenTestCase, ctest("test_pgm_plain_open", test_pgm_plain_open, NULL));
    ctctestadd(pnmOpenTestCase, ctest("test_ppm_raw_open", test_ppm_raw_open, NULL));
    ctctestadd(pnmOpenTestCase, ctest("test_ppm_plain_open", test_ppm_plain_open, NULL));
    
    ctcase_t *pnmWriteTestCase = ctcase("pnm write");
    
    ctctestadd(pnmWriteTestCase, ctest("test_pbm_raw_write", test_pbm_raw_write, NULL));
    ctctestadd(pnmWriteTestCase, ctest("test_pbm_plain_write", test_pbm_plain_write, NULL));
    ctctestadd(pnmWriteTestCase, ctest("test_pgm_raw_write", test_pgm_raw_write, NULL));
    ctctestadd(pnmWriteTestCase, ctest("test_pgm_plain_write", test_pgm_plain_write, NULL));
    ctctestadd(pnmWriteTestCase, ctest("test_ppm_raw_write", test_ppm_raw_write, NULL));
    ctctestadd(pnmWriteTestCase, ctest("test_ppm_plain_write", test_ppm_plain_write, NULL));
    
    ctscaseadd(suite, pnmOpenTestCase);
    ctscaseadd(suite, pnmWriteTestCase);
    
    return suite;
}
