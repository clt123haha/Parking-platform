#include "writethread.h"

#include <QTextCodec>

WriteThread * WriteThread::myWriteThread = nullptr;

WriteThread *WriteThread::getWriteThread()
{
    if(myWriteThread == nullptr)
    {
        myWriteThread = new WriteThread;
    }
    return myWriteThread;
}

void WriteThread::run()
{
    int res = 0;
    while(true)
    {
        if(len != 0)
        {
            qDebug() << len;
            res = write(conneet::getmyconneet()->getFd(),buf,len);
            qDebug() << res;
            bzero(buf,sizeof (buf));
            len = 0;
        }
    }
}

void WriteThread::sendLogin(QString name, QString pwd)
{
    HEAD myHead = {0};
    LOGIN myLogin = {0};

    myHead.bussinessType = 1;
    myHead.bussinessLength = sizeof (LOGIN);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(myLogin.account,name.toStdString().c_str(),sizeof (myLogin.account));
    memcpy(myLogin.pwd,pwd.toStdString().c_str(),sizeof (myLogin.pwd));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&myLogin,sizeof (LOGIN));

    len = sizeof (HEAD) + sizeof (LOGIN);
}

void WriteThread::sendEnroll(QString account, QString name, QString pwd)
{
    HEAD myHead = {0};
    REG reg = {0};

    myHead.bussinessType = 2;
    myHead.bussinessLength = sizeof (REG);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(reg.account,account.toStdString().c_str(),sizeof (account.toStdString().c_str()));
    memcpy(reg.name,name.toStdString().c_str(),sizeof (name.toStdString().c_str()));
    memcpy(reg.pwd,pwd.toStdString().c_str(),sizeof (reg.pwd));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&reg,sizeof (REG));

    len = sizeof (HEAD) + sizeof (REG);
}

void WriteThread::sendEntrance(QString number, QString door, QString time, QString path)
{
    HEAD myHead = {0};
    ENTRANCE entrance = {0};

    myHead.bussinessType = 3;
    myHead.bussinessLength = sizeof (ENTRANCE);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    sprintf(entrance.entrance_entrance,"%s",door.toLocal8Bit().data());
    sprintf(entrance.vehicle_number,"%s",number.toLocal8Bit().data());
    memcpy(entrance.entrance_time,time.toStdString().data(),sizeof (entrance.entrance_time));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&entrance,sizeof (ENTRANCE));

    qDebug() << entrance.entrance_time;
    qDebug() << entrance.vehicle_number;
    qDebug() << entrance.entrance_entrance;


    len = sizeof (HEAD) + sizeof (ENTRANCE);
}

void WriteThread::sendExit(int isvip, QString number, QString door, QString time, QString path)
{
    HEAD myHead = {0};
    EXIT exit = {0};

    myHead.bussinessType = 4;
    myHead.bussinessLength = sizeof (EXIT);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    exit.isvip = isvip;
    memcpy(exit.exit_time,time.toStdString().data(),sizeof (exit.exit_time));
    sprintf(exit.exit_export,"%s",door.toLocal8Bit().data());
    sprintf(exit.vehicle_number,"%s",number.toLocal8Bit().data());

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&exit,sizeof (EXIT));

    len = sizeof (HEAD) + sizeof (EXIT);
}

void WriteThread::sendUserExit(QString account)
{
    HEAD myHead = {0};
    USEREXIT exit = {0};

    myHead.bussinessType = -1;
    myHead.bussinessLength = sizeof (USEREXIT);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(&(exit.account),account.toStdString().c_str(),sizeof (exit.account));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&exit,sizeof (USEREXIT));

    len = sizeof (HEAD) + sizeof (USEREXIT);
}

void WriteThread::sendCurVehicleInfo(int flag)
{
    HEAD myHead = {0};
    CURVEHICLEINFO curInfo = {0};

    myHead.bussinessType = 7;
    myHead.bussinessLength = sizeof (CURVEHICLEINFO);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    curInfo.flag = flag;

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&curInfo,sizeof (CURVEHICLEINFO));

    len = sizeof (HEAD) + sizeof (CURVEHICLEINFO);
}

