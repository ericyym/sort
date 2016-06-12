/**
 * @file sort.cpp
 * @author yuyimiao(com@baidu.com)
 * @date 2016/03/28 19:05:32
 * @brief 
 *  
 **/

#include "sort.h"
#include "inc.h"
#include "math.h"
#include "string.h"

void swap(int* a, int* b) {
    if(0 == a && 0 == b) return;
    if(*a == *b) return;
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}

void insert(int* input, int value, int size, int k) {
    if(0 >= k) return;
    for(int i=size; i>0; i-=k) {
        input[i] = input[i-k];
    }
    input[0] = value;
}

void insert(int* input, int value, int size) {                    
    insert(input, value, size, 1);                                
} 

void simple_insert_sort(int* input, int input_size, int k) {
    if(0 == input) return;
    if(0 >= k) return;
    for(int i=k; i<input_size; i+=k) {
        for(int o=0; o<i; o+=k) {
            if(input[i] <= input[o]) {
                insert(input + o, input[i], i - o, k);
            }
        }
    }
}

void simple_insert_sort(int* input, int input_size) {             
    simple_insert_sort(input, input_size, 1);                     
} 

void shell_sort(int* input, int input_size) {
    if(0 == input) return;
    int k = input_size / 2 - 1;
    for(int i = k; i > 0; i--) {
        for(int j=0; j<input_size; j++) {
            simple_insert_sort(input + j, input_size - j, i);
        }
        print_vector(input, input_size);
    }
}

int min_pos(int* input, int input_size, int k) {  
    if(0 == input) return -1;
    int min_pos = 0;
    for(int i=0; i<input_size; i+=k) {
        if(input[min_pos] > input[i])
            min_pos = i;
    }
    return min_pos;
}

int min_pos(int* input, int input_size) {
    min_pos(input, input_size, 1);
}

void simple_min_sort(int* input, int input_size, int k) {
    if(0 == input) return;
    for(int i=0; i<input_size; i+=k) {
        int min_position = min_pos(input + i, input_size - i, k) + i;
        swap(input + i, input + min_position);
    }
}

void simple_min_sort(int* input, int input_size) {
    simple_min_sort(input, input_size, 1);
}

void heap_adjust(int* input, int input_size) {
    /*l=2*f; r=2*f+1*/
    /*father>left && father>right*/
    /*deep*/
    if(0 == input) return;
    int deep = (int)log2(input_size);
    for(int i=(int)pow(2, deep);i>0;i--) {
        int f = i / 2;
        int l = 2 * i + 1;
        if(input[f] > input[i])
            swap(input + f, input + i);
        if(l < input_size && input[f] > input[l])
            swap(input + f, input + l);
    }
}

void heap_min_sort(int* input, int input_size) {
    if(0 == input) return;
    for(int i=0; i<input_size; i+=1) {
        heap_adjust(input + i, input_size - i);
    }
}

void bubble_sort(int* input, int input_size, int k) {
    if(0 == input) return;
    for(int i=0; i<input_size; i+=k) {
        for(int j=0; j+k<input_size; j+=k) {
            if(input[j] > input[j + k])
                swap(input + j, input + j + k);
        }
    }
}

void bubble_sort(int* input, int input_size) {
    bubble_sort(input, input_size, 1);
}

void quick_sort(int* input, int input_size, int k) {
    if(0 == input || 1 >= input_size) return;
    int ref = *input;
    int ref_idx = 0;
    int for_idx = 0;
    int bak_idx = input_size - 1;

    /*swap order: for_idx, bak_idx*/
    while(for_idx < bak_idx) {
        for_idx = 0;
        bak_idx = input_size - 1;
        while(input[bak_idx] > ref && bak_idx > for_idx) {
            bak_idx--;
        }
        while(input[for_idx] < ref && bak_idx > for_idx) {
            for_idx++;
        }
        swap(input + for_idx, input + bak_idx);

        /*update ref_idx*/
        if(ref_idx == for_idx) {
            ref_idx = bak_idx;
        }
        else if(ref_idx == bak_idx) {
            ref_idx = for_idx;
        }
    }
    quick_sort(input, ref_idx, k);
    quick_sort(input + ref_idx + 1, input_size - ref_idx - 1, k); 
}

void quick_sort(int* input, int input_size) {
    quick_sort(input, input_size, 1);
}

void swap_ptr(int* a, int* b) {
    int* tmp;
    tmp = a;
    a = b;
    b = tmp;
    tmp = 0;
}

void merge_sort(int* input, int input_size) {
    /*group:{{left},{right}}*/
    /*g_step=2*(g_step+1)*/
    /*while(ptr1,ptr2,ptr3){if()ptr1++;if()ptr2++,ptr3++}*/
    if(0 == input || 1 >= input_size) return;
    int* output = new int[input_size];
    for(int g_step=2; g_step<=input_size; g_step=2*g_step) {
        for(int i=0; i<input_size; i+=g_step) {
            int l_ptr = i;
            int r_ptr = i + g_step/2;
            int o_ptr = i;
            while(i + g_step/2 > l_ptr && i + g_step > r_ptr) {
                if(input[l_ptr] < input[r_ptr]) {
                    output[o_ptr] = input[l_ptr];
                    l_ptr++;
                }
                else {
                    output[o_ptr] = input[r_ptr];
                    r_ptr++;
                }
                o_ptr++;
            }
            for(int j=l_ptr; j<i+g_step/2; j++) {
                output[o_ptr] = input[j];
                o_ptr++;
            }
            for(int j=r_ptr; j<i+g_step; j++) {
                output[o_ptr] = input[j];
                o_ptr++;
            }
        }
        for(int i=0; i<input_size; i++) {
            input[i] = output[i];
        }
    }
    delete output;
    output = 0;
}

void bucket_sort(int* input, int input_size, int max_scale) {
    if(0 == input || 1 >= input_size) return;

    //bucket begin
    int buckets[10][BUCKET_SIZE] = {0};
    int level[10] = {0};
    //endof bucket

    int scale = 0;
    while(scale < max_scale) {
        for(int i=0; i<input_size; i++) {
            int buck = (input[i] / ((int)pow(10, scale))) % 10;
            buckets[buck][level[buck]] = input[i];
            level[buck]++;
        }
        int inc = 0;
        for(int i=0; i<10; i++) {
            for(int j=0; j<level[i]; j++) {
                input[inc] = buckets[i][j];
                inc++;
            }
        }
        for(int i=0; i<10; i++) {
            level[i] = 0;
        }
        scale++;
    }
}



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
