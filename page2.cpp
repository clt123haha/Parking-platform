#include "page2.h"
#include "ui_page2.h"

#include <QMessageBox>

Page2::Page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);

    cascade.load("cars.xml");
    pr.setDetectType(PR_DETECT_CMSER | PR_DETECT_COLOR);
    pr.setMaxPlates(4);
    pr.setResultShow(false);

    timer = new QTimer;
    timer->start(1000);

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdata()));
    connect(ReadThread::getReadThread(),SIGNAL(sendFileSendBack(int,char*,char*,char*,int)),this,SLOT(getFileSendBack(int,char*,char*,char*,int)));
    connect(CameraThread::getCameraThread(),SIGNAL(sendMat(Mat)),this,SLOT(getMat(Mat)),Qt::BlockingQueuedConnection);
    connect(ReadThread::getReadThread(),SIGNAL(sendExitBack(int,int,double,double,QString,QString,QString,QString)),this,SLOT(getExitBack(int,int,double,double,QString,QString,QString,QString)));
    connect(ReadThread::getReadThread(),SIGNAL(sendCurVehicleInfoBack(int)),this,SLOT(getCURVEHICLEINFOBACK(int)));
}

void Page2::paintEvent(QPaintEvent *)
{
    ui->label->setPixmap(QPixmap::fromImage(this->img));
    ui->label_9->setText(time_out);
}

void Page2::openCamera()
{

}

Page2::~Page2()
{
    delete ui;
}

void Page2::on_pushButton_clicked()
{
    int isvip = ui->radioButton->isChecked()?1:0;
    WriteThread::getWriteThread()->sendExit(isvip,ui->lineEdit->text().mid(3),"西入口",time_out,path);

    th = new SplitThread(path,id);
    connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
    th->start();
}

void Page2::getMat(Mat mat)
{
    this->originalMat = mat.clone();
    this->originalImg = QImage(originalMat.data,originalMat.cols,originalMat.rows,QImage::Format_RGB888);
    this->identify();

    update();
}

void Page2::timerUpdata()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_7->setText(str);
}

void Page2::identify()
{
    Mat mat = this->originalMat.clone();

    Mat gray;
    cvtColor(mat,gray,CV_RGB2GRAY);

    Mat small(cvRound(mat.rows/2),cvRound(mat.cols/2),CV_8UC1);
    cv::resize(gray,small,small.size(),0,0,INTER_LINEAR);

    equalizeHist(small,small);
    vector<Rect> cars;

    cascade.detectMultiScale(small,cars,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));

    vector<Rect>::const_iterator iter;
    for(iter = cars.begin();iter!=cars.end();iter++)
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

    this->img = QImage(mat.data,mat.cols,mat.rows,QImage::Format_RGB888);

    this->img = this->img.scaled(ui->label->width(),ui->label->height());
}

void Page2::setId(int value)
{
    id = value;
    ui->label_5->setText(QString::number(value));
}

void Page2::getFileSendBack(int flag, char *account, char *path, char *fileName,int type_)
{
    if(type_ == 2)
    {
        if(flag == 1)
        {
            QMessageBox::information(this,"提示信息","图片上传成功");
        }else
        {
            QString path_ = QString(path)  +  QString(fileName);

            th = new SplitThread(path_.toStdString().c_str(),id);
            connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
            th->start();
        }
    }
}

void Page2::fileSplitOver()
{
    sendTh = new FileSendThread(th->getFileList(),th->getFileList().size());
    connect(sendTh,SIGNAL(fileSendOver()),this,SLOT(fileSendOver()));
    sendTh->start();
}

void Page2::on_pushButton_2_clicked()
{
    Mat car;
    int res;

    vector<CPlate> plateVec;
    res =  pr.plateRecognize(originalMat,plateVec);

    if(res == 0)
    {
        plate = plateVec.at(0);
        plateMat = plate.getPlateMat();
        cvtColor(plateMat,car,CV_BGR2RGB);
        cvtColor(car,car,CV_BGR2RGB);

        carImg = QImage(car.data,car.cols,car.rows,QImage::Format_RGB888);
        this->carImg = this->carImg.scaled(ui->label_11->width(),ui->label_11->height());
        ui->label_11->setPixmap(QPixmap::fromImage(this->carImg));

        string number_car = plateVec[0].getPlateStr();
        number = QString::fromLocal8Bit(number_car.c_str());

        QDateTime dateTime= QDateTime::currentDateTime();
        time_out = dateTime.toString("yyyy-MM-dd hh:mm:ss");

        ui->lineEdit->setText(number);

        path = getSetting::getmyseting()->getImgPath() + "/" + number.mid(3) + time_out + ".jpg";

        carImg.save(path);

        update();
    }
}

void Page2::getExitBack(int flag, int count, double park_time, double money, QString number, QString mes, QString time_in, QString time_out)
{
    if(flag == 1)
    {
        QMessageBox::information(this,"提示信息","车辆出场成功");
        ui->label_3->setText(QString::number(count));
        ui->label_16->setText(QString::number(park_time));
        ui->label_14->setText(time_in);
        ui->label_18->setText(QString::number(money));
    }else if(flag == -2)
    {
        QMessageBox::information(this,"提示信息","未查询到车牌或车辆未入场");
    }
}


void Page2::fileSendOver()
{
    char buf[300] = {0};

    FILESENDOVER filesendover = {0};
    filesendover.fileType = 2;
    memcpy(filesendover.findFieldName,ui->lineEdit->text().mid(3).toStdString().c_str(),sizeof (filesendover.findFieldName));
    memcpy(filesendover.fileName,number.mid(3).toStdString().c_str(),sizeof (filesendover.fileName));
    memcpy(filesendover.account,QString::number(id).toStdString().c_str(),sizeof (filesendover.account));
    memcpy(filesendover.fileName,path.split("/").last().toStdString().c_str(),sizeof (filesendover.fileName));
    memcpy(filesendover.filePath,(getSetting::getmyseting()->getImgPath() + "/").toStdString().c_str(),sizeof (filesendover.filePath));
    filesendover.fileTotalByte = th->getAll_count();
    filesendover.fileTotalCount = th->getFileList().size();

    HEAD head = {0};
    head.bussinessType = 6;
    head.bussinessLength = sizeof (FILESENDOVER);

    memcpy(buf,&head,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&filesendover,sizeof (FILESENDOVER));

    write(conneet::getmyconneet()->getFd(),buf,sizeof (HEAD) + sizeof (FILESENDOVER));

    qDebug() << "over!!!";
}

void Page2::getCURVEHICLEINFOBACK(int num)
{
    ui->label_3->setText(QString::number(num));
}
