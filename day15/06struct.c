/*
 结构体练习
 */
#include <stdio.h>
typedef struct {
   int x, y;
} pt;
int main(){
   pt pt1 = {1, 2}, pt2 = {3, 4};
   pt1 = pt2;
   printf("pt1是(%d, %d)\n", pt1.x, pt1.y);
   return 0;
}
