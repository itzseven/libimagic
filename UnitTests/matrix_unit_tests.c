//
//  matrix_unit_tests.c
//  UnitTests
//
//  Created by itzseven on 06/12/2017.
//  Copyright © 2017 itzseven. All rights reserved.
//

#include "matrix_unit_tests.h"
#include "matrix.h"
#include "cunit.h"

#include <stdbool.h>

typedef struct {
    int a;
    bool b;
}TestType;

ctcase_return_t test_matrix_alloc_bad_parameters() {
    mat_t *mat1 = mat(0, 13, sizeof(int));
    mat_t *mat2 = mat(12, 0, sizeof(unsigned long));
    
    cassertt((mat1 == NULL) && (mat2 == NULL), "mat1 or mat2 is not NULL\n")
    
    return CTPassed;
}

ctcase_return_t test_matrix_alloc_valid_parameters() {
    mat_t *mat0 = mat(10, 20, sizeof(float));
    
    cassertnnull(mat0, "mat0 is NULL\n")
    casserteq(mat0->width, 10, "mat0 width is not equal to 10\n")
    casserteq(mat0->height, 20, "mat0 height is not equal to 20\n")
    casserteq(mat0->dsize, sizeof(float), "mat0 dsize is not equal to %d\n", sizeof(float))
    cassertnnull(mat0->data, "mat0 data is NULL\n")
    
    unsigned int i = 0;
    
    for (i = 0; i < mat0->width * mat0->height; i++) {
        casserteq(((float *)mat0->data)[i], 0, "value at index %d is not equal to 0\n", i)
    }
    
    matfree(mat0);
    
    return CTPassed;
}

ctcase_return_t test_matrix_copy_matrix() {
    cassertnull(matcpy(NULL), "matcpy with NULL parameter does not return NULL\n")
    
    mat_t *mat0 = mat(3, 3, sizeof(uint32_t));
    
    unsigned int i = 0;
    
    for (i = 0; i < mat0->width * mat0->height; i++) {
        ((uint32_t *)mat0->data)[i] = arc4random_uniform(300);
    }
    
    mat_t *mat1 = matcpy(mat0);
    
    cassertnnull(mat1, "mat1 is NULL\n")
    casserteq(mat1->width, mat0->width, "mat1 width is not equal to mat0 width\n")
    casserteq(mat1->height, mat0->height, "mat1 height is not equal to mat0 height\n")
    casserteq(mat1->dsize, mat0->dsize, "mat1 dsize is not equal to mat0 dsize\n")
    cassertnnull(mat1->data, "mat1 data is NULL\n")
    
    for (i = 0; i < mat0->width * mat0->height; i++) {
        casserteq(((uint32_t *)mat0->data)[i], ((uint32_t *)mat1->data)[i], "mat0 element at index %d is not equal to mat1 element\n", i)
    }
    
    matfree(mat0);
    matfree(mat1);
    
    return CTPassed;
}

