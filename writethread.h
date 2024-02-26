#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QObject>
#include <QThread>
#include "conneet.h"
#pragma execution_character_set("utf-8")


class WriteThread :public QThread
{
    Q_OBJECT
public:
    static WriteThread * getWriteThread();
    void run();
    void sendLogin(QString name,QString pwd);
    void sendEnroll(QString account,QString name,QString pwd);
    void sendEntrance(QString number,QString door,QString time,QString path);
    void sendExit(int isvip,QString number,QString door,QString time,QString path);
    void sendUserExit(QString account);
    void sendCurVehicleInfo(int flag);
    void snedVideo(long num,QString path,QString name,QString time,int id);
    void sendDATEINFO(int id,int flag);
    void sendVIDEOQUERY(int page,int id,QString time);
    void sendVIDEOPLAY(int id,QString name);
    void sendVIDEOPLAYOVER(int count,int id,QString name,QString time);
    void sendVEHICLEINFOQUERY(int page,QString number,QString in_time,QString out_time);
    void sendHEART(int id);

private:
    static WriteThread * myWriteThread;
    WriteThread();
    char buf[200];
    int len;
};

#endif // WRITETHREAD_H
