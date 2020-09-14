#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

#include <QPainter>
#include <QMouseEvent>
#include <math.h>
#include <QMessageBox>
#include <Qstring>
#include <chessbyperson.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //创建按钮
    btn1=new QPushButton(this);
    btn1->setText(" 人人对战");
    btn1->move(100,50);
    btn2=new QPushButton(this);
    btn2->setText("人机对战");
    btn2->move(100,100);
    btn3=new QPushButton(this);
    btn3->setText("机机对战");
    btn3->move(100,150);
    //重置窗口大小
    resize(600,500);
    //连接信号和槽
    connect(btn1,&QPushButton::pressed,this,&MainWindow::close);




    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}






