/*
 递归函数练习
 */
#include <stdio.h>
/*void f(){
   printf("1\n");
   f();
}*/
void f(int num){
    if (num){
	    printf("1\n");
		f(num - 1);
	}
}
int main(){
   int num = 0;
   /*for(num = 0;num <= 4;num++){
      printf("1\n");
   }*/
   f(5);
   return 0;
}
