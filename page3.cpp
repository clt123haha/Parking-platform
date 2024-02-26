#include "page3.h"
#include "ui_page3.h"

#include <QDateTime>
#include <QMessageBox>

Page3::Page3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page3)
{
    re1 = re2 = false;
    rth2end  =false;
    is30 = isRe = false;
    ui->setupUi(this);
    timer = new QTimer;
    is30s = isRecord = videoEnd = false;
    cascade.load("cars.xml");
    cascade2.load("face.xml");

    connect(ReadThread::getReadThread(),SIGNAL(sendCurVehicleInfoBack(int)),this,SLOT(getCurVehicleInfoBack(int)));
    connect(ReadThread::getReadThread(),SIGNAL(sendFileSendBack(int,char*,char*,char*,int,char *)),this,SLOT(getFileSendBack(int,char*,char*,char*,int,char*)));
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdata()));
    connect(CameraThread2::getCameraThread2(),SIGNAL(sendMat(Mat)),this,SLOT(getMat(Mat)),Qt::BlockingQueuedConnection);
}

void Page3::paintEvent(QPaintEvent *)
{
    ui->label->setPixmap(QPixmap::fromImage(this->img));
}

void Page3::openTimer()
{
    WriteThread::getWriteThread()->sendCurVehicleInfo(1);
    timer->start(100000);
}

void Page3::stoptimer()
{
    if(timer->isActive())
        timer->stop();
}

void Page3::closeRecord()
{
    if(rth1 != nullptr)
        rth1->setIsend(true);
    if(rth2 != nullptr)
        rth2->setIsend(true);
}

Page3::~Page3()
{
    delete ui;
}

void Page3::on_pushButton_clicked()
{
    QDateTime dateTime= QDateTime::currentDateTime();
    QString str = dateTime.toString("yyyy-MM-dd hh:mm:ss");

    imgPath = getSetting::getmyseting()->getImgPath() + "/"  + "image" + str +".jpg";

    this->img.save(imgPath);

    th = new SplitThread(imgPath,id);
    connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
    th->start();
    type = 3;
}

void Page3::getMat(Mat mat)
{
    noChangeMat = mat.clone();
    cvtColor(mat, mat, CV_BGR2RGB);
    this->originalMat = mat.clone();
    this->originalImg = QImage(originalMat.data,originalMat.cols,originalMat.rows,QImage::Format_RGB888);

    if(isRecord)
    {

                    rth1->addFream(noChangeMat);

    }
    if(is30s)
    {

                    rth2->addFream(noChangeMat);

    }


    this->identify();

    update();
}

void Page3::timerUpdata()
{
    WriteThread::getWriteThread()->sendCurVehicleInfo(1);
}

void Page3::identify()
{
    Mat mat = this->originalMat.clone();

    Mat gray;
    cvtColor(mat,gray,CV_RGB2GRAY);

    Mat small(cvRound(mat.rows/2),cvRound(mat.cols/2),CV_8UC1);
    cv::resize(gray,small,small.size(),0,0,INTER_LINEAR);

    equalizeHist(small,small);
    vector<Rect> cars;
    vector<Rect> person;
    vector<Rect> merged;

    cascade.detectMultiScale(small,cars,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
    cascade2.detectMultiScale(small,person,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));

    merged.insert(merged.end(), cars.begin(), cars.end());
    merged.insert(merged.end(), person.begin(), person.end());

    vector<Rect>::const_iterator iter;
    for(iter = merged.begin();iter!=merged.end();iter++)
    {
        rectangle(mat,
                  cvPoint(cvRound(iter->x*2),cvRound(iter->y*2)),
                  cvPoint(cvRound((iter->x + iter->width)*2),cvRound((iter->y + iter->height)*2)),
                  Scalar(0,255,0),
                    2,
                    8);
    }

    Mat Rgb;

    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        cv::cvtColor(Rgb, Rgb, CV_BGR2RGB);//颜色空间转换
        this->img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else
    {
        this->img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }

    this->img = this->img.scaled(ui->label->width(),ui->label->height());
}

void Page3::setId(int value)
{
    id = value;

}

void Page3::rth2Over()
{
    th = new SplitThread(rth2->getImgPath(),id);
    connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
    th->start();
    rth2end  =true;
}

void Page3::getFileSendBack(int flag, char *account, char *path, char *fileName,int type_,char * findNmae)
{
    if(type_ == 3 || type_ == 4)
    {
        if(flag == 1)
        {
            QMessageBox::information(this,"提示信息","图片上传成功");
        }else
        {
            path_ = QString(path) +  QString(fileName);
            rePath = path;
            refileName = fileName;
            refindName = findNmae;

            if(type_ == 4)
                re1 = true;

            th = new SplitThread(path_.toStdString().c_str(),id);
            connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
            th->start();
            type = type_;
        }
    }
}

