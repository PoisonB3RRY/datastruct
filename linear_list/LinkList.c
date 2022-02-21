#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    //L为带头节点的单链表的头指针；
    //当第i个元素存在时，其赋值给e并返回OK，否则返回ERROR
    p = L->next;    //初始化,p指向第一个节点，j为计数器
    j = 1;
    while (p && j < i)   //顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;    //第i个元素不存在
    }
    e = p->data;    //取第i个元素
    return OK;
}//GetElem_L

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1)  //寻找第i-1个节点
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));  //生成新结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    //在带头结点的单链表L中，删除第i个元素，并由e返回其值
    p = L;
    j = 0;
    while (p->next && j < i - i)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}//ListDelete_L

void CreateList_L(LinkList &L, int n)
{
    //逆位序输入n个元素的值，建立带表头节点的单链线性表L
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;     //先建立一个带头结点的单链表
    for (int i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(LNode));  //生成新节点
        scanf(&p->data);    //插入元素值
        p->next = L->next;    //插入到表头
        L->next = p;
    }
}//CreateList_L

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    //已知单链线性表La和Lb的元素按值非递减排列
    //归并La和Lb得到新的单链线性表Lc, Lc的元素也按值非递减排列
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La; //用La的头结点作为Lc的头结点
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        pc->next = pa ? pa : pb; //插入剩余段
        free(Lb); //释放Lb的头结点
    }
} //MergeList_L