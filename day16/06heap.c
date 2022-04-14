/*
 堆练习
 */
#include <stdio.h>
#include <stdlib.h>
enum {CHAR, SHORT, INT};
void *heap_ma(int type, int size){
   if (type == CHAR){
      return malloc(size * sizeof(char));
   }
   else if (type == SHORT){
      return malloc(size * sizeof(short));
   }
   else {
      return malloc(size * sizeof(int));
   }

}
int main(){
   void *p = heap_ma(SHORT, 4);
   if (p) {
      printf("分配成功\n");
	  free(p);
	  p = NULL;
   }
   return 0;
}
