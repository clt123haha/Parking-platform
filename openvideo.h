#ifndef OPENVIDEO_H
#define OPENVIDEO_H

#include "videothread.h"
#include "getsetting.h"
#include "setingwiget.h"
#include "loginview.h"
#include "conneet.h"
#include "readthread.h"
#include "writethread.h"

#include <QWidget>

namespace Ui {
class openVideo;
}

class openVideo : public QWidget
{
    Q_OBJECT

public:
    explicit openVideo(QWidget *parent = nullptr);
    ~openVideo();
    void paintEvent(QPaintEvent *e);
    void play();

public slots:
    void receiveFrame(int currentFrame,Mat frame);
    void endVideo();
    void setOver();

private:
    Ui::openVideo *ui;
    videothread *pthread;
    QImage img1;
    SetingWiget *setView;
    LoginView * loginView;
};

#endif // OPENVIDEO_H
