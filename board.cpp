#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <fstream>

#include "board.h"

using namespace std;

int MapSize;			// 수정) 메크로 값 MapSize를 전역변수로 변경했습니다.
int stone1, stone2;		// score
string up;				// 수정) bord의  윗 틀 문자열. string형으로 변경했습니다.
string middle;			// 수정) bord의 중간틀 문자열. string형으로 변경했습니다.
string down;			// 수정) bord의 아래틀 문자열. string형으로 변경했습니다.


// 첫 시작시 보드판 정보를 설정하는 함수.
// reset()함수와 동일. 
// turn = Player1(흑돌)부터 시작.
board::board()
{
	int i, j;
	for (i = 0; i < MapSize; i++)
	{
		for (j = 0; j < MapSize; j++)
		{
			circle[i][j] = NONE;
		}

	}

	// 수정) MapSize에 맞게 가운데 돌 위치 변경.
	int left = (MapSize / 2) - 1;
	int right = (MapSize / 2);
	circle[left][left] = Player1;
	circle[left][right] = Player2;
	circle[right][left] = Player2;
	circle[right][right] = Player1;

	x = left;
	y = left;
	turn = Player1;
}

/*--------------------getter--------------------*/

int board::getX()
{
	return x;
}

int board::getY()
{
	return y;
}
int board::getTurn()
{
	return turn;
}

int board::getCircle(int x, int y)
{
	return circle[x][y];
}

int board::getSize() {
	return MapSize;
}




/*--------------------setter--------------------*/

void board::setSize(int size) {
	MapSize = size;
}

void board::setUpTable(int size) {
	// 기본형태:┌ ─ ┬ ─ ┬ ─ ┬ ─ ┐
	std::string result = "┌";
	for (int i = 1; i <= size; i++) {
		if (i == size) {
			result.append(" ─ ┐");	// 끝 단인 경우.
		}
		else {
			result.append(" ─ ┬");
		}
	}
	up = result;
}

void board::setMiddleTable(int size) {
	// 기본형태:├ ─ ┼ ─ ┼ ─ ┼ ─ ┤
	std::string result = "├";
	for (int i = 1; i <= size; i++) {
		if (i == size) {
			result.append(" ─ ┤");	// 끝 단인 경우.
		}
		else {
			result.append(" ─ ┼");
		}
	}
	middle = result;
}

void board::setDownTable(int size) {
	// 기본형태:└ ─ ┴ ─ ┴ ─ ┴ ─ ┘
	std::string result = "└";
	for (int i = 1; i <= size; i++) {
		if (i == size) {
			result.append(" ─ ┘");	// 끝 단인 경우.
		}
		else {
			result.append(" ─ ┴");
		}
	}
	down = result;
}

void board::setX(int x)
{
	this->x = x;
}

void board::setY(int y)
{
	this->y = y;
}
void board::setTurn(int turn)
{
	this->turn = turn;
}
void board::setCircle(int x, int y, int turn)
{
	circle[x][y] = turn;
}

void board::printScreen()
{
	system("cls");
	int i, j;
	stone1 = 0;
	stone2 = 0;
	cout << up << endl;

	for (i = 0; i < MapSize; i++)
	{
		for (j = 0; j < MapSize; j++)
		{
			if (circle[j][i] == Player1)
			{
				cout << line << " ○";
				stone1++;
			}
			else if (circle[j][i] == Player2)
			{
				cout << line << " ●";
				stone2++;
			}
			else
			{
				cout << line << bin;
			}
		}


		cout << line;

		if (i == 1)
		{
			if (turn == Player1)
			{
				cout << "    ○" << " 흑돌(Player1)의 TURN";
			}
			else
			{
				cout << "    ●" << " 백돌(Player2)의 TURN";
			}
		}
		if (i == MapSize - 1)
		{

			cout << "    ○ = " << stone1 << "   ● = " << stone2;
		}
		cout << endl;
		if (i != MapSize - 1)
			cout << middle << endl;

	}
	cout << down << endl;
	cout << endl << " 방향키   ↑↓←→";

	cout << "   SET = SPACE" << endl;

}

