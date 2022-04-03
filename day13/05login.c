/*
 模拟登录
 */
#include <stdio.h>
int main(){
   char usr[20];
   char pwd[20];
   int count = 0;//记录登录次数
   while(count<3){
      printf("\t模拟登录\n");
	  printf("用户名:");
	  fgets(usr,20,stdin);
	  printf("密码:");
      fgets(pwd,20,stdin);
	  if(strcmp(usr,"admin\n")==0&&strcmp(pwd,"123456\n")==0){
	     printf("登录成功!\n");
		 return 0;
	  }
	  printf("登录失败...");
	  count++;
   }
   printf("三次登录失败，请联系管理员...\n");
   return  0;
}
