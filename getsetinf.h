#ifndef GETSETINF_H
#define GETSETINF_H

#include <QObject>
#include <QString>
#include<iostream>
#include<fstream>
#include<QObject>
using namespace std;
class getSetinf
{
    Q_OBJECT
public:
    static getSetinf * getmyseting();
    QString getIp() const;
    QString getPort() const;
    QString getVideoPath() const;
    QString getImgPath() const;
    int getSize() const;

signals:
    void isempty();

private:
    getSetinf();
    static getSetinf * myseting;
    QString ip;
    QString port;
    QString videoPath;
    QString imgPath;
    int size;
};

#endif // GETSETINF_H
