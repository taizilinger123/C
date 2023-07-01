#include <QApplication>
#include <QWidget>
#include <QPushButton>
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
   return app.exec();
}
