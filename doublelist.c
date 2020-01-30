#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int datatype;

typedef struct doublelist{
      datatype data;
      struct doublelist *next, *prev;
}double_list, *double_plist;


/* 初始化 */
void init_doublelist(double_plist *list)
{
      *list = (double_plist)malloc(sizeof(double_list)); /* 申请内存空间 */
      if (NULL == *list)
      {
            perror("malloc"); /* 打印内存申请失败原因 */
            exit(1);
      }

      (*list)->next = *list;
      (*list)->prev = *list;
}

/* 向p指向的结点后面插入new指向的结点 */
void insert_doublelist_behind(double_plist p, double_plist new)
{
      new->next = p->next;
      p->next->prev = new;
      new->prev = p;
      p->next = new;
}

/* 向p指向的结点前面插入new指向的结点 */
void insert_doublelist_tail(double_plist p, double_plist new)
{
      new->prev = p->prev;
      p->prev->next = new;
      new->next = p;
      p->prev = new;
}

/* 删除p指向的结点后面的结点 */
void delete_doublelist_post(double_plist p)
{      
      double_plist t = NULL;

      t = p->next;
      p->next = t->next;
      t->next->prev = p;
      free(t);
}

/* 删除p指向的结点前面的结点 */
void delete_doublelist_prev(double_plist p)
{
      double_plist t = NULL;

      t = p->prev;
      p->prev = t->prev;
      t->prev->next = p;
      free(t);
}

/*  删除p指向的结点*/
void delete_doublelist(double_plist p)
{
      p->prev->next = p->next;
      p->next->prev = p->prev;
      //free(p);
}

/* 判断链表是否为空 */
bool isempty_doublelist(double_plist head)
{
      if (head == head->next)
      {
            return true;
      }
      else
      {
            return false;
      }  
}

/* 打印链表 */
void show_doublelist(double_plist head)
{
      double_plist p = NULL;

      for (p = head->next; p != head; p = p->next)
      {
            printf("%d\t", p->data);
      }
      printf("\n");
}



/*
用双向循环链表实顺序递增存储若干自然数，比如输入一个整数10，
则建立一个双向循环链表，里面的每个节点分别存放1，2，3，4，5，6，7，8，9，10，
然后通过某些操作，将其重新排列成1，3，5，7，9，10，8，6，4，2，即奇数升序偶数降序，
并在屏幕上打印出来。
*/


/* 创建链表 */
void create_doublelist(double_plist head)
{
      int n = 0;
      int i = 0;
      double_plist new = NULL;

      printf("请输入要插入的数据个数：");
      scanf("%d", &n);

      for (i=0; i<n; i++)
      {
            new = (double_plist)malloc(sizeof(double_list));
            if (NULL == new)
            {
                  perror("malloc");
                  exit(1);
            }
            printf("输入要插入的第%d个数据：", i+1);
            scanf("%d", &(new->data));

            /* 使用前插方法 */
            insert_doublelist_tail(head, new);
            show_doublelist(head);
      }
}

/* 排序 */
void sort_doublelist(double_plist head)
{
      double_plist p = NULL;
      double_plist t = NULL;

      p = head->prev;   /* p指向最后那个结点，从后往前找 */
      while (p != head)
      {
            if (1 == (p->data % 2))    /* 判断是否为奇数 */
            {
                  p = p->prev; /* 如果是奇数，p往前移 */
            }
            else  /* 偶数 */
            {
                  t = p; /* 保存这个结点的数据 */
                  p = p->prev; /* p继续往前移 */
                  delete_doublelist(t);   /* 删除这个结点，但不释放它，还继续保存数据 */
                  insert_doublelist_tail(head, t); /* 将t结点作为新结点插入到head结点后面 */
                  show_doublelist(head);
            }
            
      }
}

int main(void)
{
      double_plist head = NULL;

      init_doublelist(&head);
      create_doublelist(head);
      sort_doublelist(head);

      return 0;
}

