#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include "verify.h"
#include <QCryptographicHash>
#include "enrollview.h"
#include "conneet.h"
#include "mainwindow.h"
#include "writethread.h"
#include "readthread.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

private slots:
    void on_pushButton_clicked();
    void getRes(int flag,char *meg,int whichView);
    void cancelEnroll();
    void on_pushButton_2_clicked();
    void backtoLogin();

    void on_pushButton_3_clicked();

private:
    bool cansee;
    Ui::LoginView *ui;
    verify *v;
    EnrollView *enrollView;
    conneet *myConneet;
    MainWindow *mainView;
};

#endif // LOGINVIEW_H
