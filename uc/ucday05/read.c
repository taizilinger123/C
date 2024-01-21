#include <stdio.h>  
//对应的printf函数
#include <stdlib.h>
//对应的exit函数
#include <unistd.h>
//对应的read/write函数
#include <fcntl.h>
//对应的open函数

int main(){
   int fd = open("a.txt",O_RDONLY);
   if(fd == -1)perror("open"),exit(-1);
   char buf[100] = {};
   int res = read(fd,buf,sizeof(buf));
   if(res == -1) perror("read"),exit(-1);
   printf("读到了%d字节，内容： %s\n",res,buf);
   close(fd);
}
//练习：用uc的系统函数实现文件复制


