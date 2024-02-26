#ifndef CONNEET_H
#define CONNEET_H
#include <QObject>
#include <QThread>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <QDebug>
#include <sys/epoll.h>
#include <QMetaType>


typedef struct head
{
    int bussinessType;
    int bussinessLength;
    char cheakCoke[8];
}HEAD;
typedef struct userExit
{
        char account[10];//退出用户的账号
}USEREXIT;

typedef struct login
{
    char account[10];
    char pwd[40];
}LOGIN;

typedef struct reg
{
    char account[10];
    char name[20];
    char pwd[40];
}REG;

typedef struct entrance
{
        char vehicle_number[10];//车牌号
        char entrance_entrance[30];//入场口
        char entrance_time[30];//入场时间
}ENTRANCE;

typedef struct exit
{
        int isvip;//是否是vip,1就是月卡，0就不是月卡
        char vehicle_number[10];//车牌号
        char exit_export[30];//出场口
        char exit_time[30];//出场时间
}EXIT;

typedef struct entranceRecord
{
    int entrance_id;//入场记录的id号
    char vehicle_number[10];//车牌号
    char entrance_time[30];//入场时间
    char entrance_entrance[30];//入场口
}ENTRANCERECORD;

typedef struct entranceBack
{
    int flag;//业务结果
    int current_count;;//当前剩余车位量
    char message[20];//业务反馈内容
    ENTRANCERECORD record[4];
}ENTRANCEBACK;

typedef struct exitBack
{
    int flag;//业务结果
    int current_count;//当前剩余车位量
    long long parkingtime;//停车时长
    double parkingmoney;//停车金额
    char vehicle_number[10];//车牌号
    char message[20];//业务反馈内容
    char entrance_time[30];//入场时间
    char exit_time[30];//出场时间
}EXITBACK;


typedef struct rcv
{
    int flag;
    char msg[20];
}RCV;

typedef struct fileSend
{
int fileTotalByte;//原文件总字节数
int fileTotalCount;//原文件碎片文件总个数
int currentFileNum;//当前碎片文件序号
int currentFileByte;//当前碎片文件字节数

char account[20];//发送用户
char fileName[50];//文件名
char filePath[150];//文件路径

char content[1000]; //当前碎片文件内容
}FILESEND;


typedef struct fileSendOverBack
{
    int flag;//碎片文件拼接的结果
    int fileType;//文件类型：1入场，2出场，3停车场内部图片，4视频封面图片
    char message[20];//业务反馈内容
    char account[20];//发送用户
    char findFieldName[50];//查找字段名称
    char fileName[50];//文件名
    char filePath[150];//文件路径
}FILESENDOVERBACK;

typedef struct fileSendOver
{
    int fileType;//文件类型：1入场，2出场，3停车场内部图片，4视频封面图片//决定了插入到哪个表
    int fileTotalByte;//原文件总字节数
    int fileTotalCount;//原文件碎片文件总个数
    char account[20];//发送用户

    char findFieldName[50];//查找的字段名称
    //出入场根据车牌号查询（闽Axxxxx）；视频封面图片根据视频名称videoxxxx-xx-xx-xx:xx:xx.avi);
    //停车场内部图片根据图片名称(imagexxxx-xx-xx-xx:xx:xx.png/jpg)
    //决定了插入到表中的哪行数据

    char fileName[50];//文件名
    char filePath[150];//文件路径
}FILESENDOVER;

typedef struct curVehicleInfo
{
    bool flag;//随意给一个标识符
}CURVEHICLEINFO;

typedef struct curVehicleInfoBack
{
    int vehicleCount;//当前车场在场车辆数量;
}CURVEHICLEINFOBACK;


typedef struct video
{
    long video_frame_count;//视频总帧数
    char account[10];//上传视频的账号，也就是当前登录用户账号
    char video_record_date[30];//视频记录时间,yyyy-mm-dd-hh-mm-ss
    char video_name[50];//视频名称,video2023-12-11-21:18:00.avi
    char video_path[150];//客户端的视频存储路径，路径是./xxx/xxx/
}VIDEO;

typedef struct dateInfo
{
    int flag; //1表示按月搜索 2表示按日搜索
    char account[10];//账号
}DATEINFO;

typedef struct myDate
{
    char date[11];//yyyy-mm或yyyy-mm-dd
}MYDATE;

//65--获取日期列表返回包//341
typedef struct dateInfoBack
{
    MYDATE dateList[31];
}DATEINFOBACK;

typedef struct videoInfo
{
    char video_name[30];//视频名称
    char video_cover[120];//视频封面图片路径
}VIDEOINFO;

typedef struct videoQuery
{
    int currentPage;//当前页
    char account[10];//当前登录用户账号
    char queryDate[20];//查询的日期要么按月要么按天，月:yyyy-mm;天：yyyy-mm-dd
}VIDEOQUERY;

typedef struct videoQueryBack
{
    VIDEOINFO videoinformation[9];//最多九条视频信息
}VIDEOQUERYBACK;

typedef struct videoPlay
{
    char account[10];//播放用户的账号
    char video_name[30];//视频名称，例如video2023-12-12-18:27:00.avi
}VIDEOPLAY;

typedef struct videoPlayOver
{
    int current_frame;//当前播放帧数
    char account[10];//播放用户账号，也就是当前登录用户
    char video_name[30];//视频名称，listItem的名称
    char play_time[30];//播放时间
}VIDEOPLAYOVER;

typedef struct videoPlayBack
{
    int current_frame;//视频的当前播放帧数，如果有查到播放记录则为表中的数据，如果查不到则为0
    int totalFrame;//视频总帧数
    char videoPlayPath[100];//视频完整播放路径
}VIDEOPLAYBACK;

typedef struct vehicleInfoQuery
{
    int currentPage;//当前页
    char vehicle_number[10];//车牌号
    char entrance_time[30];//入场日期
    char exit_time[30];//出场日期
}VEHICLEINFOQUERY;

typedef struct vehicleInfo
{
    int id;//序号
    double exit_money;//停车金额
    char vehicle_number[10];//车牌号
    char entrance_time[30];//入场时间
    char exit_time[30];//出场时间
    char entrance_path[100];//入场图片路径
    char exit_path[100];//出场图片路径
}VEHICLEINFO;

typedef struct vehicleInfoQueryBack
{
    VEHICLEINFO vehicleRecord[5];
}VEHICLEINFOQUERYBACK;

typedef struct heart
{
    char account[10];//账号
}HEART;

typedef struct heartBack
{
    bool flag;//返回true
}HEARTBACK;

class conneet:public QObject
{
    Q_OBJECT
public:
    static conneet * getmyconneet();
    bool Conneet(QString ip,int port);
    int getFd() const;

signals:
    void loginrcv(int id,int ret);

private:
    static conneet * myconneet;
    struct sockaddr_in addr;
    conneet();
    int fd;
};


#endif // CONNEET_H
