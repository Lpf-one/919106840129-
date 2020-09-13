#include "chessbyperson.h"
#include"gamemodel.h"
#include <mainwindow.h>
//画图所需头文件
#include"QPainter"
#include"QMouseEvent"
#include<math.h>
#include<QMessageBox>

chessByPerson::chessByPerson(QWidget *parent):QMainWindow(parent)
{
    this->setWindowTitle("hello");
    setFixedSize(space*2+cell_size*chessboard_size,
                 space*2+cell_size*chessboard_size);
    goback.setParent(this);
    goback.setText("rad");
    goback.move(300,size().height()-cell_size);
    initGame();
    goback.move(300,size().height()-cell_size);
    huiqizi.setParent(this);
    huiqizi.setText("悔棋!");
    huiqizi.move(600,size().height()-cell_size);

};

void chessByPerson::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    setMouseTracking(true);
    //绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing,true);  //抗锯齿
    for(int i=0;i<=chessboard_size;i++){
        painter.drawLine(space+cell_size*i,space,
                         space+cell_size*i,size().height()-space);    //从左到右
        painter.drawLine(space,space+cell_size*i,
                         size().width()-space,space+cell_size*i);     //从上到下
    }

    //绘制选中点
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);  //定义刷子模式
    //绘制落子标记（防止鼠标出框越界）
    if(clickPosRow>0&&clickPosRow<chessboard_size&&
            clickPosCol>0&&clickPosCol<chessboard_size&&
            game->map[clickPosRow][clickPosCol]=='*')
    {
        if(game->playerflag) brush.setColor(Qt::black);
        else brush.setColor(Qt::white);
        painter.setBrush(brush);
        painter.drawRect(space+cell_size*clickPosCol-mark_size/2,space+cell_size*clickPosRow-mark_size/2,mark_size,mark_size);

    }
    //绘制棋子
    for(int i=0;i<chessboard_size;i++)
        for(int j=0;j<chessboard_size;j++){
            if(game->map[i][j]=='B'){
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(space+cell_size*j-chess_r,space+cell_size*i-chess_r,chess_r*2,chess_r*2);
            }
            else if(game->map[i][j]=='W'){
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(space+cell_size*j-chess_r,space+cell_size*i-chess_r,chess_r*2,chess_r*2);
            }
        }
    if(game->legal(clickPosRow,clickPosCol)){
        if(game->winorlose(clickPosRow,clickPosCol)&&game->gameStatus==PLAYING){
            game->gameStatus=WIN;
            //sound
            QString str;
            if(game->map[clickPosRow][clickPosCol]=='B') str="黑棋";
            else if(game->map[clickPosRow][clickPosCol]=='W') str="白棋";
            QMessageBox::StandardButton btnValue = QMessageBox::information(this, "六子棋对战", str + "win!");
            if(btnValue==QMessageBox::Ok){
                game->startGame(game_type);
                game->gameStatus=PLAYING;
            }
        }
    }
    if(game->heqi()){
        QMessageBox::StandardButton btnValue=QMessageBox::information(this,"六子棋对战","和棋");
        if(btnValue==QMessageBox::Ok)
        {
            game->startGame(game_type);
            game->gameStatus=PLAYING;
        }
    }
}

void chessByPerson::initGame()
{
    game=new GameModel;
    game_type=gamemodeone;
    game->gameStatus=PLAYING;
    game->startGame(game_type);
}

void chessByPerson::mouseMoveEvent(QMouseEvent *event){
    int x=event->x();
    int y=event->y();
    //棋盘的边缘不能落子
    if(x>=space+cell_size/2&&
            x<size().width()-space-cell_size/2&&
            y>=space+cell_size/2&&
            y<size().height()-space-cell_size/2)
    {
        //获取最近的左上角的点
        int col=(x-space)/cell_size;
        int row=(y-space)/cell_size;
        //int col=x/kBlocksize;
        //int row=y/kBlocksize;
        int leftTopPosx=space+cell_size*col;
        int leftTopPosy=space+cell_size*row;
        //根据距离计算合适的电击位置，一共四个点，根据半径距离选最近的
        clickPosRow=-1;    //初始化最终的值
        clickPosCol=-1;
        int len=0;    //计算后取整
        selectPos=false;
        //确定一个误差在范围内的点，且只能确定一个
        len=sqrt((x-leftTopPosx)*(x-leftTopPosx)+(y-leftTopPosy)*(y-leftTopPosy));
        if(len<fuzzy_d){
            clickPosCol=col;
            clickPosRow=row;
            if(game->map[clickPosRow][clickPosCol]=='*'){selectPos=true;}
        }
        len=sqrt((x-leftTopPosx-cell_size)*(x-leftTopPosx-cell_size)+(y-leftTopPosy)*(y-leftTopPosy));
        if(len<fuzzy_d){
            clickPosCol=col+1;
            clickPosRow=row;
            if(game->map[clickPosRow][clickPosCol]=='*'){selectPos=true;}
        }
        len=sqrt((x-leftTopPosx)*(x-leftTopPosx)+(y-leftTopPosy-cell_size)*(y-leftTopPosy-cell_size));
        if(len<fuzzy_d){
            clickPosCol=col;
            clickPosRow=row+1;
            if(game->map[clickPosRow][clickPosCol]=='*'){selectPos=true;}
        }
        len=sqrt((x-leftTopPosx-cell_size)*(x-leftTopPosx-cell_size)+(y-leftTopPosy-cell_size)*(y-leftTopPosy-cell_size));
        if(len<fuzzy_d){
            clickPosCol=col+1;
            clickPosRow=row+1;
            if(game->map[clickPosRow][clickPosCol]=='*'){selectPos=true;}
        }
    }
     //有了坐标后也要重绘
    update();
}

void chessByPerson::mouseReleaseEvent(QMouseEvent *event){
    if(selectPos==false){return;}
    //落子前将落子标记设为false
    else {selectPos=false;}
    chessByPerson();
}

void chessByPerson::actionByPerson(int clickPosRow, int clickPosCol){
    //根据当前存储的坐标下子，且此处没有子有效点击才下子
    if(clickPosRow!=-1&&clickPosCol!=-1&&game->map[clickPosRow][clickPosCol]=='*'){
        //在游戏的数据模型中落子
        updatemap(clickPosRow,clickPosCol);
        //播放落子音效
        //重绘
        update();
    }
}


void chessByPerson::updatemap(int row,int col){
    if(game->playerflag) game->map[row][col]='B';
    else game->map[row][col]='W';
    //换手
    game->playerflag=!game->playerflag;
}

void chessByPerson::sendslot(){
    emit mysignal();
}

