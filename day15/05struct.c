/*
 结构体练习
 */
#include <stdio.h>
#define ABS(n) ((n) > 0 ? (n) : 0 - (n))
typedef struct {
   int x, y;
} pt;
typedef struct {
   pt pt1, pt2;
} rect;
int main(){
   rect r = {{0, 0}, {0, 0}};
   printf("请输入第一个点的位置: ");
   scanf("%d %d", &(r.pt1.x), &(r.pt1.y));
   printf("请输入第二个点的位置: ");
   scanf("%d %d", &(r.pt2.x), &(r.pt2.y));
   printf("面积是%d\n", ABS(r.pt1.x - r.pt2.x)*ABS(r.pt1.y - r.pt2.y));
   pt mid = {(r.pt1.x + r.pt2.x)/2, (r.pt1.y + r.pt2.y)/2};
   printf("中心点位置是(%d, %d)\n", mid.x, mid.y);
   return 0;
}
