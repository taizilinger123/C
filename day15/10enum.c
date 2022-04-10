/*
 枚举类型练习
 */
#include <stdio.h>
/*#define  SPR     0
#define  SUM     1
#define  AUT     2
#define  WIN     3*/
int main(){
	enum {SPR, SUM = 8, AUT, WIN};
	printf("AUT是%d\n", AUT);
    return 0;
}
