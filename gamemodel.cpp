#include "gamemodel.h"

#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <Windows.h>
using namespace std;
int a, b, a1, b1, a2, b2;
char ch;

bool GameModel::winorlose(int x, int y){
    char t;
    if(playerflag) t='B';
    else t='W';
    int count;
    count = 1;                         //竖直方向
    for (int i = x, j = y + 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && j <= y + 5; j++) {
        if (map[i][j] == t) count++;
        else break;
    }
    for (int i = x, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && j >= y - 5; j--) {
        if (map[i][j] == t) count++;
        else break;
    }
    if (count >= 6) return true;
    count = 1;                    //水平方向
    for (int i = x + 1, j = y; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i <= x + 5; i++) {
        if (map[i][j] == t) count++;
        else break;
    }
    for (int i = x - 1, j = y; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i >= x - 5; i--) {
        if (map[i][j] == t) count++;
        else break;
    }
    if (count >= 6) return true;
    count = 1;          //从左下斜向右上
    for (int i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i <= x + 5 && j <= y + 5; i++, j++) {
        if (map[i][j] == t) count++;
        else break;
    }
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i >= x - 5 && j >= y - 5; i--, j--) {
        if (map[i][j] == t) count++;
        else break;
    }
    if (count >= 6) return true;
    count = 1;    //左上斜向右下
    for (int i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i >= x - 5 && j <= y + 5; i--, j++) {
        if (map[i][j] == t) count++;
        else break;
    }
    for (int i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i <= x + 5 && j >= y - 5; i++, j--) {
        if (map[i][j] == t) count++;
        else break;
    }
    if (count >= 6) return true;
    return false;
}

bool GameModel::legal(int x, int y){
    if (x >=chessboard_size || x < 0 || y>=chessboard_size || y < 0 || map[x][y] != '*')
        return false;
    else return true;
}

bool GameModel::huiqi(int x, int y){
    if (x == -1 && y == 20)
        return true;
    else return false;
}

bool GameModel::heqi(){
    for (int i = 0; i < chessboard_size; i++) {
        for (int j = 0; j < chessboard_size; j++) {
            if (map[i][j] == '*') return false;
        }
    }
    return true;
}

bool GameModel::jinshou(int x, int y){
    char t,s;
    if(playerflag) {t='B';s='W';}
    else {t='W';s='B';}
    int num4 = 0, num5 = 0, i, j;
        int count;
        char temp1, temp2;
        count = 1;          //竖直方向判断禁手
        for (i = x, j = y + 1; i >= 0 && j >= 0 && i <chessboard_size && j < chessboard_size && j <= y + 4; j++) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp1 = map[i][j];
        for (i = x, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && j >= y - 4; j--) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp2 = map[i][j];
        if (count == 4) {
            num4++;
            if (temp1 == s && temp2 == s) num4--;
        }
        if (count == 5) {
            num5++;
            if (temp1 == s && temp2 == s) num5--;
        }
        count = 1;          //水平方向判断禁手
        for (i = x + 1, j = y; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i <= x + 4; i++) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp1 = map[i][j];
        for (i = x - 1, j = y; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i >= x - 4; i--) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp2 = map[i][j];
        if (count == 4) {
            num4++;
            if (temp1 == s && temp2 == s) num4--;
        }
        if (count == 5) {
            num5++;
            if (temp1 == s && temp2 == s) num5--;
        }
        count = 1;    //从左下斜向右上
        for (i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < chessboard_size&& j < chessboard_size && i <= x + 4 && j <= y + 4; i++, j++) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp1 = map[i][j];
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size&& i >= x - 4 && j >= y - 4; i--, j--) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp2 = map[i][j];
        if (count == 4) {
            num4++;
            if (temp1 == s && temp2 == s) num4--;
        }
        if (count == 5) {
            num5++;
            if (temp1 == s && temp2 == s) num5--;
        }
        count = 1;    //左上斜向右下
        for (i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i >= x - 4 && j <= y + 4; i--, j++) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp1 = map[i][j];
        for (i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < chessboard_size && j < chessboard_size && i <= x + 4 && j >= y - 4; i++, j--) {
            if (map[i][j] == t) count++;
            else break;
        }
        temp2 = map[i][j];
        if (count == 4) {
            num4++;
            if (temp1 == s && temp2 == s) num4--;
        }
        if (count == 5) {
            num5++;
            if (temp1 == s && temp2 == s) num5--;
        }
        if (num4 >= 2) return true;
        else if (num5 >= 2) return true;
        else return false;
}

void GameModel::initializemap(){
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            map[i][j] = '*';
}

void GameModel::gamestart(){
    cout << "开始游玩" << endl;
    cout << "请选择游戏模式" << endl;
    cout << "1.人人对战" << endl;
    cout << "2.人机对战" << endl;
    cout << "3.机机对战" << endl;
    cout << "4.Quit" << endl;
}

void GameModel::playchess(int x, int y){
    if (playerflag) map[x][y] = 'B';
    else map[x][y] = 'W';
}

