#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   printf("父进程开始运行\n");
   pid_t pid = fork();//创建子进程
   if(pid==0){//子进程
     printf("我是子进程\n");
   }else{//父进程
     printf("我是父进程\n");
   }
   printf("进程%d over\n",getpid());
}//练习：在子进程和父进程中，打印出父子进程的PID
