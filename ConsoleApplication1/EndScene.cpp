#include "EndScene.h"

extern Player player;
extern bool GameQuit; 

void GameFaild()
{
	printf("패배 하셨습니다.\0");
	Time::GetTotalTime();
	printf("당신의 스코어 : %d", player.score);
	GameQuit = true; 
}

void GameWinner()
{
	// 스코어 점수 달성으로 승리. 
	// 엔딩 씬으로 연결? 
	ConsoleRender::ScreenClear();

	printf("승리 하셨습니다.\0");
	Time::GetTotalTime();
	GameQuit = true;
}
