#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int fd = open("b.txt",O_RDWR|O_CREAT,0777);
	if(fd==-1) perror("open"),exit(-1);
	struct stat s = {};
	fstat(fd,&s);
	printf("mode=%o\n",s.st_mode & 0777);
}
