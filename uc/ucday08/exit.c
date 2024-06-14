#include <stdio.h>
#include <stdlib.h>
void at(){
   printf("at() is called\n");
}
int main(){
   atexit(at);//注册了exit()在退出前调用的函数
   printf("准备退出进程\n");
   //return 0;//也会调用at()
   //exit(0);//调用at(),然后退出
   _Exit(0);//立即退出，不调用at()
}
