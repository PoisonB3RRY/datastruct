/*
 * =====================================================================================
 *
 *       Filename:  doubleLinkedList.c
 *
 *    Description: 双向链表 
 *
 *        Version:  1.0
 *        Created:  2021/12/28 16时07分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (nickj), 
 *   Organization:  SPDB
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

#define ElemType int

typedef struct DuLNode{
				ElemType data;
				struct DuLNode *prior;
				struct DuLNode *next;
}DuLNode, *DuLinkList;


