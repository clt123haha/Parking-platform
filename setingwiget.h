#ifndef SETINGWIGET_H
#define SETINGWIGET_H

#include <QWidget>
#include <QFileDialog>
#include<iostream>
#include<fstream>
#include <QMessageBox>
#include"getsetting.h"

using namespace std;

namespace Ui {
class SetingWiget;
}

class SetingWiget : public QWidget
{
    Q_OBJECT

public:
    explicit SetingWiget(QWidget *parent = nullptr);
    ~SetingWiget();
    void getSetting2Widget();

    void setIsMain(bool value);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void setEnd();
    void setCancel();

private:
    bool isMain;
    Ui::SetingWiget *ui;
};

#endif // SETINGWIGET_H
