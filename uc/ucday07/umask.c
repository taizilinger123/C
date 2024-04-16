#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	mode_t old = umask(0123);//修改权限屏蔽字
	//系统默认的权限屏蔽字 002
    int fd = open("b.txt",O_RDWR|O_CREAT,0777);
	if(fd==-1) perror("open"),exit(-1);
	struct stat s = {};
	fstat(fd,&s);
	printf("mode=%o\n",s.st_mode & 0777);
	umask(old);//还原系统屏蔽字
	//要删除原来的b.txt文件再gcc umask.c  a.out
}
