/*
 秒表练习
 man 3 sleep
 */
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main(){
   int start = time(0);
   while(1){
      printf("%3ld\r",time(0) - start);
	  fflush(stdout);
	  sleep(1);
   }
   return 0;
}
