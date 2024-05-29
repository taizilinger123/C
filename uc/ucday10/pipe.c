#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int fd[2] = {};
  pipe(fd);//内核管道文件和读写管道都OK
  pid_t pid = fork();
  if(pid == 0){//子进程执行
   close(fd[1]);//子进程关闭写通道
   while(1){
     int x;
	 if(read(fd[0],&x,4) <= 0) break;
	 printf("%d\n",x);
   }
   close(fd[0]);
   exit(0);
  }//父进程执行
  close(fd[0]);//父进程关闭读通道，子进程没影响
  int i;
  for(i=0;i<100;i++){
    write(fd[1],&i,4); usleep(100000);    
  }
  close(fd[1]);
}
