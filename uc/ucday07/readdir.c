#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
   DIR* dir = opendir("../");
   if(dir == NULL) perror("opendir"),exit(-1);
   struct dirent* ent = readdir(dir);//读第一项
   while(ent/*!= NULL*/){
      printf("%d,%s\n",ent->d_type,ent->d_name);
	  ent = readdir(dir);//读下一项
   }//目录的d_type为4，普通文件为8
}
