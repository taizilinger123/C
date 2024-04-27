#include <stdio.h>
#include <unistd.h>
//执行ls -l ../命令
int main(){
   printf("begin ls\n");
   //参数:1 是命令所在的路径 2 命令  3 选项
   //4 参数  以 NULL 结束
   execl("/bin/ls","ls","-l","../",NULL);
   printf("over ls\n");
}
