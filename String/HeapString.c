#include "status.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *ch; //若是非空串，则按串长分配存储区，否则ch为NULL；
    int length; //串长度
} HString;

Status StrAssign(HString &T, char *chars);
//生产一个值等于串常量chars的串T

int StrLength(HString T);
//返回串T的长度

int StrCompare(HString S, HString T);
//若S>T，则返回值>0；若S=T则返回0；若S<T则返回值>0

Status ClearString(HString &S);
//将S清空并释放S所占的空间

Status Concat(HString &T, HString S1, HString S2);
//用T返回S1和S2连接而成的空串

HString SubString(HString S, int pos, int len);
//返回串S的第pos个字符起长度为len的子串

Status StrAssign(HString &T, char *chars) {
    //生产一个值等于串常量chars的串T
    if (T.ch) {
        free(T.ch);
    }
    //求串chars的长度
    int i;
    for (i = 0 char *c = chars; c; ++i, ++c) {
        /* code */
    }
    if (i == 0) {
        T.ch = NULL;
        T.length = 0;
    } else {
        T.ch = (char *)malloc(sizeof(char) * i);
        for (int j = 0; j < i; ++j) {
            T.ch[j] = chars[j];
        }
        T.length = i;
    }

    return OK;
}

int StrLength(HString S) {
    //返回S的元素个数，称为串的长度
    return S.length;
}

int StrCompare(HString S, HString T) {
    for (int i = 0; i < S.length && i < T.length; ++i) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

Status ClearString(HString &S) {
    //如果S是空串，则直接返回
    //否则清空S
    if (S.ch == NULL) {
        return OK;
    } else {
        free(S.ch);
        S.ch = NULL;
        S.length = 0;
    }

    return OK;
}

Status Concat(HString &T, HString S1, HString S2) {
    if (T.ch) {
        free(ch);
    }
    T.ch = (char *)malloc(sizeof(char) * (S1.length + S2.length));
    if (!T.ch) {
        return OVERFLOW;
    }
    int i = j = 0;
    while (i <= S1.length) {
        T.ch++ = S1.ch++;
        ++i;
    }
    while (j <= S2.length) {
        T.ch++ = S2.ch++;
        ++j;
    }
    T.length = S1.length + S2.length;
    T.ch - T.length;
    return OK;
}

Status SubString(HString &Sub, HString S, int pos, int len) {
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) {
        return ERROR;
    }
    if (Sub.ch) {
        free(Sub.ch);
    }
    Sub.ch = (char *)malloc(sizeof(char) * len);
    if (!Sub.ch) {
        return OVERFLOW;
    }
    int i = 0;
    S.ch + pos - 1;
    while (i <= len) {
        Sub.ch++ = S.ch++;
        ++i;
    }
    Sub.ch - len;
    return OK;
}