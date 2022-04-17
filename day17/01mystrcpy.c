/*
 mystrcpy函数练习
 */
#include <stdio.h>
#include <stdlib.h>
void mystrcpy(const char *p_str, char **pp_str){
     const char *p_old = p_str;
	 while(*p_old){
	     p_old++;
	 }
	char *p_new = (char *)malloc((p_old - p_str + 1) * sizeof(char));
	if (!p_new){
	  *pp_str = NULL;
	  return;
	}
	*pp_str = p_new;
	p_old = p_str;
    while(*p_old){
	   *p_new = *p_old;
	   p_old++;
	   p_new++;
	}
	*p_new = 0;
}
int main(){
   char *p_str = NULL;
   mystrcpy("abcdef", &p_str);
   if(p_str){
       printf("%s\n", p_str);
	   free(p_str);
	   p_str = NULL;
   }
   return 0;
}
