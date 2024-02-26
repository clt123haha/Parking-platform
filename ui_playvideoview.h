/********************************************************************************
** Form generated from reading UI file 'playvideoview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYVIDEOVIEW_H
#define UI_PLAYVIDEOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayVideoView
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QComboBox *comboBox;

    void setupUi(QWidget *PlayVideoView)
    {
        if (PlayVideoView->objectName().isEmpty())
            PlayVideoView->setObjectName(QStringLiteral("PlayVideoView"));
        PlayVideoView->resize(783, 525);
        label = new QLabel(PlayVideoView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 671, 401));
        label_2 = new QLabel(PlayVideoView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 490, 131, 17));
        pushButton = new QPushButton(PlayVideoView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 490, 89, 25));
        comboBox = new QComboBox(PlayVideoView);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(390, 490, 86, 25));

        retranslateUi(PlayVideoView);

        QMetaObject::connectSlotsByName(PlayVideoView);
    } // setupUi

    void retranslateUi(QWidget *PlayVideoView)
    {
        PlayVideoView->setWindowTitle(QApplication::translate("PlayVideoView", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("PlayVideoView", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PlayVideoView", "\346\232\202\345\201\234", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PlayVideoView", "1.0x", Q_NULLPTR)
         << QApplication::translate("PlayVideoView", "1.5x", Q_NULLPTR)
         << QApplication::translate("PlayVideoView", "2.0x", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class PlayVideoView: public Ui_PlayVideoView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYVIDEOVIEW_H
