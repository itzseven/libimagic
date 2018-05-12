//
//  convert_unit_tests.c
//  UnitTests
//
//  Created by itzseven on 06/01/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#include "convert_unit_tests.h"
#include "convert.h"
#include "cunit.h"

ctest_return_t test_rgb_to_gray(ctest_t *test, void *arg) {
    const uint8_t data[12] = {54, 70, 235, 182, 42, 0, 18, 152, 40, 10, 45, 233};
    
    img_t *rgb8 = img(2, 2, 3, sizeof(uint8_t));
    imgdcpy(rgb8, data);
    
    img_t *gray = img(rgb8->width, rgb8->height, 1, rgb8->dsize);
    
    rgb2gray(rgb8, gray);
    
    CTAssertEqual(test, ELT_DATA(gray, uint8_t, 0), 119);
    CTAssertEqual(test, ELT_DATA(gray, uint8_t, 1), 74);
    CTAssertEqual(test, ELT_DATA(gray, uint8_t, 2), 70);
    CTAssertEqual(test, ELT_DATA(gray, uint8_t, 3), 96);
    
    imgfree(rgb8);
    imgfree(gray);
}

ctest_return_t test_gray_to_rgb(ctest_t *test, void *arg) {
    const uint8_t data[4] = {54, 70, 235, 182};
    
    img_t *gray = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(gray, data);
    
    img_t *rgb = img(gray->width, gray->height, 3, gray->dsize);
    
    gray2rgb(gray, rgb);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 0), 54);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 1), 54);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 2), 54);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 3), 70);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 4), 70);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 5), 70);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 6), 235);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 7), 235);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 8), 235);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 9), 182);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 10), 182);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 11), 182);
    
    imgfree(gray);
    imgfree(rgb);
}

ctest_return_t test_gray_to_mono(ctest_t *test, void *arg) {
    
    const uint8_t data[4] = {54, 70, 235, 182};
    
    img_t *gray = img(2, 2, 1, sizeof(uint8_t));
    imgdcpy(gray, data);
    
    img_t *mono = img(gray->width, gray->height, 1, gray->dsize);
    
    gray2mono(gray, mono, 100);
    
    CTAssertEqual(test, ELT_DATA(mono, uint8_t, 0), 0);
    CTAssertEqual(test, ELT_DATA(mono, uint8_t, 1), 0);
    CTAssertEqual(test, ELT_DATA(mono, uint8_t, 2), 1);
    CTAssertEqual(test, ELT_DATA(mono, uint8_t, 3), 1);
    
    imgfree(gray);
    imgfree(mono);
}

ctest_return_t test_mono_to_gray(ctest_t *test, void *arg) {
    
    const uint8_t data[4] = {1, 0, 0, 1};
    
    img_t *mono = img(2, 2, 1, sizeof(uint8_t));
    imgdcpy(mono, data);
    
    img_t *gray8 = img(mono->width, mono->height, 1, mono->dsize);
    
    mono2gray(mono, gray8);
    
    CTAssertEqual(test, ELT_DATA(gray8, uint8_t, 0), 0);
    CTAssertEqual(test, ELT_DATA(gray8, uint8_t, 1), UINT8_MAX);
    CTAssertEqual(test, ELT_DATA(gray8, uint8_t, 2), UINT8_MAX);
    CTAssertEqual(test, ELT_DATA(gray8, uint8_t, 3), 0);
    
    imgfree(mono);
    imgfree(gray8);
}

ctest_return_t test_rgb_to_rgba(ctest_t *test, void *arg) {
    const uint8_t data[12] = {54, 70, 235, 182, 42, 0, 18, 152, 40, 10, 45, 233};
    
    img_t *rgb8 = img(2, 2, 3, sizeof(uint8_t));
    imgdcpy(rgb8, data);
    
    img_t *rgba = img(rgb8->width, rgb8->height, 4, rgb8->dsize);
    
    rgb2rgba(rgb8, rgba, 0.5);
    
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 0), 54);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 1), 70);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 2), 235);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 3), 127);
    
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 4), 182);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 5), 42);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 6), 0);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 7), 127);
    
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 8), 18);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 9), 152);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 10), 40);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 11), 127);
    
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 12), 10);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 13), 45);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 14), 233);
    CTAssertEqual(test, ELT_DATA(rgba, uint8_t, 15), 127);
    
    imgfree(rgb8);
    imgfree(rgba);
}

