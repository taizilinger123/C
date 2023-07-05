#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
int main(int argc,char **argv){
   QApplication  app(argc,argv);
   QWidget  *parent;
   QSlider  *qsli;
   QSpinBox *qspin;
   /*给父窗口赋值*/
   parent=new QWidget();
   parent->resize(500,300);
   /*创建组件*/
   qsli=new QSlider(parent);
   qspin=new QSpinBox(parent);
   /*调整组件的位置和大小*/
   qsli->move(50,50);
   qsli->resize(30,200);
   qspin->move(200,200);
   qspin->resize(40,40);
   //qspin->setValue(198);
   parent->show();
   /*如何让qsli去影响qspin*/
   QObject::connect(qsli,SIGNAL(valueChanged(int)),
		   qspin,SLOT(setValue(int)));
   /*qspin去影响qsli*/
   QObject::connect(qspin,SIGNAL(valueChanged(int)),
		   qsli,SLOT(setValue(int)));
   return  app.exec();
}
