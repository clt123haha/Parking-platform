/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page1
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Page1)
    {
        if (Page1->objectName().isEmpty())
            Page1->setObjectName(QStringLiteral("Page1"));
        Page1->resize(1031, 433);
        label = new QLabel(Page1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 541, 311));
        label_4 = new QLabel(Page1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(650, 60, 67, 17));
        label_5 = new QLabel(Page1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(740, 50, 241, 41));
        label_6 = new QLabel(Page1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(650, 120, 67, 17));
        label_14 = new QLabel(Page1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 400, 67, 17));
        label_15 = new QLabel(Page1);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(110, 400, 67, 17));
        label_16 = new QLabel(Page1);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(210, 400, 67, 17));
        label_17 = new QLabel(Page1);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(300, 400, 67, 17));
        label_18 = new QLabel(Page1);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(400, 400, 67, 17));
        label_19 = new QLabel(Page1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(490, 400, 201, 17));
        pushButton_2 = new QPushButton(Page1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(880, 360, 89, 25));
        pushButton = new QPushButton(Page1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 360, 89, 25));
        label_2 = new QLabel(Page1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(650, 20, 67, 17));
        label_3 = new QLabel(Page1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(740, 20, 231, 21));
        lineEdit = new QLineEdit(Page1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(740, 110, 241, 31));
        tableWidget = new QTableWidget(Page1);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(610, 190, 421, 151));

        retranslateUi(Page1);

        QMetaObject::connectSlotsByName(Page1);
    } // setupUi

    void retranslateUi(QWidget *Page1)
    {
        Page1->setWindowTitle(QApplication::translate("Page1", "Form", Q_NULLPTR));
        label->setText(QString());
        label_4->setText(QApplication::translate("Page1", "\350\275\246\347\211\214\345\233\276\347\211\207:", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("Page1", "\350\275\246\347\211\214\345\217\267\347\240\201:", Q_NULLPTR));
        label_14->setText(QApplication::translate("Page1", "\345\211\251\344\275\231\350\275\246\344\275\215:", Q_NULLPTR));
        label_15->setText(QString());
        label_16->setText(QApplication::translate("Page1", "\345\275\223\345\211\215\347\224\250\346\210\267", Q_NULLPTR));
        label_17->setText(QApplication::translate("Page1", "uid", Q_NULLPTR));
        label_18->setText(QApplication::translate("Page1", "\345\275\223\345\211\215\346\227\266\351\227\264", Q_NULLPTR));
        label_19->setText(QApplication::translate("Page1", "time", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Page1", "\350\257\206\345\210\253 ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Page1", "\345\217\221\351\200\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("Page1", "\345\205\245\345\234\272\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Page1", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Page1", "\350\275\246\347\211\214\345\217\267\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Page1", "\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Page1", "\344\275\215\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("Page1", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("Page1", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("Page1", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("Page1", "4", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page1: public Ui_Page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
