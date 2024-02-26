#include "filesendthread.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


FileSendThread::FileSendThread(queue<FILESEND> fileList,int count)
{
    this->fileList = fileList;
    this->count = count;
    this->id = id;
}

void FileSendThread::run()
{
    QThreadPool::globalInstance()->setMaxThreadCount(10);

    int size = fileList.size();

    for(int i=0;i<size;i++)
    {
        myThread * task = new myThread(fileList.front());
        QObject::connect(task,SIGNAL(sendOver(int)),this,SLOT(getOverSingal(int)));
        task->setAutoDelete(true);
        QThreadPool::globalInstance()->start(task);
        fileList.pop();
        msleep(250);
    }
}

void FileSendThread::getOverSingal(int num)
{
    if(num == count)
    {
        emit fileSendOver();
    }
}
