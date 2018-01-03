//
//  image_unit_tests.c
//  UnitTests
//
//  Created by itzseven on 07/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "image_unit_tests.h"
#include "image.h"
#include "cunit.h"

ctcase_return_t test_image_rgb8_comparison() {
    const uint8_t data[27] = {0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9, 8, 9, 10};
    
    img_t *rgb81 = img(3, 3, 3, sizeof(uint8_t));
    imgdcpy(rgb81, data);
    
    img_t *rgb81copy = imgcpy(rgb81);
    
    CTAssertTrue(imgcmp(rgb81, rgb81copy) == 0)
    
    ELT_DATA(rgb81copy, uint8_t, 0) = 0;
    ELT_DATA(rgb81copy, uint8_t, 1) = 0;
    ELT_DATA(rgb81copy, uint8_t, 2) = 0;
    
    CTAssertFalse(imgcmp(rgb81, rgb81copy) == 0)
    
    img_t *rgb82 = img(10, 10, 3, sizeof(uint8_t));
    img_t *rgb83 = img(9, 10, 3, sizeof(uint8_t));
    
    CTAssertFalse(imgcmp(rgb82, rgb83) == 0)
    
    imgfree(rgb81);
    imgfree(rgb81copy);
    imgfree(rgb82);
    imgfree(rgb83);
    
    return CTPassed;
}

ctcase_return_t test_image_gray8_comparison() {
    
    const uint8_t data[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    
    img_t *gray81 = img(3, 3, 1, sizeof(uint8_t));
    imgdcpy(gray81, data);
    
    img_t *gray81copy = imgcpy(gray81);
    
    CTAssertTrue(imgcmp(gray81, gray81copy) == 0)
    
    ELT_DATA(gray81copy, uint8_t, 0) = 1;
    
    CTAssertFalse(imgcmp(gray81, gray81copy) == 0)
    
    img_t *gray82 = img(10, 10, 1, sizeof(uint8_t));
    img_t *gray83 = img(9, 10, 1, sizeof(uint8_t));
    
    CTAssertFalse(imgcmp(gray82, gray83) == 0)
    
    imgfree(gray81);
    imgfree(gray81copy);
    imgfree(gray82);
    imgfree(gray83);
    
    return CTPassed;
}

ctsuite_t *image_test_suite(void) {
    ctsuite_t *suite = ctsuite("image component");
    
    ctsaddtc(ctcase("test_image_rgb8_comparison", test_image_rgb8_comparison), suite);
    ctsaddtc(ctcase("test_image_gray8_comparison", test_image_gray8_comparison), suite);
    
    return suite;
}
