#include "status.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *ch; //若是非空串，则按串长分配存储区，否则ch为NULL；
  int length; //串长度
} HString;
