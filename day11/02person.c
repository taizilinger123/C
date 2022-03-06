/*
 人员信息打印练习
 */
#include <stdio.h>
#include <stdbool.h>
bool read(FILE *p_file){
  int id;
  char name[20] = {};
  float salary = 0.0f;
  if (p_file){
    if (!fread(&id, sizeof(int), 1, p_file)){
	    return true;
	}
	 fread(name, sizeof(char), 20, p_file);
	 fread(&salary, sizeof(float), 1, p_file);
	 printf("id是%d\n", id);
	 printf("姓名是%s\n", name);
	 printf("工资是%g\n", salary);
  }
  return false;
}
int main(){
  FILE *p_file = NULL;
  p_file = fopen("a.bin", "rb");
  if(p_file){
	 while (!read(p_file));
     fclose(p_file);
	 p_file = NULL;
  }
  return 0;
}

//02person.c:16:10: warning:代表16行有问题
//root@test:/home/test/biaoc/C/day11# cp ../day10/a.bin .
