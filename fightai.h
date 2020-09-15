#ifndef FIGHTAI_H
#define FIGHTAI_H

#include <QWidget>
#include <QPushButton>
#include <gamemodel.h>

class fightAI : public QWidget
{
    Q_OBJECT
public:
    explicit fightAI(QWidget *parent = nullptr);
    void sendsalottwo();
    GameModel *game;          //游戏指针
    GameType game_type;       //游戏存储类型

     int clickPosRow,clickPosCol;           //存储将点击的位置
     bool selectPos=false;                  //是否移动到合适的位置，来选中某个交叉点
     void initGame();
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void chessoneByPerson();
     void AIplaywu();
signals:
    void mysignal();
public slots:
    void paintEvent(QPaintEvent *event);     //绘制
private:
    QPushButton b2;
};

#endif // FIGHTAI_H
