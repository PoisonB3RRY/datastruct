#include <stdio.h>
#include <stdlib.h>
#include "status.h"

struct SqStack S;

void conversion()
{
    //对于输入的任意非负十进制整数，打印输出与其相等值的八进制数
    InitStack(S);
    scanf("%d", N);
    while (N)
    {
        Push(S, N % 8);
        N = N / 8;
    }
    while (!StackEmpty(s))
    {
        Pop(S, e);
        printf("%d", e);
    }
}//conversion
//将余数由低位至高位推进栈里，再有高位到低位输出

void LineEdit(SqStack &s)
{
    InitStack(s);
    c = getchar();
    char ch;
    while (c != EOF)
    {
        while (c != EOF && c != '\n')
        {
            switch (c)
            {
            case '#': Pop(s, ch);
                break;
            case '@': ClearStack(s);
                break;
            default: Push(s, c);
                break
            }
            c = getchar();
        }
        ClearStack(s);
        if (c != EOF) //如果c为换行符，则继续输入，否则摧毁堆栈退出这个方法
        {
            c = getchar();
        }
    }
    DestroyStack(s);
}//LineEdit