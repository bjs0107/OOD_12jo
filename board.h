#ifndef _board_
#define _board_
#include <iostream>
#include <cstring>
#include <string>
#include <curses.h>
#include <term.h>
//#include <windows.h>
#include <time.h>
#include <iomanip>
#include <fstream>

// ��ũ��
#define line "��"
#define bin "   "
#define Player1 1
#define Player2 2
#define NONE 0

#ifndef KEY_LEFT
#define KEY_LEFT 0x25
#endif
#ifndef KEY_RIGHT
#define KEY_RIGHT 0x27
#endif
#ifndef KEY_UP
#define KEY_UP 0x26
#endif
#ifndef KEY_DOWN
#define KEY_DOWN 0x28
#endif
#ifndef KEY_SPACE
#define KEY_SPACE 0x20
#endif
using namespace std;

// ��������
extern int MapSize;			// ����) ��ũ�� �� MapSize�� ���������� �����߽��ϴ�.
extern int stone1, stone2;	// score
extern string up;			// ����) bord��  �� Ʋ ���ڿ�. string������ �����߽��ϴ�.
extern string middle;		// ����) bord�� �߰�Ʋ ���ڿ�. string������ �����߽��ϴ�.
extern string down;			// ����) bord�� �Ʒ�Ʋ ���ڿ�. string������ �����߽��ϴ�.


/*
// Ű���� �Է°˻縦 ���� ASCII��.
const int KEY_LEFT = 0x25;
const int KEY_RIGHT = 0x27;
const int KEY_UP = 0x26;
const int KEY_DOWN = 0x28;
const int KEY_SPACE = 0x20;
*/

//�Լ� ����
class board
{
 public:
	board();						// ù ���� �� �־��� ���� ������ �ʱ�ȭ�ϴ� �Լ�.
	int getX();						// Ŀ����ǥ x�� ��ȯ.
	int getY();						// Ŀ����ǥ y�� ��ȯ.
	int getTurn();					// ���� ����(�浹=1, �鵹=2)�� ��ȯ. 
	int getCircle(int x, int y);	// Ŀ����ǥ�� �����ϴ� �� ��ȯ.
	int getSize();					// �߰�) MapSize�� ��ȯ.

	void setSize(int size);			// �߰�) MapSize�� �ʱ�ȭ.
	void setUpTable(int size);		// �߰�) up���ڿ��� MapSize�� �°� �ʱ�ȭ.
	void setMiddleTable(int size);	// �߰�) middle���ڿ��� MapSize�� �°� �ʱ�ȭ.
	void setDownTable(int size);	// �߰�) down���ڿ��� MapSize�� �°� �ʱ�ȭ.
	void setX(int x);				// �־��� Ŀ����ǥ x�� �ʱ�ȭ.
	void setY(int y);				// �־��� Ŀ����ǥ y�� �ʱ�ȭ.
	void setTurn(int turn);			// �־��� ���ʷ� �ʱ�ȭ.
	void setCircle(int x, int y, int turn);	// �ش� Ŀ����ǥ�� �����ϴ� ���� �ش� ����(turn)�� ���� �ʱ�ȭ.
	void reset();				// ������ϴ� �Լ�. board()�� ����.
		
	void printScreen();			// �������� �׷��ִ� �Լ�.
	void control();				// ��Ʈ�� �Լ�.
	int gotoxy(int x, int y);	// ��ǥ �Լ�.
	void SetCursorShow();		// Ŀ���� ǥ���ϴ� �Լ�.
	bool change();				// ���� ������ ��, ��ȯ+��ȯ���� �˻��ϴ� �Լ�.
	bool End();

	// change()���� �����ϴ� 8���� Ž���Լ�.
	int change1();//12
	int change2();//1.5
	int change3();//3
	int change4();//4.5
	int change5();//6
	int change6();//7.5
	int change7();//9
	int change8();//10.5

private:
	int x, y;				// ���� Ŀ���� x, y ��ǥ
	int turn;				// ���� ����. (�浹=1, �鵹=2)
	int circle[50][50];	// �ܸۡ� ǥ���ϴ� 2���� �迭. �������� �ִ����� �����մϴ�.
};
#endif
