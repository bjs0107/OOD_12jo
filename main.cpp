#include "board.h"

using namespace std;

board Game;
board test1;
board test2;
void StartSetting();		// 게임 시작 전 기본정보를 입력받는 함수.
void EndResult();			
bool Testing1();
bool Testing2();
int gotoxy(int x, int y);



int main()
{
	StartSetting();

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

		cout << "재시작을 원하면, 아무키나 입력하세요..." << endl;
		getch();
	}
	return 0;
}

void StartSetting() {
	int sizeInput;			// 보드판의 사이즈 입력.

	cout << "--------------------------------------------" << endl;
	cout << "# 오델로 프로그램을 시작합니다." << endl;
	cout << "# 보드판 사이즈를 입력해주세요: " << endl;
	cin >> sizeInput;

	// 보드판의 size는 항상 4이상이며, 짝수이어야만 합니다.
	if (sizeInput < 4 || (sizeInput % 2) == 1) {
		cout << "# 사이즈 " << sizeInput << " (은)는 잘못된 입력입니다.기본값 8로 설정합니다." << endl;
		sizeInput = 8;
	}
	// 사이즈 입력 후 bord.h에 sizeinput을 전송합니다.
	Game.setSize(sizeInput);
	Game.setUpTable(sizeInput);
	Game.setMiddleTable(sizeInput);
	Game.setDownTable(sizeInput);
	cout << "# 사이즈 " << sizeInput << " (으)로 게임을 시작합니다. 아무 키나 입력하세요..." << endl;
	getch();
}

void EndResult()
{	
	gotoxy(0,20);
	cout << "흑돌(Player1) = " << stone1 << "   백돌(Player2) = " << stone2 << endl;

	if(stone1 > stone2)
		cout << "흑돌(Player1) 이 승리했습니다!" << endl;
	else if(stone1 == stone2)
		cout << "비겼습니다!" << endl;
	else
		cout << "백돌(Player2) 이 승리했습니다!" << endl;
}
bool Testing1()
{
	int i = 0 ,j = 0;
	test1 = Game;

	for(i = 0; i< test1.getSize(); i++)
	{
		for(j = 0; j < test1.getSize(); j++)
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

	for(i = 0; i< test2.getSize(); i++)
	{
		for(j = 0; j < test2.getSize(); j++)
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
int gotoxy(int x, int y){
  initscr();
   move(x, y);
   endwin();
   return 0;
}
