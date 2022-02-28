/*
 颠倒数组内容练习
 */
#include <stdio.h>
void reverse(int num[], int size){
     /*int num1 = 0;
	 for(num1 = 0;num1 <= (size - 1)/2;num1++){
	     if (2 * num1 != (size -1)){
		     int tmp = num[num1];
			 num[num1] = num[size - 1 - num1];
			 num[size - 1 - num1] = tmp;
		 }
	 }*/
     int head = 0, tail = size - 1;
	 while (head < tail) {
	    int tmp = num[head];
		num[head] = num[tail];
		num[tail] = tmp;
		head++;
		tail--;
	 }
}
int main(){
	int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int num1 = 0;
	for (num1 = 0;num1 <= 8;num1++){
	    printf("%d", num[num1]);
	}
	printf("\n");
	reverse(num, 9);
	for (num1 = 0;num1 <= 8;num1++){
	   printf("%d", num[num1]);
	}
	printf("\n");
    return 0;
}
