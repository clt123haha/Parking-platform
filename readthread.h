#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QThread>
#include "conneet.h"

class ReadThread : public QThread
{
    Q_OBJECT
public:
    void run();
    static ReadThread * getReadThread();
    void test();

private:
    ReadThread();
    static ReadThread * myReadThread;


signals:
    void sendDate(MYDATE * dateList);
    void sendRcv(int flag,char *meg);
    void sendRcv(int flag,char *meg,int whichView);
    void sendEntranceBack(int flag,int count,char *mes);
    void sendExitBack(int flag,int count,double park_time,double money,QString number,QString mes,QString time_in,QString time_out);
    void sendFileSendBack(int flag,char *account,char *path,char *fileName,int type_,char * findName);
    void sendFileSendBack(int flag,char *account,char *path,char *fileName,int type_);
    void sendCurVehicleInfoBack(int flag);
    void sendVIDEOQUERYBACK(VIDEOINFO * infoList);
    void sendVIDEOPLAYBACK(int count,int count_all,QString path);
    void sendVEHICLEINFOQUERYBACK(VEHICLEINFO * infoList);
    void senddata(int row,int id ,QString str1,QString str2,QString str3);
};

#endif // READTHREAD_H
