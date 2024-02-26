#ifndef PAGE2_H
#define PAGE2_H

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
#include "filesendthread.h"

using namespace easypr;
using namespace std;
using namespace cv;

namespace Ui {
class Page2;
}

class Page2 : public QWidget
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void openCamera();
    ~Page2();

    void setId(int value);

private slots:
    void getFileSendBack(int flag,char *account,char *path,char *fileName,int type_);
    void fileSplitOver();
    void on_pushButton_clicked();
    void getMat(Mat mat);
    void timerUpdata();
    void on_pushButton_2_clicked();
    void getExitBack(int flag,int count,double park_time,double money,QString number,QString mes,QString time_in,QString time_out);
    void fileSendOver();
    void getCURVEHICLEINFOBACK(int num);

private:
    FileSendThread * sendTh;
    SplitThread * th;
    CPlate plate;
    QString number;
    CPlateRecognize pr;
    CascadeClassifier cascade;
    QTimer * timer;
    bool isopen;
    Ui::Page2 *ui;
    Mat originalMat,mat,plateMat;
    QImage originalImg,img,carImg;
    QString time_out;
    void identify();
    QString path;
    int id;
};

#endif // PAGE2_H
