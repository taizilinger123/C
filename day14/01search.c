/*
 根据id查找人员信息
 */
#include <stdio.h>
int main(){
   FILE *p_file = fopen("a.bin", "rb");
   int size = 0, id = 0, newid = 0;
   char name[20] = {};
   float salary = 0.0f;
   if(p_file){
	   printf("请输入一个id:");
	   scanf("%d", &newid);
	   size = fread(&id, sizeof(int), 1, p_file);
	   while(size){
	      if(id == newid){
		     fread(name, sizeof(char), 20, p_file);
			 fread(&salary, sizeof(float), 1, p_file);
             printf("id是%d\n", id);
			 printf("姓名是%s\n", name);
			 printf("工资是%g\n", salary);
			 break;
		  }else{
		     fseek(p_file, 24, SEEK_CUR);
		  }
		  size = fread(&id, sizeof(int), 1, p_file);
	   }
       fclose(p_file);
       p_file = NULL;
   }
   return 0;
}
