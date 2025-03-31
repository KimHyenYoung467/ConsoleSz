#include "GameScene.h"

static SceneType currentScene = MENU; 
extern Player player;


bool GameQuit = false; 

char map[ScreenHeight][ScreenWidth];

void RunGame()
{	
	ConsoleRender::ScreenInit();

	Time::InitTime();
	
	ShowScene(); 
	MapSetInit();

	while (!GameQuit) {
		
		RenderScene();
		UpateScene();
		
	}

	ConsoleRender::ScreenRelease();
}

void ShowScene()
{	
	printf("RandomScorGame Enter<-"); 
	getchar(); 

	currentScene = PLAY; 
}

void UpateScene()
{
	Input::Update();

	PlayerAttackCheck();

	if (currentScene == PLAY) {
		if (player.x < 0) player.x = 2;
		if (player.x >= ScreenWidth) player.x = ScreenWidth - 1;
		if (player.y < 0) player.y = 2;
		if (player.y >= ScreenHeight) player.y = ScreenHeight - 1;
		 
	};
}

SceneType GetCurrentScene()
{
	return currentScene;
}

SceneType SetCurrentScene(SceneType nextScene)
{
	return currentScene = nextScene;
}

/****************************************************************************/

									//UI
	
/****************************************************************************/

void MapSetInit()
{
	for (int y = 0; y < ScreenHeight; ++y)
	{
		for (int x = 0; x < ScreenWidth; ++x)
		{
			map[y][x] = 0;

			map[ScreenHeight - 1][x] = 1;
			map[0][x] = map[ScreenHeight - 1][x];

			map[y][ScreenWidth - 1] = 1;
			map[y][0] = map[y][ScreenWidth - 1];
		}
	}
	
	for (int X = 1; X < ScreenWidth - 1; ++X)
	{
		map[ScreenHeight - 2][X] = 2; 
	}

	map[ScreenHeight - 3][3] = 3;
}



// ¸Ê UI Print
void PrintMap()
{
	char buf[250] = { 0, };
	float time = Time::GetDeltaTime();
	char TimeText = sprintf_s(buf, "PlayTime : %f", time);
	ConsoleRender::ScreenDrawChar(2, 2, TimeText, FG_SKY);

	RandomScoreIndex();

	for (int y = 0; y < ScreenHeight; ++y)
	{
		for (int x = 0; x < ScreenWidth; ++x)
		{
			switch (map[y][x])
			{
			case 0:
				buf[x] = ' ';    // ºó °ø°£
				break;
			case 1:
				buf[x] = '#';   // º®				
				break;
			case 2:
				buf[x] = '_';    // ¹Ù´Ú				
				break;
			case 3:
				buf[x] = 'P';    // ÇÃ·¹ÀÌ¾î
				break;
			case 'S' : 
				isActive = true; 
				buf[x] = 'S'; 
				break;
			case 'F':
				isActive = false;
				buf[x] = 'F';
				break;
			default:
				buf[x] = ' ';    // ¿¹¿Ü Ã³¸®
				buf[ScreenWidth] = '\0';
				break;
			}
		}
		
		ConsoleRender::ScreenDrawString(0, y, buf, FG_WHITE);
	}
}