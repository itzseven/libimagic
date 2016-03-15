//
//  opticalflow.c
//  imagic
//
//  Created by Adrien on 23/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "opticalflow.h"

vec2d_t* optical_flow(gray8i_t image1, gray8i_t image2) {
    
    vec2d_t* result;    // The speed vectors array
    int16_t* pdX;       // The array of partial derivatives on X
    int16_t* pdY;       // The array of partial derivatives on Y
    int16_t* pdT;       // The array of partial derivatives on Time
    
    
    // Initializes the speed vectors array
    result = gray8ialloc(image1.width, image2.height);
    
    
    // *************************************
    // **** Deduces partial derivatives ****
    // *************************************
    
    // Allocate partial derivatives table
    
    
}
