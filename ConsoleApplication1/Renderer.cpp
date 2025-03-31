#include "Renderer.h"
#include <stdio.h>

extern Player player;

void RenderScene()
{
	ConsoleRender::ScreenClear();
	
	if (GetCurrentScene() == PLAY)
	{
		
		PlayerKeyUpdate();
		RandomScoreIndex();  // 아이템 랜덤 배치
		PrintMap();			 // 맵 및 플레이어 출력
		

		
		if (GameQuit == true)
		{
			SetCurrentScene(END);
		}

		ConsoleRender::ScreenDrawString(1, 1, "Play Scene", FG_YELLOW);
	}

	ConsoleRender::ScreenFlipping(); // 버퍼 교체
}


	