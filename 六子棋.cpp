#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[20][20];
int order;
                              //�ж���Ӯ
bool winorlose(int x, int y) {
	if (x <= 14 &&
		map[x][y] == map[x + 1][y] &&
		map[x][y] == map[x + 2][y] &&
		map[x][y] == map[x + 3][y] &&
		map[x][y] == map[x + 4][y] &&
		map[x][y] == map[x + 5][y])
		return true;               //�����Һ����ж�
	if (x >= 5 &&
		map[x][y] == map[x - 1][y] &&
		map[x][y] == map[x - 2][y] &&
		map[x][y] == map[x - 3][y] &&
		map[x][y] == map[x - 4][y] &&
		map[x][y] == map[x - 5][y])
		return true;              //���ҵ�������ж�
	if (y <= 14 &&
		map[x][y] == map[x][y + 1] &&
		map[x][y] == map[x][y + 2] &&
		map[x][y] == map[x][y + 3] &&
		map[x][y] == map[x][y + 4] &&
		map[x][y] == map[x][y + 5])
		return true;              //���ϵ��������ж�
	if (y >= 5 &&
		map[x][y] == map[x][y - 1] &&
		map[x][y] == map[x][y - 2] &&
		map[x][y] == map[x][y - 3] &&
		map[x][y] == map[x][y - 4] &&
		map[x][y] == map[x][y - 5])
		return true;              //���µ��������ж�
	if (x >= 5 && y >= 5 &&
		map[x][y] == map[x - 1][y - 1] &&
		map[x][y] == map[x - 2][y - 2] &&
		map[x][y] == map[x - 3][y - 3] &&
		map[x][y] == map[x - 4][y - 4] &&
		map[x][y] == map[x - 5][y - 5] )
		return true;                   //���µ����ϵ��ж�
	if (x <= 14 && y <= 14 &&
		map[x][y] == map[x +1][y + 1] &&
		map[x][y] == map[x + 2][y +2] &&
		map[x][y] == map[x + 3][y + 3] &&
		map[x][y] == map[x + 4][y + 4] &&
		map[x][y] == map[x + 5][y + 5])
		return true;                   //���ϵ����µ��ж�
	if (x >= 5 && y <=14  &&
		map[x][y] == map[x - 1][y + 1] &&
		map[x][y] == map[x - 2][y + 2] &&
		map[x][y] == map[x - 3][y + 3] &&
		map[x][y] == map[x - 4][y + 4] &&
		map[x][y] == map[x - 5][y + 5])
		return true;                   //���µ����ϵ��ж�
	if (x <=14 && y >= 5 &&
		map[x][y] == map[x + 1][y - 1] &&
		map[x][y] == map[x + 2][y - 2] &&
		map[x][y] == map[x + 3][y - 3] &&
		map[x][y] == map[x + 4][y - 4] &&
		map[x][y] == map[x + 5][y - 5])
		return true;                   //���ϵ����µ��ж�
	return false;
} 
                          //�жϺϷ���
bool legal(int x, int y) {
	if (x > 19 || x < 0 || y>19 || y < 0 || map[x][y] != '*')
		return false;
	else return true;
}
                   //�ж��Ƿ���壬 ����-1��20ʱ����
bool huiqi(int x, int y) {
	if (x == -1 && y == 20)
		return true;
	else return false;
} 
                  //�ж��Ƿ����
bool heqi(int x, int y) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
                   //������Ϸ�Ľ���
void gamestart() {
		cout << "��ʼ����" << endl;
		cout << "��ѡ����Ϸģʽ" << endl;
		cout << "1.���˶�ս" << endl;
		cout << "2.Quit" << endl;
}
                   //��ӡ����
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
	for (int i = 0; i < 20; i++)                 //��ͼ��ʼ��
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
	gamestart();                                //������Ϸ
	while (cin >> order) {
		if (order == 1) gamemodeone();
		if (order == 2) {
			cout << "��л���Ĳ��룬���ٽ�������߾���ˮƽ��" << endl;
				break;
		}

	}
}
