#include "status.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK_NUM 1000 //假设只对1000本书建索引表
#define MAX_KEY_NUM 2500  //索引表的最大容量
#define MAX_LINE_LEN 500  //书目串的最大长度
#define MAX_WORD_NUM 10   //词表的最大容量

typedef struct {
  char *item[];
  int last;
} WordListType;
typedef int ElemType;
typedef struct {
  HString key;
  LinkList bnolist;
} IdxTermType;
typedef struct {
  IdxTermType item[MAX_KEY_NUM + 1];
  int last;
} IdxListType;

char *buf;
WordListType wdList;