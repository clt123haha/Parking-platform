#include "playvideoview.h"
#include "ui_playvideoview.h"
#include "videothread.h"

PlayVideoView::PlayVideoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayVideoView)
{
    ui->setupUi(this);
    isPuase = false;
    slider = new newqslider(this);
    slider->setMinimum(0);
    slider->setSingleStep(1);
    slider->setOrientation (Qt::Horizontal);
    slider->setGeometry(QRect(50,450,691,20));//50,450,691,20
    connect(slider,SIGNAL(sliderMoved(int)),this,SLOT(moveSlider(int)));//接收每一帧Mat
    connect(slider,SIGNAL(sliderReleased()),this,SLOT(releseSlider()));//接收每一帧Mat
}

PlayVideoView::~PlayVideoView()
{
    delete ui;
}

QString intToQString(int x) {
    int hours = x / 3600; // 计算小时
    int minutes = (x % 3600) / 60; // 计算分钟
    int seconds = x % 60; // 计算秒钟
    return QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
}


void PlayVideoView::paintEvent(QPaintEvent *e)
{
    ui->label->setPixmap(QPixmap::fromImage(this->img));
    ui->label_2->setText(intToQString(count/th->getFps()) + '/' + time_all);
}

void PlayVideoView::closeEvent(QCloseEvent *event)
{
    QDateTime dateTime= QDateTime::currentDateTime();
    QString time_now = dateTime.toString("yyyy-MM-dd hh:mm:ss");

    if(count != th->getVideoAllFramecount())
        emit sendCount(count,time_now);
    th->setIsrun(false);
    if(isPuase)
    {
        ui->pushButton->setText("暂停");
        isPuase = !isPuase;
    }
}

void PlayVideoView::setPath(const QString &value)
{
    path = value;
    th = new videothread(const_cast<char *>(value.toStdString().c_str()));
    slider->setMaximum(th->getVideoAllFramecount());
    th->setIsrun(true);
    time_all = intToQString(th->getVideoAllFramecount()/th->getFps());
    connect(th,SIGNAL(sendFrame(int,Mat)),this,SLOT(getMat(int,Mat)),Qt::BlockingQueuedConnection);//接收每一帧Mat
    th->start();
}

void PlayVideoView::setCount(int count)
{
    slider->setValue(count);
    th->pauseThread();
    th->setCurrentFrame(count);
    th->resumeThread();
}

void PlayVideoView::releseSlider()
{
    th->setCurrentFrame(slider->value());
    th->resumeThread();
    if(isPuase)
    {
        isPuase = !isPuase;
        ui->pushButton->setText("暂停");
    }
}



void PlayVideoView::on_pushButton_clicked()
{
    isPuase = !isPuase;
    if(isPuase)
    {
        ui->pushButton->setText("继续");
        th->pauseThread();
    }else
    {
        ui->pushButton->setText("暂停");
        th->resumeThread();
    }
}

void PlayVideoView::getMat(int count , Mat mat)
{
    this->img = QImage(mat.data,mat.cols,mat.rows,QImage::Format_RGB888);
    this->img = this->img.scaled(ui->label->width(),ui->label->height());
    this->count = count;
    slider->setValue(count);
    update();
}

void PlayVideoView::moveSlider(int p)
{
    th->pauseThread();//播放暂停
    if(!isPuase)
    {
        isPuase = !isPuase;
        ui->pushButton->setText("继续");
    }
}


void PlayVideoView::on_comboBox_currentIndexChanged(int index)
{
    th->setWaitTime(40 - 10*index);
}

void PlayVideoView::setId(int value)
{
    id = value;
}

