/*
 文件拷贝练习
 */
#include <stdio.h>
typedef struct {
   int id;
   char name[20];
   float salary;
} person;
void cp(FILE *p_src, FILE *p_dest, int id){
    person p;
	int num = 0;
	num = fread(&p, sizeof(person), 1, p_src);
	while(num) {
	    if (id != p.id){
		    fwrite(&p, sizeof(person), 1, p_dest);
		}
		num = fread(&p, sizeof(person), 1, p_src);
	}
}
int main(){
   FILE *p_src = fopen("a.bin", "rb");
   FILE *p_dest = NULL;
   if(p_src){
      p_dest = fopen("b.bin", "wb");
	  if(p_dest){
		 cp(p_src, p_dest, 2);
         fclose(p_dest);
		 p_dest = NULL;
	  }
	  fclose(p_src);
	  p_src = NULL;
   }
   return 0;
}
