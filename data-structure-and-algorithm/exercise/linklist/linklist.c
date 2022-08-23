#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

// 初始化链表
node* initial_nohead_null();
node* initial_head_null();
node* initial_head_arglist(int num_of_data, ...);

// 链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
node* insertElem(node* p_head, int elem, int add);
// 删除结点的函数，p代表操作链表，add代表删除节点的位置
node* delElem(node* p_head, int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(node* p_head, int elem);
// 更新结点的函数，newElem为新的数据域的值
node* amendElem(node* p_head, int add, int newElem);
void display(node* p_head);

int main()
{
    //初始化链表
    {    
        printf("初始化无头空链表: ");
        node* p_head = initial_nohead_null();
        display(p_head);
        printf("address: %p\n", p_head);
    }

    {       
        printf("初始化有头空链表: ");
        node* p_head = initial_head_null();
        display(p_head);
        printf("address: %p\n", p_head);
    }

    {
        printf("arglist初始化链表: ");
        node* p_head = initial_head_arglist(4, 7, 9, 90, 89);
        display(p_head);
        printf("address: %p\n", p_head);
    }

    // int num, pos;
    // printf("输入插入元素：");
    // scanf("%d", &num);
    // printf("输入插入位置：");
    // scanf("%d", &pos);
    // printf("在位置%d插入元素%d：", pos, num);
    // p_head = insertElem(p_head, num, pos);
    // display(p_head);

    // printf("删除元素3:\n");
    // p_head = delElem(p_head, 3);
    // display(p_head);

    // printf("查找元素2的位置为：\n");
    // int address = selectElem(p_head, 2);
    // if (address == -1) {
    //     printf("没有该元素");
    // }
    // else {
    //     printf("元素2的位置为：%d\n", address);
    // }
    // printf("更改第3的位置上的数据为7:\n");
    // p_head = amendElem(p_head, 3, 7);
    // display(p_head);

    return 0;
}

node* initial_nohead_null()
{
    node* head = NULL; // head为头指针

    return head;
}

node* initial_head_null()
{
    node* head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    head->data = 0;
    head->next = NULL;

    return head;
}

// 利用不定参数初始化链表
node* initial_head_arglist(int num_of_data, ...)
{
    va_list arg_list;
    va_start(arg_list, num_of_data);
    node* head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    head->data = num_of_data;
    head->next = NULL;
    node* it = head; // 创建一个指针指向头结点，用于遍历链表

    // 为链表添加节点
    for (int i = 0; i < num_of_data; i++)
    {
        node* tmp = (node* )malloc(sizeof(node));
        tmp->data = va_arg(arg_list, int);
        tmp->next = NULL;
        it->next = tmp;
        it = it->next;
    }
    va_end(arg_list);
    return head;
}

node* insertElem(node* p_head, int elem, int add)
{
    node* temp = p_head; //创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 0; i < add; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p_head;
        }
    }
    //创建插入结点c
    node* c = (node* )malloc(sizeof(node));
    c->data = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p_head;
}

node* delElem(node* p_head, int add)
{
    node* temp = p_head;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("没有该结点\n");
            return p_head;
        }
    }
    node* del = temp->next;        //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     //手动释放该结点，防止内存泄漏
    return p_head;
}

int selectElem(node* p_head, int elem)
{
    node* t = p_head;
    int i = 1;
    while (t->next)
    {
        t = t->next;
        if (t->data == elem)
        {
            return i;
        }
        i++;
    }
    return -1;
}

node* amendElem(node* p_head, int add, int newElem)
{
    node* temp = p_head;
    temp = temp->next; // tamp指向首元结点
    // temp指向被删除结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->data = newElem;
    return p_head;
}

void display(node* p_head)
{
    // 如果头指针为NULL，直接返回
    if (NULL == p_head || 0 == p_head->data)
    {
        printf("\n");
        return;
    }

    node* temp = p_head; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}