#include "page1.h"
#include "ui_page1.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>

Page1::Page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page1)
{
    ui->setupUi(this);
    cascade.load("cars.xml");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    pr.setDetectType(PR_DETECT_CMSER | PR_DETECT_COLOR);
    pr.setMaxPlates(4);
    pr.setResultShow(false);

    timer = new QTimer;
    timer->start(1000);

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdata()));
    connect(CameraThread::getCameraThread(),SIGNAL(sendMat(Mat)),this,SLOT(getMat(Mat)),Qt::BlockingQueuedConnection);
    connect(ReadThread::getReadThread(),SIGNAL(sendFileSendBack(int,char*,char*,char*,int)),this,SLOT(getFileSendBack(int,char*,char*,char*,int)));
    connect(ReadThread::getReadThread(),SIGNAL(sendEntranceBack(int,int,char*)),this,SLOT(getEntranceBack(int,int,char*)));
    connect(ReadThread::getReadThread(),SIGNAL(senddata(int,int,QString,QString,QString)),this,SLOT(getdate(int,int,QString,QString,QString)));
}

void Page1::paintEvent(QPaintEvent *)
{
    ui->label->setPixmap(QPixmap::fromImage(this->img));
    ui->label_5->setPixmap(QPixmap::fromImage(this->carImg));
    ui->label_3->setText(time_in);
}

Page1::~Page1()
{
    delete ui;
}


void Page1::getMat(Mat mat)
{
    cvtColor(mat, mat, CV_BGR2RGB);
    this->originalMat = mat.clone();
    this->originalImg = QImage(originalMat.data,originalMat.cols,originalMat.rows,QImage::Format_RGB888);
    this->identify();

    update();
}

void Page1::on_pushButton_clicked()
{
    QString door = "西入口";
    WriteThread::getWriteThread()->sendEntrance(ui->lineEdit->text().mid(3),door,time_in,path);

    th = new SplitThread(path,id);
    connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
    th->start();
}

void Page1::on_pushButton_2_clicked()
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
        carImg = carImg.scaled(ui->label_5->width(),ui->label_5->height());

        string number_car = plateVec[0].getPlateStr();
        number = QString::fromLocal8Bit(number_car.c_str());

        QDateTime dateTime= QDateTime::currentDateTime();
        time_in = dateTime.toString("yyyy-MM-dd hh:mm:ss");

        ui->lineEdit->setText(number);

        path = getSetting::getmyseting()->getImgPath() + "/" + number.mid(3) + time_in + ".jpg";

        qDebug() << path;

        carImg.save(path);

        update();
    }
}

void Page1::getEntranceBack(int flag, int count, char *mes)
{
    if(flag == 1)
    {
        QMessageBox::information(this,"提示信息","车辆入场成功");
    }else if(flag == -1)
    {
        if(strcmp("insert error",mes) == 0)
        {
            QMessageBox::information(this,"提示信息","车辆入场失败");
        }else if(strcmp("entrance error",mes) == 0)
        {
            QMessageBox::information(this,"提示信息","车辆还未出场");
        }
    }

    ui->label_15->setText(QString::number(count));


}

void Page1::getdate(int row,int id, QString str1, QString str2, QString str3)
{

    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(id)));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(str1));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(str2));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(str3));

}

void Page1::timerUpdata()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_19->setText(str);

}

void Page1::fileSendOver()
{
    char buf[300] = {0};

    FILESENDOVER filesendover = {0};
    filesendover.fileType = 1;
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

void Page1::fileSplitOver()
{
    sendTh = new FileSendThread(th->getFileList(),th->getFileList().size());
    connect(sendTh,SIGNAL(fileSendOver()),this,SLOT(fileSendOver()));
    sendTh->start();
}

void Page1::getFileSendBack(int flag, char *account, char *path, char *fileName,int type_)
{
    if(type_ == 1)
    {
        if(flag == 1)
        {
            QMessageBox::information(this,"提示信息","图片上传成功");
        }else
        {
            QString path_ = QString(path) +  QString(fileName);

            th = new SplitThread(path_.toStdString().c_str(),id);
            connect(th,SIGNAL(over()),this,SLOT(fileSplitOver()));
            th->start();
        }
    }
}

void Page1::setId(int value)
{
    id = value;
    ui->label_17->setText(QString::number(value));
}

void Page1::identify()
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

    this->img = this->img.scaled(ui->label->width(),ui->label->height());
}
