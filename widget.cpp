#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //主窗口
    setWindowTitle("鹏飞六子棋");
    setFixedSize(space*2+cell_size*(chessboard_size-1),
                 space*2+cell_size*(chessboard_size-1));
    //按钮的实现
    btn1=new QPushButton(this);
    btn1->setText("player1 battle player2");
    btn1->move(100,100);
    btn2=new QPushButton(this);
    btn2->setText("player battle AI");
    btn2->move(100,200);
    btn3=new QPushButton(this);
    btn3->setText("AI1 battle AI2");
    btn3->move(100,300);
    btn4=new QPushButton(this);
    btn4->setText("close");
    btn4->move(100,400);

    resize(1200,600);

    //按钮信号的连接
    connect(btn1,&QPushButton::released,this,&Widget::changeone);
    connect(&w1,&chessByPerson::mysignal,this,&Widget::dealchessByPerson);
    connect(btn2,&QPushButton::released,this,&Widget::changetwo);
    connect(&w2,&fightAI::mysignal,this,&Widget::dealfightAI);
    connect(btn3,&QPushButton::released,this,&Widget::changethree);
    connect(&w3,&AIfight::mysignal,this,&Widget::dealAIfight);
    connect(btn4,&QPushButton::pressed,this,&Widget::close);


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

void Widget::paintEvent(QPaintEvent *){
    QPainter p;  //创建画家对象
    p.begin(this);   //指定当前窗口为绘图设备
    p.drawPixmap(0,0,width(),height(),QPixmap("/QT/pfconnectsix/zhuchuangkou"));
    p.end();
}

Widget::~Widget()
{
    delete ui;
}
