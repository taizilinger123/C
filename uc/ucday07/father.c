#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
   printf("欢迎使用银行ATM系统\n");
   printf("输入1存钱,2取钱,0退出\n");
   int num;
   scanf("%d",&num);
   if(num == 1){
     pid_t pid = vfork();
	 if(pid == 0){
	    execl("./child","child",NULL);
		//exit(0);//exec后面的代码不会被执行
	 }
   }else if(num == 2){
   
   }else if(num == 0){
     exit(0);
   }else{
     printf("输入错误\n");
   }

}
