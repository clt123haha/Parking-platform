#include "readthread.h"

ReadThread * ReadThread::myReadThread = nullptr;

void ReadThread::run()
{
    char buf[2000] = {0};
    HEAD myHead = {0};
    while(true)
    {
        bzero(&myHead,sizeof (HEAD));
        bzero(&buf,sizeof (buf));
        read(conneet::getmyconneet()->getFd(),&buf,sizeof (buf));
        memcpy(&myHead,buf,sizeof (HEAD));
        qDebug() << myHead.bussinessType;
        if(myHead.bussinessType == 50)
        {
            RCV rcv = {0};

            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendRcv(rcv.flag,rcv.msg,0);
        }else if(myHead.bussinessType == 51)
        {
            //login
            RCV rcv = {0};

            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendRcv(rcv.flag,rcv.msg,1);
        }else if(myHead.bussinessType == 52)
        {
            RCV rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendRcv(rcv.flag,rcv.msg,2);
        }else if(myHead.bussinessType == 53)
        {
            ENTRANCEBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            qDebug() <<  "flag"  << rcv.flag;
            qDebug() <<"current_count" <<  rcv.current_count;
            qDebug() <<"message" << rcv.message;
            for(int i=0;i<4;i++)
            {
                if(strlen(rcv.record[i].vehicle_number) != 0)
                    emit senddata(i,rcv.record[i].entrance_id,rcv.record[i].vehicle_number,rcv.record[i].entrance_time,rcv.record[i].entrance_entrance);
            }

            emit sendEntranceBack(rcv.flag,rcv.current_count,rcv.message);
        }else if(myHead.bussinessType == 54)
        {
            EXITBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendExitBack(rcv.flag,rcv.current_count,rcv.parkingtime,rcv.parkingmoney,rcv.vehicle_number,rcv.message,rcv.entrance_time,rcv.exit_time);
        }else if(myHead.bussinessType == 56)
        {
            FILESENDOVERBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendFileSendBack(rcv.flag,rcv.account,rcv.filePath,rcv.fileName,rcv.fileType);
            emit sendFileSendBack(rcv.flag,rcv.account,rcv.filePath,rcv.fileName,rcv.fileType,rcv.findFieldName);
        }else if(myHead.bussinessType == 65)
        {
            DATEINFOBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendDate(rcv.dateList);
        }else if(myHead.bussinessType == 57)
        {
            CURVEHICLEINFOBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendCurVehicleInfoBack(rcv.vehicleCount);
        }else if(myHead.bussinessType == 60)
        {
            VIDEOQUERYBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);
            for(int i=0;i<9;i++)
            {
                if(strlen(rcv.videoinformation[i].video_name) == 0)
                    break;
                qDebug() << "video_name" <<  rcv.videoinformation[i].video_name;
                qDebug() <<"video_cover" << rcv.videoinformation[i].video_cover;
            }

            emit sendVIDEOQUERYBACK(rcv.videoinformation);
        }else if(myHead.bussinessType == 61)
        {
            VIDEOPLAYBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendVIDEOPLAYBACK(rcv.current_frame,rcv.totalFrame,rcv.videoPlayPath);
        }else if(myHead.bussinessType == 63)
        {
            VEHICLEINFOQUERYBACK rcv = {0};
            memcpy(&rcv,(void *)(buf + sizeof (HEAD)),myHead.bussinessLength);

            emit sendVEHICLEINFOQUERYBACK(rcv.vehicleRecord);
        }

    }
}

ReadThread * ReadThread::getReadThread()
{
    if(myReadThread == nullptr)
    {
        myReadThread = new ReadThread();
    }
    return myReadThread;
}

ReadThread::ReadThread()
{
}

void ReadThread::test()
{

}
