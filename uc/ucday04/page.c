#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("pid=%d\n",getpid());
  int size = getpagesize();
  printf("size=%d\n",size);
  int* p = malloc(4);//映射了33个内存页
  //(p+33*1024-4) = 100;//移动到了33页之外
  sleep(20);
  printf("malloc2\n");
  int* p2 = malloc(4096*20);
  sleep(15);
  printf("malloc3\n");
  int* p3 = malloc(4096*13-4);
  sleep(15);
  printf("malloc4\n");
  int* p4 = malloc(4096);
  free(p4);
  free(p3);
  printf("free p3\n");
  sleep(15);
  free(p2);
  printf("free p2\n");
  sleep(15);
  free(p);printf("free all\n");
  while(1);
}
