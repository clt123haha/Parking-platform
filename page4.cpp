#include "page4.h"
#include "ui_page4.h"

#include <QMessageBox>

Page4::Page4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page4)
{
    ui->setupUi(this);
    playView = new PlayVideoView;
    BtnGroup = new QButtonGroup;
    BtnGroup->addButton(ui->radioButton,1);
    BtnGroup->addButton(ui->radioButton_2,0);
    ui->radioButton->setChecked(true);
    BtnGroup->setExclusive(true);
    page = 1;
    ui->listWidget->setViewMode(QListWidget::IconMode);
    ui->listWidget->setIconSize(QSize(834, 216));
    ui->listWidget->setSpacing(10);//间距
    ui->listWidget->setResizeMode(QListView::Adjust);//适应布局调整
    ui->listWidget_2->setMovement(QListView::Static);//不能移动

    connect(ReadThread::getReadThread(),SIGNAL(sendDate(MYDATE*)),this,SLOT(getDate(MYDATE*)));
    connect(ReadThread::getReadThread(),SIGNAL(sendVIDEOPLAYBACK(int,int,QString)),this,SLOT(getVIDEOPLAYBACK(int,int,QString)));
    connect(ReadThread::getReadThread(),SIGNAL(sendVIDEOQUERYBACK(VIDEOINFO*)),this,SLOT(getVIDEOQUERYBACK(VIDEOINFO*)));
    connect(playView,SIGNAL(sendCount(int,QString)),this,SLOT(closePlayView(int,QString)));
}

void Page4::sendDate()
{
    WriteThread::getWriteThread()->sendDATEINFO(id,BtnGroup->checkedId()+1);
}

Page4::~Page4()
{
    delete ui;
}

void Page4::flush()
{
    WriteThread::getWriteThread()->sendDATEINFO(id,BtnGroup->checkedId()+1);
}

void Page4::closePlayView(int count,QString time)
{
    WriteThread::getWriteThread()->sendVIDEOPLAYOVER(count,id,ui->listWidget->currentItem()->text(),time);
}

void Page4::on_radioButton_2_clicked()
{
    WriteThread::getWriteThread()->sendDATEINFO(id,BtnGroup->checkedId()+1);
}

void Page4::on_listWidget_itemClicked(QListWidgetItem *item)
{
}

void Page4::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    WriteThread::getWriteThread()->sendVIDEOPLAY(id,item->text());
}

void Page4::on_pushButton_clicked()
{
    if(page == 1)
    {
        QMessageBox::information(this,"提示信息","已经是第一页");
        return;
    }

    --page;
    //发送请求
    WriteThread::getWriteThread()->sendVIDEOQUERY(page,id,ui->listWidget_2->currentItem()->text());
}

void Page4::on_pushButton_2_clicked()
{
    if(ui->listWidget_2->currentItem())
    {
        ++page;
        //发送请求
        WriteThread::getWriteThread()->sendVIDEOQUERY(page,id,ui->listWidget_2->currentItem()->text());
    }
    else
    {
        QMessageBox::information(this,"提示信息","请先选择一个日期");
    }
}

void Page4::getDate(MYDATE *dateList)
{
    ui->listWidget_2->clear();
    for(int i=0;i<31;i++)
    {
        if(strlen(dateList[i].date) == 0)
            break;
        else
        {
            QListWidgetItem * item = new QListWidgetItem;
            item->setText(dateList[i].date);
            ui->listWidget_2->addItem(item);
        }
    }
}

void Page4::getVIDEOQUERYBACK(VIDEOINFO *infoList)
{
    ui->listWidget->clear();
    if(strlen(infoList[0].video_name) == 0)
    {
        QMessageBox::information(this,"提示信息","已经是最后一页");
        --page;
        WriteThread::getWriteThread()->sendVIDEOQUERY(page,id,ui->listWidget_2->currentItem()->text());
        return;
    }
    for(int i=0;i<9;i++)
    {
        if(strlen(infoList[i].video_name) == 0 || infoList[i].video_name[0] != 'v')
            break;

        QListWidgetItem * item = new QListWidgetItem;
        qDebug() <<  infoList[i].video_cover;
        qDebug() <<  infoList[i].video_name;
        item->setIcon(QIcon(infoList[i].video_cover));
        item->setText(infoList[i].video_name);
        ui->listWidget->addItem(item);
    }
}

void Page4::setId(int value)
{
    id = value;
}

int Page4::getId() const
{
    return id;
}

void Page4::on_radioButton_clicked()
{
    WriteThread::getWriteThread()->sendDATEINFO(id,BtnGroup->checkedId()+1);
}

void Page4::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    WriteThread::getWriteThread()->sendVIDEOQUERY(page,id,item->text());
}

void Page4::getVIDEOPLAYBACK(int count, int count_all, QString path)
{
    playView->setPath(path);
    if(count != 0)
        playView->setCount(count);
    playView->show();
}
