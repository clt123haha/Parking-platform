#ifndef SPLITTHREAD_H
#define SPLITTHREAD_H

#include <QObject>
#include <queue>
#include "conneet.h"
#include <QThread>
#include <sys/types.h>
#include <sys/stat.h>
#include "getsetting.h"
#include <fcntl.h>
#include "filesendthread.h"

using namespace std;

class SplitThread :public QThread
{
    Q_OBJECT
public:
    SplitThread(QString path,int id);
    void run();
    queue<FILESEND> getFileList() const;
    int getAll_count() const;

private:
    QString path;
    queue<FILESEND> fileList;
    int id;
    int readbuf;
    int all_count;
    bool isover;

signals:
    void over();
};

#endif // SPLITTHREAD_H
