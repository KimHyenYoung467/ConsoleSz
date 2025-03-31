#include "Renderer.h"
#include <stdio.h>

extern Player player;

void RenderScene()
{
	ConsoleRender::ScreenClear();
	
	if (GetCurrentScene() == PLAY)
	{
		
		PlayerKeyUpdate();
		RandomScoreIndex();  // ������ ���� ��ġ
		PrintMap();			 // �� �� �÷��̾� ���
		

		
		if (GameQuit == true)
		{
			SetCurrentScene(END);
		}

		ConsoleRender::ScreenDrawString(1, 1, "Play Scene", FG_YELLOW);
	}

	ConsoleRender::ScreenFlipping(); // ���� ��ü
}


	