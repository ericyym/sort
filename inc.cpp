/**
 * @file inc.cpp
 * @author yuyimiao(com@baidu.com)
 * @date 2016/03/28 18:34:14
 * @brief 
 *  
 **/

#include "inc.h"
#include <stdio.h>



void print_vector(int* vector, int vector_size) {                 
    if(0 == vector) return;                                       
    for(int i=0; i<vector_size; i++) {                            
        printf("%d ", vector[i]);                                 
    }                                                             
    printf("\n");                                                 
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
