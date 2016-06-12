/**
 * @file simple_insert.cpp
 * @author yuyimiao(com@baidu.com)
 * @date 2016/03/28 18:10:03
 * @brief 
 *  
 **/

#include "inc.h"
#include "sort.h"
#include <stdio.h>

int main(void) {
    printf("main begin\n");
    int input[] = {3, 7, 34, 15, 1, 28, 46, 9};
    print_vector(input, 8);
    // @todo:
    //simple_insert_sort(input, 8);
    //simple_insert_sort(input, 8, 2);
    //shell_sort(input, 8);
    //simple_min_sort(input, 8);
    heap_min_sort(input, 8);
    //swap(input + 2, input + 5);
    //bubble_sort(input, 8, 1);
    //quick_sort(input, 8);
    //merge_sort(input, 8);
    //bucket_sort(input, 8, 2);

    print_vector(input, 8);
    printf("endof main\n");
    return 1;
}
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
