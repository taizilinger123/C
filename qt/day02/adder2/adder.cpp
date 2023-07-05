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
}
Adder::~Adder(){
    delete  add;
}
/*自定义槽函数 实现计算*/
void  Adder::getRes(){
     
}
