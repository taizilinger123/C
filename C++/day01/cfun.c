#include <stdio.h>
/*void  testcfun(void){
    printf("this is c fun\n");
}*/
/*c语言函数  有参需要严格匹配*/
void  testcfun(int x){
    printf("this is c fun\n");
}
int main(){
    testcfun();
    testcfun(1);
    testcfun(1,2);
}
