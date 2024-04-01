#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd = open("a.txt",O_RDWR);
   struct flock lock;
   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 5;
   lock.l_pid = -1;//读写之前加锁
   /*int res = fcntl(fd,F_SETLK,&lock);
   if(res != -1){//锁定成功
      write(fd,"HELLO",5);//读写
	  lock.l_type = F_UNLCK;//读写完毕释放锁
	  fcntl(fd,F_SETLK,&lock);
   }else{
      printf("其他进程正在使用文件，写失败\n");
   }*/
   int res = fcntl(fd,F_SETLKW,&lock);//等待写
   if(res==-1) perror("fcntl"),exit(-1);
   write(fd,"abcde",5);
   lock.l_type = F_UNLCK;//读写完毕释放锁
   fcntl(fd,F_SETLK,&lock);
   close(fd);
}
