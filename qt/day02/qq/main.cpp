#include <QApplication>
#include "qq.h"
int main(int argc,char** argv){
    QApplication app(argc,argv);
	QQ  qq;
	qq.show();
	return app.exec();
}

