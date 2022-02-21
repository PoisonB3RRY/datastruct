#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct {
    ElemType *elem; //存储空间基址
    int length; //当前长度
    int listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;

Status InitList_Sq(SqList &L)
{
    //构造一个空的线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) //存储分配失败
    {
        exit(OVERFLOW);
    }
    L.length = 0; //空表长度为0
    L.listsize = LIST_INIT_SIZE; //初始存储容量
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    //在顺序线性表L中第i个位置之前插入新的元素e
    // i 的合法值为 1<= i <= ListLength_Sq(L)+1
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;
    }
    if (L.length >= L.listsize)
    {
        //当前存储空间已满，增加分配
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) //存储分配失败
        {
            exit(OVERFLOW);
        }
        L.elem = newbase; //新基址
        L.listsize += LISTINCREMENT; //增加存储容量
    }
    ElemType *q = &(L.elem[i - 1]);
    ElemType *p = &(L.elem[L.length - 1]);
    for (; p >= q; --p) //插入位置及其之后的元素右移
    {
        *(p + 1) = *p;
    }

    *q = e;
    ++L.length;
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    //在顺序线性表L中删除第i个元素，并用e返回其值
    // i 的合法值为 1<=i<=ListLength_Sq(L)
    if ((i < 1) || (i > L.length)) //认为i值不合法
    {
        return ERROR;
    }
    ElemType *p = &(L.elem[i - 1]); //p为被删除元素的位置
    e = *p;                         //被删除元素的值赋值给e
    ElemType *q = &(L.elem + L.length - 1); //表尾元素的位置
    for (++p; p <= q; ++p)             //被删除元素之后的元素左移
    {
        *(p - 1) = *p;
    }
    --L.length;                       //表长减1
    return OK;
} // ListDelete_Sq

int LocateElem(SqList L, ElemType e, Status (* compare)(ElemType , ElemType))
{
    //在顺序线性表L中找到第1个值与e满足compare()的元素的位序
    //若找到，则返回其在L中的位序，否则返回0
    i = 1;
    p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e)) ++i;
    if (i <= L.length)
    {
        return i;
    }
    else
    {
        return 0;
    }
} // LocateElem_Sq

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    //已知顺序线性表La和Lb的元素按值非递减排列
    //归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.ElemType)
    {
        exit(OVERFLOW);
    }
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) //归并
    {
        if (pa <= pa_last)
        {
            *pc++ = *pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) //插入La的剩余元素
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) //插入Lb的剩余元素
    {
        *pc++ = *pb++;
    }
}//MergeList_Sq

Status compare(int a, int b)
{
    if (a == b)
    {
        return 1;
    }

    return 0;
}