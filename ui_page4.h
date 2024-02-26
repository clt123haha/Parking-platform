/********************************************************************************
** Form generated from reading UI file 'page4.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE4_H
#define UI_PAGE4_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page4
{
public:
    QListWidget *listWidget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget_2;

    void setupUi(QWidget *Page4)
    {
        if (Page4->objectName().isEmpty())
            Page4->setObjectName(QStringLiteral("Page4"));
        Page4->resize(1016, 469);
        listWidget = new QListWidget(Page4);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(300, 20, 651, 381));
        radioButton = new QRadioButton(Page4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 10, 112, 23));
        radioButton_2 = new QRadioButton(Page4);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 10, 112, 23));
        pushButton = new QPushButton(Page4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 420, 89, 25));
        pushButton_2 = new QPushButton(Page4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(780, 420, 89, 25));
        listWidget_2 = new QListWidget(Page4);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(20, 50, 241, 351));

        retranslateUi(Page4);

        QMetaObject::connectSlotsByName(Page4);
    } // setupUi

    void retranslateUi(QWidget *Page4)
    {
        Page4->setWindowTitle(QApplication::translate("Page4", "Form", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Page4", "\346\214\211\345\244\251\346\230\276\347\244\272", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Page4", "\346\214\211\346\234\210\346\230\276\347\244\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Page4", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Page4", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page4: public Ui_Page4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE4_H
