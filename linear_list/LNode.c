/*
 * =====================================================================================
 *
 *       Filename:  LNode.c
 *
 *    Description: 线性链表 
 *
 *        Version:  1.0
 *        Created:  2022/01/28 14时48分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
				ElemType data;
				struct LNode *next;
}*Link, *Position;

typedef struct{					//链表类型
				Link head, tail;   //分别指向线性链表中的头结点和最后一个结点
				int len;						//指示线性表中数据元素的个数
}LinkList;


