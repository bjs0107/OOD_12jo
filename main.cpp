#include "board.h"

using namespace std;

board Game;
board test1;
board test2;
void StartSetting();		// ���� ���� �� �⺻������ �Է¹޴� �Լ�.
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

			//���� ���� ���� ���� ���!!
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

		cout << "������� ���ϸ�, �ƹ�Ű�� �Է��ϼ���..." << endl;
		getch();
	}
	return 0;
}

void StartSetting() {
	int sizeInput;			// �������� ������ �Է�.

	cout << "--------------------------------------------" << endl;
	cout << "# ������ ���α׷��� �����մϴ�." << endl;
	cout << "# ������ ����� �Է����ּ���: " << endl;
	cin >> sizeInput;

	// �������� size�� �׻� 4�̻��̸�, ¦���̾�߸� �մϴ�.
	if (sizeInput < 4 || (sizeInput % 2) == 1) {
		cout << "# ������ " << sizeInput << " (��)�� �߸��� �Է��Դϴ�.�⺻�� 8�� �����մϴ�." << endl;
		sizeInput = 8;
	}
	// ������ �Է� �� bord.h�� sizeinput�� �����մϴ�.
	Game.setSize(sizeInput);
	Game.setUpTable(sizeInput);
	Game.setMiddleTable(sizeInput);
	Game.setDownTable(sizeInput);
	cout << "# ������ " << sizeInput << " (��)�� ������ �����մϴ�. �ƹ� Ű�� �Է��ϼ���..." << endl;
	getch();
}

void EndResult()
{	
	gotoxy(0,20);
	cout << "�浹(Player1) = " << stone1 << "   �鵹(Player2) = " << stone2 << endl;

	if(stone1 > stone2)
		cout << "�浹(Player1) �� �¸��߽��ϴ�!" << endl;
	else if(stone1 == stone2)
		cout << "�����ϴ�!" << endl;
	else
		cout << "�鵹(Player2) �� �¸��߽��ϴ�!" << endl;
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
