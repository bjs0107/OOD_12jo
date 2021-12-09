#include "board.h"

board Game;
board test1;
board test2;
void EndResult();
bool Testing1();
bool Testing2();
int gotoxy(int x, int y);



void main()
{
	
	cout << "# 오델로 프로그램을 시작합니다." << endl;
	cout << "--------------------------------------------" << endl;
	cout << "# 보드판 사이즈를 입력해주세요: " << endl;
	int size;
	cin >>  size;
	if (size < 4 || (size % 2) == 1) {
		cout << "# 잘못된 사이즈 입력입니다. 기본값 8로 설정합니다." << endl;
		size = 8;
	}
	// 흑돌 = player1
	// 백돌 = player2
	cout << "--------------------------------------------" << endl;
	cout << "# 사이즈 "<< size << " 로 게임을 시작합니다. Enter를 눌러주세요." << endl;
	

	while(1)
	{
		Game.reset();
		Game.SetCursorShow();
		Game.printScreen();

		do
		{				
			if(Game.End())
				break;
			Game.control();
			Game.printScreen();

			//돌을 놓을 곳이 없을 경우!!
			if(Testing1() == false && Testing2() == false)
			{
				break;
			}

			if(Game.getTurn() == Player1)
			{
				if(Testing1() == false)
					Game.setTurn(Player2);
			}
			else
			{			
				if(Testing2() == false)
					Game.setTurn(Player1);
			}
		}while(1);

		EndResult();

		cout << "If you want replay, Press any key..." << endl;
		getch();
	}
}

void EndResult()
{	
	gotoxy(0,20);
	cout << "Player1 is " << stone1 << "  Player2 is " << stone2 << endl;

	if(stone1 > stone2)
		cout << "Player1 is winner" << endl;
	else if(stone1 == stone2)
		cout << "Game is Draw" << endl;
	else
		cout << "Player2 is winner" << endl;
}
bool Testing1()
{
	int i = 0 ,j = 0;
	test1 = Game;

	for(i = 0; i< 8 ; i++)
	{
		for(j = 0; j < 8 ; j++)
		{
			if(test1.getCircle(j,i) == NONE)
			{
				test1.setCircle(j,i, Player1);
				test1.setX(j);
				test1.setY(i);

				if(test1.change())
				{
					return true;
				}
				test1.setCircle(j, i, NONE);
			}
		}
	}
	return false;
}
bool Testing2()
{
	int i = 0 ,j = 0;
	test2 = Game;

	for(i = 0; i< 8 ; i++)
	{
		for(j = 0; j < 8 ; j++)
		{
			if(test2.getCircle(j,i) == NONE)
			{
				test2.setCircle(j,i, Player2);
				test2.setX(j);
				test2.setY(i);
				if(test2.change())
				{
					return true;
				}
				test2.setCircle(j, i, NONE);
			}
		}
	}
	return false;
}

int gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}
