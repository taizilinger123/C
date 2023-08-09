#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
void Dialog::keyPressEvent(QKeyEvent *e){
    switch(e->key()){
       case Qt::Key_Up:
        qDebug("up key pressed");
        break;
       case Qt::Key_Down:
        qDebug("down key pressed");
        break;
       case Qt::Key_Left:
        qDebug("left key pressed");
        break;
       case Qt::Key_Right:
        qDebug("right key pressed");
        break;
    }
}

void Dialog::mousePressEvent(QMouseEvent *e){
    switch(e->button()){
       case Qt::LeftButton:
        qDebug("%d:%d left button  clicked",
               e->x(),e->y());//e.x,e.y
        break;
       case Qt::RightButton:
        qDebug("right button clicked");
        break;
       case Qt::MidButton:
        qDebug("mid button clicked");
        break;
    }
}

Dialog::~Dialog()
{
    delete ui;
}
