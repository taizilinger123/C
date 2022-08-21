#include <stdio.h>
struct Date{
   
};
int main(){
  struct Date  date; 
  printf("%d\n",sizeof date);
}

/*
 root@test:/home/test/biaoc/C/C++/day01# gcc  struct.c 
 struct.c: In function ‘main’:
 struct.c:7:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
    printf("%d\n",sizeof date);
	          ^
			  root@test:/home/test/biaoc/C/C++/day01# ./a.out 
			  0
			  root@test:/home/test/biaoc/C/C++/day01# 
			  root@test:/home/test/biaoc/C/C++/day01# 
			  root@test:/home/test/biaoc/C/C++/day01# g++  struct.c 
			  struct.c: In function ‘int main()’:
			  struct.c:7:28: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
			     printf("%d\n",sizeof date);
				                             ^
											 root@test:/home/test/biaoc/C/C++/day01# ./a.out 
											 1
 */
