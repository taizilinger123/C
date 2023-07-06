#include "qq.h"
//构造函数
QQ::QQ(){
   this->resize(400,300);
   /*给成员变量赋值*/
   username=new  QLineEdit(this);
   userpasswd=new QLineEdit(this);
   login=new QPushButton("login",this);
   cancel=new QPushButton("cancel",this);
   /*调整组件的位置*/
   username->move(200,50);
   userpasswd->move(200,100);
   login->move(50,200);
   cancel->move(250,200);
   connect(login,SIGNAL(clicked()),this,SLOT(loginAndCancel()));
   connect(cancel,SIGNAL(clicked()),this,SLOT(loginAndCancel()));
}
//析构函数
QQ::~QQ(){
   delete username;
   delete userpasswd;
   delete login;
   delete cancel;
}
#include <QMessageBox>
//槽函数
void  QQ::loginAndCancel(){
   /*要区分是那个按钮*/
   if(((QPushButton*)sender())->text()=="cancel"){
      this->close();
   }
   if(((QPushButton*)sender())->text()=="login"){
      if(username->text()=="abc"&&userpasswd->text()=="123"){
	      qDebug("login  success");
	  }else{
	      qDebug("login  failed");
	  }
   }
}
