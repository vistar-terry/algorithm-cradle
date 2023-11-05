#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>

#define false 0
#define true 1
typedef int bool;

#define MAX_LEN 10

typedef struct
{
	int* pData;		// 数组的首地址
	int  length;    // 数组的当前长度  
    int  maxSize;   // 数组最大容量大小
} Array;


extern bool init_array(int** arr_ad, int size);

extern bool initArray(Array* array, int size);
extern bool printArray(Array* array);
extern bool insertBack(Array* array, int num);
extern bool insert(Array* array, int index, int num);
extern bool removeWithIndex(Array* array, int index);
extern bool removeWithValue(Array* array, int value);


#endif