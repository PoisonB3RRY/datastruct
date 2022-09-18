#include "status.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 255 //用户可以在255以内定义最大串长

typedef unsigned char SString[MAXSTRLEN + 1]; // 0号单元存放串的长度

Status Concat(SString &T, SString S1, SString S2) {
  bool uncut = false;
  if (S1[0] + S2[0] <= MAXSTRLEN) //未截断
  {
    for (int i = 1; i <= S1[0]; i++) {
      T[i] = S1[i];
    }
    for (int j = S1[0] + 1; j <= S2[0]; j++) {
      T[j] = S2[j];
    }
    T[0] = S1[0] + S2[0];
    uncut = true;
  } else if (S1[0] < MAXSTRLEN) { //截断
    for (int i = 1; i <= S1[0]; i++) {
      T[i] = S1[i];
    }
    for (int j = S[0] + 1; j <= MAXSTRLEN; j++) {
      T[j] = S2[j];
    }
    T[0] = MAXSTRLEN;
    uncut = false;
  } else { //截断 仅能取到S1
    for (int i = 1; i <= MAXSTRLEN; i++) {
      T[i] = S1[i];
    }
    T[0] = MAXSTRLEN;
    uncut = false;
  }
  return uncut;
}

Status SubString(SString &Sub, SString S, int pos, int len) {
  //用Sub返回串S的第pos个字符长起长度为len的子串
  //其中， 1<= pos <= StrLength(S)且第pos个字符起长度为len的子串

  if (pos < 1 || pos > S[0] || len < 0) {
    return ERROR;
  }
  int realLen = 0;
  if (len > S[0] - pos + 1) {
    realLen = S[0] - pos + 1;
  } else {
    realLen = len;
  }
  for (int i = 1; i <= realLen; i++) {
    Sub[i] = S[i + pos - 1];
  }
  Sub[0] = realLen;
  return OK;
}

int Index(SString S, SString T, int pos) {
  //返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0.
  //其中，T非空，1<=pos<=StrLength(S)。
  int i; //在S中查找时使用的游标
  S = S + pos;
  while (i <= S[0] - T[0]) {
    int j;
    for (j = 1; j <= T[0]; ++j) {
      if (*(S + j) == *(T + j)) {
        continue;
      } else {
        S++;
        T++;
        break;
      }
    }
    if (j == T[0] + 1) {
      return i;
    }
    ++i;
  }

  return 0;
}
