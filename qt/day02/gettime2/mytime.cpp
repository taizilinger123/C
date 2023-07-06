#include "mytime.h"
#include <QApplication>
MyTime::MyTime(){
    res=new QLabel("current time",this);
	gettime=new QPushButton("gettime",this);
	this->resize(400,500);
	/*移动组件的位置*/
	res->move(200,50);
	gettime->move(200,400);
	/*绑定按钮 到槽函数*/
	connect(gettime,SIGNAL(clicked()),this,SLOT(setTime()));
	/*绑定自定义信号 和 最终的槽函数*/
	connect(this,SIGNAL(mySig(QString)),res,SLOT(setText(QString)));
}
MyTime::~MyTime(){
    delete res;
	delete gettime;
}
#include <QTime>
void MyTime::setTime(){
    /*调用setText*/
	//res->setText(QTime::currentTime().toString("hh:mm:ss"));
	/*不方便访问  res*/
	/*发射mySig信号*/
    emit mySig(QTime::currentTime().toString("hh:mm:ss"));
}
int main(int argc,char** argv){
    QApplication  app(argc,argv);
	MyTime mt;
	mt.show();
	return  app.exec();
}
