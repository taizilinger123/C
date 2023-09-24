#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void print(char* str){//没有错误处理 返回void
   printf("%s\n",str);
}
char* iserror(char* str){//返回指针 NULL代表出错
  if(strcmp("error",str)==0) return "ok";
  return NULL;
}
int rand10(){
   srand(time(0));
   int ra = rand()%10 + 1;
   if(ra==5) return -1;
   return ra;
}
int max(int x,int y,int* r){
  if(x == y) return -1;
  *r = (x>y)?x:y;//指针拿到了最大值
  return 0;//返回0代表正确
}
int main(){
  print("hello");
  char* st = iserror("erro");
  if(st/*!=NULL*/) printf("%s\n",st);
  else printf("返回NULL，出错了\n");
  int r = rand10();
  if(r == -1)printf("出错了\n");
  else printf("%d\n",r);
  int res = max(3,3,&r);
  if(res==-1) printf("出错了\n");
  else printf("max=%d\n",r);
}
