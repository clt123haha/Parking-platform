#include "videothread.h"

videothread::videothread(char*filename)
{
    this->stop = false;
    this->isrun =false;
    this->currentFramecount=0;
    this->videoWriterFrame=0;
    waitTime = 40;
    if(cap.open(filename));//创建视频对象
    {
        this->allFramecount=cap.get(CAP_PROP_FRAME_COUNT);//获取视频文件中的总帧数
        this->fps=int(round(cap.get(CAP_PROP_FPS)));//获取视频帧率
    }
}

void videothread::run()
{
    if(!isVideoFile)
    {
        while(!stop)//线程运行和停止  卡住线程 暂停时不退出线程
        {
            while(isrun)//视频运行和暂停
            {
                if(cap.read(frame))//捕获视频帧
                {
                    this->currentFramecount++;
                    cvtColor(frame, frame, CV_BGR2RGB);//opencvBGR格式转成Image用到的RGB
                    emit sendFrame(currentFramecount,frame);//发送帧数据
                }
                msleep(waitTime);//延时
            }
        }
    }
    else
    {
        while(cap.read(frame))//捕获视频帧
        {
            this->currentFramecount++;
            cvtColor(frame, frame, CV_BGR2RGB);//opencvBGR格式转成Image用到的RGB
            emit sendFrame(currentFramecount,frame);//发送帧数据
            msleep(waitTime);//延时
        }
        emit videoEnd();
    }

    cap.release();//释放打开的视频
}

int videothread::getVideoAllFramecount()
{
    return allFramecount;
}


void videothread::setStop(bool value)
{
    stop = value;
}

void videothread::setCurrentFrame(int value)
{
    this->currentFramecount=value;//当前帧数
    cap.set(CV_CAP_PROP_POS_FRAMES,currentFramecount);//进度条跳转对应帧
}

bool videothread::getIsrun() const
{
    return isrun;
}

void videothread::setIsrun(bool value)
{
    isrun = value;
}

void videothread::pauseThread()//这两个函数用于确保是在运行情况下才能切换状态
{
    if(this->isRunning()&&this->isrun==true)//当前线程运行且视频运行
    {
        this->isrun=false;
    }
}

void videothread::resumeThread()
{
    if(this->isRunning()&&this->isrun==false)//当前线程运行且视频暂停
    {
        this->isrun=true;
    }
}

void videothread::stopThread()
{
    if(this->isRunning())//当前线程运行
    {
       this->stop=true;//结束线程
       //msleep(10);

        this->terminate();
    }
}

void videothread::setIsVideoFile(bool value)
{
    isVideoFile = value;
}

void videothread::setWaitTime(int value)
{
    waitTime = value;
}


int videothread::getFps() const
{
    return fps;
}


bool videothread::getStop() const
{
    return stop;
}