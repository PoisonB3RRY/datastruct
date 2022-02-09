/*
 * =====================================================================================
 *
 *       Filename:  pointerTest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2022/02/09 12时39分26秒
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

void main(){
				int a = 10;
				int *b = &a;
				printf("%p\n", &a);
				printf("%p\n", b);
				printf("%p\n", &b);
				printf("%d\n", a);
				printf("%d\n", b);
				printf("%p\n", b);
				printf("%d\n", *b);
}