void GameModel::AIgetscore(char ch){
    int oppnum = 0, AInum = 0,blanknum= 0;
        char dh;
        if (ch == 'B') dh = 'W';
        else if (ch == 'W') dh = 'B';
        for (int i = 0; i < chessboard_size; i++)             //对AI得分地图初始化
            for (int j = 0; j <chessboard_size; j++)
                scoremap[i][j] = 0;
        for (int i = 0; i < chessboard_size; i++) {       //计算得分
            for (int j = 0; j < chessboard_size; j++) {
                if (i >= 0 && j >= 0 && i <chessboard_size && j <chessboard_size&& map[i][j] == '*') {  //保证此处可以下棋
                    for(int k=-1;k<=1;k++)
                        for (int z = -1; z <= 1; z++) {   //寻遍周围八个方向的棋子
                            oppnum = 0; AInum = 0; blanknum = 0;  //先将每个方向的各种棋子数量记为零
                            if (!(k == 0 && z == 0)) {  //k z为0时不为八个方向之一
                             //根据对手落子情况评定分数:
                                for (int s = 1; s <= 5; s++) {   //此方向查询五颗棋子
                                    if (i + k * s >= 0 && i + k * s <chessboard_size &&    //查询此方向满足条件的敌方棋子个数
                                        j + z * s >= 0 && j + z * s <chessboard_size &&
                                        map[i + k * s][j + z * s] == ch) oppnum++;   //计算此方向满足条件的敌方棋子个数
                                    else if (i + k * s >= 0 && i + k * s <chessboard_size &&  //查询此方向满足条件的暂无棋子位置
                                        j + z * s >= 0 && j + z * s <chessboard_size &&
                                        map[i + k * s][j + z * s] == '*') {
                                        blanknum++;  //此方向无棋子位置加一
                                        break;   //跳出循环
                                    }
                                    else break;   //检测到自己的棋子或者达到边界则退出循环
                                }
                                for (int s = 1; s <= 5; s++) {   //此方向的反方向查询五颗棋子
                                    if (i - k * s >= 0 && i - k * s <chessboard_size &&    //查询此方向反方向满足条件的敌方棋子个数
                                        j - z * s >= 0 && j - z * s <chessboard_size &&
                                        map[i - k * s][j - z * s] == ch) oppnum++;   //计算此方向反方向满足条件的敌方棋子个数
                                    else if (i - k * s >= 0 && i - k * s <chessboard_size &&  //查询此方向反方向满足条件的暂无棋子位置
                                        j - z * s >= 0 && j - z * s <chessboard_size &&
                                        map[i - k * s][j - z * s] == '*') {
                                        blanknum++;  //此方向反方向无棋子位置加一
                                        break;   //跳出循环
                                    }
                                    else break;   //检测到自己的棋子或者到达边界则退出循环
                                }
                                if (oppnum == 1) scoremap[i][j] += 10;   //抵挡敌方棋子一颗时分数+10
                                else if (oppnum == 2) {
                                    if (blanknum == 1) scoremap[i][j] += 20;  //抵挡敌方眠2时分数+20
                                    else scoremap[i][j] += 25;        //抵挡敌方活2时分数+25
                                }
                                else if (oppnum == 3) {
                                    if (blanknum == 1) scoremap[i][j] += 30;
                                    else scoremap[i][j] += 35;
                                }
                                else if (oppnum == 4) {
                                    if (blanknum == 1) scoremap[i][j] += 40;
                                    else scoremap[i][j] += 45;
                                }
                                else if (oppnum == 5) scoremap[i][j] += 100;
                                blanknum = 0;
                            //根据自己落子情况评定分数：
                                for (int s = 1; s <= 5; s++) {   //此方向查询五颗棋子
                                    if (i + k * s >= 0 && i + k * s <chessboard_size &&    //查询此方向满足条件的我方棋子个数
                                        j + z * s >= 0 && j + z * s <chessboard_size &&
                                        map[i + k * s][j + z * s] == dh) AInum++;   //计算此方向满足条件的我方棋子个数
                                    else if (i + k * s >= 0 && i + k * s <chessboard_size &&  //查询此方向满足条件的暂无棋子位置
                                        j + z * s >= 0 && j + z * s <chessboard_size &&
                                        map[i + k * s][j + z * s] == '*') {
                                        blanknum++;  //此方向无棋子位置加一
                                        break;   //跳出循环
                                    }
                                    else break;   //检测到敌方的棋子或者达到边界则退出循环
                                }
                                for (int s = 1; s <= 5; s++) {   //此方向的反方向查询五颗棋子
                                    if (i - k * s >= 0 && i - k * s <chessboard_size &&    //查询此方向反方向满足条件的我方棋子个数
                                        j - z * s >= 0 && j - z * s <chessboard_size &&
                                        map[i - k * s][j - z * s] == dh) AInum++;   //计算此方向反方向满足条件的我方棋子个数
                                    else if (i - k * s >= 0 && i - k * s <chessboard_size &&  //查询此方向反方向满足条件的暂无棋子位置
                                        j - z * s >= 0 && j - z * s <chessboard_size &&
                                        map[i - k * s][j - z * s] == '*') {
                                        blanknum++;  //此方向反方向无棋子位置加一
                                        break;   //跳出循环
                                    }
                                    else break;   //检测到敌方的棋子或者到达边界则退出循环
                                }
                                if (AInum == 1) scoremap[i][j] += 10;   //抵挡敌方棋子一颗时分数+10
                                else if (AInum == 2) {
                                    if (blanknum == 1) scoremap[i][j] += 20;  //抵挡敌方眠2时分数+20
                                    else scoremap[i][j] += 25;        //抵挡敌方活2时分数+25
                                }
                                else if (AInum == 3) {
                                    if (blanknum == 1) scoremap[i][j] += 30;
                                    else scoremap[i][j] += 35;
                                }
                                else if (AInum == 4) {
                                    if (blanknum == 1) scoremap[i][j] += 40;
                                    else scoremap[i][j] += 45;
                                }
                                else if (AInum >= 5) scoremap[i][j] += 100;
                                blanknum = 0;
                            }
                        }
                }
            }
        }
}

