#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct linklist
{
    datatype data;  /* 数据域 */
    struct linklist *next;  /* 指针域 */
}link_list, *link_plist;

/* 初始化 */
void init_linklist(link_plist *list)
{
    *list = (link_plist)malloc(sizeof(link_list));
    if(NULL == *list)
    {
        printf("内存申请失败\n");
        perror("malloc");   /* 打印内存申请失败原因 */
        exit(1);
    }
    (*list)->next = NULL;   /* 将next设为NULL，建立空链表 */
}

/* 插入 */
void insert_linklist(link_plist head, link_plist new)
{
    new->next = head->next;
    head->next = new;
}

/* 删除 */
void delete_linklist(link_plist pnode)
{
    link_plist dnode;

    dnode = pnode->next;
    pnode->next = dnode->next;
    free(dnode);
}

/* 判断是否为空 */
bool isempty(link_plist head)
{
    if(NULL == head->next)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/* 遍历打印单向链表 */
void show_linklist(link_plist head)
{
    link_plist p;
    /* 因为头结点不存数据，因此从p = head->next开始 */
    for(p = head->next; p != NULL; p = p->next)
    {
        printf("%d\t", p->data);
    }
    printf("\n");
}

/* 创建单向链表 */
void create_linklist(link_plist head)
{
    link_plist new = NULL;
    link_plist p = head;
    int len = 0;
    int i = 0;

    printf("输入要插入数据的个数:");
    scanf("%d", &len);

    for(i = 0; i < len; i++)
    {
        new = (link_plist)malloc(sizeof(link_list));
        if(NULL == new)
        {
            printf("内存申请失败\n");
            perror("malloc");
            exit(1);
        }
        printf("输入要插入的第%d个数据:", (i+1));
        scanf("%d", &(new->data));
        insert_linklist(p, new);
        p = p->next;

        show_linklist(head);   /* 打印 */
    }
}

/* 将数据逆向排序 */
void sort_linklist(link_plist head)
{
    link_plist p = NULL;
    link_plist t = NULL;

    p = head->next;
    head->next = NULL;
    
    while(p != NULL)
    {
        t = p;
        p = p->next;
        insert_linklist(head, t);
        show_linklist(head);
    }
}

int main(void)
{
    link_plist head;        /* 定义一个头指针 */

    init_linklist(&head);   /* 初始化 */
    create_linklist(head);  /* 创建单向链表 */
    sort_linklist(head);    /* 逆转 */

    return 0;
}
