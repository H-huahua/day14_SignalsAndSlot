#include "mywidget.h"
#include <QPushButton>
#include<mypushbotton.h>
#include<QDebug>

//命名规范
//类名 首字母大写，单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释 ctrl + /
//运行 ctrl + r
//编译 ctrl + b
//字体缩放 ctrl + 鼠标滚轮
//查找 ctrl + f
//整行移动 ctrl +shift+↑或者↓
//帮助文档 F1
//自动对齐 ctrl + i
//同名之间的.h和.cpp切换   F4

//帮助文档 第一种方式F1 第二种 左侧按钮 第三种 D:\Qt\qt\6.2.4\mingw_64\bin
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    //btn->show();//有了按钮，但是另外一个顶层窗口进行弹出。
    //但是需求是让btn对象依赖在M\myWeidget窗口之中，所以上述show方法不行，尝试setParent方法
    btn->setParent(this);//这个this就是指向myWidget对象的指针

    //显示文本
    btn->setText("华华创建的第一个按钮");


    //创建第二个按钮 按照空间大小创建窗口
    QPushButton * btn2 = new QPushButton("华华创建的第二个按钮", this);//有参构造
    //移动btn2按钮
    btn2->move(100,100);

    //重置窗口大小
    resize(600,400);

    //设置固定的窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("华华的第一个窗口");


    //创建一个自己的按钮的对象
    myPushBotton * myBtn = new myPushBotton;
    myBtn->setText("点击这个按钮，可关闭");
    myBtn->move(200,0);
    myBtn->setParent(this);//设置到对象树中


    //需求 点击我自己的按钮 可以关闭窗口
    //参数1，信号的发送者 参数2，点击的信号（函数的地址） 参数3， 信号的接收者，参数4，处理的槽函数。

    connect(myBtn, &myPushBotton::clicked, this, &myWidget::close);

}

myWidget::~myWidget()
{
    qDebug()<<"myWidget的析构调用";
}

