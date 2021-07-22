#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000 //链表的最大长度

typedef int ElemType;

typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e)
{
    //在静态单链线性表L中查找第1个值为e的元素
    //若找到，则返回它在L中的位序，负责返回0
    i = S[0].cur;     //i指示表中第1个节点
    while (i && S[i].data != e)
    {
        i = S[i].cur;    //在表中顺链查找
    }
    return i;
}//LocateElem_SL

void InitSpace_SL(SLinkList &space)
{
    //将一维数组space中各分量链成一个备用链表,space[0].cur为头指针
    //"0"表示空指针
    for (int i = 0; i < MAXSIZE - 1; ++i)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
}//InitSpace_SL

int Malloc_SL(SLinkList &space)
{
    //若备用空间链表非空，则返回分配的结点下标，否则返回0
    i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}//Malloc_SL

void Free_SL(SLinkList &space, int k)
{
    //将下标为k的空闲结点回收到备用链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}