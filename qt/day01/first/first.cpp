#include <QApplication>

int main(int argc,char**argv){
   /*构建一个QApplication  对象*/
   QApplication  app(argc,argv);

   /*让程序进入事件循环*/
   return app.exec();
}
