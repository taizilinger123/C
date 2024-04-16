#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
   if(access("a.txt",F_OK)==0)
	   printf("文件存在\n");
   else printf("文件不存在\n");
   if(!access("a.txt",R_OK)) printf("可读\n");
   if(!access("a.txt",W_OK)) printf("可写\n");
   if(!access("a.txt",X_OK)) printf("可执行\n");

   chmod("a.txt",0766);//改变文件权限
   truncate("a.txt",100);//改变文件大小
}

