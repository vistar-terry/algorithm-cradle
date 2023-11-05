#include <stdio.h>
#include "array.h"

int main()
{
    printf("*********** pure C ***********\n");
    int* arr;
    if (init_array(&arr, MAX_LEN))
    {
        for (int i = 0; i < MAX_LEN; i++)
        {
            arr[i] = i;
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    printf("\n******* Object Oriented *******\n");
    Array array;
    if (initArray(&array, MAX_LEN))
    {
        for (int i = 0; i < 7; i++)
        {
            array.pData[i] = i;
            array.length++;
        }
        printArray(&array);
    }

    insertBack(&array, 1);
    printArray(&array);

    insert(&array, 3, 89);
    printArray(&array);

    removeWithIndex(&array, 2);
    printArray(&array);

    removeWithValue(&array, 1);
    printArray(&array);


    return 0;
}