ctest_return_t test_rgba_to_rgb(ctest_t *test, void *arg) {
    const uint8_t data[16] = {54, 70, 235, 156, 182, 42, 0, 255, 18, 152, 40, 173, 10, 45, 233, 23};
    
    img_t *rgba = img(2, 2, 4, sizeof(uint8_t));
    imgdcpy(rgba, data);
    
    img_t *rgb = img(rgba->width, rgba->height, 3, rgba->dsize);
    
    rgba2rgb(rgba, rgb);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 0), 54);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 1), 70);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 2), 235);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 3), 182);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 4), 42);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 5), 0);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 6), 18);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 7), 152);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 8), 40);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 9), 10);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 10), 45);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 11), 233);
    
    imgfree(rgba);
    imgfree(rgb);
}

ctest_return_t test_rgb_to_argb(ctest_t *test, void *arg) {
    const uint8_t data[12] = {54, 70, 235, 182, 42, 0, 18, 152, 40, 10, 45, 233};
    
    img_t *rgb8 = img(2, 2, 3, sizeof(uint8_t));
    imgdcpy(rgb8, data);
    
    img_t *argb = img(rgb8->width, rgb8->height, 4, rgb8->dsize);
    
    rgb2argb(rgb8, argb, 0.5);
    
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 0), 127);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 1), 54);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 2), 70);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 3), 235);
    
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 4), 127);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 5), 182);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 6), 42);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 7), 0);
    
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 8), 127);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 9), 18);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 10), 152);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 11), 40);
    
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 12), 127);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 13), 10);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 14), 45);
    CTAssertEqual(test, ELT_DATA(argb, uint8_t, 15), 233);
    
    imgfree(rgb8);
    imgfree(argb);
}

ctest_return_t test_argb_to_rgb(ctest_t *test, void *arg) {
    const uint8_t data[16] = {234, 54, 70, 235, 56, 182, 42, 0, 98, 18, 152, 40, 200, 10, 45, 233};
    
    img_t *argb = img(2, 2, 4, sizeof(uint8_t));
    imgdcpy(argb, data);
    
    img_t *rgb = img(argb->width, argb->height, 3, argb->dsize);
    
    argb2rgb(argb, rgb);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 0), 54);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 1), 70);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 2), 235);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 3), 182);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 4), 42);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 5), 0);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 6), 18);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 7), 152);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 8), 40);
    
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 9), 10);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 10), 45);
    CTAssertEqual(test, ELT_DATA(rgb, uint8_t, 11), 233);
    
    imgfree(argb);
    imgfree(rgb);
}

ctsuite_t *convert_test_suite(void) {
    ctsuite_t *suite = ctsuite("convert component");
    
    ctcase_t *convertRgb = ctcase("convert rgb");
    
    ctctestadd(convertRgb, ctest("test_rgb_to_gray", test_rgb_to_gray, NULL));
    ctctestadd(convertRgb, ctest("test_rgb_to_rgba", test_rgb_to_rgba, NULL));
    ctctestadd(convertRgb, ctest("test_rgb_to_argb", test_rgb_to_argb, NULL));
    
    ctcase_t *convertRgba = ctcase("convert rgba");
    
    ctctestadd(convertRgba, ctest("test_rgba_to_rgb", test_rgba_to_rgb, NULL));
    
    ctcase_t *convertArgb = ctcase("convert argb");
    
    ctctestadd(convertArgb, ctest("test_argb_to_rgb", test_argb_to_rgb, NULL));
    
    ctcase_t *convertGray = ctcase("convert gray");
    
    ctctestadd(convertGray, ctest("test_gray_to_rgb", test_gray_to_rgb, NULL));
    ctctestadd(convertGray, ctest("test_gray_to_mono", test_gray_to_mono, NULL));
    
    ctcase_t *convertMono = ctcase("convert mono");
    
    ctctestadd(convertMono, ctest("test_mono_to_gray", test_mono_to_gray, NULL));
    
    ctscaseadd(suite, convertRgb);
    ctscaseadd(suite, convertRgba);
    ctscaseadd(suite, convertArgb);
    ctscaseadd(suite, convertGray);
    ctscaseadd(suite, convertMono);
    
    return suite;
}
