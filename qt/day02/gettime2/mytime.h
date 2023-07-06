#ifndef MYTIME_H
#define MYTIME_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
   class  MyTime:public QDialog{
	   Q_OBJECT
       private:
	   QLabel        *res;
	   QPushButton   *gettime;
	   public:
	   MyTime();
	   ~MyTime();
	   /*提供一个信号(线程)*/
	   public:signals:
	   void  mySig(QString par);
	   /*提供一个槽函数  和按钮绑定 并调用标签的槽函数setText(QString)*/
	   public slots:
	   void  setTime();
   };
#endif
