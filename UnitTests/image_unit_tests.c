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

ctcase_return_t test_image_rgb8i_comparison() {
    rgb8 data[9] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}, {5, 6, 7}, {6, 7, 8}, {7, 8, 9}, {8, 9, 10}};
    
    rgb8i_t *rgb81 = rgb8i(3, 3);
    rgb8idcpy(rgb81, data);
    
    rgb8i_t *rgb81copy = rgb8icpy(rgb81);
    
    CTAssertTrue(rgb8icmp(rgb81, rgb81copy) == 0)
    
    rgb81copy->data[0].r = 0;
    rgb81copy->data[0].g = 0;
    rgb81copy->data[0].b = 0;
    
    CTAssertFalse(rgb8icmp(rgb81, rgb81copy) == 0)
    
    rgb8i_t *rgb82 = rgb8i(10, 10);
    rgb8i_t *rgb83 = rgb8i(9, 10);
    
    CTAssertFalse(rgb8icmp(rgb82, rgb83) == 0)
    
    rgb8ifree(rgb81);
    rgb8ifree(rgb81copy);
    rgb8ifree(rgb82);
    rgb8ifree(rgb83);
    
    return CTPassed;
}

ctcase_return_t test_image_gray8i_comparison() {
    
    uint8_t data[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    
    gray8i_t *gray81 = gray8i(3, 3);
    gray8idcpy(gray81, data);
    
    gray8i_t *gray81copy = gray8icpy(gray81);
    
    CTAssertTrue(gray8icmp(gray81, gray81copy) == 0)

    gray81copy->data[8] = 0;
    
    CTAssertFalse(gray8icmp(gray81, gray81copy) == 0)
    
    gray8i_t *gray82 = gray8i(10, 10);
    gray8i_t *gray83 = gray8i(9, 10);
    
    CTAssertFalse(gray8icmp(gray82, gray83) == 0)
    
    gray8ifree(gray81);
    gray8ifree(gray81copy);
    gray8ifree(gray82);
    gray8ifree(gray83);
    
    return CTPassed;
}

ctsuite_t *image_test_suite(void) {
    ctsuite_t *suite = ctsuite("image component");
    
    ctsaddtc(ctcase("test_image_rgb8i_comparison", test_image_rgb8i_comparison), suite);
    ctsaddtc(ctcase("test_image_gray8i_comparison", test_image_gray8i_comparison), suite);
    
    return suite;
}
