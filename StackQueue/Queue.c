#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;  //队头指针
    QueuePtr rear;	 //队尾指针
} LinkQueue; //链队列

Status InitQueue(LinkQueue &Q);  //构造一个空队列

Status DestroyQueue(LinkQueue &Q); //销毁一个队列

Status ClearQueue(LinkQueue &Q); //清空一个队列

Status QueueEmpty(LinkQueue Q); //判断队列是否为空

int QueueLength(LinkQueue Q); //返回队列的长度

Status GetHead(LinkQueue &Q, ElemType &e); //若队列不空，用e反馈队列Q的头元素，并反馈OK,否则返回ERROR

Status EnQueue(LinkQueue &Q, ElemType e); //插入e元素作为Q的新队尾元素

Status DeQueue(LinkQueue &Q, ElemType &e); //若Q不空，则删除队头元素，并用e返回

Status QueueTraverse(LinkQueue Q, visit()); //从队头到队尾每个元素调用一次visit,一旦visit失败则操作失败

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
    {
        return ERROR;
    }
    Q.front.next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    while (Q.front != Q.rear)
    {
        QueuePtr q = Q.front->next;
        free(Q.front);
        Q.front = q;
    }
    free(Q.rear);
    return OK;
}

Status EnQueue(LinkQueue &Q, ElemType e)
{
    //插入元素e作为&Q的新队尾元素
    QNode q = (QueuePtr)malloc(sizeof(QNode));
    if (!q)
    {
        return OVERFLOW;
    }
    q.data = e;
    q->next = NULL;
    Q.rear->next = q;
    Q.rear = q;
    return OK;
}

Status DeQueue(LinkQueue &Q, ElemType &e)
{
    //若队列不空，则删除Q的头元素，并用e返回其值，并return OK
    //否则return ERROR

    if (Q.front == Q.rear)
    {
        return ERROR;
    }

    e = Q.front->next->data;
    p = Q.front->next;
    Q.front->next->data = NULL;
    Q.front->next = Q.front->next->next;
    if (p == Q.rear) //若p为队尾元素，则需要讲队首队尾指针对齐
    {
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}