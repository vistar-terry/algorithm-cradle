#include <stdio.h>

// 全局域创建数组
int num1[3];
int num5[3] = {1};

void array()
{
    // 自定义函数局部域
    int num3[3];
    int num4[3] = {1};
    printf("自定义函数num3[1]: %d\n", num3[1]);
    printf("\n打印数组创建时初始化，未被初始化的元素\n");
    printf("自定义函数num4[1]: %d\n", num4[1]);
}

int main()
{
    printf("打印数组创建时未初始化，数组的元素\n");
    printf("全局域num1[1]: %d\n", num1[1]);
    int num2[3];
    printf("main函数num2[1]: %d\n", num2[1]);

    array();
    
    printf("全局域num5[1]: %d\n", num5[1]);
    int num6[3] = {1};
    printf("main函数num6[1]: %d\n", num6[1]);
    
    return 0;
}