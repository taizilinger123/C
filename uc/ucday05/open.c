#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   printf("O_RDONLY=%d,O_WRONLY=%d,O_RDWR=%d\n",
		O_RDONLY,O_WRONLY,O_RDWR);
   printf("O_CREAT=%d,O_APPEND=%d\n",O_CREAT,O_APPEND);
   int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
   //如果新建文件，需要指定权限
   if(fd == -1)
    perror("open"),exit(-1);
   printf("文件创建/打开成功\n");
   printf("fd=%d\n",fd);
   close(fd);
}
//man 2 open 
//man 2 read
//void * 是万能指针可以转化为char *,string *
