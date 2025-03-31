#include "Gamesystems.h"
#include "Player.h" // Player 구조체를 사용하기 위해 추가

extern Player player;
bool isActive; // 활성화됬는지 확인

extern bool GameQuit;

float ScoreSpawnIndex = 0.0f; 

void RandomScoreIndex()
{
	ScoreSpawnIndex += Time::GetDeltaTime();

	int randomX = rand() % ScreenWidth; // 랜덤 인덱스 생성
	int randomY = rand() % ScreenHeight; // 랜덤 인덱스 생성
	
	int PrevrandomY;
	int PrevrandomX;
	//// 배열 인덱스 접근 (범위 초과 방지)
	if ((randomX < ScreenWidth && randomY < ScreenHeight)) {
		isActive = true; 
		map[randomY][randomX] = 'S'; // 임의의 위치에 문자 배치 (예제)
		PrevrandomY = randomY;
		PrevrandomX = randomX;
		};

	if (ScoreSpawnIndex > 3.0f)
	{
		isActive = false; 
		map[PrevrandomY][PrevrandomX] = 'F';
	}
	if (PrevrandomX >= 0 && PrevrandomY >= 0)
	{
		map[PrevrandomY][PrevrandomX] = 0;
	}

		return;
	
}

bool ScoreCheck()
{
	if (player.score == 50)
	{
		ConsoleRender::ScreenDrawString(ScreenWidth / 2, ScreenHeight / 2, "승리하셨습니다.", FG_PINK_DARK);
		return true; 
	}
	else if (player.score == 0)
	{
		ConsoleRender::ScreenDrawString(ScreenWidth / 2, ScreenHeight / 2, "패배하셨습니다.", FG_PINK_DARK);
		return false;
	}
}



