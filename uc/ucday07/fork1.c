#include <stdio.h>
#include <unistd.h>

int main(){
   printf("begin\n");
   pid_t pid = fork();//创建子进程->2个进程
   printf("end%d\n",pid);
}
