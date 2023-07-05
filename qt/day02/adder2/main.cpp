#include <QApplication>
#include "adder.h"
int main(int  argc,char**argv){
    QApplication  app(argc,argv);
	Adder  adder;
	adder.show();
	qDebug("this is  qt  output");  #这里是在命令行终端输出的
	return  app.exec();
}

/*
 root@test:/home/test/biaoc/C/qt/day02/adder2# make 
 g++ -c -m64 -pipe -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -o main.o main.cpp
 g++ -m64 -Wl,-O1 -o adder2 adder.o main.o moc_adder.o    -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
 root@test:/home/test/biaoc/C/qt/day02/adder2# ./adder2 
 this is  qt  output   #这句就是这里的打印qDebug("this is  qt  output");
 */
