#include "ver.h"

#include <QPainter>
#include <QStyleOption>
#include <QLineEdit>
#include <QTime>
#include <QChar>
#include <QDebug>

Ver::Ver(QWidget *parent) :
    QFrame(parent)
{
     //paintEvent();

     generateRandomNumber();
     update();
}

Ver::~Ver()
{

}

void Ver::generateRandomNumber()
{
    code.clear();

    for(int i = 0;i < 4;++i)
        {
            int num = qrand()%3;
            if(num == 0)
            {
                //数字
                code += QString::number(qrand()%10);
             }
             else if(num == 1)
             {
                //大写字母
                int temp = 'A';
                code += static_cast<QChar>(temp + qrand()%26);
              }else if(num == 2)
              {
                 //小写字母
                 int temp = 'a';
                code += static_cast<QChar>(temp + qrand()%26);
               }
       }
}



void Ver::paintEvent(QPaintEvent *)            //绘画
{


    QPainter painter(this);
    QPen pen;

    //画点
    for(int i = 0;i < 100;++i) {
       pen = QPen(QColor(qrand()%256,qrand()%256,qrand()%256));
       painter.setPen(pen);
       painter.drawPoint(qrand()%150,qrand()%50);
     }

     //画线
     for(int i = 0;i < 10;++i) {
         painter.drawLine(qrand()%150,qrand()%50,qrand()%150,qrand()%50);
     }

     pen = QPen(QColor(255,0,0,100));
     QFont font("楷体",25,QFont::Bold,true);
     painter.setFont(font);
     painter.setPen(pen);
     //绘画字
     for(int i = 0;i < 4;++i) {
        painter.drawText(10+30*i,5,30,40,Qt::AlignCenter, QString(code[i]));
     }

     //ui->ver->setText(code);
}

void Ver::mousePressEvent(QMouseEvent *event)
{
    generateRandomNumber();
    update();

   // qDebug() << code << endl;
}
