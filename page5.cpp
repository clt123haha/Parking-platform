#include "page5.h"
#include "ui_page5.h"

#include <QMessageBox>

Page5::Page5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page5)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("such as 闽A296Q0");
    ui->lineEdit_2->setPlaceholderText("xxxx-xx-xx xx:xx");
    ui->lineEdit_3->setPlaceholderText("xxxx-xx-xx xx:xx");
    timeView = new QCalendarWidget;
    page = 1;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ReadThread::getReadThread(),SIGNAL(sendVEHICLEINFOQUERYBACK(VEHICLEINFO*)),this,SLOT(getVEHICLEINFOQUERYBACK(VEHICLEINFO*)));
}

void Page5::getDate()
{
    WriteThread::getWriteThread()->sendVEHICLEINFOQUERY(page,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
}

Page5::~Page5()
{
    delete ui;
}

void Page5::on_pushButton_2_clicked()
{
    if(page == 1)
    {
        QMessageBox::information(this,"提示信息","已经是第一页");
        return;
    }
    WriteThread::getWriteThread()->sendVEHICLEINFOQUERY(page,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
}

void Page5::getVEHICLEINFOQUERYBACK(VEHICLEINFO *infoList)
{
    if(strlen(infoList[0].exit_time) == 0 && page>1)
    {
        QMessageBox::information(this,"提示信息","已经是最后一页");
        --page;
        WriteThread::getWriteThread()->sendVEHICLEINFOQUERY(page,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
        return;
    }
    else
    {
        ui->tableWidget->clear();
        list.clear();
        for(int i=0;i<5;i++)
        {
            if(infoList[i].id != 0)
            {

                qDebug() << "entrance_path" << infoList[i].entrance_path;
                qDebug() << "exit_path" << infoList[i].exit_path;
                QLabel *l1 = new QLabel();
                QImage img(infoList[i].entrance_path);
                img = img.scaled(ui->tableWidget->width()/6, ui->tableWidget->height()/5, Qt::KeepAspectRatio);
                l1->setPixmap(QPixmap::fromImage(img));
                l1->setAlignment(Qt::AlignCenter);
                ui->tableWidget->setCellWidget(i,3,l1);

                QLabel *l2 = new QLabel();
                QImage img2(infoList[i].exit_path);
                img2 = img2.scaled(ui->tableWidget->width()/6, ui->tableWidget->height()/5, Qt::KeepAspectRatio);
                l2->setPixmap(QPixmap::fromImage(img2));
                l2->setAlignment(Qt::AlignCenter);
                ui->tableWidget->setCellWidget(i,4,l2);

                list.push_back(infoList[i]);
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(infoList[i].vehicle_number));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(infoList[i].entrance_time));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(infoList[i].exit_time));
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(infoList[i].exit_money,'f',2)));
            }
        }
    }
}

void Page5::on_pushButton_3_clicked()
{
    ++page;
    WriteThread::getWriteThread()->sendVEHICLEINFOQUERY(page,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
}


void Page5::on_pushButton_4_clicked()
{
    umask(0);
    QDateTime dateTime= QDateTime::currentDateTime();
    QString time_now = dateTime.toString("yyyy-MM-dd");
    QString path = "/out"  +time_now +".txt";
    qDebug() << path;
    fstream f;
    f.open(path.toStdString().c_str(), ios::out | ios::trunc);
    if(f.is_open())
    {
        for(int i=0;i<5;i++)
        {
            if(list.size() <= i)
                break;
            f << list[i].vehicle_number;
            f << "\n";
            f << list[i].entrance_time;
            f << "\n";
            f << list[i].exit_time;
            f << "\n";
            f << list[i].entrance_path;
            f << "\n";
            f << list[i].exit_path;
            f << "\n";
            f << list[i].exit_money;
            f << "\n";
        }
        QMessageBox::information(this,"提示信息",QString("导出成功"+path));
    }else
    {
        QMessageBox::information(this,"提示信息","无法打开文件");
    }
}

void Page5::on_pushButton_clicked()
{
    WriteThread::getWriteThread()->sendVEHICLEINFOQUERY(page,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
}
