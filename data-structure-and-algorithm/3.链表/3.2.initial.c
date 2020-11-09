#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *initLinkList0();
void display(node *);

int main()
{
    node *p = initLinkList();
    // printf("%p\n", p);
    display(p);
    return 0;
}

// 不带头结点的空链表
node *initLinkList0()
{
    // 创建头指针，用于指示链表的存储位置
    node *head = NULL;
    return head;
}

node *insertNode(node* p, int data, int loc){
    
}

// 带头结点的空链表
node *initLinkList1()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}

// 带头结点的非空链表(头插法)
node *initLinkList()
{
    node *head = (node *)malloc(sizeof(node)); //头指针与头结点
    head->next = NULL;
    //头插法建立链表
    for (int i = 0; i < 5; i++)
    {
        node *a = (node *)malloc(sizeof(node));
        a->data = i;
        a->next = head->next;
        head->next = a;
    }
    return head;
}

// 带头结点的非空链表(尾插法)
node *initLinkList3()
{
    node *head = (node *)malloc(sizeof(node)); //头指针与头结点
    node *tail = head;                         //尾指针
    //尾插法建立链表
    for (int i = 0; i < 5; i++)
    {
        node *a = (node *)malloc(sizeof(node));
        a->data = i;
        tail->next = a;
        tail = a;
    }
    tail->next = NULL;
    return head;
}

// 打印链表
void display(node *p)
{
    node *temp = p; //将temp游标指针指向头结点
    //只要temp指针指向的结点的next不是NULL，就执行输出语句
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}