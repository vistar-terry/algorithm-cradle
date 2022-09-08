/**
 * @file: linklist.c
 * @brief: 链表相关函数
 * @author: 万俟淋曦(1055311345@qq.com)
 * @date: 2022-08-13 12:27:24
 * @modifier: 万俟淋曦(1055311345@qq.com)
 * @date: 2022-08-27 22:33:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

// 链表节点
typedef struct Node
{
    int data;
    struct Node* next;
} node;

typedef struct Array
{
    int size;
    int* array;
} array;


// 初始化链表
node* initial_nohead_null();
node* initial_head_null();
node* initial_head_arglist_h(int num_of_data, ...);
node* initial_head_arglist_t(int num_of_data, ...);
node* initial_head_array_h(int size, int* p_array);
node* initial_head_array_t(int size, int* p_array);

/**
 * @brief: 链表插入元素，通过位置索引
 * @param[in] p_head: 要执行插入操作的链表头指针
 * @param[in] pos: 要插入元素的位置
 * @param[in] data: 要插入元素的值
 * @return bool: 执行结果
 */
bool insert_pos(node* p_head, int pos, int data);

/**
 * @brief: 按索引删除节点
 * @param[in] p_head: 要执行删除操作的链表头指针
 * @param[in] index: 要删除的节点的位置
 * @return bool: 执行结果
 */
bool delete_index(node* p_head, int index);

/**
 * @brief: 按值删除节点
 * @param[in] p_head: 要执行删除操作的链表头指针
 * @param[in] del: 要删除的节点的值
 * @return bool: 执行结果
 */
bool delete_value(node* p_head, int del);

/**
 * @brief: 按值查找元素
 * @param[in] p_head: 要执行查找操作的链表头指针
 * @param[in] value: 要查找的值
 * @param[out] index: 返回第一个找到的节点位置, 找不到返回-1
 * @return bool: 执行结果, true: 存在, false: 不存在/查找失败
 */
bool find_first(node* p_head, int value, int* index);

/**
 * @brief: 按值查找元素
 * @param[in] p_head: 要执行查找操作的链表头指针
 * @param[in] value: 要查找的值
 * @param[out] index: 返回第一个找到的节点位置, 找不到返回-1
 * @return bool: 执行结果, true: 存在, false: 不存在/查找失败
 */
bool find_last(node* p_head, int value, int* index);

/**
 * @brief: 按值查找元素
 * @param[in] p_head: 要执行查找操作的链表头指针
 * @param[in] value: 要查找的值
 * @param[out] p_result: 存储所有找到的节点位置的数组, 找不到返回空数组
 * @return bool: 执行结果, true: 存在, false: 不存在/查找失败
 */
bool find_all(node* p_head, int value, array* p_result);

/**
 * @brief: 获取链表大小
 * @param[in] p_head: 要执行操作的链表头指针
 * @param[out] size: 链表大小
 * @return bool: 执行结果, true: 成功, false: 失败
 */
bool size(node* p_head, int* size);

/**
 * @brief: 获得节点的值
 * @param[in] p_head: 要执行操作的链表头指针
 * @param[in] index: 节点索引
 * @param[out] value: 节点的值
 * @return bool: 执行结果, true: 成功, false: 失败
 */
bool get_value(node* p_head, int index, int* value);

/**
 * @brief: 链表判空
 * @param[] p_head: 要执行操作的链表头指针
 * @return bool: 执行结果, true: 链表为空, false: 链表非空
 */
bool empty(node* p_head);


void destory(node** p_head);

bool clear(node* p_head);


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
        printf("address: %p\n\n", p_head);
    }

    {       
        printf("初始化有头空链表: ");
        node* p_head = initial_head_null();
        display(p_head);
        printf("address: %p\n\n", p_head);
    }

    {
        printf("初始化有头非空链表(arglist, 尾插): ");
        node* p_head = initial_head_arglist_h(4, 7, 9, 90, 89);
        display(p_head);
        printf("address: %p\n\n", p_head);
    }

    {
        printf("初始化有头非空链表(array, 头插): ");
        int data[] = {7, 88, 9, 90, 89, 6, 88, 89};
        node* p_head = initial_head_array_t(8, data);
        display(p_head);
        printf("address: %p\n", p_head);

        printf("insert_pos(3, 88): ");
        insert_pos(p_head, 3, 88);
        display(p_head);

        printf("delete_index(0): ");
        delete_index(p_head, 0);
        display(p_head);

        printf("delete_value(90): ");
        delete_value(p_head, 90);
        display(p_head);

        int index;
        find_first(p_head, 888, &index);
        printf("find_first(888): %d\n", index);

        find_last(p_head, 88, &index);
        printf("find_last(88): %d\n", index);

        array p_find_result;
        if (find_all(p_head, 88, &p_find_result))
        {
            printf("find_all(88): [ ");
            for (int i = 0; i < p_find_result.size; i++)
            {
                printf("%d ", p_find_result.array[i]);
            }
            printf("]\n");
        }

        int list_size;
        size(p_head, &list_size);
        printf("size of list: %d\n", list_size);

        int value;
        if (get_value(p_head, 5, &value))
        {
            printf("value: %d\n", value);
        }
        else
        {
            printf("no that node.\n");
        }

        printf("p_head_p: %p, NULL: %slist: ", p_head, p_head==NULL?"true\n":"false\n");
        display(p_head);
        destory(&p_head);
        printf("p_head_b: %p, NULL: %slist: ", p_head, p_head==NULL?"true\n":"false\n");
        destory(&p_head);
        display(p_head);
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
    node* p_head = NULL; // head为头指针

    return p_head;
}

