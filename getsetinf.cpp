#include "getsetinf.h"

static getSetinf * myseting = nullptr;

getSetinf *getSetinf::getmyseting()
{
    if(myseting == nullptr)
    {
        myseting = new getSetinf();
    }
    return myseting;
}

getSetinf::getSetinf()
{

}

int getSetinf::getSize() const
{
    fstream f;
    //文件读取，把原来的ios::out改成ios::in
    f.open("setting.txt",ios::in);

    string name;
    int number;
    //分别读取储存入变量中，一直读到文件结束
    while(f>>name>>number)
    cout<<name<<" "<<number<<endl; //显示读取内容
    f.close();
    return 0;
    return size;
}

QString getSetinf::getImgPath() const
{
    return imgPath;
}

QString getSetinf::getVideoPath() const
{
    return videoPath;
}

QString getSetinf::getPort() const
{
    return port;
}

QString getSetinf::getIp() const
{
    return ip;
}
