//
//  edge_tests.c
//  imagic
//
//  Created by Romain Dubreucq on 06/02/2016.
//  Copyright © 2016 Romain Dubreucq. All rights reserved.
//

#include "edge_tests.h"

int edge_tests_passed;
int edge_tests_failed;

void test_grad_alloc()
{
    puts("Starts test_grad_alloc\n");
    
    uint16_t width = 20, height = 20;
    
    grad_t *grad = gradalloc(width, height);
    
    if (grad->len == (width * height))
    {
        int i = 0;
        
        for (i = 0; i < grad->len; i++)
        {
            if ((grad->hor[i] != 0) || (grad->ver[i] != 0) || (grad->mag[i] != 0.f))
            {
                printf("test_grad_alloc failed : expected values (%d, %d, %f) but got (%d, %d, %f) on %d\n", 0, 0, 0.2f, grad->hor[i], grad->ver[i], grad->mag[i], i);
                edge_tests_failed++;
                gradfree(grad);
                return;
            }
        }
    }
    
    else
    {
        printf("test_grad_alloc failed : expected length %d and got %d\n", width * height, grad->len);
        edge_tests_failed++;
        gradfree(grad);
        return;
    }
    
    puts("test_grad_alloc passed\n");
    edge_tests_passed++;
    gradfree(grad);
}

void test_grdsobel()
{
    puts("Starts test_grdsobel\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gX[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 0, -255, -255, 0, 0, 765, 765, 0, -765, -765, 0, 0, 1020, 1020, 0, -1020, -1020, 0, 0, 765, 765, 0, -765, -765, 0, 0, 255, 255, 0, -255, -255, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gY[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 765, 1020, 765, 255, 0, 0, 255, 765, 1020, 765, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, -255, -765, -1020, -765, -255, 0, 0, -255, -765, -1020, -765, -255, 0, 0, 0, 0, 0, 0, 0, 0};
    
    float mag[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 360.624451, 806.380798, 1020.0, 806.380798, 360.624451, 0.0, 0.0, 806.380798, 1081.873413, 1020.0, 1081.873413, 806.380798, 0.0, 0.0, 1020.0, 1020.0, 0.0, 1020.0, 1020.0, 0.0, 0.0, 806.380798, 1081.873413, 1020.0, 1081.873413, 806.380798, 0.0, 0.0, 360.624451, 806.380798, 1020.0, 806.380798, 360.624451, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    grad_t *sobel = grdsobel(img);
    
    int i = 0;
    
    for (i = 0; i < sobel->len; i++)
    {
        if ((sobel->hor[i] != gX[i]) || (sobel->ver[i] != gY[i]) || (sobel->mag[i] != mag[i]))
        {
            printf("test_grdsobel failed : expected values (%d, %d, %f) but got (%d, %d, %f) on %d\n", gX[i], gY[i], mag[i], sobel->hor[i], sobel->ver[i], sobel->mag[i], i);
            edge_tests_failed++;
            gradfree(sobel);
            gray8ifree(img);
            return;
        }
    }
    
    puts("test_grdsobel passed\n");
    edge_tests_passed++;
    gradfree(sobel);
    gray8ifree(img);
}

void test_grdprewitt()
{
    puts("Starts test_grdprewitt\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gX[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 0, -255, -255, 0, 0, 510, 510, 0, -510, -510, 0, 0, 765, 765, 0, -765, -765, 0, 0, 510, 510, 0, -510, -510, 0, 0, 255, 255, 0, -255, -255, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gY[] = {0, 0, 0, 0, 0, 0, 0, 0, 255, 510, 765, 510, 255, 0, 0, 255, 510, 765, 510, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, -255, -510, -765, -510, -255, 0, 0, -255, -510, -765, -510, -255, 0, 0, 0, 0, 0, 0, 0, 0};
    
    float mag[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 360.624451, 570.197327, 765.0, 570.197327, 360.624451, 0.0, 0.0, 570.197327, 721.248901, 765.0, 721.248901, 570.197327, 0.0, 0.0, 765.0, 765.0, 0.0, 765.0, 765.0, 0.0, 0.0, 570.197327, 721.248901, 765.0, 721.248901, 570.197327, 0.0, 0.0, 360.624451, 570.197327, 765.0, 570.197327, 360.624451, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    grad_t *prewitt = grdprewitt(img);
    
    int i = 0;
    
    for (i = 0; i < prewitt->len; i++)
    {
        if ((prewitt->hor[i] != gX[i]) || (prewitt->ver[i] != gY[i]) || (prewitt->mag[i] != mag[i]))
        {
            printf("test_grdprewitt failed : expected values (%d, %d, %f) but got (%d, %d, %f) on %d\n", gX[i], gY[i], mag[i], prewitt->hor[i], prewitt->ver[i], prewitt->mag[i], i);
            edge_tests_failed++;
            gradfree(prewitt);
            gray8ifree(img);
            return;
        }
    }
    
    puts("test_grdprewitt passed\n");
    edge_tests_passed++;
    gradfree(prewitt);
    gray8ifree(img);
}

void test_grdderiv()
{
    puts("Starts test_grdderiv\n");
    
    uint16_t width = 7, height = 7;
    
    uint8_t data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gX[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, -255, 0, 0, 0, 255, 0, 0, -255, 0, 0, 0, 255, 0, 0, -255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int gY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -255, -255, -255, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    float mag[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 360.624451, 255.0, 255.0, 255.0, 0.0, 0.0, 0.0, 255.0, 0.0, 0.0, 255.0, 0.0, 0.0, 0.0, 255.0, 0.0, 0.0, 255.0, 0.0, 0.0, 0.0, 255.0, 255.0, 255.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    gray8i_t *img = gray8iallocwd(width, height, data);
    
    grad_t *deriv = grdderiv(img);
    
    int i = 0;
    
    for (i = 0; i < deriv->len; i++)
    {
        if ((deriv->hor[i] != gX[i]) || (deriv->ver[i] != gY[i]) || (deriv->mag[i] != mag[i]))
        {
            printf("test_grdderiv failed : expected values (%d, %d, %f) but got (%d, %d, %f) on %d\n", gX[i], gY[i], mag[i], deriv->hor[i], deriv->ver[i], deriv->mag[i], i);
            edge_tests_failed++;
            gradfree(deriv);
            gray8ifree(img);
            return;
        }
    }
    
    puts("test_grdderiv passed\n");
    edge_tests_passed++;
    gradfree(deriv);
    gray8ifree(img);
}
