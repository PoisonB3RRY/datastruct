#include <stdarg.h>	//标准头文件，提供宏va_start、va_arg和va_end，用于存取变长参数表
#include "status.h"
#define MAX_ARRAY_DIM 8 //数组的最大维度为8

typedef struct {
    ElemType *base;		//数组元素基址，由InitArray分配
    int dim;	//数组维数
    int *bound;		//数组维界基址，由InitArray分配
    int *constants;		//数组映象函数常量基址，由InitArray分配
} Array;

Status InitArray(Array &A, int dim, ...);
//若维数dim和随后的各维度长度合法，则构造相应的数组A，并返回OK；