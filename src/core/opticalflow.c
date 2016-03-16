//
//  opticalflow.c
//  imagic
//
//  Created by Adrien on 23/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "opticalflow.h"

vect2darray_t *opticalflow(gray8i_t *image1, gray8i_t *image2) {
    
    // Variables
    uint32_t i=0, j=0, k=0, t=0;
    uint16_t width = image1->width;         // The images width
    uint16_t height = image1->height;       // The images height
    uint32_t pixel_count = width*height;    // The images pixels count
    vect2darray_t *result;                  // The speed vectors array
    vect2darray_t *tmp_result;              // The temporary speed vectors array
    int32_t* pdX;                           // The array of partial derivatives on X
    int32_t* pdY;                           // The array of partial derivatives on Y
    int32_t* pdT;                           // The array of partial derivatives on Time
    double average_x_speed = 0;             // The average speed on X
    double average_y_speed = 0;             // The average speed on Y
    double reason = 0;                      // The reason of the H&S solution numeric suite
    double alpha = 100;                     // The empiric parameter of the H&S solution
    
    // Initializes the speed vectors arrays
    result = vect2arralloc(pixel_count);
    tmp_result = vect2arralloc(pixel_count);
    
    // Initializes partial derivatives arrays
    pdX = (int32_t *)calloc(pixel_count, sizeof(int32_t));
    pdY = (int32_t *)calloc(pixel_count, sizeof(int32_t));
    pdT = (int32_t *)calloc(pixel_count, sizeof(int32_t));
    
    // Defines values of Partial Derivatives arrays
    int32_t pdX_value;
    int32_t pdY_value;
    int32_t pdT_value;
    
    // Defines the images pixels
    uint8_t image1_i__j;
    uint8_t image1_i__j_add1;
    uint8_t image1_i_add1__j;
    uint8_t image1_i_add1__j_add1;
    
    uint8_t image2_i__j;
    uint8_t image2_i__j_add1;
    uint8_t image2_i_add1__j;
    uint8_t image2_i_add1__j_add1;
    
    // Defines values of Speed Vectors array
    vect2d_t vec_i__j_less1;
    vect2d_t vec_i_add1__j;
    vect2d_t vec_i__j_add1;
    vect2d_t vec_i_less1__j;
    
    vect2d_t vec_i_less1__j_less1;
    vect2d_t vec_i_add1__j_less1;
    vect2d_t vec_i_add1__j_add1;
    vect2d_t vec_i_less1__j_add1;

    // First iteration, with partial derivatives deduction
    for (i = 0; i < height-1; i++) {
        for (j = 0; j < width-1; j++) {
            
            // Index for arrays
            uint32_t arrayIndex = PXL_IDX(width, j, i);
            
            // *************************************
            // **** Deduces partial derivatives ****
            // *************************************
            //
            // WARNING (needs tests results to put this WARNING on) :
            //      Y axe is reversed in the H&S article, so to avoid issues, we will
            //      use "table[i] and table[i-1]" instead of "table[i] and table[i+1]".
            //      This way we keep the same axes than H&S.
            //
            
            image1_i__j             = image1->data[arrayIndex];
            image1_i__j_add1        = image1->data[PXL_IDX(width, j+1, i)];
            image1_i_add1__j        = image1->data[PXL_IDX(width, j, i+1)];
            image1_i_add1__j_add1   = image1->data[PXL_IDX(width, j+1, i+1)];
            
            image2_i__j             = image2->data[PXL_IDX(width, j, i)];
            image2_i__j_add1        = image2->data[PXL_IDX(width, j+1, i)];
            image2_i_add1__j        = image2->data[PXL_IDX(width, j, i+1)];
            image2_i_add1__j_add1   = image2->data[PXL_IDX(width, j+1, i+1)];
            
            pdX_value = (image1_i__j_add1 - image1_i__j
                        + image1_i_add1__j_add1 - image1_i_add1__j
                        + image2_i__j_add1 - image2_i__j
                        + image2_i_add1__j_add1 - image2_i_add1__j) / 4;
            
            pdX[arrayIndex] = pdX_value;
            
            
            pdY_value = (image1_i_add1__j - image1_i__j
                        + image1_i_add1__j_add1 - image1_i__j_add1
                        + image2_i_add1__j - image2_i__j
                        + image2_i_add1__j_add1 - image2_i__j_add1) / 4;
            
            pdY[arrayIndex] = pdY_value;
            
            
            pdT_value = (image2_i__j - image1_i__j
                        + image2_i__j_add1 - image1_i__j_add1
                        + image2_i_add1__j - image1_i_add1__j
                        + image2_i_add1__j_add1 - image1_i_add1__j_add1) / 4;
            
            pdT[arrayIndex] = pdT_value;
            
            
            // *************************************
            // ******* Deduces average speed *******
            // *************************************
            // At the first iteration, average speeds are 0 as the speed vectors array is initialized.
            
            // *************************************
            // * Deduces new speed vectors values **
            // *************************************
            reason = pdT_value / (alpha*alpha + pdX_value*pdX_value + pdY_value*pdY_value);
            
            result->data[arrayIndex].x = -pdX_value * reason;
            result->data[arrayIndex].y = -pdY_value * reason;
            
        }
    }
    
    // Next iterations until ITERATION Constant
    for (k = 0; k < ITERATION-1; k++) {
        
        for (i = 1; i < height-1; i++) {
            for (j = 1; j < width-1; j++) {
                
                // Retrieves speed vectors values from the array
                
                vec_i__j_less1          = result->data[PXL_IDX(width, j-1, i)];
                vec_i_add1__j           = result->data[PXL_IDX(width, j, i+1)];
                vec_i__j_add1           = result->data[PXL_IDX(width, j+1, i)];
                vec_i_less1__j          = result->data[PXL_IDX(width, j, i-1)];

                vec_i_less1__j_less1    = result->data[PXL_IDX(width, j-1, i-1)];
                vec_i_add1__j_less1     = result->data[PXL_IDX(width, j-1, i+1)];
                vec_i_add1__j_add1      = result->data[PXL_IDX(width, j+1, i+1)];
                vec_i_less1__j_add1     = result->data[PXL_IDX(width, j+1, i-1)];
                
                // *************************************
                // ******* Deduces average speed *******
                // *************************************
                
                average_x_speed =   (vec_i_less1__j.x
                                    + vec_i__j_add1.x
                                    + vec_i_add1__j.x
                                    + vec_i__j_less1.x) / 6
                                +
                                    (vec_i_less1__j_less1.x
                                     + vec_i_less1__j_add1.x
                                     + vec_i_add1__j_add1.x
                                     + vec_i_add1__j_less1.x) / 12;
                
                average_y_speed =   (vec_i_less1__j.y
                                     + vec_i__j_add1.y
                                     + vec_i_add1__j.y
                                     + vec_i__j_less1.y) / 6
                                +
                                    (vec_i_less1__j_less1.y
                                     + vec_i_less1__j_add1.y
                                     + vec_i_add1__j_add1.y
                                     + vec_i_add1__j_less1.y) / 12;
                
                // *************************************
                // * Deduces new speed vectors values **
                // *************************************
                uint32_t arrayIndex = PXL_IDX(width, j, i);
                pdX_value = pdX[arrayIndex];
                pdY_value = pdY[arrayIndex];
                pdT_value = pdT[arrayIndex];
                
                reason = (pdX_value * average_x_speed + pdY_value * average_y_speed + pdT_value) /
                            (alpha*alpha + pdX_value*pdX_value + pdY_value*pdY_value);
                
                tmp_result->data[arrayIndex].x = average_x_speed - pdX_value * reason;
                tmp_result->data[arrayIndex].y = average_y_speed - pdY_value * reason;
            }
        }
        
        // Copy tmp_result in result
        //memcpy(result, tmp_result, width*height);
        for (t = 0; t < pixel_count; t++) {
            result->data[t] = tmp_result->data[t];
        }
    }
    
    // Frees memory
    free(pdX);
    free(pdY);
    free(pdT);
    free(tmp_result);
    
    return result;
}
