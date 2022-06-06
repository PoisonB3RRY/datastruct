#include <stdio.h>
#include <stdio.h>
#include "status.h"
#include "../StackQueue/SqStack.c"

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BitNode *lchild, *rchild;
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T);

Status PreOrderTreverse(BiTree T, Status (*visit)(TElemType e));

Status InOrderTreverse(BiTree T, Status (*visit)(TElemType e));

Status PostOrderTreverse(BiTree T, Status (*visit)(TElemType e));

Status LevelOrderTreverse(BiTree T, Status (*visit)(TElemType e));

Status CreateBiTree(BiTree &T)
{
    TElemType tempdata;
    scanf("%d", &tempdata);

    if (tempdata == -1)
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode)malloc(sizeof(BiTNode));
        T.data = tempdata;
        CreateBiTree(&(T.lchild));
        CreateBiTree(&(T.rchild));
    }
    return OK;
}

Status PrintElement(TElemType e)
{
    printf(e);
    return OK;
}

Status PreOrderTreverse(BiTree T, Status (*visit)(TElemType e))
{
    //采用二叉链表存储结构，visit是对数据元素操作的应用函数
    //先序遍历二叉树T的递归算法，对每个数据元素调用visit;
    visit = &PrintElement;
    if (T)
    {
        if (visit(T->data))
        {
            if (PreOrderTreverse(T->lchild, visit))
            {
                if (PreOrderTreverse(T->rchild, visit))
                {
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else
    {
        return OK;
    }
}

Status InOrderTreverse(BiTree T, Status (*visit)(TElemType e))
{
    //中序遍历二叉树的非递归算法，利用栈
    visit = &PrintElement;
    SqStack S;
    InitStack(S);
    BiTNode *p = &T;
    Push(S, p); //根指针进栈
    while (!StackEmpty(S))
    {
        while (GetTop(S, p) && p)
        {
            Push(S, p->lchild); //向左走到尽头
        }
        Pop(S, p); //最后一个空指针退栈
        if (!StackEmpty(S))
        {
            Pop(S, p);
            if (!visit(p->data)) //访问节点，向右一步
            {
                return ERROR;
            }
            Push(S, p->rchild);
        }
    }
    return OK;
}