#ifndef VERIFY_H
#define VERIFY_H

#include <QFrame>
#include <QString>
#include <QPaintEvent>
#include <QMouseEvent>

class verify : public QFrame
{
    Q_OBJECT
public:
    verify(QWidget * parent = nullptr);
    void generateRandNum();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    QString code;
};

#endif // VERIFY_H
