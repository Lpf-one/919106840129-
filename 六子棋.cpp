#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[20][20];
int order;
int a,b,a1,b1,a2,b2;
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
bool legal(int x,int y) {
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
bool heqi() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
//��ͼ��ʼ��
void initializemap() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
}
//�ж��Ƿ����
bool jinshou(int x, int y, char t, char s) {     //tΪ�Լ����ӣ�sΪ�з�����
	int num4 = 0, num5 = 0, i, j;
	int count;
	char temp1, temp2;
	count = 1;          //��ֱ�����жϽ���
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
	count = 1;          //ˮƽ�����жϽ���
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
	count = 1;    //������б������
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
	count = 1;    //����б������
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
//������Ϸ�Ľ���
void gamestart() {
	cout << "��ʼ����" << endl;
	cout << "��ѡ����Ϸģʽ" << endl;
	cout << "1.���˶�ս" << endl;
	cout << "2.Quit" << endl;
}
//������ӣ�BΪ���壬WΪ����
void playchess(int x, int y, int player) {
	if (player == 1) map[x][y] = 'B';
	else map[x][y] = 'W';
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
void gamemodeone() {
	int count = 1;
	bool flag1 = true, flag2 = true;
	while (1) {
		cout << "��" << count++ << "�غϣ�" << endl<< "���1������:" << endl;
		cin >> a>> b;
		if (huiqi(a, b) && flag1 && (count > 2)) {
			flag1 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "���1����ɹ������������룺" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a1= a;
			b1 = b;
		} else {
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a1 = a;
			b1 = b;
		}
		playchess(a, b, 1);
		printmap();
		if (jinshou(a, b, 'B', 'W')) {
			cout << "���2ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		if (winorlose(a, b)) {
			cout << "���1ʤ��" << endl<<"Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		cout << "���2�����壺" << endl;
		cin >> a >> b;
		if (huiqi(a, b)&&flag2&&(count>2)) {
			flag2 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "���2����ɹ������������룺" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a2 = a;
			b2 = b;
		} else {
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a2 =a;
			b2 = b;
		}
		playchess(a, b, 2);
		printmap();
		if (winorlose(a, b)) {
			cout << "���2ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		if (heqi()) {
			cout << "����" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
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
	return 0;
}
