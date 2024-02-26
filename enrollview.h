#ifndef ENROLLVIEW_H
#define ENROLLVIEW_H

#include <QWidget>
#include <readthread.h>
#include <writethread.h>
#include <QCryptographicHash>

namespace Ui {
class EnrollView;
}

class EnrollView : public QWidget
{
    Q_OBJECT

public:
    explicit EnrollView(QWidget *parent = nullptr);
    ~EnrollView();

private:
    bool cansee1;
    bool cansee2;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void getRuslt(int flag,char *mes,int whichView);

signals:
    void back2LoginView();

private:
    Ui::EnrollView *ui;


};

#endif // ENROLLVIEW_H
