#include "adder.h"
#include "ui_adder.h"

Adder::Adder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adder)
{
    ui->setupUi(this);
    connect(ui->equ,SIGNAL(clicked()),this,SLOT(getRes()));
}
void Adder::getRes(){
    ui->res->setText(QString::number(
    ui->add->text().toInt()+
    ui->added->text().toInt()));
}
Adder::~Adder()
{
    delete ui;
}

/*工具->选项->环境->键盘->keyboard shortcuts里面输入comp->选中
CompleteThis->下面输入框里的快捷键改为alt+/->apply->ok*/
