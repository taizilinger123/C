#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i1 = 100;
int main(){
   int i2 = 200;//父进程定义，子进程复制
   char* st = malloc(20);
   strcpy(st,"abcd");
   pid_t pid = fork();
   if(pid==-1) perror("fork"),exit(-1);
   int i3 = 300;//fork之后的变量父子进程分别定义了i3
   if(pid==0){//子进程
     i1=10; i2=20; i3=30; strcpy(st,"123");   
	 printf("child:i1=%d,i2=%d,i3=%d,st=%s\n",i1,i2,i3,st);
	 printf("child:&i1=%p,st=%p\n",&i1,st);
	 exit(0);
   }
   sleep(1);//只有父进程执行
   printf("father:i1=%d,i2=%d,i3=%d,st=%s\n",i1,i2,i3,st);
   printf("father:&i1=%p,st=%p\n",&i1,st);

}
