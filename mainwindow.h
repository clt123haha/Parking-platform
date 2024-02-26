#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"
#include "page5.h"
#include "setingwiget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setId(QString value);
    void ReadyWork();
    void openTimer();
    void timerStop();

private slots:
    void setCansel();
    void setEnd();
    void time_send();
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();
    void getRes(int flag,char * mes,int which);

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
    
    void on_pushButton_6_clicked();

private:
    SetingWiget * setView;
    QTimer * timer;
    QStackedLayout *wigetLayout;
    Page1 * page1;
    Page2 * page2;
    Page3 * page3;
    Page4 * page4;
    Page5 * page5;
    int id;
    Ui::MainWindow *ui;


signals:
    void back2Login();
};

#endif // MAINWINDOW_H
