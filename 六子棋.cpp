#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[20][20];
int order;
int a,b,a1,b1,a2,b2;
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
bool legal(int x,int y) {
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
bool heqi() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
//地图初始化
void initializemap() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
}
//判断是否禁手
bool jinshou(int x, int y, char t, char s) {     //t为自己棋子，s为敌方棋子
	int num4 = 0, num5 = 0, i, j;
	int count;
	char temp1, temp2;
	count = 1;          //竖直方向判断禁手
	for (i = x, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j <= y + 4; j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j >= y - 4; j--) {
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
	for (i = x + 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4; i++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4; i--) {
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
	for (i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j <= y + 4; i++, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j >= y - 4; i--, j--) {
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
	for (i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j <= y + 4; i--, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j >= y - 4; i++, j--) {
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
//进入游戏的界面
void gamestart() {
	cout << "开始游玩" << endl;
	cout << "请选择游戏模式" << endl;
	cout << "1.人人对战" << endl;
	cout << "2.Quit" << endl;
}
//玩家落子，B为黑棋，W为白棋
void playchess(int x, int y, int player) {
	if (player == 1) map[x][y] = 'B';
	else map[x][y] = 'W';
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
void gamemodeone() {
	int count = 1;
	bool flag1 = true, flag2 = true;
	while (1) {
		cout << "第" << count++ << "回合：" << endl<< "玩家1请下棋:" << endl;
		cin >> a>> b;
		if (huiqi(a, b) && flag1 && (count > 2)) {
			flag1 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "玩家1悔棋成功，请重新输入：" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a1= a;
			b1 = b;
		} else {
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a1 = a;
			b1 = b;
		}
		playchess(a, b, 1);
		printmap();
		if (jinshou(a, b, 'B', 'W')) {
			cout << "玩家2胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		if (winorlose(a, b)) {
			cout << "玩家1胜利" << endl<<"Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		cout << "玩家2请下棋：" << endl;
		cin >> a >> b;
		if (huiqi(a, b)&&flag2&&(count>2)) {
			flag2 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "玩家2悔棋成功，请重新输入：" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a2 = a;
			b2 = b;
		} else {
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a2 =a;
			b2 = b;
		}
		playchess(a, b, 2);
		printmap();
		if (winorlose(a, b)) {
			cout << "玩家2胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		if (heqi()) {
			cout << "和棋" << endl;
			initializemap();                            //地图初始化
			break;
		}
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
	return 0;
}
