#include "conneet.h"

conneet * conneet::myconneet = nullptr;

conneet *conneet::getmyconneet()
{
    if(myconneet == nullptr)
    {
        myconneet = new conneet();
    }
    return myconneet;
}

bool conneet::Conneet(QString ip,int port)
{
    fd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == fd)
    {
        return false;
    }

    addr.sin_addr.s_addr = inet_addr(ip.toLatin1().data());
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if(-1 == ::connect(fd,(struct sockaddr*)&addr,sizeof (addr)))
    {
        perror("连接失败");
        return false;
    }

    return true;
}




conneet::conneet():QObject()
{

}

int conneet::getFd() const
{
    return fd;
}
