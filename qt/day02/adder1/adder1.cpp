#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
int main(int argc,char**argv){
    QApplication  app(argc,argv);
    QDialog  *parent=new QDialog();
	parent->resize(660,300);
	/*定义组件的指针*/
	QLineEdit     *add;
	QLabel        *oper;
	QLineEdit     *added;
	QPushButton   *equ;
	QLineEdit     *res;
	QPushButton   *bclose;
	/*给组件的指针赋值*/
	add=new    QLineEdit(parent);
	oper=new   QLabel("+",parent);
	added=new  QLineEdit(parent);
	equ=new    QPushButton("=",parent);
	res=new    QLineEdit(parent);
	bclose=new QPushButton("close",parent);
    /*调整组件位置*/
	add->move(20,130);
	oper->move(170,130);
	added->move(220,130);
	equ->move(370,130);
	res->move(480,130);
	bclose->move(320,200);
	parent->show();
	/*实现点击bclose  关闭parent */
	QObject::connect(bclose,SIGNAL(clicked()),parent,SLOT(close()));
	return app.exec();
}
