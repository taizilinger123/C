#include "qq.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQ w;
    w.show();

    return a.exec();
}
