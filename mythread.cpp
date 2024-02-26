#include "mythread.h"

myThread::myThread(FILESEND file):QObject (nullptr)
{
    memcpy(&(this->file),&file,file.currentFileByte);
}

void myThread::run()
{
    char buf[2000];
    if(file.currentFileByte > 0)
    {
        QMutexLocker locker(&mutex);
        HEAD head = {0};

        head.bussinessType = 5;
        head.bussinessLength = sizeof (FILESEND);

        memcpy(buf,&head,sizeof (HEAD));
        memcpy((void *)(buf + sizeof (HEAD)),&file,sizeof (FILESEND));



        qDebug() <<"currentFileNum" << file.currentFileNum;
        qDebug() <<"currentFileByte" << file.currentFileByte;
        qDebug() << "account" << file.account;
        qDebug() << "content" << file.content;
        qDebug() << "fileName" << file.fileName;
        qDebug() << "filePath" << file.filePath;
        qDebug() << "fileTotalByte" << file.fileTotalByte;
        qDebug() << "fileTotalCount" << file.fileTotalCount;

        int res = write(conneet::getmyconneet()->getFd(),buf,sizeof (HEAD) + sizeof (FILESEND));

        qDebug() << "res" << res;

        emit sendOver(file.currentFileNum);
    }
}
