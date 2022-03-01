/*
 文件操作练习
 */
#include <stdio.h>
int main(){
   FILE *p_file = fopen("a.bin", "w");
   if (p_file) {
	  //...
      fclose(p_file);
	  p_file = NULL;
   }
   return 0;
}
