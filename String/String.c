#include<stdio.h>
#include<stdlib.h>
#include "status.h"

#define MAXSTRLEN 255 //用户可以在255以内定义最大串长

typedef unsigned char SString[MAXSTRLEN+1]; //0号单元存放串的长度