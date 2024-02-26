#ifndef FILESENDTHREAD_H
#define FILESENDTHREAD_H

#include <QObject>
#include <queue>
#include <QThreadPool>
#include "mythread.h"

using namespace std;

class FileSendThread:public QThread
{
    Q_OBJECT
public:
    FileSendThread(queue<FILESEND> fileList,int count);
    void run();

signals:
    void sendOver();
    void fileSendOver();

private slots:
    void getOverSingal(int num);

private:
    int id;
    queue<FILESEND> fileList;
    int count;
};

#endif // FILESENDTHREAD_H
