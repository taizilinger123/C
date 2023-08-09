#include "qq.h"
#include "ui_qq.h"

QQ::QQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QQ)
{
    ui->setupUi(this);
    connect(ui->bcancel,SIGNAL(clicked()),this,SLOT(loginAndCancel()));
    connect(ui->blogin,SIGNAL(clicked()),this,SLOT(loginAndCancel()));
}
void QQ::loginAndCancel(){
    if(((QPushButton*)sender())->objectName()=="bcancel"){
         this->close();
    }
    if(((QPushButton*)sender())->objectName()=="blogin"){
         qDebug("login blogin");
    }
}
QQ::~QQ()
{
    delete ui;
}
