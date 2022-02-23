#include <stdio.h>
#include <stdlib.h>
#include "status.h"

struct SqStack S;

void conversion()
{
  //对于输入的任意非负十进制整数，打印输出与其相等值的八进制数
  InitStack(S);
  scanf("%d", N);
  while(N)
  {
    Push(S,N%8);
    N=N/8;
  }
  while(!StackEmpty(s))
  {
    Pop(S,e);
    printf("%d",e);
  })
}//conversion