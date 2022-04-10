/*
 结构体练习
 */
#include <stdio.h>
typedef struct {
    int x, y;
} pt;
typedef struct {
    pt  pt1, pt2;
} rect;
int main(){
   pt pt1 = {1, 2};
   rect r = {{3, 7}, {8, 13}};
   printf("(%d, %d)\n", pt1.x, pt1.y);
   printf("(%d, %d) (%d, %d)\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);
   return 0;
}