void WriteThread::snedVideo(long num, QString path, QString name, QString time,int id)
{
    HEAD myHead = {0};
    VIDEO vidoe = {0};

    myHead.bussinessType = 8;
    myHead.bussinessLength = sizeof (VIDEO);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    vidoe.video_frame_count = num;
    memcpy(vidoe.video_name,name.toStdString().c_str(),sizeof (vidoe.video_name));
    memcpy(vidoe.video_path,path.toStdString().c_str(),sizeof (vidoe.video_path));
    memcpy(vidoe.video_record_date,time.toStdString().c_str(),sizeof (vidoe.video_record_date));
    memcpy(vidoe.account,QString::number(id).toStdString().c_str(),sizeof (vidoe.account));

    qDebug() << "path   " << vidoe.video_name;
    qDebug() << "path   " << name;

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&vidoe,sizeof (VIDEO));

    len = sizeof (HEAD) + sizeof (VIDEO);
}

void WriteThread::sendDATEINFO(int id, int flag)
{
    HEAD myHead = {0};
    DATEINFO date = {0};

    myHead.bussinessType = 15;
    myHead.bussinessLength = sizeof (DATEINFO);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    date.flag = flag;
    memcpy(date.account,QString::number(id).toStdString().c_str(),sizeof (date.account));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&date,sizeof (DATEINFO));

    len = sizeof (HEAD) + sizeof (DATEINFO);
}

void WriteThread::sendVIDEOQUERY(int page,int id,QString time)
{
    HEAD myHead = {0};
    VIDEOQUERY qure = {0};

    myHead.bussinessType = 10;
    myHead.bussinessLength = sizeof (VIDEOQUERY);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    qure.currentPage = page;
    memcpy(qure.account,QString::number(id).toStdString().c_str(),sizeof (qure.account));
    memcpy(qure.queryDate,time.toStdString().c_str(),sizeof (qure.queryDate));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&qure,sizeof (VIDEOQUERY));

    len = sizeof (HEAD) + sizeof (VIDEOQUERY);
}

void WriteThread::sendVIDEOPLAY(int id, QString name)
{
    HEAD myHead = {0};
    VIDEOPLAY qure = {0};

    myHead.bussinessType = 11;
    myHead.bussinessLength = sizeof (VIDEOPLAY);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(qure.account,QString::number(id).toStdString().c_str(),sizeof (qure.account));
    memcpy(qure.video_name,name.toStdString().c_str(),sizeof (qure.video_name));

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&qure,sizeof (VIDEOPLAY));

    len = sizeof (HEAD) + sizeof (VIDEOPLAY);
}

void WriteThread::sendVIDEOPLAYOVER(int count, int id, QString name, QString time)
{
    HEAD myHead = {0};
    VIDEOPLAYOVER qure = {0};

    myHead.bussinessType = 12;
    myHead.bussinessLength = sizeof (VIDEOPLAYOVER);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(qure.account,QString::number(id).toStdString().c_str(),sizeof (qure.account));
    memcpy(qure.video_name,name.toStdString().c_str(),sizeof (qure.video_name));
    memcpy(qure.play_time,time.toStdString().c_str(),sizeof (qure.play_time));
    qure.current_frame = count;

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&qure,sizeof (VIDEOPLAYOVER));

    len = sizeof (HEAD) + sizeof (VIDEOPLAYOVER);
}

void WriteThread::sendVEHICLEINFOQUERY(int page, QString number, QString in_time, QString out_time)
{
    HEAD myHead = {0};
    VEHICLEINFOQUERY qure = {0};

    myHead.bussinessType = 13;
    myHead.bussinessLength = sizeof (VEHICLEINFOQUERY);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));

    memcpy(qure.exit_time,out_time.toStdString().c_str(),sizeof (qure.exit_time));
    memcpy(qure.entrance_time,in_time.toStdString().c_str(),sizeof (qure.entrance_time));
    memcpy(qure.vehicle_number,number.toStdString().c_str(),sizeof (qure.vehicle_number));
    qure.currentPage = page;

    qDebug() << qure.entrance_time;

    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&qure,sizeof (VEHICLEINFOQUERY));

    len = sizeof (HEAD) + sizeof (VEHICLEINFOQUERY);
}

void WriteThread::sendHEART(int id)
{
    HEAD myHead = {0};
    HEART qure = {0};

    myHead.bussinessType = 14;
    myHead.bussinessLength = sizeof (HEART);
    memcpy(myHead.cheakCoke,"abc",sizeof (myHead.cheakCoke));


    memcpy(qure.account,QString::number(id).toStdString().c_str(),sizeof (qure.account));


    memcpy(buf,&myHead,sizeof (HEAD));
    memcpy((void *)(buf + sizeof (HEAD)),&qure,sizeof (HEART));

    len = sizeof (HEAD) + sizeof (HEART);
}

WriteThread::WriteThread()
{
    bzero(buf,sizeof (buf));
    len = 0;
}
