#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#ifndef STACK_INIT_SITE
#define STACK_INIT_SITE 100
#endif

#ifndef STACK_INCREMENT
#define STACK_INIT_SITE 50
#endif

typedef struct {
    ElemType *base; //在栈构造之前和销毁之后，base的值为NULL
    ElemType *top;	//栈顶指针
    int stacksize;	//当前已分配的存储空间，以元素为单位
} SqStack;

Status InitStack(SqStack &S);

Status DestroyStack(SqStack &S);

Status ClearStack(SqStack &S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S, ElemType &e);

Status Push(SqStack &S, ElemType e);

Status Pop(SqStack &S, ElemType &e);

Status StackTraverse(SqStack S, Status (*visit)());

Status InitStack(SqStack &S)
{
    //构造一个空栈
    S.base = (SqStack *)malloc(STACK_INIT_SITE * sizeof(ElemType));
    if (!S.base)
    {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.length = STACK_INIT_SITE;
    return OK;
}//InitStack

Status DestroyStack(SqStack &S)
{
    //销毁栈
    if (S.base)
    {
        S.length = 0;
        free(S.base);
        S.base = S.top = NULL;
    }
    return OK;
}

Status GetTop(SqStack S, ElemType &e)
{
    if (S.base == S.top)
    {
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, ElemType e)
{
    //先判断栈满了没有，满了就扩容
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SqStack *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            exit(OVERFLOW);
        }
        S.top = S.base + S.stacksize; //top指针重新定位于栈内
        S.stacksize += STACK_INCREMENT;
    }
    //推入元素
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
    //先判断是否为空栈
    if (S.top == S.base)
    {
        exit(ERROR);
    }
    //若不为空则将top值赋予e,top自减1释放一位空间
    e = *(--S.top);
    return OK;
}

