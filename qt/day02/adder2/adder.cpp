	   /*QLineEdit   *add;
	   QLabel      *oper;
	   QLineEdit   *added;
	   QPushButton *equ;
	   QLineEdit   *res;
	   QPushButton *bclose;*/
#include  "adder.h"
Adder::Adder(){
    this->resize(660,300);
	/*给组件赋值*/
	add=new  QLineEdit(this);
	oper=new QLabel("+",this);
	added=new QLineEdit(this);
	equ=new QPushButton("=",this);
	res=new QLineEdit(this);
	bclose=new QPushButton("close",this);
	/*调整组件的位置*/
	add->move(20,130);
	oper->move(170,130);
	added->move(220,130);
	equ->move(370,130);
	res->move(480,130);
	bclose->move(320,200);
	/*连接bclose 和 this */
	connect(bclose,SIGNAL(clicked()),this,SLOT(close()));
	/*连接equ 和 this */
	connect(equ,SIGNAL(clicked()),this,SLOT(getRes()));
}
Adder::~Adder(){
    delete  add;
	delete  oper;
	delete  added;
	delete  equ;
	delete  res;
	delete  bclose;
}
/*自定义槽函数 实现计算*/
void  Adder::getRes(){
    res->setText("9527");
	/*1.得到add和added的输入值
	  2.把得到的QString的值变成int
	  3.相加得到和 
	  4.把和变成QString类型最后赋值给res
	 */

}
