#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //主窗口
    setWindowTitle("鹏飞六子棋");
    //按钮的实现
    btn1=new QPushButton(this);
    btn1->setText("player1 battle player2");
    btn1->move(100,100);
    btn2=new QPushButton(this);
    btn2->setText("player battle AI");
    btn2->move(100,200);
    btn3=new QPushButton(this);
    btn3->setText("AI battle player");
    btn3->move(100,300);

    resize(600,500);

    //按钮信号的连接
    connect(btn1,&QPushButton::released,this,&Widget::changeone);
    connect(&w1,&chessByPerson::mysignal,this,&Widget::dealchessByPerson);
    connect(btn2,&QPushButton::released,this,&Widget::changetwo);
    connect(&w2,&fightAI::mysignal,this,&Widget::dealfightAI);
    connect(btn3,&QPushButton::released,this,&Widget::changethree);
    connect(&w3,&AIfight::mysignal,this,&Widget::dealAIfight);

}

void Widget::changeone(){
    w1.show();  //子窗口显示
    this->hide();  //子窗口隐藏
}
void Widget::dealchessByPerson(){
    w1.hide();  //子窗口隐藏
    show();    //子窗口显示
}

void Widget::changetwo(){
    w2.show();  //子窗口显示
    this->hide();  //子窗口隐藏
}
void Widget::dealfightAI(){
    w2.hide();  //子窗口隐藏
    show();    //子窗口显示
}
void Widget::changethree(){
    w3.show();  //子窗口显示
    this->hide();  //子窗口隐藏
}
void Widget::dealAIfight(){
    w3.hide();  //子窗口隐藏
    show();    //子窗口显示
}
Widget::~Widget()
{
    delete ui;
}
