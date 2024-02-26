/********************************************************************************
** Form generated from reading UI file 'enrollview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLLVIEW_H
#define UI_ENROLLVIEW_H

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

class Ui_EnrollView
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *EnrollView)
    {
        if (EnrollView->objectName().isEmpty())
            EnrollView->setObjectName(QStringLiteral("EnrollView"));
        label = new QLabel(EnrollView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 20, 72, 15));
        label_2 = new QLabel(EnrollView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 100, 72, 15));
        lineEdit = new QLineEdit(EnrollView);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 90, 171, 21));
        lineEdit_2 = new QLineEdit(EnrollView);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 130, 171, 21));
        label_3 = new QLabel(EnrollView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 140, 72, 15));
        lineEdit_3 = new QLineEdit(EnrollView);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 170, 171, 21));
        label_4 = new QLabel(EnrollView);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 180, 72, 15));
        lineEdit_4 = new QLineEdit(EnrollView);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(200, 210, 171, 21));
        label_5 = new QLabel(EnrollView);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 220, 72, 15));
        pushButton = new QPushButton(EnrollView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 300, 93, 28));
        pushButton_2 = new QPushButton(EnrollView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 300, 93, 28));
        pushButton_3 = new QPushButton(EnrollView);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 170, 21, 21));
        pushButton_4 = new QPushButton(EnrollView);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(380, 210, 21, 21));

        retranslateUi(EnrollView);

        QMetaObject::connectSlotsByName(EnrollView);
    } // setupUi

    void retranslateUi(QWidget *EnrollView)
    {
        EnrollView->setWindowTitle(QApplication::translate("EnrollView", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EnrollView", "\346\263\250\345\206\214\347\225\214\351\235\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("EnrollView", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("EnrollView", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("EnrollView", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("EnrollView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("EnrollView", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("EnrollView", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EnrollView: public Ui_EnrollView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLLVIEW_H
