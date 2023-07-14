#include "adder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Adder w;
    w.show();

    return a.exec();
}
