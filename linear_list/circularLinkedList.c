#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#define MAXSIZE 1000

typedef int ElemType;

typedef struct DuLNode
{
  ElemType data;
  struct DuLNode *prior;
  struct DuLNode *next;
} DuLNode, *DuLinkList;

Status GetElem_DuL(DuLinkList &L, int i, ElemType &e)
{
  // L为带头节点的单链表的头指针；
  //当第i个元素存在时，其赋值给e并返回OK，否则返回ERROR
  p = L->next; //初始化,p指向第一个节点，j为计数器
  j = 1;
  while (p && j < i) //顺指针向后查找，直到p指向第i个元素或p为空
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
  {
    return ERROR; //第i个元素不存在
  }
  e = p->data; //取第i个元素
  return OK;
} // GetElem_DuL

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e)
{
  //带头结点的双链循环线性表L中第i个位置之前插入元素e
  // i的合法值为1<=i<=(表长+1)
  ElemType *p;
  if (!(p = GetElem_DuL(L, i))) //在L中确定插入位置指针p
  {                             // i等于表长加1时，p指向头结点；i大于表长加1时，p=NULL
    return ERROR;
  }
  if (!(s = (DuLinkList)malloc(sizeof(DuLNode)))) //若分配空间失败，则报错
  {
    return ERROR;
  }
  s->data = e;
  s->prior = p->prior;
  p->prior->next = s;
  s->next = p;
  p->prior = s;
  return OK;
} // ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e)
{
  //删除带头结点的双循环线性表L的第i个元素，i的合法值为1<=i<=表长
  if (!(p = GetElem_DuL(L, i))) //在L中确定第i个元素的位置指针p
  {
    return ERROR; // p=NULL,即第i个元素不存在
  }
  e = p->data;
  p->prior->next = p->next;
  p->next->prior = p->prior;
  free(p);
  return OK;
}

void method(){
  return null;
}
