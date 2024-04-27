#include <stdio.h>
#include <unistd.h>
//执行ls -l ../命令
int main(){
   printf("begin ls\n");
   //参数:1 是命令所在的路径 2 命令  3 选项
   //4 参数  以 NULL 结束
   execl("/bin/ls","ls","-l","../",NULL);
   //execlp("ls","ls","-l","../",NULL);
   //execlp可以省略PATH中的路径
   printf("over ls\n");//不会打印
   //因为exec系列函数换了新的代码区,就是换了内存空间,fork和vfork是换了进程 
}
