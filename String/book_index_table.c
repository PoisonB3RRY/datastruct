#include "status.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK_NUM 1000 //假设只对1000本书建索引表
#define MAX_KEY_NUM 2500  //索引表的最大容量
#define MAX_LINE_LEN 500  //书目串的最大长度
#define MAX_WORD_NUM 10   //词表的最大容量

typedef struct {
    char *item[];	//字符串数组
    int last;	//词表的长度
} WordListType; //词表类型
typedef int ElemType;	//链表的数据类型为整型
typedef struct {
    HString key; //关键词
    LinkList bnolist; //存放书号类型索引的链表
} IdxTermType; //索引项类型
typedef struct {
    IdxTermType item[MAX_KEY_NUM + 1];
    int last;
} IdxListType;	//索引表类型

char *buf;	//书目串缓冲区
WordListType wdList; //词表

//基本操作

void InitIdxList(IdxListType &idxList);

void GetLine(FILE f); //从文件f读一个书目信息到书目串缓冲区buf

void ExtractKeyWord(ElemType &bno);

Status InsIdxList(IdxListType &idxList, ElemType bno);

void PutText(FILE g, IdxListType idxList);

void main()
{

}