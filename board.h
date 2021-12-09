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

// 메크로
#define line "│"
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

// 전역변수
extern int MapSize;			// 수정) 메크로 값 MapSize를 전역변수로 변경했습니다.
extern int stone1, stone2;	// score
extern string up;			// 수정) bord의  윗 틀 문자열. string형으로 변경했습니다.
extern string middle;		// 수정) bord의 중간틀 문자열. string형으로 변경했습니다.
extern string down;			// 수정) bord의 아래틀 문자열. string형으로 변경했습니다.


/*
// 키보드 입력검사를 위한 ASCII값.
const int KEY_LEFT = 0x25;
const int KEY_RIGHT = 0x27;
const int KEY_UP = 0x26;
const int KEY_DOWN = 0x28;
const int KEY_SPACE = 0x20;
*/

//함수 정의
class board
{
 public:
	board();						// 첫 시작 시 주어진 게임 정보로 초기화하는 함수.
	int getX();						// 커서좌표 x를 반환.
	int getY();						// 커서좌표 y를 반환.
	int getTurn();					// 현제 차례(흑돌=1, 백돌=2)를 반환. 
	int getCircle(int x, int y);	// 커서좌표애 존재하는 값 반환.
	int getSize();					// 추가) MapSize를 반환.

	void setSize(int size);			// 추가) MapSize를 초기화.
	void setUpTable(int size);		// 추가) up문자열을 MapSize에 맞게 초기화.
	void setMiddleTable(int size);	// 추가) middle문자열을 MapSize에 맞게 초기화.
	void setDownTable(int size);	// 추가) down문자열을 MapSize에 맞게 초기화.
	void setX(int x);				// 주어진 커서좌표 x로 초기화.
	void setY(int y);				// 주어진 커서좌표 y로 초기화.
	void setTurn(int turn);			// 주어진 차례로 초기화.
	void setCircle(int x, int y, int turn);	// 해당 커서좌표애 존재하는 값을 해당 차례(turn)의 돌로 초기화.
	void reset();				// 재시작하는 함수. board()와 동일.
		
	void printScreen();			// 보드판을 그려주는 함수.
	void control();				// 컨트롤 함수.
	int gotoxy(int x, int y);	// 좌표 함수.
	void SetCursorShow();		// 커서를 표시하는 함수.
	bool change();				// 돌을 놓았을 때, 변환+변환여부 검사하는 함수.
	bool End();

	// change()에서 수행하는 8가지 탐색함수.
	int change1();//12
	int change2();//1.5
	int change3();//3
	int change4();//4.5
	int change5();//6
	int change6();//7.5
	int change7();//9
	int change8();//10.5

private:
	int x, y;				// 현재 커서의 x, y 좌표
	int turn;				// 현재 차례. (흑돌=1, 백돌=2)
	int circle[50][50];	// ○●를 표시하는 2차원 배열. 보드판의 최댓값으로 정의합니다.
};
#endif
