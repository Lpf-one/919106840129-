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
    QPushButton *btn1=new QPushButton("人人对战",this);
    QPushButton *btn2=new QPushButton("人机对战",this);
    QPushButton *btn3=new QPushButton("机机对战",this);
    btn1->move(300,100);
    btn2->move(300,200);
    btn3->move(300,300);
    //重置窗口大小
    resize(600,500);
    chessByPerson *p;
    p=new chessByPerson;






    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}