node* initial_head_null()
{
    node* p_head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    p_head->data = 0;
    p_head->next = NULL;

    return p_head;
}

// 利用不定参数初始化链表(头插)
node* initial_head_arglist_h(int num_of_data, ...)
{
    va_list arg_list;
    va_start(arg_list, num_of_data);
    node* p_head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    p_head->data = num_of_data;   // 头节点记录链表大小
    p_head->next = NULL;

    // 为链表添加节点
    for (int i = 0; i < num_of_data; i++)
    {
        node* p_tmp = (node*)malloc(sizeof(node));
        p_tmp->data = va_arg(arg_list, int);
        p_tmp->next = p_head->next;
        p_head->next = p_tmp;
    }
    va_end(arg_list);
    return p_head;
}

// 利用不定参数初始化链表(尾插)
node* initial_head_arglist_t(int num_of_data, ...)
{
    va_list arg_list;
    va_start(arg_list, num_of_data);
    node* p_head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    p_head->data = num_of_data;   // 头节点记录链表大小
    p_head->next = NULL;
    node* p_tail = p_head; // 尾指针

    // 为链表添加节点
    for (int i = 0; i < num_of_data; i++)
    {
        node* p_tmp = (node*)malloc(sizeof(node));
        p_tmp->data = va_arg(arg_list, int);
        p_tmp->next = NULL;
        p_tail->next = p_tmp;
        p_tail = p_tail->next;
    }
    va_end(arg_list);
    return p_head;
}

// 利用数组初始化链表(头插)
node* initial_head_array_h(int size, int* p_array)
{
    node* p_head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    p_head->data = size;    // 头节点记录链表大小
    p_head->next = NULL;

    // 为链表添加节点
    for (int i = 0; i < size; i++)
    {
        node* p_tmp = (node*)malloc(sizeof(node));
        p_tmp->data = p_array[i];
        p_tmp->next = p_head->next;
        p_head->next = p_tmp;
    }

    return p_head;
}

// 利用数组初始化链表(尾插)
node* initial_head_array_t(int size, int* p_array)
{
    node* p_head = (node*)malloc(sizeof(node)); // 创建一个头结点，head为头指针
    p_head->data = size;   // 头节点记录链表大小
    p_head->next = NULL;
    node* p_tail = p_head;   // 尾指针

    // 为链表添加节点
    for (int i = 0; i < size; i++)
    {
        node* p_tmp = (node*)malloc(sizeof(node));
        p_tmp->data = p_array[i];
        p_tmp->next = NULL;
        p_tail->next = p_tmp;
        p_tail = p_tail->next;
    }

    return p_head;
}

bool insert_pos(node* p_head, int pos, int data)
{
    // 建议记录链表长度并判断，否则需要调用时保证插入位置有效，避免访问越界
    if (p_head == NULL || pos > p_head->data)
    {
        printf("插入位置无效.\n");
        return false;
    }

    node* p_tmp = p_head;
    
    // 首先找到要插入位置的上一个结点
    for (int i = 0; i < pos; i++)
    {
        p_tmp = p_tmp->next;
    }
    // 创建插入结点c
    node* p_new = (node*)malloc(sizeof(node));
    p_new->data = data;
    // 向链表中插入结点
    p_new->next = p_tmp->next;
    p_tmp->next = p_new;
    p_head->data++;
    
    return true;
}

bool delete_index(node* p_head, int index)
{
    if (empty(p_head) || index > p_head->data)
    {
        printf("没有该结点\n");
        return false;
    }

    // 遍历到被删除结点的直接前驱结点
    node* p_pre = p_head;
    for (int i = 0; i < index; i++)
    {
        p_pre = p_pre->next;
    }

    node* p_del = p_pre->next; // 单独设置一个指针指向被删除结点，以防丢失
    p_pre->next = p_del->next; // 删除某个结点的方法就是更改前一个结点的指针域
    p_head->data--;
    free(p_del);               // 手动释放该结点，防止内存泄漏

    return true;
}

