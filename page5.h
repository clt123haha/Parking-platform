#ifndef PAGE5_H
#define PAGE5_H

#include <QWidget>
#include <QCalendarWidget>
#include <QDebug>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "writethread.h"
#include "readthread.h"
#include "vector"
#include<fstream>

using namespace std;

namespace Ui {
class Page5;
}

class Page5 : public QWidget
{
    Q_OBJECT

public:
    explicit Page5(QWidget *parent = nullptr);
    void getDate();
    ~Page5();

private slots:
    void on_pushButton_2_clicked();
    void getVEHICLEINFOQUERYBACK(VEHICLEINFO * infoList);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    
    void on_pushButton_clicked();

private:
    vector<VEHICLEINFO> list;
    QString date;
    QCalendarWidget * timeView;
    int page;
    Ui::Page5 *ui;
};

#endif // PAGE5_H
