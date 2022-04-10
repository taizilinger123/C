/*
 结构体练习
 */
#include <stdio.h>
typedef struct {
   int x, y;
} pt;
pt *midpt(const pt *p_pt1, const pt *p_pt2, pt *p_mid){
   p_mid->x = (p_pt1->x + p_pt2->x)/2;
   p_mid->y = (p_pt1->y + p_pt2->y)/2;
   return p_mid;
}
int main(){
   pt pt1 = {5, 5}, pt2 = {7, 7}, mid = {0, 0};
   pt *p_pt = midpt(&pt1, &pt2, &mid);
   printf("mid是(%d, %d)\n", p_pt->x, p_pt->y);
   p_pt = NULL;
   return 0;
}
