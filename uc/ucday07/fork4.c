#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   //pid_t pid = fork();
   int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
   if(fd == -1) perror("open"),exit(-1);
   pid_t pid = fork();//fd只复制描述符不复制文件表
   if(pid ==0){//子进程
     printf("child:fd=%d\n",fd);
	 write(fd,"hello",5);
	 close(fd);
	 exit(0);
   }
   printf("father:fd=%d\n",fd);
   write(fd,"abcde",5);
   close(fd);
}
