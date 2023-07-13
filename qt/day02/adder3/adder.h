#ifndef  ADDER_H
#define  ADDER_H
#include "jfq.h"
class Adder:public  QDialog{
   Q_OBJECT
   /*定义一个界面指针*/
   Ui_Dialog  *ui;
   public:
   Adder();
   ~Adder();
   public slots:
   void   getRes();
};
#endif
