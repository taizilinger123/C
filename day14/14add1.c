#include "14add1.h"
int  result = 0;
//static int result;//静态全局变量不可以被其他文件使用
void add(int x, int y){
   result =  x + y;
}
