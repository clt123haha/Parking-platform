#ifndef PAGE3_H
#define PAGE3_H

#include <QWidget>
#include "camerathread2.h"
#include <QTimer>
#include <easypr.h>
#include "recordthread.h"
#include "readthread.h"
#include "writethread.h"
#include "splitthread.h"
#include "filesendthread.h"
#include "getsetting.h"
#include <mutex>

using namespace easypr;
using namespace std;
using namespace cv;

namespace Ui {
class Page3;
}

class Page3 : public QWidget
{
    Q_OBJECT

public:
    explicit Page3(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void openTimer();
    void stoptimer();
    void closeRecord();
    ~Page3();

    void setId(int value);

private slots:
    void rth2Over();
    void getFileSendBack(int flag,char *account,char *path,char *fileName,int type_,char * findNmae);
    void on_pushButton_clicked();
    void getMat(Mat mat);
    void timerUpdata();
    void on_pushButton_2_clicked();
    void getCurVehicleInfoBack(int num);
    void on_checkBox_stateChanged(int arg1);
    void fileSplitOver();
    void fileSendOver();

private:
    mutex  mtx,mtx2;
    QString path_ ;
    QString rePath;
    QString refileName;
    QString refindName;
    bool re1,re2;
    bool rth2end;
    bool isRe;
    bool is30;
    QString imgPath;
    int type;
    FileSendThread * sendTh;
    SplitThread  * th;
    void identify();
    QTimer * timer;
    RecordThread * rth1;
    RecordThread * rth2;
    Mat noChangeMat;
    bool is30s;
    bool isRecord;
    bool videoEnd;
    CPlateRecognize pr;
    CPlate plate;
    CascadeClassifier cascade,cascade2;
    Ui::Page3 *ui;
    Mat originalMat;
    QImage originalImg,img;
    int id;
};

#endif // PAGE3_H
