#include <stdio.h>

int main(){
   int n = 10;
   //const int* p = &n;
   int* const p = &n;
   *p = 100;
   //n = 100;
   printf("%d\n",*p);
   return 0;
}
