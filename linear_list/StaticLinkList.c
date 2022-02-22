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
        i = S[i].cur;    //在表中顺链查找,cur总比i大1
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
    //头结点的游标存放的永远是下一个未存放数据的下标，从头结点cur中找下个可用结点下标
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
    //不清楚space[k]中的数据
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void difference(SLinkList &space, int &S)
{
    //依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)的静态链表，S为其头指针。假设备用空间足够大，space[0].cur为其头指针
    InitSpace_SL(space);                                                //初始化备用空间
    S = Malloc_SL(space);                                               //生成S的头结点
    int *r;
    r = S;                                                              //r指向S的当前最后结点
    int m, n;
    scanf(m, n);                                                        //输入A和B的元素个数
    for (int j = 1; j < m; ++j)                                         //建立集合A的链表
    {
        i = Malloc_SL(space);                                           //分配结点
        scanf(space[i].data);                                           //输入元素A的值
        space[r].cur = i;                                               //将尾指针的cur指向i
        r = i;
    }
    space[r].cur = 0;                                                   //表A插入完成后，将尾元素的cur指向表头的空指针
    for (int j = 0; j < n; ++j)                                         //依次输入B的元素，若不在当前表中，则插入，否则删除
    {
        scanf(b);
        p = S;
        k = space[S].cur;                                               //k指向集合A中的第一个结点
        while (k != space[r].cur && space[k].data != b)                 //在当前表中查找 1st条件判断A集合是否为空 2nd条件判断b值是否与k结点的相等
        {
            p = k;                                                      //p指向k上一个结点，方便删除时调用
            k = space[k].cur;                                           //k结点向后移动
        }
        if (k == space[r].cur)                                          //当前表中不存在该元素，插入在r所指结点之后，且r的位置不变
        {
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;                                //space[r].cur为0，指向头结点，此值给space[i],i为最新结点
            space[r].cur = i;                                           //space[r].cur记录最新分配的结点,r不动
        }
        else
        {
            space[p].cur = space[k].cur;                                //该元素已存在表中，删除之
            Free_SL(space, k);
            if (r == k)                                                 //若删除的是r所指结点，则需要修改尾指针
            {
                r = p;
            }
        }
    }
}