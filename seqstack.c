#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8
typedef int datatype;
typedef struct seqstack{
      datatype data[SIZE];
      int top;
}seq_stack, *seq_pstack;

// 初始化
void init_seqstack(seq_pstack *stack)
{
    (*stack) = (seq_pstack)malloc(sizeof(seq_stack));

    if (NULL == stack)
    {
        perror("malloc");
        exit(1);
    }

    (*stack)->top = -1;
}

// 判断栈是否已经满
bool isfull_seqstack(seq_pstack stack)
{
    if (SIZE - 1 == stack->top)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// 入栈
void push_seqstack(seq_pstack stack, datatype dat)
{
    if (isfull_seqstack(stack))
    {
        printf("栈已满\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = dat;
}

// 判断栈是否为空
bool isempty_seqstack(seq_pstack stack)
{
    if (-1 == stack->top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//出栈
void pop_seqstack(seq_pstack stack, datatype *dat)
{
    if (isempty_seqstack(stack))
    {
        printf("栈为空\n");
        return;
    }

    *dat = stack->data[stack->top]; //出栈数据保存在*dat中
    stack->top--;
}

//打印
void show_seqstack(seq_pstack stack)
{
    int i = 0;

    for (i = stack->top; i >= 0; i--)
    {
        printf("%d\t", stack->data[i]);
    }

    printf("\n");
}

//用顺序栈实现整数的逆序输出。例如输入整数1，2，3，输出3，2，1
int main(void)
{
    seq_pstack stack = NULL;
    int data = 0;
    int ret = 0;

    init_seqstack(&stack);  // 初始化

    while (1)
    {
        printf("输入整数:");
        ret = scanf("%d", &data);

        if (0 == ret)
        {
            printf("bye-bye\n");
            break;
        }
        else
        {
            push_seqstack(stack, data);
            printf("输出:\t");
            show_seqstack(stack);
        }
    }
    
    return 0;
}

