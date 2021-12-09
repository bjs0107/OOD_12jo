#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <fstream>

#define line "��"
#define bin "   "
#define MapSize 8
#define Player1 1
#define Player2 2
#define NONE 0


using namespace std;


// ��������
int stone1, stone2;// score
char up[] =		"�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";
char middle[] =	"�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";
char down[] =	"�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��";

const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_SPACE = 32;

//�Լ� ����
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
		
	void printScreen();//���� �׷���
	void control();// ��Ʈ��
	int gotoxy(int x, int y);//��ǥ
	void SetCursorShow();//Ŀ�� ����
	bool change();//��ȯ+��ȯ���� �˻�
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
	int x, y;//Ŀ���� x, y ��ǥ
	int turn; // ���� �����ϱ��???
	int circle[9][9];//�ۡ� ǥ��


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
				cout << line << " ��";
				// cout << line << "��";
				stone1++;
			}
			else if(circle[j][i] == Player2)
			{
				cout << line << " ��";
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
				cout << "    ��" << " TURN";
			}
			else
			{
				cout << "    ��" << " TURN";
			}
		}
		if(i==7)
		{
			
			cout << "    �� = " << stone1 << "   �� = " << stone2;
		}
		cout << endl;
		if(i != MapSize -1)
			cout << middle << endl;

	}
	cout << down << endl;
	cout << endl <<" ����Ű   �����";

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
	if(y == 0)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{
		if(circle[x][y-i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x][y-i] == NONE || y-i == 0)
			break;
		
	}
	if(j == 0 || j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x][y-j] = turn;
	}
	return 1;	
}


int board::change2()//1.5
{
	int i,j;
	if(y == 0 || x == 7)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x+i][y-i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x+i][y-i] == NONE || x+i == 7 || y-i == 0)
			break;
	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x+j][y-j] = turn;
	}
	return 1;	
}
int board::change3()//3
{
	int i,j;
	if(x == 7)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x+i][y] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x+i][y] == NONE || x+i ==7 )
			break;

	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x+j][y] = turn;
	}
	return 1;	
}
int board::change4()//4.5
{
	int i,j;
	if(y == 7 || x == 7)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{

		if(circle[x+i][y+i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x+i][y+i] == NONE || x+i == 7 || y+i == 7) 
			break;
	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x+j][y+j] = turn;
	}
	return 1;	
}
int board::change5()//6
{
	int i,j;
	if(y == 7)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{

		if(circle[x][y+i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x][y+i] == NONE || y+i == 7)
			break;
	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x][y+j] = turn;
	}
	return 1;	
}
int board::change6()//7.5
{
		int i,j;
	if(y == 7 || x == 0)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{		
		if(circle[x-i][y+i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x-i][y+i] == NONE || x-i == 0 || y+i == 7)
			break;

	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x-j][y+j] = turn;
	}
	return 1;	
}
int board::change7()//9
{
	int i,j;
	if(x == 0)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{		

		if(circle[x-i][y] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x-i][y] == NONE || x-i == 0)
			break;
	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)

	for(; j > 0; j--)
	{
		circle[x-j][y] = turn;
	}
	return 1;	
}
int board::change8()//10.5
{
	int i,j;
	if(y == 0 || x == 0)//�ǳ� �� ���� ���� ���
		return 0;
	//�ƴҰ��
	for(i = 1, j = 0; i<8 ; i++)
	{
		if(circle[x-i][y-i] == turn)//�ڽŰ� ���� ���� �߰��� ���
		{
			j = i;
			break;
		}
		if(circle[x-i][y-i] == NONE || x-i ==0 || y-i == 0)
			break;

	}
	if(j == 0|| j == 1)// ������ ���� or �� �ٸ��� �ϰ��, �ٷ� ���� ���� ���� ���
		return 0;
	//�� ���� ���(change�� ���)
	for(; j > 0; j--)
	{
		circle[x-j][y-j] = turn;
	}
	return 1;	
}
bool board::change()//��ȯ+��ȯ���� �˻�
{
	if(change1()+change2() + change3() +change4() + change5() + change6() + change7() + change8()!=0)
		return true;
	
	return false;
}
bool board::End()
{
	if(stone1 + stone2 == 64)//��� �ڸ��� ���� �� ä������
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