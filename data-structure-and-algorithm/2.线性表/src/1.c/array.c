#include <stdio.h>
#include "array.h"


bool init_array(int** arr_ad, int size)
{
    *arr_ad = (int*)malloc(size * sizeof(int));

    if (*arr_ad == NULL)
    {
        return false;
    }
    
    return true;
}

bool initArray(Array* array, int size)
{
    array->pData = (int*)malloc(size * sizeof(int));
    array->maxSize = size;
    array->length = 0;

    if (array->pData == NULL)
    {
        return false;
    }
    
    return true;
}

bool printArray(Array* array)
{
    if (array == NULL || array->pData == NULL || array->length > array->maxSize)
    {
        return false;
    }

    for (int i = 0; i < array->length; i++)
    {
        printf("%d ", array->pData[i]);
    }
    printf("\n");

    return true;
}

bool insertBack(Array* array, int num)
{
    if (array == NULL || array->pData == NULL || array->length > array->maxSize)
    {
        return false;
    }

    array->pData[array->length] = num;
    array->length++;

    return true;
}

bool insert(Array* array, int index, int num)
{
    if (array == NULL || array->pData == NULL || array->length > array->maxSize)
    {
        return false;
    }

    for (int i = array->length; i > index; i--)
    {
        array->pData[i] = array->pData[i-1];
    }
    array->length++;
    array->pData[index] = num;

    return true;
}

bool removeWithIndex(Array* array, int index)
{
    if (array == NULL || array->pData == NULL || array->length > array->maxSize)
    {
        return false;
    }

    for (int i = index+1; i < array->length; i++)
    {
        array->pData[i-1] = array->pData[i];
    }
    array->length--;

    return true;
}

bool removeWithValue(Array* array, int value)
{
    if (array == NULL || array->pData == NULL || array->length > array->maxSize)
    {
        return false;
    }

    int tmpArray[array->length];
    int j = 0;
    for (int i = 0; i < array->length; i++)
    {
        if (array->pData[i] == value)
        {
            continue;
        }
        tmpArray[j++] = array->pData[i];
    }
    array->pData = tmpArray;
    array->length = j;

    return true;
}

