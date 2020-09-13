#ifndef GAMEMODEL_H
#define GAMEMODEL_H


//----六子棋游戏模型类----//
#include <vector>

//游戏类型，人人，人机，机机
enum GameType{
    gamemodeone,  //人人
    gamemodetwo,  //人机
    gamemodethree  //机机
};
//游戏状态
enum GameStatus{
    PLAYING,
    WIN,
    DEAD,
    HEQI
};

const int chessboard_size =22;   //棋盘尺寸
const int space=40;   //棋盘边缘的空隙大小
const int chess_r=15;   //棋子半径
const int mark_size=7;   //落子标记边长
const int cell_size=40;   //格子大小
const int fuzzy_d=cell_size*0.3;   //鼠标点击的模糊距离上限
const int AI_think_time=1000;   //AI下棋的思考时间

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
    bool legal(int x,int y);          //判断合法性
    bool huiqi(int x,int y);          //判断是否悔棋，输入-1和20时悔棋
    bool heqi();                      //判断是否和棋
    bool jinshou(int x,int y);        //判断是否禁手
    void initializemap();             //地图初始化
    void gamestart();                 //进入游戏的界面
    void playchess(int x, int y);     //玩家落子，B为黑棋，W为白棋
    void AIgetscore(char ch);         //AI得分图
    void AIplayyou();                 //AI下棋（有禁手规则）
    void AIplaywu();                  //AI下棋（无禁手规则）
    void AI1play();                   //AI1下棋（有禁手规则）
    void AI2play();                   //AI2下棋（无禁手规则）


    void startGame(GameType type);
    void actionByPerson(int row,int col);
    void updatemap(int row,int col);


};


#endif // GAMEMODEL_H