void GameModel::AIplayyou(){
    AIgetscore(ch);
    char dh;
    if (ch == 'B') dh = 'W';
    else dh = 'B';
    int maxscore = 0;
    for (int i = 0; i <chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
    int num = 0;             //最大值个数
    int p[400], q[400];            //存放可放最大值位置的数组
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] == maxscore) {
                if (!jinshou(i, j)) {
                    p[num] = i;
                    q[num] = j;
                    num++;
                }
            }
    int n;
    srand((unsigned)time(0));
    n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
    if (ch == 'B') map[p[n]][q[n]] = 'W';
    else map[p[n]][q[n]] = 'B';
    a2 = p[n];
    b2 = q[n];
    a = p[n];
    b = q[n];
    Sleep(2000);
}

void GameModel::AIplaywu(){
    AIgetscore(ch);
    int maxscore = 0;
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
    int num = 0;             //最大值个数
    int p[400], q[400];            //存放最大值位置的数组
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] == maxscore) {
                p[num] = i;
                q[num] = j;
                num++;
            }
    int n;
    srand((unsigned)time(0));
    n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
    if (ch == 'B') map[p[n]][q[n]] = 'W';
    else map[p[n]][q[n]] = 'B';
    a2 = p[n];
    b2 = q[n];
    a = p[n];
    b = q[n];
    Sleep(2000);
}

void GameModel::AI1play(){
    AIgetscore(ch);
    char dh;
    if (ch == 'B') dh = 'W';
    else dh = 'B';
    int maxscore = 0;
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
    int num = 0;             //最大值个数
    int p[400], q[400];            //存放可放最大值位置的数组
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            if (scoremap[i][j] == maxscore) {
                if (!jinshou(i, j)) {
                    p[num] = i;
                    q[num] = j;
                    num++;
                }
            }
    int n;
    srand((unsigned)time(0));
    n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
    if (ch == 'B') map[p[n]][q[n]] = 'W';
    else map[p[n]][q[n]] = 'B';
    a = p[n];
    b = q[n];
    Sleep(2000);
}

void GameModel::AI2play(){
    AIgetscore(ch);
    int maxscore = 0;
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
    int num = 0;             //最大值个数
    int p[400], q[400];            //存放最大值位置的数组
    for (int i = 0; i < chessboard_size; i++)
        for (int j = 0; j < chessboard_size; j++)
            if (scoremap[i][j] == maxscore) {
                p[num] = i;
                q[num] = j;
                num++;
            }
    int n;
    srand((unsigned)time(0));
    n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
    if (ch == 'B') map[p[n]][q[n]] = 'W';
    else map[p[n]][q[n]] = 'B';
    a = p[n];
    b = q[n];
    Sleep(2000);
}


void GameModel::startGame(GameType type){
    gameType=type;
    map.clear();
    //初始化棋盘
    for(int i=0;i<chessboard_size;i++){
        std::vector<char> lineBoard;
        for(int j=0;j<chessboard_size;j++)
            lineBoard.push_back('*');
        map.push_back(lineBoard);
    }
    //如果是AI模式，初始化分数图
    if(gameType==gamemodetwo){
        scoremap.clear();
        for(int i=0;i<chessboard_size;i++){
            std::vector<int> lineScores;
            for(int j=0;j<chessboard_size;j++)
                lineScores.push_back(0);
            scoremap.push_back(lineScores);
        }
    }
    //黑方下棋为true，白方下棋为false
    playerflag=true;
}


void GameModel::actionByPerson(int row, int col){
    updatemap(row,col);

}


void GameModel::updatemap(int row,int col){
    if(playerflag) map[row][col]='B';
    else map[row][col]='W';
    //换手
    playerflag=!playerflag;
}
