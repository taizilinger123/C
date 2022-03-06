/*
 拷贝练习
 */
#include <stdio.h>
int main(){
   char buf[100] = {};
   FILE *p_file = NULL;
   FILE *p_file1 = NULL;
   int size = 0;
   p_file = fopen("a.bin", "rb");
   if(p_file){
	  p_file1 = fopen("b.bin", "wb");
	  if(p_file1){
		  size = fread(buf, sizeof(char), 100, p_file);
		  while(size){
             fwrite(buf, sizeof(char), size, p_file1);
			 size = fread(buf, sizeof(char), 100, p_file);
		  }
	      fclose(p_file1);
		  p_file1 = NULL;
	  }
      fclose(p_file);
	  p_file = NULL;
   }
   return 0;
}
//cp -r /home/test/biaoc/C/day06/a.out  ../day11/a.bin
//chmod 755  /home/test/biaoc/C/day11/b.bin
/*
root@test:/home/test/biaoc/C/day11# ./b.bin
54321
5432
543
54
5
root@test:/home/test/biaoc/C/day11# ./a.bin
54321
5432
543
54
5
*/

