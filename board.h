#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <fstream>

#define line "│"
#define bin "   "
#define MapSize 8
#define Player1 1
#define Player2 2
#define NONE 0


using namespace std;


// 전역변수
int stone1, stone2;// score
char up[] =		"┌ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┐";
char middle[] =	"├ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┤";
char down[] =	"└ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┘";

const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_SPACE = 32;

//함수 정의
class board
{
public:
	board();//reset(); turn = = Player1;
	int getX();
	int getY();
	int getTurn();
	int getCircle(int x, int y);

	void setX(int x);
	void setY(int y);
	void setTurn(int turn);
	void setCircle(int x, int y, int turn);
	void reset();
		
	void printScreen();//판을 그려줌
	void control();// 컨트롤
	int gotoxy(int x, int y);//좌표
	void SetCursorShow();//커서 깜빡
	bool change();//변환+변환여부 검사
	bool End();
////////////////////////////////////////////
	int change1();//12
	int change2();//1.5
	int change3();//3
	int change4();//4.5
	int change5();//6
	int change6();//7.5
	int change7();//9
	int change8();//10.5
////////////////////////////////////////////////
private:
	int x, y;//커서의 x, y 좌표
	int turn; // 누구 차례일까요???
	int circle[9][9];//○● 표시


};


board::board()//reset(); turn = = Player1;
{
	int i,j;
	for(i =0; i<MapSize; i++)
	{
		for(j=0; j<MapSize; j++)
		{
			circle[i][j] = NONE;
		}
		
	}
	circle[3][3] = Player1;
	circle[3][4] = Player2;
	circle[4][3] = Player2;
	circle[4][4] = Player1;

	x = 3;
	y = 3;
	turn = Player1;
}
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




///////////////////////////////////////////
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
	int i,j;
	stone1 = 0;
	stone2 = 0;
	cout << up << endl;
	
	for(i = 0; i < 8; i++)
	{
		for(j = 0 ; j < 8; j++)
		{
			if(circle[j][i] == Player1)
			{
				cout << line << " ○";
				// cout << line << "가";
				stone1++;
			}
			else if(circle[j][i] == Player2)
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
		
		if(i == 5)
		{
			if(turn == Player1)
			{
				cout << "    ○" << " TURN";
			}
			else
			{
				cout << "    ●" << " TURN";
			}
		}
		if(i==7)
		{
			
			cout << "    ○ = " << stone1 << "   ● = " << stone2;
		}
		cout << endl;
		if(i != MapSize -1)
			cout << middle << endl;

	}
	cout << down << endl;
	cout << endl <<" 방향키   ↑↓←→";

	cout << "   SET = SPACE" << endl;

}

void board::control()
{
	char command;
	int Loof = 2;
	
	SetCursorShow();
	gotoxy(2+4*x, 1+2*y);
	while(Loof)
	{
		command = getch();
		switch(command)
		{
		case KEY_LEFT:
			if(x>0)
			{
				x = x-1;
				gotoxy(2+4*x,1+2*y);
			}
			break;
		case KEY_RIGHT:
			if(x < 7)
			{
				x = x +1;
				gotoxy(2+4*x,1+2*y);
			}
			break;
		case KEY_UP:			
			if(y > 0)
			{
				y = y -1;
				gotoxy(2+4*x,1+2*y);
			}
			break;
		case KEY_DOWN:
			if(y < 7)
			{
				y = y+1;
				gotoxy(2+4*x,1+2*y);
			}
			break;
		case KEY_SPACE:
			if(circle[x][y] == NONE )
			{
				if(turn == Player1)
				{
					if(change())
					{
						circle[x][y] = turn;
						turn = Player2;
					}
				}else
				{					
					if(change())
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

	GetConsoleCursorInfo( hConsole, &ci );
	ci.dwSize = 100;
	ci.bVisible = TRUE;
	SetConsoleCursorInfo( hConsole , &ci );
}


int board::change1()//12
{
	int i,j;
	if(y == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{
		if(circle[x][y-i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x][y-i] == NONE || y-i == 0)
			break;
		
	}
	if(j == 0 || j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x][y-j] = turn;
	}
	return 1;	
}


int board::change2()//1.5
{
	int i,j;
	if(y == 0 || x == 7)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x+i][y-i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x+i][y-i] == NONE || x+i == 7 || y-i == 0)
			break;
	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x+j][y-j] = turn;
	}
	return 1;	
}
int board::change3()//3
{
	int i,j;
	if(x == 7)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x+i][y] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x+i][y] == NONE || x+i ==7 )
			break;

	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x+j][y] = turn;
	}
	return 1;	
}
int board::change4()//4.5
{
	int i,j;
	if(y == 7 || x == 7)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{

		if(circle[x+i][y+i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x+i][y+i] == NONE || x+i == 7 || y+i == 7) 
			break;
	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x+j][y+j] = turn;
	}
	return 1;	
}
int board::change5()//6
{
	int i,j;
	if(y == 7)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{

		if(circle[x][y+i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x][y+i] == NONE || y+i == 7)
			break;
	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x][y+j] = turn;
	}
	return 1;	
}
int board::change6()//7.5
{
		int i,j;
	if(y == 7 || x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x-i][y+i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x-i][y+i] == NONE || x-i == 0 || y+i == 7)
			break;

	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x-j][y+j] = turn;
	}
	return 1;	
}
int board::change7()//9
{
	int i,j;
	if(x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{		

		if(circle[x-i][y] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x-i][y] == NONE || x-i == 0)
			break;
	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)

	for(; j > 0; j--)
	{
		circle[x-j][y] = turn;
	}
	return 1;	
}
int board::change8()//10.5
{
	int i,j;
	if(y == 0 || x == 0)//맨끝 에 점이 찍힐 경우
		return 0;
	//아닐경우
	for(i = 1, j = 0; i<8 ; i++)
	{
		if(circle[x-i][y-i] == turn)//자신과 같은 색을 발견할 경우
		{
			j = i;
			break;
		}
		if(circle[x-i][y-i] == NONE || x-i ==0 || y-i == 0)
			break;

	}
	if(j == 0|| j == 1)// 위에가 공백 or 쭉 다른색 일경우, 바로 위가 같은 색일 경우
		return 0;
	//그 외의 경우(change될 경우)
	for(; j > 0; j--)
	{
		circle[x-j][y-j] = turn;
	}
	return 1;	
}
bool board::change()//변환+변환여부 검사
{
	if(change1()+change2() + change3() +change4() + change5() + change6() + change7() + change8()!=0)
		return true;
	
	return false;
}
bool board::End()
{
	if(stone1 + stone2 == 64)//모든 자리에 돌이 꽉 채워질시
		return true;
	if(stone1 == 0 || stone2 == 0)
		return true;
	
	return false;
}
void board::reset()
{
	int i,j;
	for(i =0; i<MapSize; i++)
	{
		for(j=0; j<MapSize; j++)
		{
			circle[i][j] = NONE;
		}
		
	}
	circle[3][3] = Player1;
	circle[3][4] = Player2;
	circle[4][3] = Player2;
	circle[4][4] = Player1;

	x = 3;
	y = 3;
	turn = Player1;
}