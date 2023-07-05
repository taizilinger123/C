#ifndef  ADDER_H
#define  ADDER_H
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
    class  Adder:public  QDialog{
	   Q_OBJECT
	   private:
	   QLineEdit   *add;
	   QLabel      *oper;
	   QLineEdit   *added;
	   QPushButton *equ;
	   QLineEdit   *res;
	   QPushButton *bclose;
       public:
	   Adder();
	   ~Adder();
	   /*自定义槽函数 实现计算*/
	   public slots:
	   void  getRes();
	};
#endif
