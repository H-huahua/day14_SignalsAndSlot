#include "mypushbotton.h"
#include<QDebug>

myPushBotton::myPushBotton(QWidget *parent)
    : QPushButton{parent}
{
    qDebug()<<"我的按钮构造调用";

}
myPushBotton::~myPushBotton(){
    qDebug()<<"我的按钮类析构";
}
