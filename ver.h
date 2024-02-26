#ifndef VER_H
#define VER_H

#include <QFrame>
#include <QLabel>
#include <QString>

namespace Ui {
class Ver;
}

class Ver : public QFrame
{
    Q_OBJECT

public:
    explicit Ver(QWidget *parent = nullptr);
    ~Ver();

    void generateRandomNumber(); //生成随机的数字和字母
    void paintEvent(QPaintEvent *); //画噪点和线
    void mousePressEvent(QMouseEvent *event); //鼠标点击事件


    QString code;



private:

};

#endif // VER_H