bool delete_value(node* p_head, int del)
{
    if (empty(p_head))
    {
        printf("链表为空\n");
        return false;
    }

    node* p_pre = p_head;
    node* p_del = p_pre->next;

    int i = 0;
    while (p_del != NULL)
    {
        while (p_del->data != del)
        {
            p_pre = p_pre->next;
            if (p_pre->next != NULL)
            {
                p_del = p_pre->next;
            }
            else if (i == 0)
            {
                printf("链表中不存在该值\n");
                return false;
            }
            else
            {
                return true;
            }
        }
        i++;
        p_pre->next = p_del->next;
        free(p_del);
        p_del = p_pre->next;
        p_head->data--;
    }

    return true;
}

bool find_first(node* p_head, int value, int* index)
{
    if (empty(p_head))
    {
        printf("链表为空\n");
        *index = -1;
        return false;
    }

    node* p_tmp = p_head;
    int i = 0;
    while (p_tmp->next)
    {
        p_tmp = p_tmp->next;
        if (p_tmp->data == value)
        {
            *index = i;
            return true;
        }
        i++;
    }
    *index = -1;
    return false;
}

bool find_last(node* p_head, int value, int* index)
{
    *index = -1;
    
    if (empty(p_head))
    {
        printf("链表为空\n");
        return false;
    }

    node* p_tmp = p_head;
    int i = 0;
    while (p_tmp->next)
    {
        p_tmp = p_tmp->next;
        if (p_tmp->data == value)
        {
            *index = i;
        }
        i++;
    }

    if (*index == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool find_all(node* p_head, int value, array* p_result)
{
    if (empty(p_head))
    {
        printf("链表为空\n");
        p_result->size = 0;
        return false;
    }

    node* p_tmp = p_head;
    int* p_array = (int*)malloc(sizeof(int) * p_tmp->data);

    int i = 0;
    int size = 0;
    int index = -1;
    while (p_tmp->next)
    {
        p_tmp = p_tmp->next;
        if (p_tmp->data == value)
        {
            p_array[size] = i;
            size++;
        }
        i++;
    }

    p_result->size = size;

    if (size == 0)
    {
        return false;
    }

    p_result->array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        p_result->array[i] = p_array[i];
    }

    free(p_array);

    return true;
}

bool size(node* p_head, int* size)
{
    if (p_head == NULL)
    {
        return false;
    }

    *size = p_head->data;

    return true;
}

bool get_value(node* p_head, int index, int* value)
{
    if (p_head == NULL || p_head->next == NULL)
    {
        printf("链表为空\n");
        return false;
    }

    node* p_tmp = p_head;
    for (int i = 0; i < p_head->data; i++)
    {
        p_tmp = p_tmp->next;
        if (i == index)
        {
            *value = p_tmp->data;
            return true;
        }
    }

    return false;
}

bool empty(node* p_head)
{
    if (p_head == NULL || p_head->next == NULL)
    {
        return true;
    }

    return false;
}

void destory(node** p_head_addr)
{
    node* p_head = *p_head_addr;
    if (p_head == NULL)
    {
        return;
    }

    node* p_tmp = p_head;
    while (p_head != NULL)
    {
        p_head = p_head->next;
        free(p_tmp);
        p_tmp = p_head;
    }
    *p_head_addr = NULL;
}

// void destory(node* p_head)
// {
//     if (p_head == NULL)
//     {
//         return;
//     }

//     node* p_tmp = p_head->next;
//     while (p_head->next != NULL)
//     {
//         p_head->next = p_tmp->next;
//         free(p_tmp);
//         p_tmp = p_tmp->next;
//         printf("p_tmp: %p\n", p_tmp);
//     }
//     printf("p_head: %p\n", p_head);
//     free(p_head);
//     p_head = NULL;
//     printf("p_head: %p, NULL: %s", p_head, p_head==NULL?"true\n":"false\n");
// }

bool clear(node* p_head)
{
    if (p_head == NULL)
    {
        return false;
    }
    static int i = 0;
    printf("\n%d\n", i++);
    node* p_cur = p_head->next;
    printf("p_cur: %p\n", p_cur);
    while (p_cur != NULL)
    {
        node* p_next = p_cur->next;
        free(p_cur);
        p_cur = p_next;
        printf("p_cur: %p\n", p_cur);
    }

    free(p_head);
    p_head = NULL;
    printf("p_head: %p\n", p_head);

    return true;
}


node* amendElem(node* p_head, int add, int newElem)
{
    node* p_tmp = p_head;
    p_tmp = p_tmp->next; // tamp指向首元结点
    // temp指向被删除结点
    for (int i = 1; i < add; i++)
    {
        p_tmp = p_tmp->next;
    }
    p_tmp->data = newElem;
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

    node* p_tmp = p_head; // 将temp指针重新指向头结点

    // 只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (p_tmp->next != NULL)
    {
        p_tmp = p_tmp->next;
        printf("%d ", p_tmp->data);
    }
    printf("\n");
}