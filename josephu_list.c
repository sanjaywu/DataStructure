#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct josephus
{
    datatype data;  /* 数据域 */
    struct josephus *next;  /* 指针域 */
}josephus_list, *josephus_plist;


/* 初始化 */
void init_josephus_list(josephus_plist *list)
{
    *list = (josephus_plist)malloc(sizeof(josephus_list));
    if(NULL == *list)
    {
        printf("内存申请失败\n");
        perror("malloc");   /* 打印内存申请失败原因 */
        exit(1);
    }
    (*list)->next = *list;
}

/* 插入 */
void insert_josephus_list(josephus_plist head, josephus_plist new)
{
    new->next = head->next;
    head->next = new;
}

/* 删除 */
void delete_josephus_list(josephus_plist pnode)
{
    josephus_plist dnode;

    dnode = pnode->next;
    pnode->next = dnode->next;
    free(dnode);
}

/* 判断是否为空 */
bool isempty(josephus_plist head)
{
    if(head == head->next)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/* 打印单向循环链表 */
void show_josephus_list(josephus_plist head)
{
    josephus_plist p = NULL;
    
    for(p = head; p->next != head; p = p->next)
    {
        printf("%d\t", p->data);
    }
    printf("%d\n", p->data);
}

/* 创建单向循环链表 */
void create_josephus_list(josephus_plist head)
{
    josephus_plist new = NULL;
    josephus_plist p = head;
    int len = 0;
    int i = 0;

    printf("输入要插入数据的个数:");
    scanf("%d", &len);

    for(i = 0; i < len; i++)
    {
        if (0 == i)
        {
            printf("输入要插入的第%d个数据:", (i+1));
            scanf("%d", &(head->data));
        }
        else
        {
            new = (josephus_plist)malloc(sizeof(josephus_list));
            if(NULL == new)
            {
                printf("内存申请失败\n");
                perror("malloc");
                exit(1);
            }
            printf("输入要插入的第%d个数据:", (i+1));
            scanf("%d", &(new->data));
            insert_josephus_list(p, new);
            p = p->next;
        }
        //show_josephus_list(head);   /* 打印 */
    }
}

/* n是第n个要删除的结点 */
void josephus(josephus_plist head, int n)
{
    int i = 0;
    josephus_plist p = head;

    while(p != p->next)
    {
        for(i = 0; i < n-2; i++)
        {
            p = p->next;
        }
        printf("-->%d", p->next->data);
        delete_josephus_list(p);
        p = p->next;
    }
    printf("-->%d\n", p->data);
}

int main(void)
{
    josephus_plist head;        /* 定义一个头指针 */

    init_josephus_list(&head);   /* 初始化 */
    create_josephus_list(head);  /* 创建单向链表 */
    josephus(head, 3);
    return 0;
}