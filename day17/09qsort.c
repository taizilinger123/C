/*
 qsort练习
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *p_num1, const void *p_num2){
    char **pp_str1 = (char **)p_num1;
	char **pp_str2 = (char **)p_num2;
	return strcmp(*pp_str1, *pp_str2);
}
int main(){
   char *names[] = {"China","France","England","America","Russia"};
   int pos = 0;
   qsort(names, 5, sizeof(char*), comp);
   for(pos = 0;pos <= 4;pos++){
      printf("%s\n", names[pos]);
   }
   return 0;
}
