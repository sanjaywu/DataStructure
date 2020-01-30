#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 构造存储结构 */
#define SIZE 8
typedef int datatype;
typedef struct seqlist{
	datatype data[SIZE];
	int last;
}seq_list, *seq_plist;

/* 初始化 
   *list:顺序表
 */
void init_seqlist(seq_plist *list)
{
    *list = (seq_plist)malloc(sizeof(seq_list));	/* 申请内存空间 */
    if (NULL == *list)
    {
        printf("申请内存失败\n");
        perror("malloc");	/* 打印申请内存失败的原因*/
        exit(1);			/* 让当前程序结束 */
    }
    
    (*list)->last = -1; /* 设置last为-1 */
}

/* 插入数据
   list:顺序表
   i:新数据插入的位置
   data:插入的新数据
 */
void insert_seqlist(seq_plist list, int i, datatype data)
{
    int j = 0;

    /* 从位置i开始将顺序表的数据往后移动 */
    for (j = list->last; j >= i; j--)
    {
        list->data[j+1] = list->data[j];
    }

    list->data[i] = data; /* 将data插入到i的位置 */
    list->last++;   /* 因为last表示最后一个数据的下标，因此需要将last加1*/
}

/* 删除数据
   list:顺序表
   i:删除数据的位置
 */
void delete_seqlist(seq_plist list, int i)
{
    int j = 0;

    /* 将位置i后面的数据全部往前面移动一个位置 */
    for (j = i; j < list->last; j++)
    {
        list->data[j] = list->data[j+1];
    }

    list->last--; /* 因为last表示最后一个数据的下标，因此需要让last减去1 */
}

/* 判断顺序表是否为空
   list:顺序表
 */
bool isempty_seqlist(seq_plist list)
{
    if (-1 == list->last)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 判断顺序表是否已满
   list:顺序表
 */
bool isfull_seqlist(seq_plist list)
{
    if ((SIZE - 1) == list->last)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 遍历打印顺序表
   list:顺序表
*/
void show_seqlist(seq_plist list)
{
    int i = 0;

    for (i = 0; i <= list->last; i++)
    {
        printf("%d\t", list->data[i]);
    }
     printf("\n");
}

/* 将数据插入顺序表，且保持有序递增
    list:顺序表
    idata:要插入的数据
 */
void insert_data(seq_plist list, datatype idata)
{
      int i = 0;
      if(isfull_seqlist(list))
      {
          printf("顺序表已满!\n");
          return;
      }

      /* 然顺序表有序递增插入 */
      for(i = 0; i <= list->last; i++)
      {
          if(idata < list->data[i])
          {
              break;
          }
      }
	    
      insert_seqlist(list, i, idata);
}

/* 将数据从顺序表删除，且保持有序递增
    list:顺序表
    ddata:要删除的数据
 */
void delelet_data(seq_plist list, datatype ddata)
{
      int i = 0;

      if(isempty_seqlist(list))
      {
          printf("顺序表为空!\n");
          return ; 
      }

      for(i = 0; i <= list->last; i++)
      {
          if(ddata == list->data[i])
          {
              break;
          }
      }

      if(i > list->last)
      {
          printf("%d 不在顺序表中!\n", ddata);
          return ;
      }
      delete_seqlist(list, i);
}

int main(void)
{
    seq_plist list;
    datatype data;
    int ret = 0;

    init_seqlist(&list);  /* 初始化顺序表 */

    while(1)
    {
	    printf("请输入一个除0之外的整数:");
	    ret = scanf("%d", &data);    /* 输入int型返回1，否则返回0 */

	    if(ret == 0)    /* 输入为字符，退出while循环，程序结束 */
        {               
             printf("Bye-bye!\n"); 
             break;
	    }
        else
        {
            if(data > 0)   /* 输入为正整数，插入数据并打印新的顺序表 */
            {  
                insert_data(list, data);
                show_seqlist(list);
            }
            else if(data < 0)   /* 输入为负整数，删除数据并打印新的顺序表 */
            {	
                delelet_data(list, -data);
                show_seqlist(list);
            }
            else
            {
                /* code */
            }
        }
    }

    return 0;
}