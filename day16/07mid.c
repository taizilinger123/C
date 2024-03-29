/*
 中间点位置练习
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int x,y;
} pt;
pt *midpt(const pt *p_pt1, const  pt *p_pt2){
  pt *p_pt =  (pt*)malloc(sizeof(pt));
  if (p_pt){
     p_pt->x = (p_pt1->x + p_pt2->x)/2;
     p_pt->y = (p_pt1->y + p_pt2->y)/2;
  }
  return p_pt;
}
int main(){
   pt pt1 = {0, 0}, pt2 = {0, 0};
   printf("请输入第一个点的位置: ");
   scanf("%d %d", &(pt1.x), &(pt1.y));
   printf("请输入第二个点的位置: ");
   scanf("%d %d", &(pt2.x), &(pt2.y));
   pt *p_pt = midpt(&pt1, &pt2);
   printf("中间点的位置是(%d, %d)\n", p_pt->x, p_pt->y);
   free(p_pt);
   p_pt = NULL;
   return 0;
}
