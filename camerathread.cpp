#include "camerathread.h"
#include <QDebug>

CameraThread * CameraThread::myCameraThread = nullptr;

CameraThread *CameraThread::getCameraThread()
{
    if(myCameraThread == nullptr)
    {
        myCameraThread = new CameraThread;
    }
    return myCameraThread;
}

void CameraThread::run()
{
    while(!isover)
    {
        if(cap.read(mat))
        {
            emit sendMat(mat);
            msleep(40);
        }
    }
}

void CameraThread::openCamera()
{
    //cap = VideoCapture("car_input2.mp4");
    cap = VideoCapture(0);
    isopen = cap.isOpened();
    FPS = int(round(cap.get(CAP_PROP_FPS)));
    cap.read(mat);
    cols = mat.cols;
    rows = mat.rows;
    rate = cap.get(5);
}

CameraThread::CameraThread() :QThread()
{
    isover = false;
}

bool CameraThread::getIsopen() const
{
    return isopen;
}

int CameraThread::getFPS() const
{
    return FPS;
}

void CameraThread::setFPS(int value)
{
    FPS = value;
}

int CameraThread::getCols() const
{
    return cols;
}

int CameraThread::getRows() const
{
    return rows;
}

int CameraThread::getRate() const
{
    return rate;
}

int CameraThread::getNum() const
{
    return Num;
}

void CameraThread::setIsover(bool value)
{
    isover = value;
}
