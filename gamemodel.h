#ifndef GAMEMODEL_H
#define GAMEMODEL_H

//----六子棋游戏模型类----//
#include <vector>

//游戏类型，人人，人机，机机
enum GameType{
    gamemodeone,  // player1 battle player2
    gamemodetwo,  // player battle AI
    gamemodethree  //AI1 battle AI2
};
//游戏状态
enum GameStatus{
    PLAYING,
    WIN,
    HEQI
};

const int chessboard_size =22;   //棋盘尺寸
const int space=40;   //棋盘边缘的空隙大小
const int chess_r=16;   //棋子半径
const int mark_size=7;   //落子标记边长
const int cell_size=40;   //格子大小
const int fuzzy_d=cell_size*0.4;   //鼠标点击的模糊距离上限

class GameModel{
public:
    GameModel(){};
public:
    std::vector<std::vector<char>> map;    //游戏棋盘以及棋子情况，空白为*，黑子为B，白子为W
    std::vector<std::vector<int>> scoremap;    //各个点的评分情况，AI下棋的依据
    bool playerflag;    //true为黑棋方，false为白棋方
    GameType gameType;    //游戏模式：人人，人机，机机
    GameStatus gameStatus;    //游戏状态

    bool winorlose(int x,int y);      //判断输赢
    bool heqi();                      //判断是否和棋
    bool jinshou(int x,int y);        //判断是否禁手
    void AIgetscore(char ch);         //AI得分图
    void AIplaywu();                  //AI下棋
    void AI1play();                   //AI1下棋
    void AI2play();                   //AI2下棋

    void actionByPerson(int row, int col);
    void startGame(GameType type);
    void updatemap(int row,int col);


};


#endif // GAMEMODEL_H
