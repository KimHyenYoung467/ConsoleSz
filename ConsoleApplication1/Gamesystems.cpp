#include "Gamesystems.h"
#include "Player.h" // Player ����ü�� ����ϱ� ���� �߰�

extern Player player;
bool isActive; // Ȱ��ȭ����� Ȯ��

extern bool GameQuit;

float ScoreSpawnIndex = 0.0f; 

void RandomScoreIndex()
{
	ScoreSpawnIndex += Time::GetDeltaTime();

	int randomX = rand() % ScreenWidth; // ���� �ε��� ����
	int randomY = rand() % ScreenHeight; // ���� �ε��� ����
	
	int PrevrandomY;
	int PrevrandomX;
	//// �迭 �ε��� ���� (���� �ʰ� ����)
	if ((randomX < ScreenWidth && randomY < ScreenHeight)) {
		isActive = true; 
		map[randomY][randomX] = 'S'; // ������ ��ġ�� ���� ��ġ (����)
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
		ConsoleRender::ScreenDrawString(ScreenWidth / 2, ScreenHeight / 2, "�¸��ϼ̽��ϴ�.", FG_PINK_DARK);
		return true; 
	}
	else if (player.score == 0)
	{
		ConsoleRender::ScreenDrawString(ScreenWidth / 2, ScreenHeight / 2, "�й��ϼ̽��ϴ�.", FG_PINK_DARK);
		return false;
	}
}



