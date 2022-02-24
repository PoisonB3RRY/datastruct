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

//汉诺塔 hanoi
void hanoi(int n, char x, char y, char z)
{
    //最初圆盘都在塔x上，由上到下编号为1~n，目标塔为z，y塔为辅助塔
    //搬动操作move(x,n,z)可以定义为(c是初始值为0的变量，可对全局搬动次数计数)
    if (n == 1)
    {
        move(x, 1, z); //将编号为1的圆盘从x柱移动到z柱
    }
    else
    {
        hanoi(n - 1, x, z, y); //讲编号为1至n-1的圆盘移到y，z做辅助
        move(x, n, z); //将编号为n的圆盘移动到z
        hanoi(n - 1, y, x, z); //将编号为1至n-1的圆盘移动到z，x做辅助
    }
}