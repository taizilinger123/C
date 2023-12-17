#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
   int* pi = sbrk(4);//返回初始位置
   *pi = 100;
   double* pd = sbrk(8);
   *pd = 3.14;
   char* s = sbrk(10);
   strcpy(s, "hello");
   printf("%d,%lf,%s\n",*pi,*pd,s);
   brk(s);//只释放字符串
   brk(pi);//全部释放
}
