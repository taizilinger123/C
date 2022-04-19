/*
 字符串格式化操作练习
 */
#include <stdio.h>
int main(){
	char buf[] = "123  5.7  g";
	int num = 0;
	float f_num = 0.0f;
	char ch = 0;
	sscanf(buf, "%d %g %c", &num, &f_num, &ch);
	printf("%c %g %d\n", ch, f_num, num);
	sprintf(buf, "%g %c %d", f_num, ch, num);
	printf("%s\n", buf);
    return 0;
}
