#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
/*测试鼠标事件*/
public:
    void mousePressEvent(QMouseEvent *e);
/*测试键盘事件*/
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
