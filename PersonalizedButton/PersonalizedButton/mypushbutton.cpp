#include "mypushbutton.h"
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QMessageBox>

MyPushButton::MyPushButton(QWidget *p):QPushButton(p)
{
    QPixmap pixMap(":/radio1.png");
    this->setFixedSize(pixMap.size());
    setMask(QBitmap(pixMap.mask()));
    this->setStyleSheet("QPushButton{border-image:url(:/radio1.png);}");
}

void MyPushButton::enterEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton{border-image:url(:/radio2.png);}");
}

void MyPushButton::leaveEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton{border-image:url(:/radio1.png);}");
}

void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    this->setStyleSheet("QPushButton{border-image:url(:/radio3.png);}");
    QMessageBox::information(this, "title", "clicked");
}
