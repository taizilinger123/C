/*
 结构体练习
 */
#include <stdio.h>
#include <stdbool.h>
/*struct phone {
   char manu[10];
   char model[10];
   float price;
   bool intelli;
};
typedef struct phone phone;*/  //typedef 后面接struct phone存在的名字，跟下面的宏相反
typedef struct /*phone*/ {
   char manu[10];
   char model[10];
   float price;
   bool intelli;
} phone;
//#define  phone  struct  phone  //宏是以#开头后面不接;
int main(){
   /*struct phone {
       char manu[10];
	   char model[10];
	   float price;
	   bool intelli;
   } iphone4*/;
   struct phone iphone4;
   phone iphone5;
   return 0;
}
