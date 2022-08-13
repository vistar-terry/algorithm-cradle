#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
typedef int bool;

const int MAX_LEN = 10;

bool init_array(int** arr_ad, int size)
{
    *arr_ad = (int*)malloc(size * sizeof(int));

    if (*arr_ad == NULL)
    {
        return false;
    }
    
    return true;
}


int main()
{
    int* arr;
    if (init_array(&arr, MAX_LEN))
    {
        for (int i = 0; i < MAX_LEN; i++)
        {
            arr[i] = i;
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    return 0;
}

