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
   return app.exec();
}
