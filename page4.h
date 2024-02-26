#ifndef PAGE4_H
#define PAGE4_H

#include <QButtonGroup>
#include <QListWidget>
#include <QWidget>
#include "playvideoview.h"
#include "writethread.h"
#include "readthread.h"
#include "getsetting.h"
#include <QMap>

namespace Ui {
class Page4;
}

class Page4 : public QWidget
{
    Q_OBJECT

public:
    explicit Page4(QWidget *parent = nullptr);
    void sendDate();
    ~Page4();
    void flush();
    int getId() const;

    void setId(int value);

private slots:
    void closePlayView(int count,QString time);
    void on_radioButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void getDate(MYDATE * dateList);
    void getVIDEOQUERYBACK(VIDEOINFO * infoList);

    void on_radioButton_clicked();
    void on_listWidget_2_itemClicked(QListWidgetItem *item);
    void getVIDEOPLAYBACK(int count,int count_all,QString path);

private:
    QButtonGroup * BtnGroup;
    int id;
    PlayVideoView * playView;
    QMap<int,int> map;
    int page;
    Ui::Page4 *ui;
};

#endif // PAGE4_H
