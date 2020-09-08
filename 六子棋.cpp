#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[20][20];
int order;
                              //判断输赢
bool winorlose(int x, int y) {
	if (x <= 14 &&
		map[x][y] == map[x + 1][y] &&
		map[x][y] == map[x + 2][y] &&
		map[x][y] == map[x + 3][y] &&
		map[x][y] == map[x + 4][y] &&
		map[x][y] == map[x + 5][y])
		return true;               //从左到右横向判断
	if (x >= 5 &&
		map[x][y] == map[x - 1][y] &&
		map[x][y] == map[x - 2][y] &&
		map[x][y] == map[x - 3][y] &&
		map[x][y] == map[x - 4][y] &&
		map[x][y] == map[x - 5][y])
		return true;              //从右到左横向判断
	if (y <= 14 &&
		map[x][y] == map[x][y + 1] &&
		map[x][y] == map[x][y + 2] &&
		map[x][y] == map[x][y + 3] &&
		map[x][y] == map[x][y + 4] &&
		map[x][y] == map[x][y + 5])
		return true;              //从上到下纵向判断
	if (y >= 5 &&
		map[x][y] == map[x][y - 1] &&
		map[x][y] == map[x][y - 2] &&
		map[x][y] == map[x][y - 3] &&
		map[x][y] == map[x][y - 4] &&
		map[x][y] == map[x][y - 5])
		return true;              //从下到上纵向判断
	if (x >= 5 && y >= 5 &&
		map[x][y] == map[x - 1][y - 1] &&
		map[x][y] == map[x - 2][y - 2] &&
		map[x][y] == map[x - 3][y - 3] &&
		map[x][y] == map[x - 4][y - 4] &&
		map[x][y] == map[x - 5][y - 5] )
		return true;                   //右下到左上的判断
	if (x <= 14 && y <= 14 &&
		map[x][y] == map[x +1][y + 1] &&
		map[x][y] == map[x + 2][y +2] &&
		map[x][y] == map[x + 3][y + 3] &&
		map[x][y] == map[x + 4][y + 4] &&
		map[x][y] == map[x + 5][y + 5])
		return true;                   //左上到右下的判断
	if (x >= 5 && y <=14  &&
		map[x][y] == map[x - 1][y + 1] &&
		map[x][y] == map[x - 2][y + 2] &&
		map[x][y] == map[x - 3][y + 3] &&
		map[x][y] == map[x - 4][y + 4] &&
		map[x][y] == map[x - 5][y + 5])
		return true;                   //左下到右上的判断
	if (x <=14 && y >= 5 &&
		map[x][y] == map[x + 1][y - 1] &&
		map[x][y] == map[x + 2][y - 2] &&
		map[x][y] == map[x + 3][y - 3] &&
		map[x][y] == map[x + 4][y - 4] &&
		map[x][y] == map[x + 5][y - 5])
		return true;                   //左上到右下的判断
	return false;
} 
                          //判断合法性
bool legal(int x, int y) {
	if (x > 19 || x < 0 || y>19 || y < 0 || map[x][y] != '*')
		return false;
	else return true;
}
                   //判断是否悔棋， 输入-1和20时悔棋
bool huiqi(int x, int y) {
	if (x == -1 && y == 20)
		return true;
	else return false;
} 
                  //判断是否和棋
bool heqi(int x, int y) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
                   //进入游戏的界面
void gamestart() {
		cout << "开始游玩" << endl;
		cout << "请选择游戏模式" << endl;
		cout << "1.人人对战" << endl;
		cout << "2.Quit" << endl;
}
                   //打印棋盘
void printmap() {
	cout << "     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19" << endl;
	for (int i = 0; i < 20; i++) {
		if (i < 10) cout << "  " << i;
		else cout << " " << i;
		for (int j = 0; j < 20; j++)
			cout << "  " << map[i][j];
		cout << endl;
	}
}
int main() {
	for (int i = 0; i < 20; i++)                 //地图初始化
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
	gamestart();                                //进入游戏
	while (cin >> order) {
		if (order == 1) gamemodeone();
		if (order == 2) {
			cout << "感谢您的参与，请再接再厉提高竞技水平！" << endl;
				break;
		}

	}
}
