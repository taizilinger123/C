#ifndef  QQ_H
#define  QQ_H
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
    class  QQ:public QDialog{
        /*继承宏,固定写法*/
		Q_OBJECT
		/*2个输入框，2个按钮*/
	    private:
		QLineEdit  *username;
		QLineEdit  *userpasswd;
		QPushButton *login;
		QPushButton *cancel;
        public:
		/*构造函数与类名一致*/
		QQ();
		/*析构函数*/
		~QQ();
        /*槽函数 负责登录和退出*/
	    public slots:
	    void  loginAndCancel();
	};
#endif
