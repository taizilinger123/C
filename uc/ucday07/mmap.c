#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

struct emp {
   int id;
   char name[20];
   double sal;
};
int main(){
   int fd=open("emp.dat",O_RDWR|O_CREAT|O_TRUNC,0666);
   if(fd==-1) perror("open"),exit(-1);
   ftruncate(fd,sizeof(struct emp)*3);//设大小 //总线错误 (核心已转储
   void* p = mmap(0,sizeof(struct emp)*3,
		   PROT_READ|PROT_WRITE,
		   //MAP_SHARED,//写入文件，其他进程可读
		   MAP_PRIVATE,//不真正写入文件，其它进程不可读
		   fd,0);
   if(p == MAP_FAILED) perror("map"),exit(-1);
   struct emp* pe = p;
   pe[0].id = 1; strcpy(pe[0].name,"zhangfei");
   pe[0].sal = 12000.0;
   pe[1].id = 2; strcpy(pe[1].name,"guanyu");
   pe[1].sal = 20000.0;
   pe[2].id = 3; strcpy(pe[2].name,"zhaoyun");
   pe[2].sal = 24000.0;//存入文件
   int i;
   for(i=0;i<3;i++){
     printf("%d,%s,%lf\n",pe[i].id,pe[i].name,pe[i].sal);
   }
   munmap(p,sizeof(struct emp)*3);
   close(fd);
}