void Page3::on_pushButton_2_clicked()
{
    isRecord = !isRecord;
    if(!isRecord)
    {
        WriteThread::getWriteThread()->snedVideo(rth1->getNum(),getSetting::getmyseting()->getVideoPath()+"/",rth1->getVideoPath().split("/").last(),rth1->getTime(),id);

        rth1->setIsend(true);
        ui->pushButton_2->setText("手动录制视频");
        th = new SplitThread(rth1->getImgPath(),id);
        connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
        th->start();
        type = 4;
        isRe = true;
        rth1->endVideo();
    }else
    {
        rth1 = new RecordThread;
        rth1->nweVideo();
        rth1->setId(id);
        rth1->setFPS(CameraThread2::getCameraThread2()->getFPS());
        rth1->setFream(this->noChangeMat);
        rth1->start();
        ui->pushButton_2->setText("停止录制");
    }
}

void Page3::getCurVehicleInfoBack(int num)
{
    ui->label_3->setText(QString::number(num));
    ui->label_6->setText(QString::number(1500 - num));
}


void Page3::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        rth2 = new RecordThread;
        rth2->nweVideo();
        connect(rth2,SIGNAL(over()),this,SLOT(rth2Over()));
        rth2->setId(id);
        rth2->setIs30s(true);
        rth2->setFPS(CameraThread2::getCameraThread2()->getFPS());
        rth2->setFream(this->noChangeMat);
        rth2->start();
        this->is30s = true;
    }else if(arg1 == 0)
    {
        rth2->setIsend(true);
        rth2->endVideo();
        this->is30s = false;
    }
}

void Page3::fileSplitOver()
{
    sendTh = new FileSendThread(th->getFileList(),th->getFileList().size());
    connect(sendTh,SIGNAL(fileSendOver()),this,SLOT(fileSendOver()));
    sendTh->start();
}

void Page3::fileSendOver()
{
    char buf[500] = {0};

    FILESENDOVER filesendover = {0};
    if(re1)
    {
        qDebug() << "isRe  !";
        QString path_ = getSetting::getmyseting()->getImgPath() + "/";
        memcpy(filesendover.account,QString::number(id).toStdString().c_str(),sizeof (filesendover.account));
        memcpy(filesendover.fileName,refileName.toStdString().c_str(),sizeof (filesendover.fileName));
        memcpy(filesendover.filePath,path_.toStdString().c_str(),sizeof (filesendover.filePath));
        memcpy(filesendover.findFieldName,refindName.toStdString().c_str(),sizeof (filesendover.findFieldName));
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalCount = th->getFileList().size();
        filesendover.fileType = 4;
        re1 = false;
    }else if(this->isRe)
    {
        qDebug() << "isRecpd  !";
        QString path_ = getSetting::getmyseting()->getImgPath() + "/";
        memcpy(filesendover.account,QString::number(id).toStdString().c_str(),sizeof (filesendover.account));
        memcpy(filesendover.fileName,rth1->getImgPath().split("/").last().toStdString().c_str(),sizeof (filesendover.fileName));
        memcpy(filesendover.filePath,path_.toStdString().c_str(),sizeof (filesendover.filePath));
        memcpy(filesendover.findFieldName,rth1->getVideoPath().split("/").last().toStdString().c_str(),sizeof (filesendover.findFieldName));
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalCount = th->getFileList().size();
        filesendover.fileType = 4;
        isRe = false;
    }else if(this->rth2end)
    {
        qDebug() << "is30s!!!!!!!!";
        QString path_ = getSetting::getmyseting()->getImgPath() + "/";
        memcpy(filesendover.account,QString::number(id).toStdString().c_str(),sizeof (filesendover.account));
        memcpy(filesendover.fileName,rth2->getImgPath().split("/").last().toStdString().c_str(),sizeof (filesendover.fileName));
        memcpy(filesendover.filePath,path_.toStdString().c_str(),sizeof (filesendover.filePath));
        memcpy(filesendover.findFieldName,rth2->getTime_old().split("/").last().toStdString().c_str(),sizeof (filesendover.findFieldName));
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalCount = th->getFileList().size();
        filesendover.fileType = 4;
        rth2end = false;
    }else
    {
        qDebug()<<"img!!!!!!";
        QString path_ = getSetting::getmyseting()->getImgPath() + "/";
        memcpy(filesendover.account,QString::number(id).toStdString().c_str(),sizeof (filesendover.account));
        memcpy(filesendover.fileName,imgPath.split('/').last().toStdString().c_str(),sizeof (filesendover.fileName));
        memcpy(filesendover.filePath,path_.toStdString().c_str(),sizeof (filesendover.filePath));
        memcpy(filesendover.findFieldName,imgPath.split("/").last().toStdString().c_str(),sizeof (filesendover.findFieldName));
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalByte = th->getAll_count();
        filesendover.fileTotalCount = th->getFileList().size();
        filesendover.fileType = 3;
    }

    HEAD head = {0};
    head.bussinessType = 6;
    head.bussinessLength = sizeof (FILESENDOVER);

    memcpy(buf,&head,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&filesendover,sizeof (FILESENDOVER));

    write(conneet::getmyconneet()->getFd(),buf,sizeof (HEAD) + sizeof (FILESENDOVER));
}
