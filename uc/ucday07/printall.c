#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
//写print函数的代码，功能是打印出一个目录和它的子目录的内容(递归调用)
//思路：如果是子文件项，打印即可，如果子目录项，打印后 递归调用print打印子目录 NULL退出
void print(char* filename){
  //printf("-------------%s\n",filename);
  DIR* dir = opendir(filename);
  if(dir == NULL) return;//不带数据的返回
  struct dirent* ent;
  while(ent=readdir(dir)){
     if(ent->d_type == 4){//目录
		 if(strcmp(".",ent->d_name)==0 || 
		 strcmp("..",ent->d_name)==0)
		 continue;//如果是.或..,继续下次
		 printf("[%s]\n",ent->d_name);
		 char buf[100] = {};
		 strcpy(buf,filename);
		 strcat(buf,"/");
		 strcat(buf,ent->d_name);
		 print(buf);
	     //print(ent->d_name);
	 }else{//文件
	     printf("%s\n",ent->d_name);
	 }
  }
}
int main(){
  print("../");
  //...
  //print("ucday05");
}
