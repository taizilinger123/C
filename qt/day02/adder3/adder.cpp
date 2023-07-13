#include "adder.h"
Adder::Adder(){
   /*创建界面对象*/
   ui=new Ui_Dialog();
   /*加载界面对象*/
   ui->setupUi(this);
   /*如何实现功能?访问界面元素通过ui访问即可*/
   /*连接equ到this getRes*/
   connect(ui->equ,SIGNAL(clicked()),this,SLOT(getRes()));
}
Adder::~Adder(){
   delete ui;
}
void   Adder::getRes(){
   ui->res->setText(QString::number(
   ui->add->text().toInt()+
   ui->added->text().toInt()));
}

