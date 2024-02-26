#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QObject>
#include <QThread>
#include "getsetting.h"
#include <QQueue>
#include "camerathread2.h"
#include <opencv2/opencv.hpp>
#include "writethread.h"
#include <mutex>

using namespace  std;
using namespace  cv;

class RecordThread : public QThread
{
    Q_OBJECT
public:
    RecordThread();
    void run();

    void setPath(const QString &value);
    void setIs30s(bool value);
    void addFream(Mat fream);
    void setFPS(int value);

    void setIsend(bool value);

    void setFream(const Mat &value);

    void setId(int value);

    QString getVideoPath() const;
    void setVideoPath(const QString &value);

    QString getImgPath() const;

    int getNum() const;
    void nweVideo();
    void endVideo();
    QString getTime() const;

    QString getTime_old() const;

private:
    QString time_old;
    bool canadd;
    QString time;
    Mat fream_my;
    mutex   mtx;
    int id;
    QString path,videoPath;
    QQueue<Mat> freamList;
    QString imgPath;
    Mat fream;
    VideoWriter writer;
    int FPS;
    int num;
    bool isend;
    bool is30s;

signals:
    void over();
};

#endif // RECORDTHREAD_H
