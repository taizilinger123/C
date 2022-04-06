/*
 条件编译练习
 */
#include <stdio.h>
int main(){
#if    defined(ELITE)
     printf("120%%\n");
#elif  !defined(ELITE) && !defined(FACTORY)
     printf("100%%\n");
#else
	 printf("80%%\n");
#endif
  return 0;
}

/*
root@test:/home/test/biaoc/C/day14# gcc 13compile.c 
root@test:/home/test/biaoc/C/day14# ./a.out 
100%
root@test:/home/test/biaoc/C/day14# gcc  -DELITE  13compile.c 
root@test:/home/test/biaoc/C/day14# ./a.out 
120%
root@test:/home/test/biaoc/C/day14# gcc  -DFACTORY  13compile.c 
root@test:/home/test/biaoc/C/day14# ./a.out 
80%

 
*/
