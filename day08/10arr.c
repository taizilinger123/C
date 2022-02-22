/*
 数组名称练习
 */
#include <stdio.h>
int main(){
  int arr[] = {1, 2, 3, 4, 5};
  char arr1[] = {'a', 'b', 'c', 'd', 'e'};
  //arr = 0; 数组名称不可以被赋值
  printf("arr是%p\n", arr);
  printf("&arr[0]是%p\n", &arr[0]);
  printf("arr + 3是%p,&arr[3]是%p\n", arr + 3, &arr[3]);
  printf("arr1 + 3是%p, &arr1[3]是%p\n", arr1 + 3, &arr1[3]);
  printf("sizeof(arr)是%d\n", sizeof(arr));
  printf("sizeof(arr1)是%d\n", sizeof(arr1));
  return 0;
}
