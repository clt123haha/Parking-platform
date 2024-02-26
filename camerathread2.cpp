#include "camerathread2.h"

#include <QDebug>

CameraThread2 * CameraThread2::myCameraThread2 = nullptr;

CameraThread2 *CameraThread2::getCameraThread2()
{
    if(myCameraThread2 == nullptr)
    {
        myCameraThread2 = new CameraThread2;
    }
    return myCameraThread2;
}

void CameraThread2::run()
{
    int count = 1;
    while(!isover)
    {
        if(cap.read(mat))
        {
            emit sendMat(mat);
            msleep(40);
        }
        if(count == Num)
        {
            count = 0;
            cap.set(CV_CAP_PROP_POS_FRAMES,0);
        }
        ++count;
    }
}

void CameraThread2::openCamera()
{
    cap = VideoCapture("car_input.mp4");
    //cap = VideoCapture(0);
    isopen = cap.isOpened();
    FPS = int(round(cap.get(CAP_PROP_FPS)));
    cap.read(mat);
    cols = mat.cols;
    rows = mat.rows;
    rate = cap.get(5);
    Num = cap.get(7);
}

CameraThread2::CameraThread2() :QThread()
{
    isover = false;
}

bool CameraThread2::getIsopen() const
{
    return isopen;
}

int CameraThread2::getFPS() const
{
    return FPS;
}

void CameraThread2::setFPS(int value)
{
    FPS = value;
}

int CameraThread2::getCols() const
{
    return cols;
}

int CameraThread2::getRows() const
{
    return rows;
}

int CameraThread2::getRate() const
{
    return rate;
}

int CameraThread2::getNum() const
{
    return Num;
}

void CameraThread2::setIsover(bool value)
{
    isover = value;
}
