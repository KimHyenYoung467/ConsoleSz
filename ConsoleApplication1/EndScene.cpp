#include "EndScene.h"

extern Player player;
extern bool GameQuit; 

void GameFaild()
{
	printf("�й� �ϼ̽��ϴ�.\0");
	Time::GetTotalTime();
	printf("����� ���ھ� : %d", player.score);
	GameQuit = true; 
}

void GameWinner()
{
	// ���ھ� ���� �޼����� �¸�. 
	// ���� ������ ����? 
	ConsoleRender::ScreenClear();

	printf("�¸� �ϼ̽��ϴ�.\0");
	Time::GetTotalTime();
	GameQuit = true;
}
