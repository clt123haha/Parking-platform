/********************************************************************************
** Form generated from reading UI file 'loginview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginView
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *LoginView)
    {
        if (LoginView->objectName().isEmpty())
            LoginView->setObjectName(QStringLiteral("LoginView"));
        LoginView->resize(481, 381);
        pushButton = new QPushButton(LoginView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 330, 71, 28));
        pushButton_2 = new QPushButton(LoginView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 330, 71, 28));
        lineEdit = new QLineEdit(LoginView);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 50, 201, 21));
        label = new QLabel(LoginView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 72, 15));
        lineEdit_2 = new QLineEdit(LoginView);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 120, 201, 21));
        label_2 = new QLabel(LoginView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 72, 15));
        lineEdit_3 = new QLineEdit(LoginView);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 210, 61, 21));
        label_3 = new QLabel(LoginView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 210, 72, 15));
        pushButton_3 = new QPushButton(LoginView);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 120, 21, 16));

        retranslateUi(LoginView);

        QMetaObject::connectSlotsByName(LoginView);
    } // setupUi

    void retranslateUi(QWidget *LoginView)
    {
        LoginView->setWindowTitle(QApplication::translate("LoginView", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginView", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginView", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("LoginView", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit_2->setText(QString());
        label_2->setText(QApplication::translate("LoginView", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_3->setText(QString());
        label_3->setText(QApplication::translate("LoginView", "\351\252\214\350\257\201\347\240\201\357\274\232", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("LoginView", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginView: public Ui_LoginView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
