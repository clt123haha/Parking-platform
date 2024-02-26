#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QRunnable>
#include "conneet.h"
#include <QMutex>
#include <QMutexLocker>

class myThread :public QObject,public QRunnable
{
    Q_OBJECT
public:
    myThread(FILESEND file);
    void run();

signals:
    void sendOver(int count);

private:
    FILESEND file;
    QMutex mutex;

};

#endif // MYTHREAD_H
