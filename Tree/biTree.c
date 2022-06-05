#include <stdio.h>
#include <stdio.h>
#include "status.h"

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

Status PreOrderTreverse(BiTree T, Status (*visit)(TElemType e))
{
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

Status PrintElement(TElemType e)
{
    printf(e);
    return OK;
}