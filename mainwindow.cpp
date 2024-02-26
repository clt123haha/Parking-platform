#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    page1 = new Page1;
    page2 = new Page2;
    page3 = new Page3;
    page4 = new Page4;
    page5 = new Page5;
    timer = new QTimer;
    setView = new SetingWiget;
    setView->setIsMain(true);

    wigetLayout = new QStackedLayout;
    ui->widget->setLayout(wigetLayout);

    wigetLayout->addWidget(page1);
    wigetLayout->addWidget(page2);
    wigetLayout->addWidget(page3);
    wigetLayout->addWidget(page4);
    wigetLayout->addWidget(page5);

    connect(ReadThread::getReadThread(),SIGNAL(sendRcv(int,char*,int)),this,SLOT(getRes(int,char*,int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(time_send()));
    connect(setView,SIGNAL(setEnd()),this,SLOT(setEnd()));
    connect(setView,SIGNAL(setCancel()),this,SLOT(setCansel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    setView->getSetting2Widget();
    this->setView->show();
}

void MainWindow::setId(QString value)
{
    id = value.toInt();
    ui->pushButton_6->setText(value);
    page1->setId(id);
    page2->setId(id);
    page3->setId(id);
    page4->setId(id);

}

void MainWindow::ReadyWork()
{
    CameraThread::getCameraThread()->openCamera();
    if(!CameraThread::getCameraThread()->getIsopen())
    {
        QMessageBox::information(this,"提示信息","摄像头无法打开");
        return;
    }
    CameraThread::getCameraThread()->start();

    CameraThread2::getCameraThread2()->openCamera();
    if(!CameraThread2::getCameraThread2()->getIsopen())
    {
        QMessageBox::information(this,"提示信息","摄像头无法打开");
        return;
    }
    CameraThread2::getCameraThread2()->start();
}

void MainWindow::openTimer()
{
    WriteThread::getWriteThread()->sendHEART(id);
    timer->start(20000);
}

void MainWindow::timerStop()
{
    timer->stop();
}

void MainWindow::setCansel()
{

    this->setView->hide();
}

void MainWindow::setEnd()
{
    this->setView->hide();
    QMessageBox::information(this,"提示信息","设置成功,重启后生效");
}

void MainWindow::time_send()
{
    WriteThread::getWriteThread()->sendHEART(id);
}

void MainWindow::on_pushButton_clicked()
{
    page3->stoptimer();
    this->wigetLayout->setCurrentIndex(0);
}

void MainWindow::getRes(int flag, char *mes, int which)
{
    if(which == 0)
    {
        if(flag == 1)
        {
            emit back2Login();
            //资源关闭操作
            this->timerStop();
            CameraThread2::getCameraThread2()->setIsover(true);
            CameraThread::getCameraThread()->setIsover(true);
            page3->closeRecord();
        }else
        {
            if(memcmp(mes,"select user error",sizeof (mes)) == 0)
            {
                QMessageBox::information(this,"提示信息","查询不到该用户");
            }else if(memcmp(mes,"update statu error",sizeof (mes)) == 0)
            {
                QMessageBox::information(this,"提示信息","修改用户状态失败");
            }
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    page3->stoptimer();
    this->wigetLayout->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    page3->openTimer();
    this->wigetLayout->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    page3->stoptimer();
    page4->flush();
    this->wigetLayout->setCurrentIndex(3);
}

void MainWindow::on_pushButton_3_clicked()
{
    page3->stoptimer();
    this->wigetLayout->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{
    WriteThread::getWriteThread()->sendUserExit(QString::number(id));
}
