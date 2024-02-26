/********************************************************************************
** Form generated from reading UI file 'page3.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE3_H
#define UI_PAGE3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page3
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *Page3)
    {
        if (Page3->objectName().isEmpty())
            Page3->setObjectName(QStringLiteral("Page3"));
        Page3->resize(1028, 433);
        label = new QLabel(Page3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 601, 401));
        label_2 = new QLabel(Page3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 60, 111, 17));
        label_3 = new QLabel(Page3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(810, 60, 131, 20));
        label_4 = new QLabel(Page3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(960, 60, 67, 17));
        label_5 = new QLabel(Page3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(700, 110, 111, 17));
        label_6 = new QLabel(Page3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(810, 110, 131, 20));
        pushButton = new QPushButton(Page3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(770, 200, 121, 25));
        pushButton_2 = new QPushButton(Page3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(770, 250, 121, 25));
        checkBox = new QCheckBox(Page3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(770, 350, 201, 23));

        retranslateUi(Page3);

        QMetaObject::connectSlotsByName(Page3);
    } // setupUi

    void retranslateUi(QWidget *Page3)
    {
        Page3->setWindowTitle(QApplication::translate("Page3", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("Page3", "\347\233\256\345\211\215\345\234\250\345\234\272\350\275\246\350\276\206", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("Page3", "\350\276\206", Q_NULLPTR));
        label_5->setText(QApplication::translate("Page3", "\347\251\272\344\275\231\350\275\246\344\275\215", Q_NULLPTR));
        label_6->setText(QString());
        pushButton->setText(QApplication::translate("Page3", "\347\211\271\345\276\201\346\212\223\346\213\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Page3", "\346\211\213\345\212\250\345\275\225\345\210\266\350\247\206\351\242\221", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Page3", "\345\274\200\345\220\25730s\350\207\252\345\212\250\345\275\225\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page3: public Ui_Page3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE3_H
