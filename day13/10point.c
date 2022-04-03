/*
 二级指针
 */
#include <stdio.h>
void swap(int** x,int** y)
{
	int *t = *x;
	*x = *y;
	*y = t;
}
int main(){
   int i = 5,j = 7;
   int *q = &i;
   int *p = &j;
   printf("before:&i=%p q=%p\n",&i,q);
   printf("before:&j=%p p=%p\n",&j,p);
   swap(&q,&p);
   printf("after:&i=%p p=%p\n",&i,p);
   printf("after:&j=%p q=%p\n",&j,q);
   return 0;
}
