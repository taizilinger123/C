#include <QApplication>
#include <QtGui/QLabel>
#include <QTextCodec>
int main(int argc,char**argv){
   /*构建一个QApplication  对象*/
   QApplication  app(argc,argv);
   /*得到编码对象*/
   QTextCodec *coder=QTextCodec::codecForName("utf-8");
   /*设置编码对象*/
   //QTextCodec::setCodecForTr(coder);
   /*构建一个标签*/
   //QLabel qlab(QObject::tr("你好 qt!","utf-8"));
   QLabel  qlab(coder->toUnicode("你好 qt!"));
   qlab.show();
   /*让程序进入事件循环 等待用户输入消息*/
   return app.exec();
}
