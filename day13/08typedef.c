/*
 使用typedef
 */
#include <stdio.h>
typedef struct
{
    int ID;
	char name[20];
	char sex;
	int age;
}student;

int main(){
   student s;
   printf("请输入学号:");
   scanf("%d",&s.ID);
   printf("请输入姓名:");
   scanf("%s",s.name);
   printf("请输入性别:");
   scanf("%*c");//缓冲区中有一个\n
   scanf("%c",&s.sex);
   printf("请输入年龄:");
   scanf("%d",&s.age);
   printf("您输入的信息是:\n");
   printf("姓名:%s 学号:%d 性别:%c 年龄:%d\n", s.name,s.ID,s.sex,s.age);
   return 0;
}
