/*
 文件练习
 */
#include <stdio.h>
int main(){
   int arr[][5] = {1, 2, 3, 4, 5,
	               6, 7, 8, 9, 10, 
				   11, 12, 13, 14, 15,
				   16, 17, 18, 19, 20,
				   21, 22, 23, 24, 25};
   int num = 0;
   FILE *p_file = fopen("a.bin", "wb");
   if(p_file) {
       /*for(num = 0;num <= 4;num++){
	      fwrite(arr[num], sizeof(int), 5, p_file);
	   }*/
	   fwrite(arr, sizeof(int), 25, p_file);
	   fclose(p_file);
	   p_file = NULL;
   }
   return 0;
}
