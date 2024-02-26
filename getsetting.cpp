#include "getsetting.h"

#include <QMessageBox>

getSetting * getSetting::myseting = nullptr;

getSetting *getSetting::getmyseting()
{
    if(myseting == nullptr)
    {
        myseting = new getSetting();
    }
    return myseting;
}

getSetting::getSetting():QObject(nullptr)
{

}

int getSetting::getSize() const
{
    return size;
}

bool getSetting::isempty()
{
    fstream f;
    f.open("setting.txt", ios::in);
    if (!f.is_open())
        return true;
    if(f.eof())
        return true;
    else
        return false;
}

QString getSetting::getImgPath() const
{
    return imgPath;
}

void getSetting::readSet()
{
    std::ifstream f;
       f.open("setting.txt", std::ios::in);
       std::string temp;
       if (f.is_open()) {
           if (getline(f, temp)) {
               ip = QString::fromStdString(temp);
           }
           if (getline(f, temp)) {
               port = std::stoi(temp);
           }
           if (getline(f, temp)) {
               imgPath = QString::fromStdString(temp);
           }
           if (getline(f, temp)) {
               videoPath = QString::fromStdString(temp);
           }
           if (getline(f, temp)) { // Assuming 'size' is also a string
               size = std::stoi(temp);
           }
       }
       f.close();

}

QString getSetting::getVideoPath() const
{
    return videoPath;
}

int getSetting::getPort() const
{
    return port;
}

QString getSetting::getIp() const
{
    return ip;
}
