/********************************************************************************
** Form generated from reading UI file 'openvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENVIDEO_H
#define UI_OPENVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openVideo
{
public:
    QLabel *label;

    void setupUi(QWidget *openVideo)
    {
        if (openVideo->objectName().isEmpty())
            openVideo->setObjectName(QStringLiteral("openVideo"));
        openVideo->resize(659, 479);
        label = new QLabel(openVideo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 641, 461));

        retranslateUi(openVideo);

        QMetaObject::connectSlotsByName(openVideo);
    } // setupUi

    void retranslateUi(QWidget *openVideo)
    {
        openVideo->setWindowTitle(QApplication::translate("openVideo", "Form", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class openVideo: public Ui_openVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENVIDEO_H
