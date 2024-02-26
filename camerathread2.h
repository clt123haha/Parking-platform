#ifndef CAMERATHREAD2_H
#define CAMERATHREAD2_H

#include <QThread>
#include <opencv2/opencv.hpp>

using namespace  std;
using namespace  cv;

class CameraThread2 : public QThread
{
    Q_OBJECT
public:
    static CameraThread2 * getCameraThread2();
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
    static CameraThread2 * myCameraThread2;
    CameraThread2();
    bool isopen;
};

#endif // CameraThread22_H
