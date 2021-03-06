#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef struct polynomialNode {
    int coefficient;
    int index;
    struct polynomialNode *item;
}*polynomial;

typedef LinkList polynomial;

int compare(polynomialNode a, polynomialNode b)
{
    if (a.index > b.index)
    {
        return 1;
    }
    if (a.index < b.index)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void CreatePolyn(polynomial &P, int m) //输入m项的系数和指数，建立表示一元多项式的系数和指数
{
    InitList(P);
    h = GetHead(P);
}

void AddPolyn(polynomial &Pa, polynomial &Pb)
{
    //多项式加法：Pa=Pa+Pb，利用两个多项式的节点构成“和多项式”
}