/*
  文件练习
 */
#include <stdio.h>
int main(){
   int arr[5][5] = {}, num = 0, num1 = 0;
   FILE *p_file = fopen("a.bin", "rb");
   if(p_file){
	   for(num = 0;num <= 4;num++){
	        fread(arr[num], sizeof(int), 5, p_file);
	   }
       fclose(p_file);
	   p_file = NULL;
   }
   for(num = 0;num <= 4;num++){
       for(num1 = 0;num1 <= 4;num1++){
	       printf("%3d", arr[num][num1]);
	   }
	   printf("\n");
   }
   return 0;
}
