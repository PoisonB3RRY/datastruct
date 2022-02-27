#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#ifndef MAXQSIZE
#define MAXQSIZE 100
#endif

typedef struct SqQueue
{
    ElemType *base; //初始化的动态分配存储空间
    int front;  //头指针，若队列不空则指向队列头元素
    int rear;	//尾指针，若队列不空则指向队尾元素的下一个元素
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q.base = (ElemType *)malloc(sizeof(SqQueue) * MAXQSIZE);
    if (!Q.base)
    {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueLength(SqQueue Q)
{
    //返回Q的元素个数即元素个数
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, ElemType e)
{
    //插入e元素为Q的新队尾
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
    {
        return ERROR;	//队列满了
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, ElemType e)
{
    //若队列不空，则删除队列的头元素并用e返回其值，并返回OK，否则返回ERROR
    if (Q.front == Q.rear)
    {
        return ERROR;
    }

    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}