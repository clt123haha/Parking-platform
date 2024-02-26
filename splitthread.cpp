#include "splitthread.h"

SplitThread::SplitThread(QString path,int id)
{
    this->path = path;
    this->id = id;
    isover = false;
}

void SplitThread::run()
{
    char buf[1000] = {0};
    int fd;
    int num = 1;
    qDebug()<< "path of img  " << path.toStdString().c_str();

    fd = open(path.toStdString().c_str(),O_RDONLY,0777);
    if(fd < 0)
    {
        perror("open file");
        return;
    }

    FILESEND filesned = {0};
    umask(0);

    memcpy(filesned.fileName,path.split("/").last().toStdString().c_str(),sizeof (filesned.fileName));
    memcpy(filesned.filePath,(getSetting::getmyseting()->getImgPath()+"/").toStdString().c_str(),sizeof (filesned.filePath));
    memcpy(filesned.account,QString::number(id).toStdString().c_str(),sizeof (filesned.account));
    all_count = lseek(fd,0,SEEK_END);
    filesned.fileTotalByte = all_count;
    if(filesned.fileTotalByte % 1000 == 0)
    {
        filesned.fileTotalCount = filesned.fileTotalByte/sizeof (buf);
    }else
    {
        filesned.fileTotalCount = filesned.fileTotalByte/sizeof (buf) + 1;
    }

    lseek(fd,0,SEEK_SET);

    while((readbuf = read(fd,buf,sizeof (buf))) != 0)
    {
        filesned.currentFileNum = num++;
        filesned.currentFileByte = readbuf;
        memcpy(filesned.content,buf,readbuf);

        bzero(buf,sizeof (buf));

        fileList.push(filesned);
    }


    qDebug() << fileList.size();

    emit over();

}

queue<FILESEND> SplitThread::getFileList() const
{
    return fileList;
}


int SplitThread::getAll_count() const
{
    return all_count;
}


