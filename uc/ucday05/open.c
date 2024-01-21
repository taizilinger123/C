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
//man 2 write
// ssize_t read(int fd, void *buf, size_t count)
//void * 是万能指针可以转化为char *,string *
//void *buf void *比数组大，是首地址 size_t代表buf的大小
/*
int read(int fd, void* buf, size_t size);  读是从文件里的读到内存里去，写是从内存里写到文件里去。
参数：fd      代表  一个打开的文件描述符
	  buf            一块内存的首地址
	  size            buf的大小(sizeof)
返回：>0      实际读到的字节数											  ==0   标识  读到了文件尾											  -1       读文件出错
*/
