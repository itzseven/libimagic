//
//  opticalflow_tests.c
//  imagic
//
//  Created by Adrien on 15/03/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "opticalflow_tests.h"
#include <math.h>

int opticalflow_tests_passed;
int opticalflow_tests_failed;

// **************************
// ****** TEST SUITE ********
// **************************
void opticalflow_testsuite() {
    test_to_left();
    test_to_right();
    test_to_up();
    test_to_bottom();
    //test_memory();
}

// **************************
// ********* UTILS **********
// **************************

int retrieves_best_angle(vect2darray_t *speed_vectors, uint16_t width, uint16_t height) {
    int i;
    int best_angle = -1;
    int *histogram = (int *)calloc(360, sizeof(int));
    
    for (i = 0; i < width*height; i++) {
        double x = speed_vectors->data[i].x;
        double y = speed_vectors->data[i].y;
        double angle;
        
        if (sqrt(x*x + y*y) > 0.04) {
            angle = atan2(-y, x) * 180 / M_PI;
            if (angle < 0) {
                angle += 360;
            }
            histogram[(int) angle]++;
        }
    }
    
    int max = -1;
    for (i = 0; i < 360; i++) {
        if (histogram[i] > max) {
            max = histogram[i];
            best_angle = i;
        }
    }
    
    free(histogram);
    return best_angle;
}

void run_opticalflow(uint8_t *image1_data, uint8_t *image2_data, uint16_t width, uint16_t height, int expected_value) {
    gray8i_t *image1 = gray8iallocwd(width, height, image1_data);
    gray8i_t *image2 = gray8iallocwd(width, height, image2_data);
    
    vect2darray_t* result = opticalflow(image1, image2);
    int best_angle = retrieves_best_angle(result, width, height);
    
    if (best_angle == expected_value) {
        opticalflow_tests_passed++;
    } else {
        printf("test failed : expected was %d, result was %d.\n", expected_value, best_angle);
        opticalflow_tests_failed++;
    }
    
    gray8ifree(image1);
    gray8ifree(image2);
    vect2darrfree(result);
}

// **************************
// ********* TESTS **********
// **************************

void test_to_left() {
    
    puts("Starts test_to_left\n");

    uint8_t image1_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
    
    uint8_t image2_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    run_opticalflow(image1_data, image2_data, 10, 10, 180);
    
}

void test_to_right() {
    
    puts("Starts test_to_right\n");
    
    uint8_t image1_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
    
    uint8_t image2_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 255, 255, 255, 255, 0,
        0, 0, 0, 0, 0, 255, 255, 255, 255, 0,
        0, 0, 0, 0, 0, 255, 255, 255, 255, 0,
        0, 0, 0, 0, 0, 255, 255, 255, 255, 0,
        0, 0, 0, 0, 0, 255, 255, 255, 255, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    run_opticalflow(image1_data, image2_data, 10, 10, 0);

}

void test_to_up() {
    
    puts("Starts test_to_up\n");
    
    uint8_t image1_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
    
    uint8_t image2_data[] = {0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    run_opticalflow(image1_data, image2_data, 10, 10, 90);

}

void test_to_bottom() {
    
    puts("Starts test_to_bottom\n");
    
    uint8_t image1_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
    
    uint8_t image2_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    run_opticalflow(image1_data, image2_data, 10, 10, 270);
    
}

void test_memory() {
    
    puts("Starts test_memory\n");
    
    uint8_t image1_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 255, 255, 255, 255, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
    
    uint8_t image2_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 255, 255, 255, 255, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int i;
    for (i = 0; i < 1000000; i++) {
        run_opticalflow(image1_data, image2_data, 10, 10, 180);
    }
}

