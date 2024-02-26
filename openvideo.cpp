#include "openvideo.h"
#include "ui_openvideo.h"

openVideo::openVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::openVideo)
{
    ui->setupUi(this);
    pthread=new videothread("./head.mp4");
    setView = new SetingWiget();
    loginView = new LoginView;
    pthread->setIsVideoFile(true);
    //第五个参数采用Qt::BlockingQueuedConnection   信号发出后发送线程阻塞，直到槽函数执行完毕，继续发送下一条信号
    connect(pthread,SIGNAL(sendFrame(int,Mat)),this,SLOT(receiveFrame(int,Mat)),Qt::BlockingQueuedConnection);//接收每一帧Mat
    connect(pthread,SIGNAL(videoEnd()),this,SLOT(endVideo()));
    connect(setView,SIGNAL(setEnd()),this,SLOT(setOver()));
}

openVideo::~openVideo()
{
    delete ui;
}

void openVideo::receiveFrame(int currentFrame, Mat frame)
{
    this->img1 = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    this->img1 = this->img1.scaled(ui->label->width(),ui->label->height());
    update();
}

void openVideo::endVideo()
{
    if(getSetting::getmyseting()->isempty())
    {
        setView->show();
        this->hide();
        return;
    }else
    {
        getSetting::getmyseting()->readSet();
    }
    if(!conneet::getmyconneet()->Conneet(getSetting::getmyseting()->getIp(),getSetting::getmyseting()->getPort()))
    {
        setView->show();
        this->hide();
    }
    else
    {
        this->hide();
        loginView->show();
        ReadThread::getReadThread()->start();
        WriteThread::getWriteThread()->start();
    }
    
}

void openVideo::setOver()
{
    setView->hide();
    loginView->show();
    ReadThread::getReadThread()->start();
    WriteThread::getWriteThread()->start();
}


void openVideo::paintEvent(QPaintEvent *e)
{
    ui->label->setPixmap(QPixmap::fromImage(this->img1));
}

void openVideo::play()
{
    pthread->start();
}


