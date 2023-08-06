#include "yaojiang.h"
#include "ui_yaojiang.h"
#include <QTime>
YaoJiang::YaoJiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YaoJiang)
{
    qsrand(QTime::currentTime().msec());
    ui->setupUi(this);
    timer=new QTimer();
    timer->setInterval(200);
    timer->start();
    /*0-4*/
    names[0]="test1";
    names[1]="test2";
    names[2]="test3";
    names[3]="test4";
    names[4]="test5";
    pflag=false;
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    connect(ui->bstart,SIGNAL(clicked()),this,SLOT(changePflag()));
    connect(ui->bstop,SIGNAL(clicked()),this,SLOT(changePflag()));
}
void  YaoJiang::changePflag(){
    /*根据点击的按钮改变绘制的值*/
    if(((QPushButton*)sender())->objectName()=="bstart"){
        pflag=true;
    }
    if(((QPushButton*)sender())->objectName()=="bstop"){
        pflag=false;
    }
}
YaoJiang::~YaoJiang()
{
    delete ui;
}
#include <QPainter>
void YaoJiang::paintEvent(QPaintEvent *){
   QPainter qp(this);
   /*随机绘制图片1-5*/
   if(pflag){
   int  ind=(qrand()%5)+1;
   QString imgpath=":/img/";
   imgpath+=QString::number(ind);
   imgpath+=".jpg";
   //img.load(":/img/5.jpg");
   img.load(imgpath);
   img=img.scaled(360,560);
   /*ind-1=0-4,ui.pname=ui->pname*/
   ui->pname->setText(names[ind-1]);
   qp.drawImage(20,40,img,0,0,360,510);
   }else{
   /*当摇奖停止时要把内存中的图片 画一下*/
   qp.drawImage(20,40,img,0,0,360,510);
   }
}
