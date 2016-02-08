//
//  edge.h
//  imagic
//
//  Created by itzseven on 03/02/2016.
//  Copyright © 2016 itzseven. All rights reserved.
//

#ifndef edge_h
#define edge_h

#include <math.h>

#include "core.h"

/*!
 *  Use the following macro to calculate a specific gradient using the value of the pixels at the neighborhood
 */

#define H_SOBEL(jp1_im1, jp1_ip1, jp1_i, jm1_im1, jm1_ip1, jm1_i) (jp1_im1 + jp1_ip1 + (2 * jp1_i) - (jm1_im1 + jm1_ip1 + (2 * jm1_i)))

#define V_SOBEL(jm1_ip1, jp1_ip1, j_ip1, jm1_im1, jp1_im1, j_im1) (jm1_ip1 + jp1_ip1 + (2 * j_ip1) - (jm1_im1 + jp1_im1 + (2 * j_im1)))

#define H_PREWITT(jp1_im1, jp1_ip1, jp1_i, jm1_im1, jm1_ip1, jm1_i) (jp1_im1 + jp1_ip1 + jp1_i - (jm1_im1 + jm1_ip1 + jm1_i))

#define V_PREWITT(jm1_ip1, jp1_ip1, j_ip1, jm1_im1, jp1_im1, j_im1) (jm1_ip1 + jp1_ip1 + j_ip1 - (jm1_im1 + jp1_im1 + j_im1))

/*!
 *  Data type that stores the horizontal (Gx), vertical (Gy) and gradient magnitude (|G(Gx, Gy)|) values :
 *
 *  - hor struct member stores the values of Gx
 *  - ver struct member stores the values of Gy
 *  - mag struct member stores the values of |G(Gx, Gy)|
 */

typedef struct _grad {
    uint32_t len;
    int *hor;
    int *ver;
    float *mag;
}grad_t;

/*!
 *  Returns an initialized grad_t object (with length width x height) with allocated data set to 0
 */

grad_t *gradalloc(uint16_t width, uint16_t height);

/*!
 *  Calculates the gradient by using a Sobel mask (I is the source image) :
 *
 *       -1  0  1                 -1  -2  -1
 *  Gx = -2  0  2  *  I      Gy =  0   0   0  * I       and G = √(Gx² + Gy²)
 *       -1  0  1                  1   2   1
 */

grad_t *grdsobel(gray8i_t *src);

/*!
 *  Calculates the gradient by using a Prewitt mask (I is the source image) :
 *
 *       -1  0  1                 -1  -1  -1
 *  Gx = -1  0  1  *  I      Gy =  0   0   0  * I       and G = √(Gx² + Gy²)
 *       -1  0  1                  1   1   1
 */

grad_t *grdprewitt(gray8i_t *src);

/*!
 *  Calculates the gradient by using simple derivatives (I is the source image) :
 *
 *  Ix'(x, y) = I(x, y) - I(x - 1, y)       and     Iy'(x, y) = I(x, y) - I(x, y - 1)
 *
 */

grad_t *grdderiv(gray8i_t *src);

/*!
 *  Frees the memory of an grad object
 */

void gradfree(grad_t *grad);

#endif /* edge_h */
