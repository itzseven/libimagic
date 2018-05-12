//
//  labelling_unit_tests.c
//  UnitTests
//
//  Created by itzseven on 04/02/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#include "labelling_unit_tests.h"
#include "labelling.h"
#include "cunit.h"

ctest_return_t test_labels_creation(ctest_t *test, void *arg) {
    labels_t *newLabels = labels(20, 20);
    
    CTAssertEqual(test, newLabels->width, 20);
    CTAssertEqual(test, newLabels->height, 20);
    CTAssertEqual(test, newLabels->count, 0);
    CTAssertNotNull(test, newLabels->data);
    
    labelsfree(newLabels);
}

ctest_return_t test_labels_copy(ctest_t *test, void *arg) {
    labels_t *newLabels = labels(3, 3);
    newLabels->count = 5;
    newLabels->data[0] = 2;
    newLabels->data[1] = 1;
    newLabels->data[2] = 1;
    newLabels->data[3] = 1;
    newLabels->data[4] = 2;
    newLabels->data[5] = 2;
    newLabels->data[6] = 3;
    newLabels->data[7] = 3;
    newLabels->data[8] = 3;
    
    labels_t *newLabelsCopy = labelscpy(newLabels);
    
    CTAssertEqual(test, newLabelsCopy->width, newLabels->width);
    CTAssertEqual(test, newLabelsCopy->height, newLabels->height);
    CTAssertEqual(test, newLabelsCopy->count, newLabels->count);
    
    unsigned int i = 0;
    
    for (i = newLabels->width * newLabels->height; i--; ) {
        CTAssertEqual(test, newLabelsCopy->data[i], newLabels->data[i]);
    }
    
    labelsfree(newLabels);
    labelsfree(newLabelsCopy);
}

ctest_return_t test_labels_labelling(ctest_t *test, void *arg) {
    uint8_t firstReferenceImageData[25] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};
    unsigned int firstReferenceLabelsData[25] = {0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0};
    
    img_t *firstReferenceImage = img(5, 5, 1, sizeof(uint8_t));
    imgdcpy(firstReferenceImage, firstReferenceImageData);
    
    labels_t *firstLabels = label(firstReferenceImage);
    
    CTAssertEqual(test, firstLabels->count, 3);
    
    unsigned int i = 0;
    
    for (i = firstLabels->width * firstLabels->height; i--; ) {
        CTAssertEqual(test, firstLabels->data[i], firstReferenceLabelsData[i], "Label %d at index %d is not equal to %d\n", firstLabels->data[i], i, firstReferenceLabelsData[i]);
    }
    
    uint8_t secondReferenceImageData[49] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    unsigned int secondReferenceLabelsData[49] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0};
    
    img_t *secondReferenceImage = img(7, 7, 1, sizeof(uint8_t));
    imgdcpy(secondReferenceImage, secondReferenceImageData);
    
    labels_t *secondLabels = label(secondReferenceImage);
    
    CTAssertEqual(test, secondLabels->count, 5);
    
    for (i = secondLabels->width * secondLabels->height; i--; ) {
        CTAssertEqual(test, secondLabels->data[i], secondReferenceLabelsData[i], "Label %d at index %d is not equal to %d\n", secondLabels->data[i], i, secondReferenceLabelsData[i]);
    }
    
    imgfree(firstReferenceImage);
    labelsfree(firstLabels);
    imgfree(secondReferenceImage);
    labelsfree(secondLabels);
}

ctsuite_t *labelling_test_suite(void) {
    ctsuite_t *suite = ctsuite("labelling component");
    
    ctcase_t *labelsCreationTestCase = ctcase("labels creation");
    
    ctctestadd(labelsCreationTestCase, ctest("test_labels_creation", test_labels_creation, NULL));
    
    ctcase_t *labelsCopyTestCase = ctcase("labels copy");
    
    ctctestadd(labelsCopyTestCase, ctest("test_labels_copy", test_labels_copy, NULL));
    
    ctcase_t *labelsLabellingTestCase = ctcase("labels labelling");
    
    ctctestadd(labelsLabellingTestCase, ctest("test_labels_labelling", test_labels_labelling, NULL));
    
    ctscaseadd(suite, labelsCreationTestCase);
    ctscaseadd(suite, labelsCopyTestCase);
    ctscaseadd(suite, labelsLabellingTestCase);
    
    return suite;
}
