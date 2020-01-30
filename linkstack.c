#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct linkstack
{
    datatype data;
    struct linkstack *next;
}link_stack, *link_pstack;

//初始化
void init_linkstack(link_pstack *top)
{
    (*top) = NULL;
}

// 入栈
void push_linkstack(link_pstack *top, datatype dat)
{
    link_pstack new = NULL;

    new = (link_pstack)malloc(sizeof(link_stack));
    if (NULL == new)
    {
        perror("malloc");
        return;
    }

    new->data = dat;
    new->next = (*top);
    (*top) = new;
}

//判断栈是否为空
bool isempty_linkstack(link_pstack top)
{
    if (NULL == top)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

//出栈
void pop_linkstack(link_pstack *top, datatype *dat)
{
    link_pstack t = NULL;

    if (isempty_linkstack(*top))
    {
        printf("栈已空\n");
        return;
    }

    t = (*top);
    (*dat) = t->data;   //保存出栈的数据
    free(t);
}

// 打印
void show_linkstack(link_pstack top)
{
    link_pstack p = NULL;

    for (p = top; p != NULL; p = p->next)
    {
        printf("%d\t", p->data);
    }

    printf("\n");
}

//用链栈实现十进制向八进制转换。例如输入123，输出0173
int main(void)
{
    link_pstack top = NULL;
    datatype data_push = 0;
    datatype data_temp = 0;
    datatype data_pop = 0;

    init_linkstack(&top);
    printf("输入十进制数:");
    scanf("%d", &data_push);
    data_temp = data_push;

    if (data_push < 0)
    {
        data_push = -data_push;
    }

    while (data_push)
    {
        push_linkstack(&top, data_push%8);
        data_push = data_push/8;
    }

    if (data_temp < 0)
    {
        printf("十进制数: %d的八进制为:-0", data_temp);
    }
    else
    {
        printf("十进制数: %d的八进制为:0", data_temp);
    }
    
    while (!isempty_linkstack(top))
    {
        pop_linkstack(&top, &data_pop);
        printf("%d", data_pop);
    }
    
    printf("\n");

    return 0;
}
