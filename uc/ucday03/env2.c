#include <stdio.h>
#include <stdlib.h>
//argc是argv的长度，argv是执行代码时命令中的单词数组(按空格划分)
//env就是环境表首地址
int main(int argc,char** argv,char** env){
  extern char** environ;
  printf("%p,%p\n",env,environ);
  char* value = getenv("LANG");
  printf("value=%s\n",value);
  putenv("VAR=ABC");
  printf("%s\n",getenv("VAR"));//ABC
  putenv("VAR=123");//肯定覆盖
  printf("%s\n",getenv("VAR"));//123
  setenv("VAR","456",0);//不覆盖
  printf("%s\n",getenv("VAR"));//123
  setenv("VAR","789",1);//覆盖
  printf("%s\n",getenv("VAR"));//789
}
