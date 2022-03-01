/*
  fread练习
 */
#include <stdio.h>
int main(){
   int num[20] = {}, num1 = 0;
   FILE *p_file = fopen("a.bin", "rb");
   if(p_file){
        int  size = fread(num, sizeof(int), 20, p_file);
		printf("一共读出%d个整数变量\n", size);
		for(num1 = 0;num1 <= size - 1;num1++){
		    printf("%d ", num[num1]);
		}
		printf("\n");
		fclose(p_file);
        p_file = NULL;
   }

   return 0;
}
