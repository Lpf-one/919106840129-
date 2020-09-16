#ifndef CHESSBYPERSON_H
#define CHESSBYPERSON_H

#include <QWidget>
#include <QPushButton>
#include <gamemodel.h>

class chessByPerson : public QWidget
{
    Q_OBJECT
public:
    explicit chessByPerson(QWidget *parent = nullptr);
    void sendsalotone();
    GameModel *game;          //游戏指针
    GameType game_type;       //游戏存储类型

     int clickPosRow,clickPosCol;           //存储将点击的位置
     bool selectPos=false;                  //是否移动到合适的位置，来选中某个交叉点
     void initGame();
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void chessonebyperson();
signals:
    void mysignal();
public slots:
        void paintEvent(QPaintEvent *event);     //绘制
private:
    QPushButton b1;
};

#endif // CHESSBYPERSON_H
