#ifndef GETSETTING_H
#define GETSETTING_H

#include <QObject>
#include<iostream>
#include<fstream>
#include <conneet.h>

using namespace std;
class getSetting :public QObject
{
    Q_OBJECT
public:
    static getSetting * getmyseting();
    QString getIp() const;
    int getPort() const;
    QString getVideoPath() const;
    QString getImgPath() const;
    void readSet();
    int getSize() const;
    bool isempty();

private:
    getSetting();
    static getSetting * myseting;
    QString ip;
    int port;
    QString videoPath;
    QString imgPath;
    int size;
};

#endif // GETSETTING_H
