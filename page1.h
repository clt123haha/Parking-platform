#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>
#include "camerathread.h"
#include "easypr.h"
#include "getsetting.h"
#include <QDateTime>
#include <QTimer>
#include "readthread.h"
#include "writethread.h"
#include<string>
#include <opencv2/opencv.hpp>
#include "splitthread.h"

using namespace easypr;
using namespace std;
using namespace cv;

namespace Ui {
class Page1;
}

class Page1 : public QWidget
{
    Q_OBJECT

public:
    explicit Page1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Page1();
    void setId(int value);

private slots:
    void on_pushButton_clicked();
    void getMat(Mat mat);
    void on_pushButton_2_clicked();
    void getEntranceBack(int flag,int count,char *mes);
    void getdate(int row,int id,QString str1,QString str2,QString str3);
    void timerUpdata();
    void fileSendOver();
    void fileSplitOver();
    void getFileSendBack(int flag,char *account,char *path,char *fileName,int type_);



private:
    int id;
    void identify();
    bool isopen;
    QImage img;
    QImage originalImg;
    CPlateRecognize pr;
    CPlate plate;
    Mat mat,plateMat,originalMat;
    Ui::Page1 *ui;
    QImage carImg;
    QString number;
    QString time_in;
    CascadeClassifier cascade;
    QString path;
    QTimer *timer;
    SplitThread * th;
    FileSendThread * sendTh;
};

#endif // PAGE1_H
