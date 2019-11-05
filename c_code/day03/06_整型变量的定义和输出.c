#include <stdio.h>

int main(int argc, char *argv[])
{
    int a;
    printf("请输入a: ");//输出
    //scanf("请输入a: %d");//err
    scanf("%d", &a); //输入
    printf("a = %d\n", a);
   
    //short占2字节
    //short b;
    short int b;
    printf("请输入b: ");//输出
    //%hd代表是短整型
    scanf("%hd", &b);
    printf( "b = %hd\n",  b);
    
    //long long  占8字节    
    long long c;
    printf("请输入c: ");//输出
    scanf("%lld", &c);
    printf("c = %lld\n", c);

    return 0;
}
