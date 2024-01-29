#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){//对比UC和标C函数 效果
  FILE* file = fopen("a.txt","w");
  if(file == NULL) perror("fopen"),exit(-1);
  int i;
  for(i=0;i<1000000;i++){
    fwrite(&i,4,1,file);
  }
  fclose(file);
}
