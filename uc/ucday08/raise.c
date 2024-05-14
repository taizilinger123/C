#include <stdio.h>
#include <signal.h>

void fa(int signo){
   printf("捕获了信号%d\n",signo);
}
int main(){
   signal(SIGINT,fa);
   raise(2);
   while(1);
}
