#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
   int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
   if(fd==-1)perror("open"),exit(-1);
   struct emp{
      int id;
	  char name[20];
	  double sal;
   };
   struct emp em = {1,"zhangfei",12000.0};
   char st[100] = {};
   sprintf(st,"%d,%s,%lf",em.id,em.name,em.sal);
   write(fd,st,strlen(st));
   close(fd);
}
