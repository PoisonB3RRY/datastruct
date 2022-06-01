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