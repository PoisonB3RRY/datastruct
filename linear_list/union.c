#include <stdio.h>
#include <stdlib.h>

void union(List &La, List Lb)
{
    // 将所有在线性表Lb中单不在La中的数据元素插入到La中
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);//求线性表的长度

    for (int i = 0; i < Lb_len; ++i)
    {
        GetElem(Lb, i , e); //取Lb中第i个数据元素赋值给e
        if (!LocateElem(La, e, equal))
        {
            ListInsert(La, ++La_len, e); //La中不存在和e相同的数据元素，则插入之
        }
    }
}// union