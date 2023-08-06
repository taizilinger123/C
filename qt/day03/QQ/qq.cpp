#include "qq.h"
#include "ui_qq.h"

QQ::QQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QQ)
{
    ui->setupUi(this);
}

QQ::~QQ()
{
    delete ui;
}
