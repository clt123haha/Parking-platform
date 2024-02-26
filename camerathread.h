#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QObject>
#include <QThread>
#include <opencv2/opencv.hpp>

using namespace  std;
using namespace  cv;

class CameraThread : public QThread
{
    Q_OBJECT
public:
    static CameraThread * getCameraThread();
    void run();
    void openCamera();

    bool getIsopen() const;

    int getFPS() const;
    void setFPS(int value);

    int getCols() const;

    int getRows() const;

    int getRate() const;

    int getNum() const;

    void setIsover(bool value);

signals:
    void sendMat(Mat mat);

private:
    bool isover;
    int rate,Num;
    int FPS,cols,rows;
    VideoCapture cap;
    Mat mat;
    static CameraThread * myCameraThread;
    CameraThread();
    bool isopen;
};

#endif // CAMERATHREAD_H
