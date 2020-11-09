#include <stdio.h>

struct Table{
    int * head;     //声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length;     //记录当前顺序表的长度
    int size;       //记录顺序表分配的存储容量
};

int main(int argc, char* argv[]){
    int i = 0;
    int arr[3] = {0};
    for(; i<=3; i++){
        arr[i] = 0;
        printf("hello world\n");
    }
    return 0;
}
