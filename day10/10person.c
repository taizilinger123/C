/*
  人员信息练习
 */
#include <stdio.h>
void save(int id, char name[], int size, float salary){
   FILE *p_file = fopen("a.bin", "ab");
   if(p_file){
        fwrite(&id, sizeof(int), 1, p_file);
		fwrite(name, sizeof(char), size, p_file);
		fwrite(&salary, sizeof(float), 1, p_file);
		fclose(p_file);
		p_file = NULL;
   }
}

int main(){
  int id = 0, flag = 0;
  char name[20] = {};
  float salary = 0.0f;
  do {
	  printf("请输入id: ");
	  scanf("%d", &id);
	  printf("请输入姓名: ");
	  scanf("%s", name);
	  printf("请输入工资: ");
	  scanf("%f", &salary);
      save(id, name, 20, salary);
	  printf("是否还要继续输入下一个人员信息：");
	  scanf("%d", &flag);
  }while (flag);
  return 0;
}
