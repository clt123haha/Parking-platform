#ifndef PLAYVIDEOVIEW_H
#define PLAYVIDEOVIEW_H

#include <QWidget>
#include "videothread.h"
#include "newqslider.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace  cv;

namespace Ui {
class PlayVideoView;
}

class PlayVideoView : public QWidget
{
    Q_OBJECT

public:
    explicit PlayVideoView(QWidget *parent = nullptr);
    ~PlayVideoView();
    void paintEvent(QPaintEvent *e);
    void closeEvent(QCloseEvent *event);
    void setPath(const QString &value);
    void setCount(int count);

    void setId(int value);

private slots:
    void releseSlider();
    void on_pushButton_clicked();
    void getMat(int count , Mat mat);
    void moveSlider(int p);
    void on_comboBox_currentIndexChanged(int index);


signals:
    void sendCount(int count,QString time);

private:
    int id;
    QString time_all;
    int time_now;
    bool isPuase;
    QString path;
    videothread * th;
    Ui::PlayVideoView *ui;
    newqslider * slider;
    int count;
    QImage img;
};

#endif // PLAYVIDEOVIEW_H
