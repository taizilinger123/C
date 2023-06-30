#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QObject>
int main(int argc,char** argv){
   QApplication  app(argc,argv);
   QLabel qlab("hello qt!");
   qlab.show();
   /*构建按钮对象*/
   QPushButton qpush("close lab");
   /*显示按钮对象*/
   qpush.show();
   /*关联两个不相关的对象
   QObject::connect(&qpush,SIGNAL(clicked()),
	                &qlab,SLOT(close()));*/
   /*把按钮的信号 发送给app 结束这个程序*/
   QObject::connect(&qpush,SIGNAL(clicked()),
		            &app,SLOT(quit()));   
   return app.exec();
}
