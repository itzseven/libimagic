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

ctcase_return_t test_labels_creation() {
    labels_t *newLabels = labels(20, 20);
    
    CTAssertEqual(newLabels->width, 20);
    CTAssertEqual(newLabels->height, 20);
    CTAssertEqual(newLabels->count, 0);
    CTAssertNotNull(newLabels->data);
    
    return CTPassed;
}

ctcase_return_t test_labels_copy() {
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
    
    CTAssertEqual(newLabelsCopy->width, newLabels->width);
    CTAssertEqual(newLabelsCopy->height, newLabels->height);
    CTAssertEqual(newLabelsCopy->count, newLabels->count);
    
    unsigned int i = 0;
    
    for (i = newLabels->width * newLabels->height; i--; ) {
        CTAssertEqual(newLabelsCopy->data[i], newLabels->data[i]);
    }
    
    return CTPassed;
}

ctcase_return_t test_labels_labelling() {
    uint8_t firstReferenceImageData[25] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};
    unsigned int firstReferenceLabelsData[25] = {0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0};
    
    img_t *firstReferenceImage = img(5, 5, 1, sizeof(uint8_t));
    imgdcpy(firstReferenceImage, firstReferenceImageData);
    
    labels_t *firstLabels = label(firstReferenceImage);
    
    CTAssertEqual(firstLabels->count, 3);
    
    unsigned int i = 0;
    
    for (i = firstLabels->width * firstLabels->height; i--; ) {
        CTAssertEqual(firstLabels->data[i], firstReferenceLabelsData[i], "Label %d at index %d is not equal to %d\n", firstLabels->data[i], i, firstReferenceLabelsData[i]);
    }
    
    uint8_t secondReferenceImageData[49] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    unsigned int secondReferenceLabelsData[49] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0};
    
    img_t *secondReferenceImage = img(7, 7, 1, sizeof(uint8_t));
    imgdcpy(secondReferenceImage, secondReferenceImageData);
    
    labels_t *secondLabels = label(secondReferenceImage);
    
    CTAssertEqual(secondLabels->count, 5);
    
    for (i = secondLabels->width * secondLabels->height; i--; ) {
        CTAssertEqual(secondLabels->data[i], secondReferenceLabelsData[i], "Label %d at index %d is not equal to %d\n", secondLabels->data[i], i, secondReferenceLabelsData[i]);
    }
    
    return CTPassed;
}

ctsuite_t *labelling_test_suite() {
    ctsuite_t *suite = ctsuite("labelling component");
    
    ctsaddtc(ctcase("test_labels_creation", test_labels_creation), suite);
    ctsaddtc(ctcase("test_labels_copy", test_labels_copy), suite);
    ctsaddtc(ctcase("test_labels_labelling", test_labels_labelling), suite);
    
    return suite;
}
