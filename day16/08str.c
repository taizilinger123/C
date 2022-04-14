/*
 字符串拷贝和合并练习
 */
#include <stdio.h>
#include <stdlib.h>
char *mystrcpy(const char *p_str){
	//统计原字符串字符变量个数
   const char *p_old = p_str;
   while(*p_old){
      p_old++;
   }
   //分配新字符串内存
   char *p_ret = (char *)malloc((p_old - p_str + 1) * sizeof(char)); 
   if (!p_ret){
       return NULL;
   }
   //拷贝字符串
   char *p_new = p_ret;
   p_old = p_str;
   while(*p_old){
      *p_new = *p_old;
	  p_old++;
	  p_new++;
   }
   *p_new = 0;
   return p_ret;
}
char *mystrcat(const char *p_str, const char *p_str1){
    const char *p_old = p_str;
	int len = 0;
	//统计新字符串中字符变量个数
	while(*p_old){
	   p_old++;
	   len++;
	}
	p_old = p_str1;
	while(*p_old){
	   p_old++;
	   len++;
	}
	len++;
	//为新字符串分配内存空间
	char *p_ret = (char*)malloc(len * sizeof(char));
	if (!p_ret){
	    return NULL;
	}
	//把原字符串中字符拷贝到新字符串中
	p_old = p_str;
	char *p_new = p_ret;
	while (*p_old){
	    *p_new = *p_old;
	    p_old++;
	    p_new++;
	}
	p_old = p_str1;
	while (*p_old){
	    *p_new = *p_old;
		p_old++;
	    p_new++;
	}
	*p_new = 0;
	return p_ret;
}
int main(){
   char *p_str = mystrcpy("abcdef");
   if (p_str){
        printf("%s\n", p_str);
		free(p_str);
        p_str = NULL;
   }
   p_str = mystrcat("uvw", "xyz");
   if(p_str){
      printf("%s\n", p_str);
	  free(p_str);
      p_str = NULL;
   }
   return 0;
}
