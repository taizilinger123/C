int a;
#gcc -E hello.c  -o  hello.i
#gcc -S hello.i  -o  hello.s
#gcc -c hello.s  -o  hello.o
#gcc hello.o -o hello
#记忆:ESc退出 iso镜像
#ldd  hello 查看hello运行所需要的.so库文件

