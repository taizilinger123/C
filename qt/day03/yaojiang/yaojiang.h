#ifndef YAOJIANG_H
#define YAOJIANG_H

#include <QDialog>
#include <QImage>
#include <QTimer>

namespace Ui {
class YaoJiang;
}

class YaoJiang : public QDialog
{
    Q_OBJECT

public:
    explicit YaoJiang(QWidget *parent = 0);
    ~YaoJiang();
/*绘制事件处理函数*/
public:
void paintEvent(QPaintEvent *);
private:
    Ui::YaoJiang *ui;
    /*准备绘制的图片*/
    QImage img;
    /*定时器 定时发出timeout()信号
      repaint()重绘*/
    QTimer *timer;
    /*名字数组*/
    QString names[5];
    /*控制绘制的标志*/
    bool    pflag;
/*两个按钮负责改变绘制标志*/
public  slots:
    void  changePflag();
};

#endif // YAOJIANG_H