void board::control()
{
	char command;
	int Loof = 2;

	SetCursorShow();
	gotoxy(2 + 4 * x, 1 + 2 * y);
	while (Loof)
	{
		command = getch();
		switch (command)
		{
		case KEY_LEFT:
			if (x > 0)
			{
				x = x - 1;
				gotoxy(2 + 4 * x, 1 + 2 * y);
			}
			break;
		case KEY_RIGHT:
			if (x < MapSize - 1)
			{
				x = x + 1;
				gotoxy(2 + 4 * x, 1 + 2 * y);
			}
			break;
		case KEY_UP:
			if (y > 0)
			{
				y = y - 1;
				gotoxy(2 + 4 * x, 1 + 2 * y);
			}
			break;
		case KEY_DOWN:
			if (y < MapSize - 1)
			{
				y = y + 1;
				gotoxy(2 + 4 * x, 1 + 2 * y);
			}
			break;
		case KEY_SPACE:
			if (circle[x][y] == NONE)
			{
				if (turn == Player1)
				{
					if (change())
					{
						circle[x][y] = turn;
						turn = Player2;
					}
				}
				else
				{
					if (change())
					{
						circle[x][y] = turn;
						turn = Player1;
					}
				}
				Loof = 0;
			}
			break;
		default:
			break;
		}
	}

}

int board::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void board::SetCursorShow()
{
	CONSOLE_CURSOR_INFO ci;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleCursorInfo(hConsole, &ci);
	ci.dwSize = 100;
	ci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &ci);
}


int board::change1()//12
{
	int i, j;
	if (y == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{
		if (circle[x][y - i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x][y - i] == NONE || y - i == 0)
			break;

	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x][y - j] = turn;
	}
	return 1;
}


int board::change2()//1.5
{
	int i, j;
	if (y == 0 || x == MapSize - 1)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{
		if (circle[x + i][y - i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x + i][y - i] == NONE || x + i == MapSize - 1 || y - i == 0)
			break;
	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x + j][y - j] = turn;
	}
	return 1;
}
int board::change3()//3
{
	int i, j;
	if (x == MapSize - 1)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{
		if (circle[x + i][y] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x + i][y] == NONE || x + i == MapSize - 1)
			break;

	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x + j][y] = turn;
	}
	return 1;
}
int board::change4()//4.5
{
	int i, j;
	if (y == (MapSize - 1) || x == (MapSize - 1))//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{

		if (circle[x + i][y + i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x + i][y + i] == NONE || x + i == (MapSize - 1) || y + i == (MapSize - 1))
			break;
	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x + j][y + j] = turn;
	}
	return 1;
}
int board::change5()//6
{
	int i, j;
	if (y == (MapSize - 1))//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{

		if (circle[x][y + i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x][y + i] == NONE || y + i == (MapSize - 1))
			break;
	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x][y + j] = turn;
	}
	return 1;
}
int board::change6()//7.5
{
	int i, j;
	if (y == (MapSize - 1) || x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{
		if (circle[x - i][y + i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x - i][y + i] == NONE || x - i == 0 || y + i == (MapSize - 1))
			break;

	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x - j][y + j] = turn;
	}
	return 1;
}
int board::change7()//9
{
	int i, j;
	if (x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{

		if (circle[x - i][y] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x - i][y] == NONE || x - i == 0)
			break;
	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for (; j > 0; j--)
	{
		circle[x - j][y] = turn;
	}
	return 1;
}
int board::change8()//10.5
{
	int i, j;
	if (y == 0 || x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for (i = 1, j = 0; i < MapSize; i++)
	{
		if (circle[x - i][y - i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if (circle[x - i][y - i] == NONE || x - i == 0 || y - i == 0)
			break;

	}
	if (j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)
	for (; j > 0; j--)
	{
		circle[x - j][y - j] = turn;
	}
	return 1;
}
bool board::change()//변환+변환여부 검사
{
	if (change1() + change2() + change3() + change4() + change5() + change6() + change7() + change8() != 0)
		return true;

	return false;
}
bool board::End()
{
	if (stone1 + stone2 == (MapSize * MapSize))//모든 자리에 돌이 꽉 채워질시
		return true;
	if (stone1 == 0 || stone2 == 0)
		return true;

	return false;
}
void board::reset()
{
	int i, j;
	for (i = 0; i < MapSize; i++)
	{
		for (j = 0; j < MapSize; j++)
		{
			circle[i][j] = NONE;
		}

	}

	// 수정) MapSize에 맞게 가운데 돌 위치 변경.
	int left = (MapSize / 2) - 1;
	int right = (MapSize / 2);
	circle[left][left] = Player1;
	circle[left][right] = Player2;
	circle[right][left] = Player2;
	circle[right][right] = Player1;

	x = left;
	y = left;
	turn = Player1;
}