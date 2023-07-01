#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
int main(int argc,char** argv){
   QApplication app(argc,argv);
   /*造一个父窗口对象*/
   QWidget  *parent=new QWidget();
   parent->resize(500,400);
   parent->show();
   QPushButton *qpush=new QPushButton("close",parent);
   qpush->resize(100,100);
   qpush->move(200,250);
   qpush->show();
   /*创建标签对象 设置父窗口指针 移动位置*/
   QLabel  *qlab=new QLabel("hello qt",parent);
   qlab->move(200,50);
   qlab->show();
   /*实现点击按钮  关闭标签*/
   QObject::connect(qpush,SIGNAL(clicked()),qlab,SLOT(close()));
   /*点击按钮  关闭父窗口*/
   QObject::connect(qpush,SIGNAL(clicked()),parent,SLOT(close()));
   return app.exec();
}

/*
root@test:/home/test/biaoc/C/qt/day01/closelab2# make 
make: Nothing to be done for 'first'.  #这个意思是没有任何代码改变
root@test:/home/test/biaoc/C/qt/day01/closelab2# ls
closelab2  closelab2.cpp  closelab2.o  closelab2.pro  Makefile
root@test:/home/test/biaoc/C/qt/day01/closelab2# ./closelab2 
如果之前执行过qmake -project  qmake  make  ./closelab2后面再改当前代码
就只需要执行make ./closelab2就可以了，不需要再执行make -project qmake了
root@test:/home/test/biaoc/C/qt/day01/closelab2# cat   ../../../gitPush.sh 
#!/bin/bash 
DATE=`date +%Y%m%d`
git  add *
git commit -m  "$DATE"
git  push  git@github.com:taizilinger123/C.git
*/
