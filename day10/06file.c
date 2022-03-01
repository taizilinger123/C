/*
    fwrite练习
 */
#include <stdio.h>
int main(){
	int num[] = {1, 2, 3, 4, 5};
   //FILE  *p_file = fopen("a.bin", "wb");
   FILE  *p_file = fopen("a.bin", "ab");
   if (p_file) {
       int size = fwrite(num,  sizeof(int), 5,  p_file);
	   printf("一共写了%d个整数变量\n", size);
       fclose(p_file);
	   p_file = NULL;
   }
   return  0;
}
