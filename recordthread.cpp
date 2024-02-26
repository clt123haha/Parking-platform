#include "recordthread.h"

#include <QDateTime>
#include <QImage>

RecordThread::RecordThread() : QThread()
{
    isend = false;
    is30s = false;
    num = 0;
}

void RecordThread::run()
{
    while(!isend)
    {

    }
}

void RecordThread::setPath(const QString &value)
{
    path = value;
}

void RecordThread::setIs30s(bool value)
{
    is30s = value;
}

void RecordThread::addFream(Mat fream)
{

if(!isend)
{
    if(!is30s)
    {
        if(num == 0)
        {
            QDateTime dateTime= QDateTime::currentDateTime();
            time = dateTime.toString("yyyy-MM-dd hh:mm:ss");

            videoPath = getSetting::getmyseting()->getVideoPath() + "/" + "video" +  time +".avi";
            imgPath = getSetting::getmyseting()->getImgPath() + "/" + "video" + time +".jpg";

            cvtColor(fream, fream, CV_BGR2RGB);
            QImage cover = QImage(fream.data,fream.cols,fream.rows,QImage::Format_RGB888);



            cover.save(imgPath);

            writer.open(videoPath.toStdString().c_str(),CV_FOURCC('M', 'J', 'P', 'G'),FPS,Size(CameraThread2::getCameraThread2()->getCols(),CameraThread2::getCameraThread2()->getRows()),true);

            if(!writer.isOpened())
            {
                qDebug() << "open avi error";
                return;
            }
        }


            try
            {
                        writer << fream;
                        ++num;
                        qDebug() << num;
            }
            catch(cv::Exception)
            {}

    }
    else
    {

            try {


            if(num == 2000)
            {
                canadd = false;
                msleep(200);
                time_old = videoPath;
                WriteThread::getWriteThread()->snedVideo(num-1,getSetting::getmyseting()->getVideoPath() + "/","video" + time+".avi",time,id);
                emit over();
                num = 0;
                writer.release();

            }else if(num ==0)
            {
                canadd = true;
                QDateTime datetime = QDateTime::currentDateTime();
                time = datetime.toString("yyyy-MM-dd hh:mm:ss");


                videoPath = getSetting::getmyseting()->getVideoPath() + "/" + "video" +  time +".avi";
                imgPath = getSetting::getmyseting()->getImgPath() + "/" + + "video" + time +".jpg";

                writer.open(videoPath.toStdString().c_str(),CV_FOURCC('M', 'J', 'P', 'G'),FPS,Size(fream.cols,fream.rows),true);

                cvtColor(fream, fream, CV_BGR2RGB);
                QImage cover = QImage(fream.data,fream.cols,fream.rows,QImage::Format_RGB888);


                cover.save(imgPath);

                if(!writer.isOpened())
                {
                    qDebug() << "open avi error";
                    return;
                }
                num = 1;
            }else if(canadd)
            {

                        writer << fream;
                        ++num;

                        qDebug() << num;


            }
            }
            catch(cv::Exception)
            {

            }
        }
}
}

void RecordThread::setFPS(int value)
{
    FPS = value;
}

void RecordThread::setIsend(bool value)
{
    isend = value;
}

void RecordThread::setFream(const Mat &value)
{
    fream = value;
}

void RecordThread::setId(int value)
{
    id = value;
}

QString RecordThread::getVideoPath() const
{
    return videoPath;
}

void RecordThread::setVideoPath(const QString &value)
{
    videoPath = value;
}

QString RecordThread::getImgPath() const
{
    return imgPath;
}

int RecordThread::getNum() const
{
    return num;
}

void RecordThread::nweVideo()
{
}

void RecordThread::endVideo()
{
    msleep(200);
    if(writer.isOpened())
        writer.release();

    num = 0;
}

QString RecordThread::getTime() const
{
    return time;
}

QString RecordThread::getTime_old() const
{
    return time_old;
}
