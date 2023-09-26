#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(){
   FILE* file = fopen("/etc/passwd1", "r");
   if(file == NULL){//先出错，再用perror()
	  printf("errno=%d\n",errno);
	  printf("%s\n",strerror(errno));//偶尔
     //perror("open passwd");//最常用
	 //printf("open passwd: %m\n");
	 return -1;
   }//errno->函数出错会改值，但成功不改值
   //因此errno不能用于判断是否出错
   printf("文件成功打开\n");
   fclose(file);
}
