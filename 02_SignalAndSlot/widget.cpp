#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>



//需求：
//Teacher类 老师类
//Student类 学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师的对象
    this->tc = new Teacher(this);

    //创建一个学生的对象
    this->st = new Student(this);

//    //老师饿了，学生请客的连接
//    connect(tc,&Teacher::hungry,st,&Student::treat);//要连接好了之后，才能触发下课的信号

//    //调用下课函数
//    classIsOver();


    //连接带参数的信号和槽：
    //指针->地址
    //函数指针->函数地址

    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;

    connect(tc,teacherSignal,st,studentSlot);
    classIsOver();


    //点击下课的按钮然后触发下课
    QPushButton * btn = new QPushButton("下课", this);
    //重置窗口大小：
    this->resize(600,400);
    //点击按钮，触发下课：
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);



    //无参信号和槽连接
    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void(Student::*studentSlot2)(void) = &Student::treat;
    connect(tc,teacherSignal2,st,studentSlot2);

    //信号连接信号：
    connect(btn,&QPushButton::clicked,tc,teacherSignal2);

    //断开信号
    disconnect(tc,teacherSignal2,st,studentSlot2);

}

void Widget::classIsOver(){
    //下课函数，调用后，触发老师饿了的信号
    emit tc->hungry();
    emit tc->hungry("汉堡炸鸡");
}

Widget::~Widget()
{
    delete ui;
}

