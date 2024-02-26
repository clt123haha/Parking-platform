#include "mainwindow.h"
#include <QApplication>
#include <QRegularExpression>
#include "openvideo.h"
#include "mainwindow.h"
#include "page5.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    openVideo w;
    w.show();
    w.play();
    /*MainWindow w;
    w.show();*/

    /*Page3 w;
    CameraThread2::getCameraThread2()->openCamera();
    CameraThread2::getCameraThread2()->start();
    w.show();*/


    return a.exec();
}
