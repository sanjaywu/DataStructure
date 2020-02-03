#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8
typedef int datatype;
typedef struct seqqueue
{
    datatype data[SIZE];   // 数据域
    int front;  // 队头前一个位置下标
    int rear;   // 队尾位置下标
}seq_queue, *seq_pqueue;

// 初始化
void init_seqqueue(seq_pqueue *queue)
{
    (*queue) = (seq_pqueue)malloc(sizeof(seq_queue));

    if (NULL == (*queue))
    {
        perror("malloc");
        exit(1);
    }

    (*queue)->front = SIZE - 1;
    (*queue)->rear = SIZE - 1;
}

// 判断队列是否已满
bool isfull_seqqueue(seq_pqueue queue)
{
    if (queue->front == (queue->rear + 1) % SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 入队
void in_seqqueue(seq_pqueue queue, datatype dat)
{
    if (isfull_seqqueue(queue))
    {
        printf("队列已满\n");
        return;
    }
    
    queue->rear = (queue->rear + 1) % SIZE;
    queue->data[queue->rear] = dat;
}

//判断队列是否已空
bool isempty_seqqueue(seq_pqueue queue)
{
    if (queue->front == queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 出队
void out_seqqueue(seq_pqueue queue, datatype *dat)
{
    if (isempty_seqqueue(queue))
    {
        printf("队列已空\n");
        return;
    }

    queue->front = (queue->front + 1) % SIZE;
    *dat = queue->data[queue->front];
}

// 打印
void show_seqqueue(seq_pqueue queue)
{
    int i = 0;

    for (i = (queue->front + 1) % SIZE; i != (queue->rear + 1) % SIZE; i = (i + 1) % SIZE)
    {
        printf("%d\t", queue->data[i]);
    }

    printf("\n");
}

int main(void)
{
    seq_pqueue queue = NULL;
    datatype in_data = 0;
    datatype out_data = 0;
    int ret = 0;

    init_seqqueue(&queue);  // 初始化队列

    while (1)
    {
        printf("输入整数:");
        ret = scanf("%d", &in_data);

        if (ret != 0)
        {
            in_seqqueue(queue, in_data);
            printf("入队后队列元素：");
            show_seqqueue(queue);
        }
        else
        {
            out_seqqueue(queue, &out_data);
            printf("出队后队列元素：");
            show_seqqueue(queue);
            while(getchar() != '\n');   // 清空输入缓冲
        }
    }

    return 0;
}