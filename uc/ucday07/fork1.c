#include <stdio.h>
#include <unistd.h>

int main(){
   printf("begin\n");
   fork();//创建子进程->2个进程
   printf("end\n");
}
