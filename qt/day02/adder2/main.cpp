#include <QApplication>
#include "adder.h"
int main(int  argc,char**argv){
    QApplication  app(argc,argv);
	Adder  adder;
	adder.show();
	qDebug("this is  qt  output");
	return  app.exec();
}
