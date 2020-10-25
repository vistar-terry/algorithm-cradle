#include <stdio.h>
#include <stdlib.h>

//链表中节点的结构
typedef struct Link
{
    int elem;
    struct Link *next;
} link;

//初始化链表的函数
link *initLink();
//用于输出链表的函数
void display(link *p);

int main()
{
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p = initLink();
    display(p);
    return 0;
}

link *initLink()
{
    link *p = NULL;                            //创建头指针
    link *temp = (link *)malloc(sizeof(link)); //创建首元节点
    //首元节点先初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp; //头指针指向首元节点
    for (int i = 2; i < 5; i++)
    {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

void display(link *p)
{
    link *temp = p; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp)
    {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
