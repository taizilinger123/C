/*
 人员信息系统练习
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[20];
	float salary;
} person;
person *read(void){
  person *p_ret = (person*)malloc(sizeof(person));
  if (!p_ret){
     return NULL;
  }
  printf("请输入id: ");
  scanf("%d", &(p_ret->id));
  scanf("%*[^\n]");
  scanf("%*c");
  printf("请输入姓名: ");
  fgets(p_ret->name, 20, stdin);
  if(strlen(p_ret->name) == 19 && p_ret->name[18] != '\n'){
      scanf("%*[^\n]");
	  scanf("%*c");
  }
  printf("请输入工资: ");
  scanf("%g", &(p_ret->salary));
  return p_ret;
}
int main(){
   person *p_person = NULL;
   FILE *p_file = fopen("a.bin", "ab");
   int flag = 0;
   if (p_file){
      do {
	   p_person = read();
	   if (p_person){
	      fwrite(p_person, sizeof(person), 1, p_file);
		  free(p_person);
		  p_person = NULL;
	   }
	   printf("是否还要输入人员信息(0表示否，1表示是):"); 
	   scanf("%d", &flag);
	  }while (flag);
	  fclose(p_file);
	  p_file = NULL;
   }
   return 0;
}
