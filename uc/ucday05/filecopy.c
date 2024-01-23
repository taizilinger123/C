#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fdr = open("a.txt",O_RDONLY);
  if(fdr == -1) perror("open a"),exit(-1);
  int fdw = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fdw == -1) perror("open b"),exit(-1);
  char buf[3] = { };
  while(1){
	 //printf("aaaaaaa\n");//读了5次，3-3-3-1-0 (hello word)
     int res = read(fdr,buf,sizeof(buf));
     if(res == -1) perror("read"),exit(-1);
	 if(res == 0) break;//多读一次 文件尾
     write(fdw,buf,res);
  }
  close(fdr);close(fdw);
}
