/**
 * @file sort.h
 * @author yuyimiao(com@baidu.com)
 * @date 2016/03/28 18:43:54
 * @brief 
 *  
 **/




#ifndef  __SORT_H_
#define  __SORT_H_

#define BUCKET_SIZE 20

/*insert sort: simple*/
void simple_insert_sort(int* input, int input_size);
void simple_insert_sort(int* input, int input_size, int k);
void insert(int* input, int value, int size);
void insert(int* input, int value, int size, int k);

/*insert sort: shell*/
void shell_sort(int* input, int input_size);

/*min sort: simple*/
void simple_min_sort(int* input, int input_size);
void simple_min_sort(int* input, int input_size, int k);
int min_pos(int* input, int input_size);
int min_pos(int* input, int input_size, int k);

/*min sort: heap*/
void heap_adjust(int* input, int input_size);
void heap_min_sort(int* input, int input_size);

/*swap sort: bubble*/
void swap(int* a, int* b);
void bubble_sort(int* input, int input_size);
void bubble_sort(int* input, int input_size, int k);

/*swap sort: quick*/
void quick_sort(int* input, int input_size);
void quick_sort(int* input, int input_size, int k);

/*group sort*/
void merge_sort(int* input, int input_size);

/*bucket sort*/
void bucket_sort(int* input, int input_size, int max_scale);


#endif  //__SORT_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
