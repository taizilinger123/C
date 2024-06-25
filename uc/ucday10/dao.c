#include "dao.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
//定义一个文件来存储账号
const char* ID_FILE = "id.dat";
//生成不重复的账号
int generator_id(){
   static int x = 100000;
   if(access(ID_FILE,F_OK)==-1){//判断文件是否存在
     //不存在就创建
	 int fd = open(ID_FILE,O_WRONLY|O_CREAT|O_EXCL,0600);
     if(fd == -1){
	    perror("文件打开失败");
		return -1;
	 }
	 write(fd,&x,sizeof(x));//写入文件
	 close(fd);
	 return x;
   }
   //如果文件存
   int fd = open(ID_FILE,O_RDWR);
   if(fd == -1){
      perror("文件打开失败");
	  return -1;
   }
   //将文件中的数值读到x中
   read(fd,&x,sizeof(x));
   x++;//保证账号唯一
   //将读写位置置到文件开始头
   lseek(fd,0,SEEK_SET);
   //再将x的值写到文件中，覆盖原来的x
   write(fd,&x,sizeof(x));
   close(fd);
}
