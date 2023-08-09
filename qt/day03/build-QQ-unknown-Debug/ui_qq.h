/********************************************************************************
** Form generated from reading UI file 'qq.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQ_H
#define UI_QQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QQ
{
public:
    QPushButton *bcancel;
    QPushButton *blogin;
    QLineEdit *uname;
    QLineEdit *upasswd;

    void setupUi(QDialog *QQ)
    {
        if (QQ->objectName().isEmpty())
            QQ->setObjectName(QString::fromUtf8("QQ"));
        QQ->resize(400, 300);
        bcancel = new QPushButton(QQ);
        bcancel->setObjectName(QString::fromUtf8("bcancel"));
        bcancel->setGeometry(QRect(20, 230, 99, 27));
        blogin = new QPushButton(QQ);
        blogin->setObjectName(QString::fromUtf8("blogin"));
        blogin->setGeometry(QRect(240, 230, 99, 27));
        uname = new QLineEdit(QQ);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(240, 40, 113, 27));
        upasswd = new QLineEdit(QQ);
        upasswd->setObjectName(QString::fromUtf8("upasswd"));
        upasswd->setGeometry(QRect(240, 110, 113, 27));
        upasswd->setEchoMode(QLineEdit::Password);

        retranslateUi(QQ);

        QMetaObject::connectSlotsByName(QQ);
    } // setupUi

    void retranslateUi(QDialog *QQ)
    {
        QQ->setWindowTitle(QApplication::translate("QQ", "QQ", 0, QApplication::UnicodeUTF8));
        bcancel->setText(QApplication::translate("QQ", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        blogin->setText(QApplication::translate("QQ", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QQ: public Ui_QQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQ_H