ctcase_return_t test_matrix_copy_data() {
    uint8_t data[20] = {1, 4, 7, 2, 9, 2, 1, 4, 7, 2, 9, 8, 9, 0, 1, 4, 7, 2, 9, 20};
    
    mat_t *mat0 = mat(5, 4, sizeof(uint8_t));
    matdcpy(mat0, data);
    
    unsigned int i = 0;
    
    for (i = 0; i < mat0->width * mat0->height; i++) {
        casserteq(((uint8_t *)mat0->data)[i], data[i], "mat0 element at index %d is not equal to data element\n", i)
    }
    
    matfree(mat0);
    
    int16_t data1[20] = {1, -4, 7, -2, 9, 2, 1, -4, 7, 2, 9, 8, -9, 0, 1, 4, 7, 2, 9, -20};
    
    mat_t *mat1 = mat(4, 5, sizeof(int16_t));
    matdcpy(mat1, data1);
    
    for (i = 0; i < mat1->width * mat1->height; i++) {
        casserteq(((int16_t *)mat1->data)[i], data1[i], "mat1 element at index %d is not equal to data1 element\n", i)
    }
    
    matfree(mat1);
    
    double data2[20] = {1.1, -4, 7.25, -2, 9, 2, 1.445, -4, 7, 2, 9.056, 8, -9.025, 0, 1, 4, 7, 2, 9, -20};
    
    mat_t *mat2 = mat(5, 4, sizeof(double));
    matdcpy(mat2, data2);
    
    for (i = 0; i < mat2->width * mat2->height; i++) {
        casserteq(((double *)mat2->data)[i], data2[i], "mat2 element at index %d is not equal to data2 element\n", i)
    }
    
    matfree(mat2);
    
    bool data3[10] = {true, true, false, true, false, false, false, true, false, true};
    
    mat_t *mat3 = mat(2, 5, sizeof(bool));
    matdcpy(mat3, data3);
    
    for (i = 0; i < mat3->width * mat3->height; i++) {
        casserteq(((bool *)mat3->data)[i], data3[i], "mat3 element at index %d is not equal to data3 element\n", i)
    }
    
    matfree(mat3);
    
    TestType data4[4] = {{2, false}, {-45, true}, {90, false}, {0, true}};
    
    mat_t *mat4 = mat(2, 2, sizeof(TestType));
    matdcpy(mat4, data4);
    
    for (i = 0; i < mat4->width * mat4->height; i++) {
        casserteq(((TestType *)mat4->data)[i].a, data4[i].a, "mat4 element a member at index %d is not equal to data4 element\n", i)
        casserteq(((TestType *)mat4->data)[i].b, data4[i].b, "mat4 element b member at index %d is not equal to data4 element\n", i)
    }
    
    matfree(mat4);
    
    return CTPassed;
}

ctcase_return_t test_matrix_element_tools_macros() {
    
    mat_t *mat0 = mat(3, 3, sizeof(int));
    ((int *)mat0->data)[0] = 0;
    ((int *)mat0->data)[1] = 1;
    ((int *)mat0->data)[2] = 2;
    ((int *)mat0->data)[3] = 3;
    ((int *)mat0->data)[4] = 4;
    ((int *)mat0->data)[5] = 5;
    ((int *)mat0->data)[6] = 6;
    ((int *)mat0->data)[7] = 7;
    ((int *)mat0->data)[8] = 8;
    
    // Tests macro that give element index for given x and y
    casserteq(ELT_IDX(mat0, 0, 0), 0)
    casserteq(ELT_IDX(mat0, 1, 0), 1)
    casserteq(ELT_IDX(mat0, 2, 0), 2)
    casserteq(ELT_IDX(mat0, 0, 1), 3)
    casserteq(ELT_IDX(mat0, 1, 1), 4)
    casserteq(ELT_IDX(mat0, 2, 1), 5)
    casserteq(ELT_IDX(mat0, 0, 2), 6)
    casserteq(ELT_IDX(mat0, 1, 2), 7)
    casserteq(ELT_IDX(mat0, 2, 2), 8)
    
    // Tests macro that give element for given x and y
    casserteq(ELT(mat0, int, 0, 0), 0)
    casserteq(ELT(mat0, int, 1, 0), 1)
    casserteq(ELT(mat0, int, 2, 0), 2)
    casserteq(ELT(mat0, int, 0, 1), 3)
    casserteq(ELT(mat0, int, 1, 1), 4)
    casserteq(ELT(mat0, int, 2, 1), 5)
    casserteq(ELT(mat0, int, 0, 2), 6)
    casserteq(ELT(mat0, int, 1, 2), 7)
    casserteq(ELT(mat0, int, 2, 2), 8)
    
    matfree(mat0);
    
    return CTPassed;
}

ctsuite_t *matrix_test_suite(void) {
    ctsuite_t *suite = ctsuite("matrix component");
    
    ctsaddtc(ctcase("test_matrix_alloc_bad_parameters", test_matrix_alloc_bad_parameters), suite);
    ctsaddtc(ctcase("test_matrix_alloc_valid_parameters", test_matrix_alloc_valid_parameters), suite);
    ctsaddtc(ctcase("test_matrix_copy_matrix", test_matrix_copy_matrix), suite);
    ctsaddtc(ctcase("test_matrix_copy_data", test_matrix_copy_data), suite);
    ctsaddtc(ctcase("test_matrix_element_tools_macros", test_matrix_element_tools_macros), suite);
    
    return suite;
}
