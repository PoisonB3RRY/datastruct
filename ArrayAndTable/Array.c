#include "status.h"
#include <stdarg.h> //标准头文件，提供宏va_start、va_arg和va_end，用于存取变长参数表
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_DIM 8 //数组的最大维度为8

typedef struct {
    ElemType *base; //数组元素基址，由InitArray分配
    int dim;        //数组维数
    int *bound;     //数组维界基址，由InitArray分配
    int *constants; //数组映象函数常量基址，由InitArray分配
} Array;

Status InitArray(Array &A, int dim, ...);
//若维数dim和随后的各维度长度合法，则构造相应的数组A，并返回OK；

Status DestroyArray(Array &A);
//销毁数组A

Status Value(Array A, ElemType &e, ...);
// A是n维数组，e为元素变量，随后是n个下表值；
//若各下标不超界，则将e的值赋为所指定的A的元素，并返回ok

Status Assign(Array &A, int dim, ...);
// A是n维数组，e为元素变量，随后是n个下标值；
//若下标不超界，则将e的值赋给所指定的A的元素值，并返回OK

Status InitArray(Array &A, int dim, ...) {
    //若维数dim和各维长度合法，则构造相应的数组A，并返回OK
    if (dim < 1 || dim > MAX_ARRAY_DIM) {
        return ERROR;
    }
    A.dim = dim;
    A.bound = (int *)malloc(dim * sizeof(int));
    if (!A.bound) {
        exit(OVERFLOW);
    }
    //若各维长度合法，则存储A.bounds，并求出A的元素总数elemtotal
    int elemtotal = 1;
    va_start(ap, dim); // ap为va_list类型，是存放变长参数表信息的数组
    for (int i = 0; i < dim, ++i) {
        A.bound[i] = va_arg(ap, int);
        if (A.bounds[i] < 0) {
            return UNDERFLOW;
        }
        elemtotal *= A.bound[i];
    }
    va_end(ap);
    A.base(ElemType *) malloc(elemtotal * sizeof(ElemType));
    if (!A.base) {
        exit(OVERFLOW);
    }
    //求映像函数的常数Ci，并存入A.constants[i-1],i=1,...,dim
    A.constants = (int *)malloc(dim * sizeof(int));
    if (!A.constants) {
        exit(OVERFLOW);
    }
    A.constants[dim - 1] = 1; // L=1，指针的增减以元素的大小为单位
    for (int i = dim - 1; i >= 0; --i) {
        A.constants[i] = A.bound[i + 1] * A.constants[i + 1];
    }
    return OK;
}

Status DestoryArray(Array &A){
    //销毁数组A
    if(!A.base){
        return ERROR;
    }
    free(A.base);
    A.base=NULL;
    if(!A.bound){
        return ERROR;
    }
    free(A.bound);
    A.bound=NULL;
    if(!A.constants){
        return ERROR;
    }
    A.constants=NULL;
    return OK;
}

Status Locate(Array A, va_list ap, int &off){
    //若ap指标的格下标值合法，则求出该元素在A中的相对地址off
    off=0;
    for(int i=0; i<A.dim; i++){
        ind=va_arg(ap,int);
        if(ind<0 || ind>=A.bound[i]){
            return OVERFLOW;
        }
        off+=A.constants[i]*ind;
    }
    return OK;
}

Status Value(Array A, ElemType &e, ...){
    //A是n维数组，e是元素变量,随后是n个下标值。
    //若各下标不超界，则e赋值为所指定的A的元素值，并返回OK。
    va_start(ap,e);
    if((result=Locate(A,ap,off))<=0){
        return 0;
    }
    e=*(A.base+off);
    return OK;
}

Status Assign(Array &A, ElemType e, ...){
    //A是n维数组，e为元素变量,随后是n个下标值
    //若下标不超界，则将e的值赋给所指定的A的元素，并返回OK
    va_start(ap,e);
    if((result=Locate(A,ap,off))<=0){
        return result;
    }
    *(A.base+off)=e;
    return OK;
}
