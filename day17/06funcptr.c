/*
 函数指针练习
 */
#include <stdio.h>
typedef struct {
   int x, y;
   int (*p_Func)(int, int);
} cal;
int add(int x, int y){
   return x + y;
}
int sub(int x, int y){
   return x - y;
}
int mul(int x, int y){
   return x * y;
}
int div(int x, int y){
   return x / y;
}
int main(){
   int pos = 0;
   char ch = 0;
   cal cals[3];
   for(pos = 0;pos <= 2;pos++){
      printf("请输入公式: ");
	  scanf("%d%c%d", &(cals[pos].x), &ch, &(cals[pos].y));
      if (ch == '+'){
	     cals[pos].p_Func = add;
	  }
	  else if (ch == '-'){
	     cals[pos].p_Func = sub;
	  }
	  else if (ch == '*'){
	     cals[pos].p_Func = mul;
	  }
	  else {
	     cals[pos].p_Func = div;
	  }
   }
   for (pos = 0;pos <= 2;pos++){
       printf("计算结果是%d\n", cals[pos].p_Func(cals[pos].x, cals[pos].y));
   }
   return 0;
}
