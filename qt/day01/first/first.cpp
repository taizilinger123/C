#include <QApplication>
#include <QtGui/QLabel>
int main(int argc,char**argv){
   /*构建一个QApplication  对象*/
   QApplication  app(argc,argv);
   /*构建一个标签*/
   QLabel qlab("hello qt!");
   qlab.show();
   /*让程序进入事件循环 等待用户输入消息*/
   return app.exec();
}

/*
 root@test:/home/test/biaoc/C/qt/day01/first# vi  first.cpp 
 root@test:/home/test/biaoc/C/qt/day01/first# ls
 first.cpp
 root@test:/home/test/biaoc/C/qt/day01/first# qmake -project
 root@test:/home/test/biaoc/C/qt/day01/first# ls
 first.cpp  first.pro
 root@test:/home/test/biaoc/C/qt/day01/first# vi first.pro
 root@test:/home/test/biaoc/C/qt/day01/first# qmake 
 root@test:/home/test/biaoc/C/qt/day01/first# ls
 first.cpp  first.pro  Makefile
 root@test:/home/test/biaoc/C/qt/day01/first# make
 g++ -c -m64 -pipe -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -o first.o first.cpp
make: 放弃循环依赖 all <- first 。
g++ -m64 -Wl,-O1 -o first first.o    -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
root@test:/home/test/biaoc/C/qt/day01/first# ls
first  first.cpp  first.o  first.pro  Makefile
root@test:/home/test/biaoc/C/qt/day01/first# date 
2023年 06月 24日 星期六 14:55:10 CST
root@test:/home/test/biaoc/C/qt/day01/first# ls
first  first.cpp  first.o  first.pro  Makefile
root@test:/home/test/biaoc/C/qt/day01/first# ./first 
first: cannot connect to X server 
sh  ../../../gitPush.sh
 */
